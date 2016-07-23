#ifndef __QUAD_CONTEXT_H
#define __QUAD_CONTEXT_H

#include "sim_module_variables.h"
#include "simulation_variables.h"

//declare global variable refs
extern bool * ekf_initialized;
extern bool * ekf_first_vicon;
extern float * controller_kp_xy;
extern float * controller_kd_xy;
extern float * controller_ki_xy;
extern float * controller_kp_z;
extern float * controller_kd_z;
extern float * controller_ki_z;
extern float * controller_massThrust;
extern float * controller_kR_xy;
extern float * controller_kR_z;
extern float * controller_kw_xy;
extern float * controller_kw_z;
extern float * controller_ki_m_xy;
extern float * controller_ki_m_z;
extern float * controller_i_range_m_xy;
extern float * controller_i_range_m_z;
extern float * controller_i_range_xy;
extern float * controller_i_range_z;
//global vars end here

typedef struct quad_context {
	bool ekf_initialized;
	bool ekf_first_vicon;
} quad_context;

struct quad_data { //possibly overkill but a good thing to have around
	quad_context context;
	/*float lastX;
	float lastY;
	float lastZ;
	float lastQ0;
	float lastQ1;
	float lastQ2;
	float lastQ3;
	uint64_t lastTime;*/
	control_t control;
	controllerState_t controllerState;
	setpoint_t setpoint;
	sensorData_t sensorData;
	state_t state;
}

extern quad_data quad_internals[max_quads];


void set_context(quad_context * context) {
	*ekf_initialized = context->ekf_initialized;
	*ekf_first_vicon = context->ekf_first_vicon;
	*controller_kp_xy = context->controller_kp_xy;
	*controller_kd_xy = context->controller_kd_xy;
	*controller_ki_xy = context->controller_ki_xy;
	*controller_kp_z = context->controller_kp_z;
	*controller_kd_z = context->controller_kd_z;
	*controller_ki_z = context->controller_ki_z;
	*controller_massThrust = context->controller_massThrust;
	*controller_kR_xy = context->controller_kR_xy;
	*controller_kR_z = context->controller_kR_z;
	*controller_kw_xy = context->controller_kw_xy;
	*controller_kw_z = context->controller_kw_z;
	*controller_ki_m_xy = context->controller_ki_m_xy;
	*controller_ki_m_z = context->controller_ki_m_z;
	*controller_i_range_m_xy = context->controller_i_range_m_xy;
	*controller_i_range_m_z = context->controller_i_range_m_z;
	*controller_i_range_xy = context->controller_i_range_xy;
	*controller_i_range_z = context->controller_i_range_z;
}

void initialize_globals() {
	for (int i=0;i<max_quads;++i) {
		save_context(&(quad_data[i].context));
	}
}

void save_context(quad_context * context) {
	//just do the opposite?
}
//maybe find a different way to do this, although that might be difficult

#define REGISTER_GLOBAL(TYPE,NAME,VARIABLE) \
TYPE * NAME = & ## VARIABLE;



#endif