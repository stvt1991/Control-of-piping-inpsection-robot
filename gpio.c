/*
 *  gpio.c
 *  
 *
 */

#include "gpio.h"

void set_gpio(const char * dev, const char * reg, int val)       // dev et reg? reg semble etre le chemin, dev?
{
	static int fd;
	static int len=0;
	static char buff[64];
	static char file[64];
	sprintf(file,"%s/%s",dev,reg);
	fd = open(file,O_RDWR);          // Ouverture du fichier de la BBB contenant la Pin voulue
	if (strcmp (reg, DIRECTION)==0) // regarde si la pin configuré, ici elle ne l'est pas donc  il le fait lui, 
	{
		switch (val) 
		{
			case 0:
				len = sprintf(buff,GPIO_IN);  // sprintf " renvoi une chaine de caratére. Len est la taille
				break;
			case 1:
				len = sprintf(buff,GPIO_OUT);
				break;
			default:
				break;
		}
	}
	else
	{
		len = sprintf(buff,"%d",val);  //deja config en IN ou OUT, il va juste envoyer la valee
	}
	write(fd,buff,len);   //ecrit dans le fichier 
	close(fd);
}




int get_gpio(const char * dev, const char * reg)
{
	static int val;
	FILE* fp;
	static char file[64];
	static char buff[64];
	static int len;
	sprintf(file,"%s/%s",dev,reg);
	fp = fopen(file, "r");
	
	if (strcmp (reg, DIRECTION)==0)
	{
		len=fscanf(fp, "%s", buff);
		buff[len]=0;
		if (strcmp (buff, GPIO_IN)==0)
		{
			val=0;
		}
		else if (strcmp (buff, GPIO_OUT)==0)
		{
			val=1;
		}
		else
		{
			val=-1;
		}
	}
	else
	{
		fscanf(fp, "%d", &val);
	}
	fclose (fp);
	return val;
}
