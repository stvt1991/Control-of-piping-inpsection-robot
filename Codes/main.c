/*
 *#© 01/03/2019- Swaminath Venkateswaran, Damien Chablat, Mathieu Poréz, Frédéric Boyer 
 *# Le LS2N, Centrale Nantes
 */

/*
 *  main.c
 *  
 *
 */

#include <stdio.h>
#include <pthread.h>
#include <time.h>

#include "pwm.h"
#include "gpio.h"
#include "adc.h"
#include "deplacement.h"

struct_robot Robot;

 
void* fonction_cmd()
{
	int nbpas=1;
	printf("debut du programme\n\n");
	

	avance(nbpas,&Robot);
	sleep(2);
	avance(nbpas,&Robot);
	sleep(2);
	recule(nbpas,&Robot);
	sleep(2);
	recule(nbpas,&Robot);	
	FILE *fend;
	fend = fopen("end","w");
	fclose(fend);
}
	

void* fonction_log()
{
	time_t t = time(NULL);
	struct tm *info;
	info = localtime( &t );
	long clk_tck = CLOCKS_PER_SEC;
	
	char buffer[256];
	strftime(buffer, sizeof(buffer), "log_%Y-%m-%d %H-%M-%S.txt", info);
	printf("Formatted fil log : |%s|\n", buffer );
	
	
	clock_t start_t, end_t, total_t;
	start_t = clock();
	
	FILE *fp;
	fp = fopen("end", "r");
	
	FILE *flog;
	flog = fopen(buffer,"w");	
	while(fp == NULL)
	{
		fp = fopen("end", "r");
		end_t = clock();
		
		double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		Robot.a1=Get_adc_M1();
		Robot.a2=Get_adc_M2();
		Robot.a3=Get_adc_M3();
		fprintf(flog,"%lf\t%i\t%i\t%i\t%i\t%i\t%i\n",total_t,Robot.a1,Robot.a2,Robot.a3,Robot.m1,Robot.m2,Robot.m3); 
		usleep(1000);
	}
	fclose(flog);
	fclose (fp);
}

int main (int argc, char ** argv)
{
	printf("debut du programme\n\n");
	remove("end");
	pthread_t thread_cmd;
	pthread_t thread_log;
	
	pthread_create(&thread_cmd , NULL , fonction_cmd ,NULL);
	pthread_create(&thread_log , NULL , fonction_log ,NULL);
	
	pthread_join(thread_cmd,NULL);
	pthread_join(thread_log,NULL);
	
	printf("\nfin programme\n");
	
	return 0;
}
