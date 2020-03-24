#include <sys/stat.h>
 
#include <fcntl.h>
 
#include <errno.h>
 
#include <netdb.h>
 
#include <sys/types.h>
 
#include <sys/socket.h>
 
#include <netinet/in.h>
 
#include <arpa/inet.h>
 
#include <stdio.h>
 
#include <string.h>
 
#include <stdlib.h>
 
#include <unistd.h>

#include <stdlib.h>

#include <string>

#include <iostream>

 
#define SERVER_PORT 6666
 
/*
连接到服务器后，会不停循环，等待输入，
输入quit后，断开与服务器的连接
*/

using namespace std;
 
int list[24] ={36, 40, 44, 48, 52, 56, 60, 64, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 149, 153, 157, 161, 165};


int main()
 
{
 
//客户端只需要一个套接字文件描述符，用于和服务器通信
 
int clientSocket;

int i;
 
//描述服务器的socket
 
struct sockaddr_in serverAddr;
 
char sendbuf[200];
 
char recvbuf[200];
 
int iDataNum;
 
if((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
 
{
 
perror("socket");
 
return 1;
 
}
 
serverAddr.sin_family = AF_INET;
 
serverAddr.sin_port = htons(SERVER_PORT);
 
//指定服务器端的ip，本地测试：127.0.0.1
 
//inet_addr()函数，将点分十进制IP转换成网络字节序IP
 
serverAddr.sin_addr.s_addr = inet_addr("10.0.0.5");
 
if(connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
 
{
 
perror("connect");
 
return 1;
 
}
 
printf("connecting to server...\n");
 
while(1)
 
{
 
for (i=0; i<24; i++){

printf("sending channel number: %d", list[i]);

string command1;
string command2;

string str;
str = to_string(list[i]);

//scanf("%s", sendbuf);

sprintf(sendbuf, "%d", list[i]);

//itoa(list[1],sendbuf,10);
 
printf("\n");


sleep(1);

command1 = "sudo iw mon0 set channel " + str + " HT20";
command2 = "sudo iw wlan0 set channel " + str + " HT20";
system(command1.c_str());
system(command2.c_str());
system ("iwconfig");

send(clientSocket, sendbuf, strlen(sendbuf), 0);
}
 

 
if(strcmp(sendbuf, "quit") == 0)
 
break;
 
//printf("读取消息:");
 
//recvbuf[0] = '\0';
 
//iDataNum = recv(clientSocket, recvbuf, 200, 0);
 
//recvbuf[iDataNum] = '\0';
 
//printf("%s\n", recvbuf);
 
}
 
close(clientSocket);
 
return 0;
 
}
