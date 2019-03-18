/*
 *  adc.c
 *  
 *
 *
 */

#include "adc.h"

int get_adc(const char * file_name)
{
	int val;
	FILE* fp;
	fp = fopen(file_name, "r");
	fscanf(fp, "%d", &val);
	fclose (fp);
	return val;
}
