#include"stdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>


typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
#define SIZE 1024

typedef struct HttpRequest{
	char first_line[SIZE]; //获取首行内容
	char * method;
	char * url;
	char * url_path;
	char * query_string;
	int content_length;
}HttpRequest;

int ServerInit(char* ip, char *port){
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock<0){
		perror("socket");
		return 1;
	}
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(port));
	addr.sin_addr.s_addr = inet_addr(ip);

	int bin = bind(sock, (sockaddr*)&addr, sizeof(addr));
	if (bin<0){
		perror("bind");
		return 1;
	}

	int lisn = listen(sock, 5);
	if (lisn<0){
		perror("listen");
		return 1;
	}

	return sock;
}
int ReadLine(int sock, char buf[], ssize_t max_size){
char c = '\0';
	size_t i = 0; 
	while (i<max_size){
		ssize_t read_size = recv(sock, &c, 1, 0);
		if (read_size <= 0){ 
			perror("recv");
			return -1;
		}
		if (c == '\r'){
			recv(sock, &c, 1, MSG_PEEK);
			if (c == '\n'){
				recv(sock, &c, 1, 0); 
			}
			else { 
				c = '\n';
			}
		}
		else if (c == '\n'){
			break;
		}
		buf[i++] = c;  
	}
	buf[i] = '\0';
	return 0; 
}

int Split(char first_line[], const char * Split_char, char * output[]){
	int out_put = 0; 
	char * tmp = NULL;
	//此处的tmp必须是栈上的变量
	char * p = strtok_r(first_line, Split_char, &tmp);
	while (p != NULL){
		output[out_put++] = p;
		p = strtok_r(NULL, Split_char, &tmp); 
	}
	return out_put;
}

int ParseFirstLine(char first_line[], char ** method_ptr, char ** url_ptr){
	
	char * tokens[100] = { NULL };
	ssize_t n = Split(first_line, " ", tokens); 
	if (n != 3){
		printf("first_line Split error! n=%d\n", n);
		return -1;
	}
	*method_ptr = tokens[0];
	*url_ptr = tokens[1];

	return 0;
}

int ParseQueryString(char * url, char ** url_path, char ** query_string){
	
	char * p = url;
	*url_path = p;
	for (; *p != '\0'; p++){
		if (*p == '?'){ 
			*p = '\0';
			*query_string = p + 1;
			return 0;
		}
	}
	
	*query_string = NULL;

	return 0; 
}


int HandlerHeader(int new_sock, int * content_length){
	char buf[SIZE] = { 0 };
	while (1){
		if (ReadLine(new_sock, buf, sizeof(buf)<0)){
			printf("readline failed!\n");
			return -1;
		}
		if (strcmp(buf, "\n") == 0){  
			printf("form error!\n");
			return 0;
		}
		char * Content_Length_str;
		if (strncmp(buf, "Content_Length_str", strlen("Content_Length_str") == 0)){
			*content_length = atoi(buf + strlen(Content_Length_str));
			
		}
	}

}

void HandlerStaticfile()
{
	//1.根据以上获得的URL_path获得一个真实的文件路径
	char file_path[size]={0};
	HandlerFilepath( req->url_path,file_path);
	//服务器一般的时候看到的路径就是http:www.baidu.com/index.html
	//这里的index.html表示的就是真实文件的路径
	//2.打开文件，把文件中的内容读出来，并写入socket，通过socket再传给客户端，也就是输出在浏览器上
	writestaticfile(new_sock,file_path);
	return 200;
}

void HandlerFilepath(const char *url_path,char file_path,char file_path[ ])
{
	sprintf("file_path",/source/url_path);//指定根目录
	//对于URL_path还有几种特殊情况
	//1.如果URL没有写路径，默认为根目录
	//如果写了，则对应的路径下的目录。比如http:www.baidu.com/source/image.png
	if( url_path[strlen(url_path)-1=='/'])//最后一个为/,说明访问的是一个目录
	{
		strcat("file_path","/")
	}
	if(iddir(file_path))
	{
		strcat("/",file_path);
	}
	
}


