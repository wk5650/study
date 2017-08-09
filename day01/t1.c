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
	int fd=-1;
	fd=open(argv[1],O_WRONLY | O_CREAT,0664);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	int ret=-1;
	char buf[4096]={'\0'};
	printf("请输入要写入的数据:");
	scanf("%s",buf);
	while(getchar()!='\n');
	ret=write(fd,buf,strlen(buf));
	if(-1==ret)
	{
		perror("write");
		return -1;
	}else
	{
		printf("写入成功,写入%d个数据\n",ret);
		return 0;
	}
	close(fd);

	return 0;
}
