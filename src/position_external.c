/**
 *    ||          ____  _ __
 * +------+      / __ )(_) /_______________ _____  ___
 * | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *  ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2012 BitCraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * position_external.c: Module to receive current position and yaw from external source
 */

 #ifndef POSITION_EXTERNAL_H_
#define POSITION_EXTERNAL_H_

void positionExternalInit(void);
bool positionExternalTest(void);

void positionExternalGetLastData(
  float* x,
  float* y,
  float* z,
  float* q0,
  float* q1,
  float* q2,
  float* q3,
  uint16_t* last_time_in_ms);

extern bool positionExternalFresh;

#endif /* POSITION_EXTERNAL_H_ */

//#include <errno.h>

/* FreeRtos includes */

#include "position_external.h"
//#include "num.h"
//#include "configblock.h"
#include "sim_module_variables.h"

bool positionExternalFresh = false;

// Private types
/*
typedef uint16_t fp16_t;
struct data {
  struct {
    uint8_t id;
    fp16_t x; // m
    fp16_t y; // m
    fp16_t z; // m
    int16_t quat[4]; //Quaternion; TODO: find more compact way to store this
                      // each component between -1 and 1
  } pose[2];
};
*/
// Global variables
/*
static bool isInit = false;
static float lastX;
static float lastY;
static float lastZ;
static float lastQ0;
static float lastQ1;
static float lastQ2;
static float lastQ3;
static uint64_t lastTime = 0;
static uint8_t my_id;
static float v_x;
static float v_y;
static float v_z;
*/

//Private functions
static void positionExternalCrtpCB(CRTPPacket* pk);

void positionExternalInit(void)
{
  //moo
}

bool positionExternalTest(void)
{
  return true;
}

void positionExternalGetLastData(
  float* x,
  float* y,
  float* z,
  float* q0,
  float* q1,
  float* q2,
  float* q3,
  uint16_t* last_time_in_ms)
{
  *x = quad_internals[current_quad].lastX;
  *y = quad_internals[current_quad].lastY;
  *z = quad_internals[current_quad].lastZ;
  *q0 = quad_internals[current_quad].lastQ0;
  *q1 = quad_internals[current_quad].lastQ1;
  *q2 = quad_internals[current_quad].lastQ2;
  *q3 = quad_internals[current_quad].lastQ3;
  if (current_tick - quad_internals[current_quad].lastTime < 10 * 1000) {
    *last_time_in_ms = current_tick - quad_internals[current_quad].lastTime;
  } else {
    *last_time_in_ms = 10 * 1000;
  }
}
/*
static void positionExternalCrtpCB(CRTPPacket* pk)
{
  struct data* d = ((struct data*)pk->data);
  for (int i=0; i < 2; ++i) {
    if (d->pose[i].id == my_id) {
      float x = half2single(d->pose[i].x);
      float y = half2single(d->pose[i].y);
      float z = half2single(d->pose[i].z);

      if (lastTime != 0) {
        float dt = (xTaskGetTickCount() - lastTime) / 1000.0f;
        v_x = (x - lastX) / dt;
        v_y = (y - lastY) / dt;
        v_z = (z - lastZ) / dt;
      }


      lastX = x;
      lastY = y;
      lastZ = z;
      lastQ0 = d->pose[i].quat[0] / 32768.0;
      lastQ1 = d->pose[i].quat[1] / 32768.0;
      lastQ2 = d->pose[i].quat[2] / 32768.0;
      lastQ3 = d->pose[i].quat[3] / 32768.0;

      lastTime = xTaskGetTickCount();
      positionExternalFresh = true;
    }
  }
}

LOG_GROUP_START(vicon)
LOG_ADD(LOG_FLOAT, v_x, &v_x)
LOG_ADD(LOG_FLOAT, v_y, &v_y)
LOG_ADD(LOG_FLOAT, v_z, &v_z)
LOG_GROUP_STOP(vicon)
*/