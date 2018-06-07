// TCP echo client
#include "headerFiles.h"

#define SIZE 1024

int main (int argc, char* argv[])
{
    //
    int s;
    int n;
    char* servName;
    int servPort;
    char* string;
    int len;
    int maxLen;
    int test;
    char buffer[SIZE];
    char* ptr = buffer;
    char buffer_rcv[SIZE];
    char* ptr_rcv = buffer_rcv;

    struct sockaddr_in servAddr;
    //
    if(argc !=4)
    {
        printf("ERROR : three arguments are needed");
        exit(1);
    }
    servName = argv[1];
    servPort = atoi(argv[2]);
    string = argv[3];
    //
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    inet_pton(AF_INET, servName, &servAddr.sin_addr);
    servAddr.sin_port = htons(servPort);
    s = socket(PF_INET, SOCK_STREAM, 0);
    if(s < 0)
    {
        perror("ERROR : socket creation failed");
        exit(1);
    }
    //
    if(connect(s, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0)
    {
        perror("ERROR : connection failed");
        exit(1);
    }
    //
    while(1){
        printf("보낼 문자열을 입력하세요 : ");
        gets(buffer);
        if(strcmp(ptr, "quit")==0)
            break;

        test = send(s, ptr, SIZE, 0);
        n = recv(s, ptr_rcv, SIZE, 0);
        printf("Echoed string received: ");
        fputs(buffer_rcv, stdout);
        printf("\n");
//        ptr_rcv = buffer_rcv[0];
    }

//
    //printf("\n");
    close(s);
    //
    exit(0);
}
