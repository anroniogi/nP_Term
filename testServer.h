#include"headerFiles.h"

#define MAXLINE 1024
#define PORTNUM 50000
#define SOCK_SETSIZE 1021

#define MAX_CLIENT 100

pthread_t accept_f;
int accept_id;
pthread_t client_echo[MAX_CLIENT];

UserData user[10];
int UserCount = 0;

int listen_s, client_s[100];
socklen_t addrlen;
int fd_num;
int maxfd = 0;
int sockfd;
int readn;
int i= 0;
char buf[MAXLINE];
int num=0;
fd_set readfds, allfds;

struct sockaddr_in server_addr, client_addr;

//연결된 소켓 배열 - 채팅방
//int list[MAX_CLIENT];
int room1[MAX_CLIENT/5];
int room2[MAX_CLIENT/5];
int room3[MAX_CLIENT/5];
int room4[MAX_CLIENT/5];
int room5[MAX_CLIENT/5];

int clnt_num1=0;
int clnt_num2=0;
int clnt_num3=0;
int clnt_num4=0;
int clnt_num5=0;

int status = 1;


/*
  func : id 입력 후 파일 내에 저장
*//*
void Input_id(int s){
    int n;
    bool status=false;
    while(!status){
        write(s,"ID : ",1024);
        n=recv(s, buf, MAXLINE-1, 0);
        buf[n]='\n';
        if(*buf != '\0'){
            SaveUserID(buf, user[UserCount].id, UserCount);
            status = true;
        }
        else
            write(s, "첫 글자는 공백을 입력할 수 없습니다.", 1024);
    }
}

/*
  func : pwd 입력 후 파일 내에 저장
*//*
void Input_pwd(int s){
    int n;
  write(s, "Pwd : ",1024);
  n=recv(s, buf, MAXLINE-1, 0);
  buf[n]='\n';
  SaveUserPwd(buf, user[UserCount].pwd, UserCount);
}

/*
  func : name 입력 후 파일 내에 저장
*//*
void Input_name(int s){
    int n;
  write(s,"Name : ",1024);
  n=recv(s, buf, MAXLINE-1, 0);
  buf[n]='\n';
  SaveUserName(buf, user[UserCount].name, UserCount);
}


void login(int s){
    bool check;
    char id[15];
    while(1){
      while(*id == '\0' || *id == ' '){
          write(s,"ID: ",1024);
          recv(s, id, 15, 0);
      }


      //id 확인
      if(check=!CheckUserId(id)){
        //회원 가입 안내 전송
        write(s,"Sign_Up Please!!",1024);

        //Input_id 호출
        Input_id(s);

        //Pwd 입력
        Input_pwd(s);

        //Name 입력
        Input_name(s);

        UserCount ++;
        return 0;
      }
      //Login pwd 입력문 호출
      else  {
        write(s,"pwd: ",1024);
        read(s, buf, MAXLINE-1);

        //pwd 확인
        if(!CheckUserPwd(buf)){
          write(s,"Faile Password!",1024);
          return 0;
        }
        else {
          UserCount++;
          break;
        }
      }
    }
}

*/



void to_Listen(){

    memset((void *)&server_addr, 0x00, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORTNUM);

    if((listen_s = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket error");
        exit(0);
    }

    if(bind(listen_s, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind error");
        exit(0);
    }
    if(listen(listen_s, 5) == -1)
    {
        perror("listen error");
        exit(0);
    }
}



void echo(int num){
    bool one=true;
    int n;
    int join = 0;
    char name[20];
    char msg[MAXLINE];

    send(client_s[num], "이름을 입력하세요", MAXLINE-1, 0);
    n=recv(client_s[num], name, MAXLINE-1, 0);
    name[n] = '\0';



    while(status){
        if((n=recv(client_s[num], buf, MAXLINE-1, 0))==0){
            printf("client[%d] 접속 종료", num);//채팅방 목록에서도 삭제해야됨
            status=0;
        }else if(join == 0){
            strcat(msg, name);
            strcat(msg, "님이 입장하셨습니다.");

            for(int i=0; i<100; ++i)
            if(client_s[num] != client_s[i])
                send(client_s[i], msg, MAXLINE-1, 0);

            msg[0]='\0';
            join = 1;
        }
        else{
            buf[n]='\0';
            strcat(msg, name);
            strcat(msg, " : ");
            strcat(msg, buf);
            if(one){
                for(int i=0; i<100; ++i){
                    if(client_s[num] != client_s[i])
                    send(client_s[i], msg, MAXLINE-1, 0);
                }
            }
            one = !one;
            msg[0]='\0';
        }
    }
}


void Accept(int num){
    int s;
    while(status){
        socklen_t addrlen = sizeof(client_addr);

        s = accept(listen_s, (struct sockaddr *)&client_addr, &addrlen);
        client_s[num] = s;

//        login(s);

        accept_id = pthread_create(&client_echo[num], NULL, echo, num);
        pthread_detach(client_echo[num]);

        num++;
    }
}

void to_Create(int listen_s){
        accept_id = pthread_create(&accept_f, NULL, Accept, num);
        pthread_detach(accept_f);

}


//접속종료시 사용자 배열에서 삭제
void Delete(int *ar, int idx)
{
    memmove(ar + idx, ar + idx + 1, strlen(ar) - idx);
}
