/*
 *  deplacement.c
 *  
 *
 */

#include "deplacement.h"
#include "pwm.h"
#include "gpio.h"
#include "adc.h"	
#include "utile.h"

//Fonctions de déplacemnt :

void initialisation (struct_robot *Robot)
{
	//Initialisation du motor 1:
	printf("initialisation pwm M1\n");
	set_pwm(pwm_M1, PWM_POLARITY,0);
	set_pwm(pwm_M1, PWM_RUN,1);
	set_pwm(pwm_M1, PWM_PERIOD, PERIODE_PWM);
	set_pwm(pwm_M1, PWM_DUTY, DUTY_ZERO);  //50% --> 0A (voir config contlr)
	printf("initialisation des pin M1\n");
	set_gpio(enable_M1,DIRECTION,1); // 1 = "out"
	set_gpio(enable_M1,VALUE,0); // 1 --> enable
	set_gpio(sens_M1,DIRECTION,1); // 1 = "out"
	set_gpio(sens_M1,VALUE,0); // 0 à gauche, 1 à droite
	printf("fin init M1\n");
	(*Robot).m1=0;
	
	//Initialisation du motor 2:
	printf("initialisation pwm M2\n");
	set_pwm(pwm_M2, PWM_POLARITY,0);
	set_pwm(pwm_M2, PWM_RUN,1);
	set_pwm(pwm_M2, PWM_PERIOD, PERIODE_PWM);
	set_pwm(pwm_M2, PWM_DUTY, DUTY_ZERO);  //50% --> 0A (voir config contlr)
	printf("initialisation des pin M2\n");
	set_gpio(enable_M2,DIRECTION,1); // 1 = "out"
	set_gpio(enable_M2,VALUE,0); // 1 --> enable
	set_gpio(sens_M2,DIRECTION,1); // 1 = "out"
	set_gpio(sens_M2,VALUE,0); // 0 à gauche, 1 à droite
	printf("fin init M2\n");
	(*Robot).m2=0;
	
	//Initialisation du motor 3:
	printf("initialisation pwm M3\n");
	set_pwm(pwm_M3, PWM_POLARITY,0);
	set_pwm(pwm_M3, PWM_RUN,1);
	set_pwm(pwm_M3, PWM_PERIOD, PERIODE_PWM);
	set_pwm(pwm_M3, PWM_DUTY, DUTY_ZERO);  //50% --> 0A (voir config contlr)
	printf("initialisation des pin M3\n");
	set_gpio(enable_M3,DIRECTION,1); // 1 = "out"
	set_gpio(enable_M3,VALUE,0); // 1 --> enable
	set_gpio(sens_M3,DIRECTION,1); // 1 = "out"
	set_gpio(sens_M3,VALUE,0); // 0 à gauche, 1 à droite
	printf("fin init M3\n");
	(*Robot).m3=0;
	sleep(3);
	printf("Fin initialisaton\n\n");
}
//  fonctions qui renvoient le courant des moteurs
 int Get_adc_M1(void)
 {
	return get_adc(adc_M1);
 }
 int Get_adc_M2(void)
  {
	return get_adc(adc_M2);
 }
 int Get_adc_M3(void)
  {
	return get_adc(adc_M3);
 }
//fonction qui se charge de déclamper les pattes avants
void clamp_AV (struct_robot *Robot)
{
	printf("Fonction clampe AVANT\n");
	int i =0;
	
	//on enable le moteur
	set_gpio(enable_M1,VALUE,1); // 1 --> enable
	

	//on alimente le moteur
	sleep(1);
	set_pwm(pwm_M1, PWM_DUTY, DUTY_AV);
	(*Robot).m1=1;
	sleep(1);
	// Controle en courant
	while((*Robot).a1 <= seuil_H)
	{
		//usleep(100);
		printf("\nVoici le courant : %d",(*Robot).a1);
	}	
	
	//on eteint le moteur
	set_pwm(pwm_M1, PWM_DUTY, DUTY_ZERO);
	(*Robot).m1=0;
	//On disable le moteur:
	set_gpio(enable_M1,VALUE,0); // 1 --> enable
	sleep(1);
	printf("\nFin clamp AV\n\n");
}

