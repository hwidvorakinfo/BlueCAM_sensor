/*
 * sensor.h
 *
 *  Created on: 6. 10. 2019
 *      Author: Petr Dvorak
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "stm32f10x.h"
#include "defs.h"
#include "application.h"
#include "misc.h"

void sensor_config (void);
void sensor_line_ready(uint8_t value);


#endif /* SENSOR_H_ */
