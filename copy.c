#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

static unsigned char buf[2048];

int version = 1; // Chapter 2 will explain this

void copy(int old,int new)
{
	int count = 0;

	while((count=read(old,buf,sizeof(buf)))>0)
	{
		write(new,buf,count);
	}
}

int main(int argc,char*argv[])
{
	if (argc != 3)
	{
		printf("need 2 arguments for copy program\n");
		exit(1);
	}

	int fdold = open(argv[1],O_RDONLY); //open source file read only

	if (fdold == -1)
	{
		printf("cannot open file %s\n",argv[1]);

		exit(1);
	}

	int fdnew = creat(argv[2],0666); //create target file rw for all
		
	if(fdnew==-1)
	{
		printf("cannot create file %s\n",argv[2]);
		exit(1);
	}

	copy(fdold,fdnew);
	exit(0);

}