//fonction qui se charge de clamper les pattes avants
void declamp_AV (struct_robot *Robot)
{
	printf("\nFonction declampe AVANT\n");
	int i =0;
	sleep(1);
	//on enable le moteur
	set_gpio(enable_M1,VALUE,1); // 1 --> enable

	//on alimente le moteur
		sleep(1);
		set_pwm(pwm_M1, PWM_DUTY, DUTY_AR);
		(*Robot).m1=-1;
	// Controle en courant
	while((*Robot).a1 >= seuil_B)
	{	
		//usleep(100);
		printf("Voici le courant : %d\n",(*Robot).a1);
	}
	//on eteint le moteur
	set_pwm(pwm_M1, PWM_DUTY, DUTY_ZERO);
	(*Robot).m1=0;
	//On disable le moteur:
	set_gpio(enable_M1,VALUE,0); // 1 --> enable
	sleep(1);
	printf("Fin declamp AV\n\n");
}

//fonction qui se charge de clamper les pattes avants dans 1 d cst
void declamp_AV_Dcst (struct_robot *Robot)
{
	printf("\nFonction declampe AVANT avec D cst\n");
	int i =0;
	sleep(1);
	//on enable le moteur
	set_gpio(enable_M1,VALUE,1); // 1 --> enable

	//on alimente le moteur
		sleep(1);
		set_pwm(pwm_M1, PWM_DUTY, DUTY_AR);
		(*Robot).m1=-1;
		printf("Voici le courant : %d\n",(*Robot).a1);
		sleep(4);
	//on eteint le moteur
	set_pwm(pwm_M1, PWM_DUTY, DUTY_ZERO);
	(*Robot).m1=0;
	//On disable le moteur:
	set_gpio(enable_M1,VALUE,0); // 1 --> enable
	sleep(1);
	printf("Fin declamp AV\n\n");
}

//fonction qui se charge de déclamper les pattes ar
void clamp_AR (struct_robot *Robot)
{
	printf("\nFonction clampe AR\n");
	int i =0;
	sleep(1);
	//on enable le moteur
	set_gpio(enable_M3,VALUE,1); // 1 --> enable


	//on alimente le moteur
	sleep(1);
	set_pwm(pwm_M3, PWM_DUTY, DUTY_AV);
	(*Robot).m3=1;
	sleep(1);
	
	// Controle en courant
	while((*Robot).a3 <= seuil_H)
	{
		//usleep(100);                        
		printf("Voici le courant : %d\n",(*Robot).a3);
	}
	//on eteint le moteur
	set_pwm(pwm_M3, PWM_DUTY, DUTY_ZERO);
	(*Robot).m3=0;
	//On disable le moteur:
	set_gpio(enable_M3,VALUE,0); // 1 --> enable
	sleep(1);
	printf("Fin clamp AR\n\n");
}

//fonction qui se charge de clamper les pattes ar
void declamp_AR (struct_robot *Robot)
{
	printf("\nFonction declampe AR\n");
	int i =0;
	sleep(1);
	//on enable le moteur
	set_gpio(enable_M3,VALUE,1); // 1 --> enable
	sleep(1);


	//on alimente le moteur
	sleep(1);
	set_pwm(pwm_M3, PWM_DUTY, DUTY_AR); 
	(*Robot).m3=-1;
	sleep(1)
	;
	// Controle en courant
	while((*Robot).a3  >= seuil_B)
	{
		//usleep(100);                      
		printf("Voici le courant : %d\n",(*Robot).a3);
	}

	//on eteint le moteur
	set_pwm(pwm_M3, PWM_DUTY, DUTY_ZERO);
	(*Robot).m3=0;
	sleep(1);
	
	//On disable le moteur:
	set_gpio(enable_M3,VALUE,0); // 1 --> enable
	printf("Fin declamp AR\n");
}
//fonction qui se charge de clamper les pattes ar avec D cst
void declamp_AR_Dcst (struct_robot *Robot)
{
	printf("\nFonction declampe AR avec D cst\n");
	int i =0;
	sleep(1);
	//on enable le moteur
	set_gpio(enable_M3,VALUE,1); // 1 --> enable

		//usleep(100);
		set_pwm(pwm_M3, PWM_DUTY, DUTY_AR);
		(*Robot).m3=-1;
		printf("Voici le courant : %d\n",(*Robot).a3);
		sleep(4);

	//on eteint le moteur
	set_pwm(pwm_M3, PWM_DUTY, DUTY_ZERO);
	(*Robot).m3=0;
	sleep(1);
	//On disable le moteur:
	set_gpio(enable_M3,VALUE,0); // 1 --> enable
	printf("Fin declamp AR\n");
}
//fonction qui se charge d'allonge le segment centrale
void repli (struct_robot *Robot)
{
	printf("\nFonction repli : \n");
	int i =0;
	//on enable le moteur
	set_gpio(enable_M2,VALUE,1); // 1 --> enable
	sleep(1);

	//on alimente le moteur
		sleep(1);
		set_pwm(pwm_M2, PWM_DUTY, DUTY_AV);
		(*Robot).m2=1;
		sleep(1);
	// Ctrl I
	while((*Robot).a2 <= 1350)
	{
		//usleep(100);
		printf("Voici le courant : %i\n",(*Robot).a2);
	}
	//on eteint le moteur
	set_pwm(pwm_M2, PWM_DUTY, DUTY_ZERO);
	(*Robot).m2=0;
	//On disable le moteur:
	set_gpio(enable_M2,VALUE,0); // 1 --> enable
	sleep(1);
	printf("Fin repl\n");
}

