#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/*creat*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>  //errno

int main(int argc, char *argv[])
{
	int i=0;
	int fd=-1;
	fd=open(argv[1],O_RDONLY);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	int ret=-1;
	char buf[4096]={'\0'};
	ret=read(fd,buf,sizeof(buf));
	if(-1==ret)
	{
		perror("read");
		return -1;
	}
	else if(0==ret)
	{
		printf("已全部读完,共读出%d个数据\n",ret);
		return 0;
	}
	else
	{
		printf("读出%d个数据\n",ret);
//		for(i=0;i<strlen(buf);i++)
//		{
			printf("%s",buf);
//		}
		return 0;
	}
	close(fd);
}
