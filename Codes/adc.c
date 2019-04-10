/*
 *#© 01/03/2019- Swaminath Venkateswaran, Damien Chablat, Mathieu Poréz, Frédéric Boyer 
 *# Le LS2N, Centrale Nantes
 */

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
