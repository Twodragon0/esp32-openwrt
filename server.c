//server.c
# include "header.h"
 
int main(int argc, char *argv[]) 
{
 
    //서버의 listen 소켓 데이터 구조 생성과정
    char buffer[BUFFER_LEN];
    struct sockaddr_in server_addr, client_addr;
    char temp[20];
    char chat_data[CHAT_SIZE];
    int server_fd, client_fd;
    int len, msg_size, n;
    char test[20];
    char Quit[5] = "quit";
 
    if (argc != 2)
    {
        printf("사용법 : ./filename 포트번호 \n");
        exit(0);
    }
 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("Server: can not Open Socket\n");
        exit(0);
    }
 
    //listen file descriptor 선언
 
    // memset은 모든 값을 0으로 초기화 해주기위해 서버 실행 시 이용한다.
    memset(&server_addr, 0x00, sizeof(server_addr));
 
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));
 
    //bind 과정
 
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Server: can not bind local address\n");
        exit(0);
    }
    printf("Waiting for clients...\n");
 
    //listen 과정
    if (listen(server_fd, 5) < 0) 
    {
        printf("Server: can not listen connect. \n");
        exit(0);
    }
 
    memset(buffer, 0x00, sizeof(buffer));
    len = sizeof(client_addr);
 
    printf("=====[PORT] : %d =====\n", atoi(argv[1]));
    printf("Server: waiting connection request.\n");
 
 
 
 
    // accept 기다리는 과정
    while (1) 
    {
        //클라이언트를 accept하는 과정
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&len);
 
        if (client_fd < 0)
        {
            printf("Server: accept failed\n");
            exit(0);
        }
 
        
        inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, temp, sizeof(temp));
        printf("Server: %s client connect,\n", temp);
        
        
        //클라이언트 메세지 받기

        char buffer[BUFFER_LEN] = {0};
	n = read(client_fd, buffer, BUFFER_LEN);
	printf("server received: %d bytes: %s", n, buffer);
        write(client_fd, buffer, strlen(buffer));
 
        //클라이언트 접속 종료
        printf("Server: %s client closed.\n", temp);
        close(client_fd);
    }
 
    //서버 listen socket 종료
    close(server_fd);
 
    return 0;
}

