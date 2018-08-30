#include< stdlib.h>
#include< stdio.h>
#include< string.h>
#include< unistd.h>
#include<test.h>//将最本质的测试合法性的代码的头文件引过来
int Getquerystring( char buf[ ])
{
	//从环境变量中读取到方法
    char *method=getenv( "REQUEST_method");
    if( method==NULL)
	{   
		 fprintf(  stderr,"FAILED");
	     return -1;
   	}
	//如果是get方法，从环境变量中获取到QUERY_STRING 
	if(strcasecmp(method,"GET")==0)
	{
		char *p=getenv("QUERY_string");
		if(p==NULL)
		{
			fprintf(stderr,"FALIED");
			return -1;
		}
		strcpy(buf,p);
		return 0;
	}
	else
	//如果是post方法，从环境变量中获取到content_length
	{
		char *p=getenv("QUERY_string");
		if( p==NULL)
		{
			fprintf(stderr,"failed");
			return -1;
		}
		//根据content_length的数值从标准输入读取id号码
		 int content_length=atoi(p);
		 int i=0;
		 for(;i< content_lenghth;++i)
		 {
			 read(0,&buf[i]);
		 }
		 buf[content_length]='\0';
	}
	return 0;
}

int main()
{
	//1.获取到必要的信息，此处需要获取需要验证的输入的身份证号码
	//解析请求
	char buf[1024*4]={0};
	//此函数的功能自动根据get或者post请求对应的参数信息
	//并且把参数信息填充到部分缓冲区里，就是写到浏览器上边网址的参数部分
	//例如写的是id=61062219971121112这样的字符串
	int ret=Getquerystring(buf);
	if(ret< 0)
	{
		fprintf(stderr,"Getquerystring failed!\n");
		return 1;
	}
	fprintf(stderr,"buf=%s\n",buf);

	//实际需要的内容为id号码,此处使用scanf完成字符串解析，获取到其中的id号码
	char *userInput_char;
	sscanf(buf,"id=%s",&userInput_char);//读取id号码

	//2.进行id号码的检测，此处的代码是关键之处，是核心，通过此处的代码，判断出号码是否合法
	//并且输出对应的信息
	
	

	//3.将所要的结果输出重定向到HTML上，只需要改写HTML的BODY部分，输出想要的内容就可以了
    test( );	
	
	return 0;
}
	





	}

		  





		
	
																	 

	