void isdir(const char *file_path)//判断是文件还是目录
{
	struct stat st;//显示文件信息
	int ret=stat(file_path,&st);
	if(ret<0)
	{
		perror("stat");
		return 0;
	}
	int temp=isdir(st.st_mode);
	if(temp)
	{
		return 1;
	}
	return 0;
}


void writestaticfile(int new_sock,const char *filepath)
{
	//1.文件打开可能根本不存在
	int fd=open(file_path,O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return 404;
	}
	//2.给socket写的数据其实一个HTTP响应
	const char *first_line="HTTP/1.1 200 OK\n";
	char Headler[SIZE]={0};
	sprintf(header,"content_length:%u\n",file_size);
	const char *blank_line='\n';
	
	//将数据由内核拷贝到用户缓冲区，然后再拷贝回去
    sendfile(new_sock,fd,NULL,getsize(&st));//节省了拷贝的开销
	close(fd);
	return 200;
}

void getsize(stat* st)
{
	return st.st_size;
}



void Handler404(int new_sock){
	const char* first_line = "HTTP/1.1 404  not found\n";
	send(new_sock, first_line, strlen(first_line), 0);
	const char *blank_line = "\n";
	
	const char *body="sorry!您的页面跑到外太空去了\n";
	char content_length[SIZE] = { 0 };
	sprintf(content_length, "content_length :%lu\n", strlen(body));
	send(new_sock, first_line, strlen(first_line), 0);
	send(new_sock, content_length, strlen(content_length), 0);
	send(new_sock, blank_line, strlen(blank_line), 0);
	send(new_sock, body, strlen(body), 0);
	return 0;
}
	

void HandlerRequest(int new_sock){
	
	HttpRequest req;
	memset(&req, 0x00, sizeof(req));
	int err_code = 200;
	
	if (ReadLine(new_sock, req.first_line, sizeof(req.first_line) - 1)<0){
		printf("Read first line failed!\n");
		err_code = 404;
		goto END;
	}
	
	if (ParseFirstLine(req.first_line, &req.method, &req.url)<0){
		printf("parse first line failed!\n");
		err_code = 404;
		goto END;
	}
	
	if (ParseQueryString(req.url, &req.url_path, &req.query_string)<0){
		printf("ParseQueryString failed! url=%s\n", req.url);
		err_code = 404;
		goto END;
	}
	
	if (HandlerHeader(new_sock, &req.content_length)<0){
		printf("HandlerHeader failed!\n");
		err_code = 404;
		goto END;
	}
	
		if (strcmp((req.method), "GET") == 0 && req.query_string == NULL){
		HandlerStaticFile(new_sock,&req);//静态文件的处理
	}
	else if (strcmp(req.method, "GET") == 0 && req.query_string != NULL){
		HandlerCGI(new_sock,&req);
	}
	else if (strcmp(req.method, "POST") == 0){
		HandlerCGI(new_sock,&req);//动态处理
	}

END:
	if (err_code != 200){
		Handler404(new_sock);//错误处理页面
	}
	
	close(new_sock);
}


void* ThreadEntry(void* arg){
	
	int new_sock = *(int *)arg;
	//HandlerRequest(new_sock);
	Handler404(new_sock);
	return NULL;

}

int main(int argc, char *argv[]){
	if (argc != 3){
		printf("Usage ./http_sever.c [ip] [port]\n");
		return 1;
	}
	
	int listen_sock = ServerInit(argv[1], argv[2]);
	if (listen_sock<0){
		printf("ServerInit failed!\n");
		return 1;
	}
	printf("ServerInit OK!\n");

	while (1){
		sockaddr_in peer;
		socklen_t len = sizeof(peer);
		int  new_sock = accept(listen_sock, (sockaddr*)&peer, &len);
		if (new_sock<0){
			perror("accept");
			return 1;
		}
		pthread_t tid;
		pthread_create(&tid, NULL, ThreadEntry, (void*)new_sock);
		pthread_detach(tid);
	}

	close(listen_sock);
	return 0;
}

