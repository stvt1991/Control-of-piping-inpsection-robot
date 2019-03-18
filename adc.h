/*
 *  adc.h
 *  
 *
 *
 */

#ifndef _ADC_H
#define _ADC_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* ADC addresses */

#define AIN0 "/sys/devices/ocp.3/helper.15/AIN0"
#define AIN1 "/sys/devices/ocp.3/helper.15/AIN1"
#define AIN2 "/sys/devices/ocp.3/helper.15/AIN2"
#define AIN3 "/sys/devices/ocp.3/helper.15/AIN3"
#define AIN4 "/sys/devices/ocp.3/helper.15/AIN4"
#define AIN5 "/sys/devices/ocp.3/helper.15/AIN5"
#define AIN6 "/sys/devices/ocp.3/helper.15/AIN6"
#define AIN7 "/sys/devices/ocp.3/helper.15/AIN7"

/* ADC constants */
#define ADC_WIDTH 1800
#define ADC_HALF_WIDTH 900
#define ADC_BIAIS 0

int get_adc(const char * file_name);

#endif
