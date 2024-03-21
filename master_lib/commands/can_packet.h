#ifndef KALMAN_ELECTRONICS_MASTER_V3_CAN_PACKET_H
#define KALMAN_ELECTRONICS_MASTER_V3_CAN_PACKET_H

#include "stdint.h"

typedef enum {
    CAN_CMD_RESET_DEVICE =           0x31,
    CAN_CMD_SET_PID =                0x32,
    CAN_CMD_RESET_ALL =              0x30,
    CAN_CMD_GET_PID_REQUEST =        0x33,
    CAN_CMD_GET_PID =                0x3F,

    CAN_CMD_MOTOR_SET_WHEELS =       0x10,
    CAN_CMD_MOTOR_CALIBRATE =        0x11,
    CAN_CMD_MOTOR_DEBUG_TX =         0x12,
    CAN_CMD_MOTOR_GET_TEMPERATURE =  0x13,
    CAN_CMD_MOTOR_GET_WHEELS1 =      0x1C,
    CAN_CMD_MOTOR_GET_WHEELS2 =      0x1D,
    CAN_CMD_MOTOR_GET_STATUS =       0x1E,
    CAN_CMD_MOTOR_DEBUG_RX =         0x1F,

    CAN_CMD_ARM_6DOF_SET_POS1 =             0xB0,
    CAN_CMD_ARM_6DOF_SET_POS2 =             0xB1,
    CAN_CMD_ARM_6DOF_SET_POS_VEL1 =         0xD0,
    CAN_CMD_ARM_6DOF_SET_POS_VEL2 =         0xD1,
    CAN_CMD_ARM_6DOF_SET_TORQUE1 =          0xD2,
    CAN_CMD_ARM_6DOF_SET_TORQUE2 =          0xD3,
    CAN_CMD_ARM_6DOF_SET_VELOCITY1 =        0xB2,
    CAN_CMD_ARM_6DOF_SET_VELOCITY2 =        0xB3,
    CAN_CMD_ARM_6DOF_GET_POS1 =             0xB8,
    CAN_CMD_ARM_6DOF_GET_POS2 =             0xB9,
    CAN_CMD_ARM_6DOF_POSITIONING_START =    0xBA,
    CAN_CMD_ARM_6DOF_POSITIONING_ABORT =    0xBB,
    CAN_CMD_ARM_6DOF_SET_ACTUAL_POS =       0xBC,
	CAN_CMD_ARM_6DOF_SET_GRIPPER =          0xBD,
	CAN_CMD_ARM_6DOF_GET_GRIPPER =          0xBE,
    CAN_CMD_ARM_6DOF_SMART_KUTONG_TOGGLE =  0xB4,
    CAN_CMD_ARM_6DOF_SMART_KUTONG_DATA =    0xB5,
	CAN_CMD_ARM_6DOF_KEYBOARD_CLICK =       0xB6,
	CAN_CMD_ARM_6DOF_SOFT_RESET =           0xB7,
    CAN_CMD_ARM_6DOF_AUTOCLICK_SET_POS =    0xBF,

    CAN_CMD_DRILL_A_BRIDGE_SET =     0x40,
    CAN_CMD_DRILL_B_BRIDGE_SET =     0x41,
    CAN_CMD_DRILL_GET_WEIGHT =       0x42,
    CAN_CMD_DRILL_SEND_WEIGHT =      0x43,

    CAN_CMD_UEUOS_SET_STATE =        0x60,
    CAN_CMD_UEUOS_SET_COLOR =        0x61,
    CAN_CMD_UEUOS_SET_EFFECT =       0x62,

    CAN_CMD_UNIVERSAL_SET_BRIDGE =   0x80,
    CAN_CMD_UNIVERSAL_SET_SERVO =    0x81,
    CAN_CMD_UNIVERSAL_SET_PWM =      0x82,
    CAN_CMD_UNIVERSAL_SET_GPIO =     0x83,
    CAN_CMD_UNIVERSAL_DEBUG_TX =     0x84,
    CAN_CMD_UNIVERSAL_GET_WEIGHT =   0x8D,
    CAN_CMD_UNIVERSAL_GET_STATUS =   0x8E,
    CAN_CMD_UNIVERSAL_DEBUG_RX =     0x8F,

    CAN_CMD_SCIENCE_POLL =               0x90,
    CAN_CMD_SCIENCE_DEBUG_TX =           0x91,
    CAN_CMD_SCIENCE_GET_TEMPERATURE1 =   0x99,
    CAN_CMD_SCIENCE_GET_TEMPERATURE2 =   0x9A,
    CAN_CMD_SCIENCE_GET_HUMIDITY =       0x9B,
    CAN_CMD_SCIENCE_GET_ATMOSPHERE =     0x9C,
    CAN_CMD_SCIENCE_GET_WEIGHT =         0x9D,
    CAN_CMD_SCIENCE_GET_STATUS =         0x9E,
    CAN_CMD_SCIENCE_DEBUG_RX =           0x9F,

    CAN_CMD_MUX_SET_CAM =             0xA1,
    CAN_CMD_MUX_SET_CHANNEL =         0xA2,
    CAN_CMD_MUX_SET_POWER =           0xA4,

    CAN_CMD_MOBILAB_SET_PUMP =			0xC0,
    CAN_CMD_MOBILAB_SET_HEATER =		0xC1,
    CAN_CMD_MOBILAB_SET_BACKLIGHT = 	0xC2,
    CAN_CMD_MOBILAB_SET_AUX	=			0xC3,
    CAN_CMD_MOBILAB_SET_SERVO =			0xC4,
    CAN_CMD_MOBILAB_GET_TEMPERATURE =	0xC5,
} can_cmd_t;

