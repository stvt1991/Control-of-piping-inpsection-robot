/*
 *#© 01/03/2019- Swaminath Venkateswaran, Damien Chablat, Mathieu Poréz, Frédéric Boyer 
 *# Le LS2N, Centrale Nantes
 */

/*
 *  eqep.h
 *  
 *
 */

#ifndef _EQEP_H
#define _EQEP_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* EQEP folders */
#define EQEP0 "/sys/devices/ocp.3/48300000.epwmss/48300180.eqep"
#define EQEP1 "/sys/devices/ocp.3/48302000.epwmss/48302180.eqep"
#define EQEP2 "/sys/devices/ocp.3/48304000.epwmss/48304180.eqep"

/* EQEP files */
#define POSITION "position"  
#define MODE "mode"
#define PERIOD "period"
#define ENABLED "enabled"

int get_eqep(const char * dev, const char * reg);
void set_eqep(const char * dev, const char * reg, int val);

#endif
