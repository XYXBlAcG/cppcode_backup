#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <netdb.h>

#define BUFSIZE 1024

/**
 * @brief 获取http头部信息
 *
 * @param fd [in] 	sock套接字
 * @param buf [in] 	存放http头部信息缓冲区
 * @param bufLen [in] 	缓冲区长度
 *
 * @return 成功：http头部/失败：-1
 */
int getHttpHead(int fd, char *buf, int bufLen)
{
	char tmp[1] = {0};
	int i = 0;
	int offset = 0;
	int nbytes = 0;

	while((nbytes=recv(fd,tmp,1, 0))==1)
	{
		if(offset > bufLen-1)
		{
			return bufLen;
		}
		
		if(i < 4)
		{
			if(tmp[0] == '\r' || tmp[0] == '\n') i++;
			else i = 0;
			
			strncpy(buf+offset, tmp, 1);
			offset++;
		}
		
		if(4 == i)
		{
			return offset;
		}
	}
	
	return offset;
}

/**
 * @brief 与URL建立连接，并获取sock_fd
 *
 * @param url [in] 	URL地址
 *
 * @return sock_fd
 */
int geturl(char* url)
{
	int			cfd;
	struct sockaddr_in	cadd;
	struct hostent		*pURL = NULL;
	char			host[BUFSIZE], GET[BUFSIZE];
	char			request[BUFSIZE];
	char			text[BUFSIZE] = {0};

	memset(host, 0, BUFSIZE);
	memset(GET, 0, BUFSIZE);
	memset(request, 0, BUFSIZE);
	memset(text, 0, BUFSIZE);
	
	if(!url)
	{
		return -1;
	}
	
	if(!strstr(url, "http://") && !strstr(url, "https://"))
    {
        return -1;
    }
	//分离url中的主机地址和文件相对路径
	sscanf(url, "%*[^//]//%[^/]%s", host, GET);

	printf("GET = %s\n", GET);
	printf("host = %s\n", host);
	printf("url = %s\n", url);

	if(!GET || !host)
	{
		return -1;
	}
	
	//创建套接字
	if (-1 == (cfd = socket( AF_INET, SOCK_STREAM, 0)))
	{
		printf( "create socket failed of client!\n" );
		return -1;
	}

	//将上面获得的主机信息通过域名解析函数获得域名信息
	pURL = gethostbyname(host);

	//设置IP地址结构
	bzero(&cadd, sizeof(struct sockaddr_in));
	cadd.sin_family			= AF_INET;
	cadd.sin_addr.s_addr	= *((unsigned long *)pURL->h_addr_list[0]);
	cadd.sin_port			= htons(80);
	
	//向HTTP服务器发送URL信息
	snprintf(request, BUFSIZE, 		\
				"GET %s HTTP/1.1\r\n"
				"HOST: %s\r\n"
				"Cache-Control: no-cache\r\n"
				"Connection: close\r\n\r\n",
				GET,host);

	printf("\nrequest = \n%s\n", request);
	
	//连接服务器
	if (-1 == connect(cfd, (struct sockaddr *)&cadd, (socklen_t)sizeof(cadd)))
	{
		printf( "connect failed of client!\n" );
		return -1;
	}

	//向服务器发送url请求的request
	if (-1 ==send(cfd, request, strlen( request ), 0 ))
	{
		printf( "向服务器发送请求的request失败!\n" );
		return -1;
	}

	//客户端接收服务器的返回信息
	getHttpHead(cfd, text, sizeof(text));
	printf("head = :\n%s\n", text);
	
	return cfd;
}


/**
 * @brief 获取URL中的文件名
 *
 * @param URLPath [in] 	URL地址
 *
 * @return 文件名
 */
char *GetFileName(char *URLPath)
{
    char ch = '/';
    char *q = strrchr(URLPath, ch) + 1;

    return q;
}

int main(int argc, char* argv[])
{
	int sockfd = -1;
	char		buf[BUFSIZE] = {0};
	char		fileName[BUFSIZE] = {0};
	int			fd = -1;
	
	if ( argc < 2 )
	{
		printf( "用法:%s url网页网址\n", argv[0] );
		return -1;
	}
	
	strncpy(fileName, GetFileName(argv[1]), BUFSIZE);
	sockfd = geturl(argv[1]);
	
	printf("fileName = %s\n", fileName);
	remove(fileName);
	
	fd = open(fileName, O_WRONLY | O_CREAT, 777 );
	if(fd == -1)
	{
		perror( "OPen error" );
		return -1;
	}
	
	while (1)
	{
		memset( buf, 0, BUFSIZE );
		int cr;
		cr = recv(sockfd, buf, BUFSIZE, 0);
		if ( cr <= 0 )
		{
			printf("break\n");
			break;
		}
		write(fd, buf, cr);
	}
	
	close(fd);
	close(sockfd);
	return 0;
}
