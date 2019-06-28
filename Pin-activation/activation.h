#ifndef _ACTIVATION_H
#define _ACTIVATION_H


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ACTIV_CAPEMGR "/sys/devices/bone_capemgr.9"

//Define PWM
#define PWM_P9_14 "/sys/devices/ocp.3/pwm_test_P9_14.12"
#define PWM_P9_31 "/sys/devices/ocp.3/pwm_test_P9_31.13"
#define PWM__P8_13 "/sys/devices/ocp.3/pwm_test_P8_13.14"

#define PWM_SLOTS "slots"
#define PWM_POLARITY "polarity"
#define PWM_RUN "run"

//Define GPIO
#define ACTIV_GPIO "/sys/class/gpio/export"

void set_activ(const char * dev, const char * reg, const char * val);
void set_gpio(const char * dev1, unsigned int val1);


#endif // ACTIVATION_H_INCLUDED