//fonction qui se charge de replier le segment centrale
void allong (struct_robot *Robot)
{
	printf("\nFonction  allong\n\n");
	sleep(1);
	//on enable le moteur
	set_gpio(enable_M2,VALUE,1); // 1 --> enable

	//on alimente le moteur	
		sleep(1);
		set_pwm(pwm_M2, PWM_DUTY, DUTY_AR);
		(*Robot).m2=-1;
		printf("Voici le courant : %d\n",(*Robot).a2);
		sleep(25);
	//}
	//on eteint le moteur
	set_pwm(pwm_M2, PWM_DUTY, DUTY_ZERO);
	(*Robot).m2=0;
	//On disable le moteur:
	set_gpio(enable_M2,VALUE,0); // 1 --> enable
	printf("Fin allong\n\n");
}

int avance (int nbpas,struct_robot *Robot)
{
	//function de déplacement avant.
	int i;
	//initialisation (ETAT);
	sleep(1);
	for(i=1;i<=nbpas;i++)
	{
	printf("avance : pas %i sur %i\n",i,nbpas);
	//marche avant
		//e1
		printf("e1 :");
		declamp_AV_Dcst(Robot);
		//e2
		printf("e2 :");
		allong(Robot);
		//e3
		printf("e3 :");
		clamp_AV(Robot);
		//e4
		printf("e4 :");
		declamp_AR_Dcst(Robot);
		//e5
		printf("e5 :");
		repli(Robot);
		//e6
		printf("e6 :");
		clamp_AR(Robot);
	}
	return 0;
}

int recule(int nbpas,struct_robot *Robot)
{
	//function de déplacement arriere, il n'y a que l'ordre des déclamp qui change.
	int i;
	sleep(3);
	for(i=1;i<=nbpas;i++)
	{
	printf("recule : pas %i sur %i\n",i,nbpas);
	//marche avant
		//e1
		printf("e1 :");
		declamp_AR_Dcst(Robot);;
		//e2
		printf("e2 :");
		allong(Robot);
		//e3
		printf("e3 :");
		clamp_AR(Robot);
		//e4
		printf("e4 :");
		declamp_AV_Dcst(Robot);
		//e5
		printf("e5 :");
		repli(Robot);
		//e6
		printf("e6 :");
		clamp_AV(Robot);
	}
	return 0;
}

int init_out_pipe (struct_robot *Robot)
{
	//fonction d'arret du robot
	initialisation (Robot);
	printf("init pos out tube:\n");
	declamp_AV(Robot);
	repli(Robot);
	declamp_AR(Robot);
	return 0;
}

int init_in_pipe (struct_robot *Robot)
{
	//fonction d'arret du robot
	initialisation (Robot);
	printf("init pos in tube:\n");
	clamp_AV(Robot);
	repli(Robot);
	clamp_AR(Robot);
	return 0;
}
	
