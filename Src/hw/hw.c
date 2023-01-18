#include <string.h>
#include "hw.h"

volatile motor_controller_t bus_motor;
volatile arm_controller_t bus_arm;
volatile arm_6dof_controller_t bus_arm_6dof;
volatile party_t bus_party;
volatile universal_t bus_universal[BUS_UNIVERSAL_COUNT];
volatile science_t bus_science[BUS_SCIENCE_COUNT];

void HW_Init() {
    // Universal init
    bus_universal[0].id = 1;

    // Science init
    bus_science[0].id = 0;

    // 6-DoF init
    memset((void*)&bus_arm_6dof, 0, sizeof(bus_arm_6dof));
    bus_arm_6dof.mode = ARM_6DOF_POSITION_MODE;
}