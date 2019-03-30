/*
 *  deplacement.h
 *  
 *
 */

#ifndef _DEPLACEMENT_H
#define _DEPLACEMENT_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pwm.h"
#include "gpio.h"
#include "adc.h"
#include "utile.h"

//define des noms de pin:
//Pour le motor 1 :
#define pwm_M1 EHRPWM1A
#define enable_M1 GPIO_31
#define sens_M1 GPIO_30
#define adc_M1 AIN0
//Pour le motor 2 :
#define pwm_M2 EHRPWM2B
#define enable_M2 GPIO_47
#define sens_M2 GPIO_27
#define adc_M2 AIN1
//Pour le motor 2 :
#define pwm_M3 EHRPWM0A
#define enable_M3 GPIO_68
#define sens_M3 GPIO_67
#define adc_M3 AIN2

//Variable PWM:
#define PERIODE_PWM 500000    //Periode (500 micros) --> 2KHz
#define DUTY_ZERO 250000     //Duty pour 50% --> 0 A (voir config contrl)
#define DUTY_AV 400000       //Duty pour 80% --> 13000 tr/min
#define DUTY_AR 100000      //Duty pour 20% --> 13000 tr/min

//Autres variable
#define seuil_B 420
#define seuil_H 1500
typedef struct struct_robot struct_robot;
struct struct_robot {
	int a1;
	int a2;
	int a3;
	int m1;
	int m2;
	int m3;
};
void initialisation (struct_robot *Robot);

int Get_adc_M1(void);
int Get_adc_M2(void);
int Get_adc_M3(void);

void declamp_AV (struct_robot *Robot);
void declamp_AV_Dcst (struct_robot *Robot);

void clamp_AV (struct_robot *Robot);

void declamp_AR (struct_robot *Robot);
void declamp_AR_Dcst(struct_robot *Robot);
void clamp_AR (struct_robot *Robot);

void allong (struct_robot *Robot);
void repli (struct_robot *Robot);

int avance (int nbpas,struct_robot *Robot);
int recule (int nbpas,struct_robot *Robot);
int init_out_pipe (struct_robot *Robot);
int init_in_pipe (struct_robot *Robot);

#endif