// --- Command arg length --
typedef enum {
	CAN_ARG_RESET_ALL = 5,
	CAN_ARG_RESET_DEVICE = 6,
	CAN_ARG_SET_PID = 8,
	CAN_ARG_GET_PID_REQUEST = 1,
	CAN_ARG_GET_PID = 8,

	CAN_ARG_MOTOR_SET_WHEELS        = 8,
	CAN_ARG_MOTOR_CALIBRATE         = 6,
	CAN_ARG_MOTOR_DEBUG_TX          = 8,
	CAN_ARG_MOTOR_GET_TEMPERATURE   = 8,
	CAN_ARG_MOTOR_GET_WHEELS1       = 8,
	CAN_ARG_MOTOR_GET_WHEELS2       = 4,
	CAN_ARG_MOTOR_GET_STATUS        = 4,
	CAN_ARG_MOTOR_DEBUG_RX          = 8,

	CAN_ARG_ARM_6DOF_SET_POS1            = 8,
	CAN_ARG_ARM_6DOF_SET_POS2            = 8,
	CAN_ARG_ARM_6DOF_SET_POS_VEL1        = 8,
	CAN_ARG_ARM_6DOF_SET_POS_VEL2        = 4,
	CAN_ARG_ARM_6DOF_SET_TORQUE1         = 8,
	CAN_ARG_ARM_6DOF_SET_TORQUE2         = 4,
	CAN_ARG_ARM_6DOF_SET_VELOCITY1       = 8,
	CAN_ARG_ARM_6DOF_SET_VELOCITY2       = 5,
	CAN_ARG_ARM_6DOF_GET_POS1            = 8,
	CAN_ARG_ARM_6DOF_GET_POS2            = 6,
	CAN_ARG_ARM_6DOF_POSITIONING_START   = 1,
	CAN_ARG_ARM_6DOF_POSITIONING_ABORT   = 0,
	CAN_ARG_ARM_6DOF_SET_ACTUAL_POS      = 3,
	CAN_ARG_ARM_6DOF_SET_GRIPPER         = 2,
	CAN_ARG_ARM_6DOF_GET_GRIPPER         = 2,
	CAN_ARG_ARM_6DOF_SMART_KUTONG_TOGGLE = 0,
	CAN_ARG_ARM_6DOF_SMART_KUTONG_DATA   = 4,
	CAN_ARG_ARM_6DOF_KEYBOARD_CLICK      = 0,
	CAN_ARG_ARM_6DOF_SOFT_RESET          = 0,
	CAN_ARG_ARM_6DOF_AUTOCLICK_SET_POS   = 1,

	CAN_ARG_DRILL_A_BRIDGE_SET    = 2,
	CAN_ARG_DRILL_B_BRIDGE_SET    = 2,
	CAN_ARG_DRILL_GET_WEIGHT      = 0,
	CAN_ARG_DRILL_SEND_WEIGHT     = 4,

	CAN_ARG_UEUOS_SET_STATE        = 1,
	CAN_ARG_UEUOS_SET_COLOR        = 3,
	CAN_ARG_UEUOS_SET_EFFECT       = 1,

	CAN_ARG_UNIVERSAL_SET_BRIDGE   = 6,
	CAN_ARG_UNIVERSAL_SET_SERVO    = 6,
	CAN_ARG_UNIVERSAL_SET_PWM      = 8,
	CAN_ARG_UNIVERSAL_SET_GPIO     = 5,
	CAN_ARG_UNIVERSAL_DEBUG_TX     = 8,
	CAN_ARG_UNIVERSAL_GET_WEIGHT   = 6,
	CAN_ARG_UNIVERSAL_GET_STATUS   = 3,
	CAN_ARG_UNIVERSAL_DEBUG_RX     = 8,

	CAN_ARG_SCIENCE_POLL              = 1,
	CAN_ARG_SCIENCE_DEBUG_TX          = 8,
	CAN_ARG_SCIENCE_GET_TEMPERATURE1   = 5,
	CAN_ARG_SCIENCE_GET_TEMPERATURE2   = 5,
	CAN_ARG_SCIENCE_GET_HUMIDITY       = 5,
	CAN_ARG_SCIENCE_GET_ATMOSPHERE     = 8,
	CAN_ARG_SCIENCE_GET_WEIGHT         = 6,
	CAN_ARG_SCIENCE_GET_STATUS         = 2,
	CAN_ARG_SCIENCE_DEBUG_RX           = 8,

	CAN_ARG_MOBILAB_SET_PUMP		= 2,
	CAN_ARG_MOBILAB_SET_HEATER		= 2,
	CAN_ARG_MOBILAB_SET_BACKLIGHT 	= 2,
	CAN_ARG_MOBILAB_SET_AUX			= 2,
	CAN_ARG_MOBILAB_SET_SERVO		= 2,
	CAN_ARG_MOBILAB_GET_TEMPERATURE	= 5,

	CAN_ARG_MUX_SET_CAM         = 2,
	CAN_ARG_MUX_SET_CHANNEL     = 2,
	CAN_ARG_MUX_SET_POWER       = 2,

} can_args_t;

typedef struct {
    can_cmd_t cmd;
    uint8_t arg_count;
    uint8_t args[64];
} can_packet_t;

typedef struct {
    can_cmd_t cmd;
    uint8_t arg_count;
    void (*execute)(uint8_t* args);
} can_packet_def_t;

//na potrzeby ramek wspolnych - nie modyfikowac!
typedef enum {
    DEVICE_MASTER       = 0,    //! Kalman Master
    DEVICE_MOTOR        = 1,    //! Motor Controller
    DEVICE_ARM          = 2,    //! Arm Controller
    DEVICE_LIDAR        = 3,    //! Lidar Rotator
    DEVICE_DRILL        = 4,    //! Driller Controller
    DEVICE_BOX          = 5,    //! Experiment Box
    DEVICE_DEBUG        = 6,    //! Debug Module
    DEVICE_UNIVERSAL    = 8,    //! Universal Module
    DEVICE_SCIENCE      = 9,    //! Sajens Module
    DEVICE_MUX          = 10,   //! Mux Module
} can_device_t;

#endif //KALMAN_ELECTRONICS_MASTER_V3_CAN_PACKET_H
