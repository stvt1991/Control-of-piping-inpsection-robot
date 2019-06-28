#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "activation.h"

int main ()
{
    //Activation PWM

    set_activ(ACTIV_CAPEMGR,PWM_SLOTS,"am33xx_pwm");
    set_activ(ACTIV_CAPEMGR,PWM_SLOTS,"bone_pwm_P9_14");
    set_activ(PWM_P9_14,PWM_RUN,"0");
    set_activ(PWM_P9_14,PWM_POLARITY,"0");
    sleep(0.1);

    set_activ(ACTIV_CAPEMGR,PWM_SLOTS,"bone_pwm_P9_31");
    set_activ(PWM_P9_31,PWM_RUN,"0");
    set_activ(PWM_P9_31,PWM_POLARITY,"1");
    sleep(0.1);

    set_activ(ACTIV_CAPEMGR,PWM_SLOTS,"bone_pwm_P8_13");
    set_activ(PWM__P8_13,PWM_RUN,"0");
    set_activ(PWM__P8_13,PWM_POLARITY,"0");
    sleep(0.1);

    //Activation GPIO

    set_gpio(ACTIV_GPIO,30);
    set_gpio(ACTIV_GPIO,31);
    set_gpio(ACTIV_GPIO,47);
    set_gpio(ACTIV_GPIO,27);
    set_gpio(ACTIV_GPIO,67);
    set_gpio(ACTIV_GPIO,68);

    //Activation AIN

    set_activ(ACTIV_CAPEMGR,PWM_SLOTS, "cape-bone-iio");

    return 0;
}

