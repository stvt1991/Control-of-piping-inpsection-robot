#include "activation.h"

void set_activ(const char * dev, const char * reg, const char * val)
{
	static int fd, len;
	static char buff[64];
	static char file[64];
	sprintf(file,"%s/%s",dev,reg);
	fd = open(file,O_RDWR);
	len = sprintf(buff,"%s",val);
	write(fd,buff,len);
	close(fd);
}

void set_gpio(const char * dev1, unsigned int val1)
{
	static int fd1, len1;
	static char buff1[64];
	static char file1[64];
	sprintf(file1,"%s",dev1);
	fd1 = open(file1,O_WRONLY);
	len1 = sprintf(buff1,"%d",val1);
	write(fd1,buff1,len1);
	close(fd1);
}

