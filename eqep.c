/*
 *  eqep.c
 *  
 *
 */

#include "eqep.h"

int get_eqep(const char * dev, const char * reg)
{
	int val;
	FILE* fp;
	char file[64];
	sprintf(file,"%s/%s",dev,reg);
	fp = fopen(file, "r");
	fscanf(fp, "%d", &val);
	fclose (fp);
	return val;
}

void set_eqep(const char * dev, const char * reg, int val)
{
	int fd, len;
	char buff[64];
	char file[64];
	sprintf(file,"%s/%s",dev,reg);
	fd = open(file,O_RDWR);
	len = sprintf(buff,"%d",val);
	write(fd,buff,len);
	close(fd);
}
