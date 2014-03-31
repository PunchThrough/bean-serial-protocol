/**
  @headerfile:    AppMessages.h

  @mainpage     Application Messages

  Types that define the application messages.<BR><BR>

  Reference: @ref APP_MESSAGES <BR><BR>

  Copyright 2014 Punch Through Design, LLC. All rights reserved.

  Should you have any questions regarding your right to use this Software,
  contact Punch Through Design at contact@punchthrough.com
*/


#ifndef APPMESSAGES_H
#define APPMESSAGES_H


#include "AppMessageTypes.h"

// Serial Message Defines and Types
#define APP_MSG_MAX_LENGTH         (66)
#define APP_MSG_RESPONSE_BIT       (0x80)
#define SERIAL_FIELD_SIZE_LENGTH   (1)
#define SERIAL_FIELD_SIZE_RESERVED (1)
#define SERIAL_FIELD_SIZE_CRC      (2)
#define SERIAL_MSG_SIZE_HEADER     (SERIAL_FIELD_SIZE_LENGTH + SERIAL_FIELD_SIZE_RESERVED)
#define SERIAL_MSG_SIZE_FOOTER     (SERIAL_FIELD_SIZE_CRC)
#define SERIAL_MSG_SIZE_OVERHEAD   (SERIAL_MSG_SIZE_HEADER + SERIAL_MSG_SIZE_FOOTER)

#define UT_CHAR_START (0x7E)
#define UT_CHAR_ESC   (0x7D)
#define UT_CHAR_END   (0x7F)

// XOR the byte to escape it
#define HDLC_ESCAPE_XOR (0x20)

// Message IDs: Major only
typedef enum
{
  MSG_ID_MAJOR_SERIAL = 0x00,
  MSG_ID_MAJOR_BLE = 0x05,
  MSG_ID_MAJOR_BOOTLOADER = 0x10,
  MSG_ID_MAJOR_CC = 0x20,
  MSG_ID_MAJOR_ARDUINO = 0x30,
  MSG_ID_MAJOR_DEBUG = 0xFE
} MSG_ID_MAJOR_T;

// Message IDs
typedef enum
{
  MSG_ID_SERIAL_DATA        = 0x0000,
  MSG_ID_BT_SET_ADV         = 0x0500,
  MSG_ID_BT_SET_CONN        = 0x0502,
  MSG_ID_BT_SET_LOCAL_NAME  = 0x0504,
  MSG_ID_BT_SET_PIN         = 0x0506,
  MSG_ID_BT_SET_TX_PWR      = 0x0508,
  MSG_ID_BT_GET_CONFIG      = 0x0510,
  MSG_ID_BT_ADV_ONOFF       = 0x0512,
  MSG_ID_BT_SET_SCRATCH     = 0x0514,
  MSG_ID_BT_GET_SCRATCH     = 0x0515,
  MSG_ID_BT_RESTART         = 0x0520,
  MSG_ID_BL_CMD             = 0x1000,
  MSG_ID_BL_FW_BLOCK        = 0x1001,
  MSG_ID_BL_STATUS          = 0x1002,
  MSG_ID_CC_LED_WRITE       = 0x2000,
  MSG_ID_CC_LED_WRITE_ALL   = 0x2001,
  MSG_ID_CC_LED_READ_ALL    = 0x2002,
  MSG_ID_CC_ACCEL_READ      = 0x2010,
  MSG_ID_AR_SET_POWER       = 0x3000,
  MSG_ID_AR_GET_CONFIG      = 0x3006,
  MSG_ID_DB_LOOPBACK        = 0xFE00,
  MSG_ID_DB_COUNTER         = 0xFE01,
  MSG_ID_DB_E2E_LOOPBACK    = 0xFE02
} MSG_ID_T;

// Message Body Structs
//Radio
typedef enum {
   TXPOWER_4DB = 0x00,
   TXPOWER_0DB,
   TXPOWER_NEG6DB,
   TXPOWER_NEG23DB,
} BT_TXPOWER_DB_T;

typedef struct {
  PTD_UINT8 adv_enabled;
  PTD_UINT16 adv_int;
  PTD_UINT16 conn_int;
  PTD_UINT8 power;
  // Name might get dropped.  TBD...
  PTD_UINT8 local_name[20];
} BT_RADIOCONFIG_T;

typedef struct {
  PTD_UINT8 number;
  PTD_UINT8 scratch[20];
} BT_SCRATCH_T;

//Accelerometer
typedef enum {
  ACC_AXIS_X = 0x00,
  ACC_AXIS_Y,
  ACC_AXIS_Z,
} ACC_AXIS_T;

typedef struct {
   PTD_INT16 xAxis;
   PTD_INT16 yAxis;
   PTD_INT16 zAxis;
} ACC_READING_T;

typedef struct {
  PTD_UINT8 axis;
  PTD_UINT16 reading;
} ACC_AXES_READING_T;

//LED
typedef struct {
   PTD_UINT8 red;
   PTD_UINT8 green;
   PTD_UINT8 blue;
} LED_SETTING_T;

typedef enum {
  LED_RED = 0x00,
  LED_GREEN,
  LED_BLUE
} LED_COLOR_T;

typedef struct {
  PTD_UINT8 color;
  PTD_UINT8 intensity;
} LED_IND_SETTING_T;

// Arduino Power
typedef struct {
  PTD_UINT8 isOn;
  PTD_UINT16 delay_ms;
} AR_PWR_SET_T;


// Bootloader states (substates)
typedef enum
{
  BL_STATE_INIT = 0x00,
  BL_STATE_WRITE_ADDRESS,
  BL_STATE_WRITE_ADDRESS_ACK,
  BL_STATE_WRITE_CHUNK,
  BL_STATE_WRITE_CHUNK_ACK,
  BL_STATE_READ_ADDRESS,
  BL_STATE_READ_ADDRESS_ACK,
  BL_STATE_READ_CHUNK,
  BL_STATE_READ_CHUNK_ACK,
  BL_STATE_VERIFY,
  BL_STATE_DONE,
  BL_STATE_DONE_ACK,

  BL_STATE_START,
  BL_STATE_START_ACK,
  BL_STATE_HELLO,
  BL_STATE_HELLO_ACK,
  BL_STATE_START_RSTAGAIN,

  BL_STATE_DONE_RESET,
  BL_STATE_PROG_MODE,
  BL_STATE_PROG_MODE_ACK,
  BL_STATE_DEVICE_SIG,
  BL_STATE_DEVICE_SIG_ACK,
  BL_STATE_WRITE_CHUNK_TWO,
  BL_STATE_ERROR
} BL_STATE_T;

// Bootloader high-level states
typedef enum
{
  BL_HL_STATE_NULL = 0x00,
  BL_HL_STATE_INIT,
  BL_HL_STATE_READY,
  BL_HL_STATE_PROGRAMMING,
  BL_HL_STATE_VERIFY,
  BL_HL_STATE_COMPLETE,
  BL_HL_STATE_ERROR
} BL_HL_STATE_T;

typedef enum
{
  BL_CMD_START_PRG  = 0x00,
  BL_CMD_VERIFY     = 0x01,
  BL_CMD_RESET      = 0x02
} BL_CMD_T;

// Bootloader Message Definitions

typedef struct
{
  PTD_UINT8 command;
  PTD_UINT8 payload[2];
} BL_MSG_CMD_T;

typedef struct
{
  PTD_UINT16 fwAddress;
  PTD_UINT8 * fwBlock;
} BL_MSG_FW_BLOCK_T;

typedef struct
{
  PTD_UINT8 hlState;  // BL_HL_STATE_T
  PTD_UINT8 intState; // BL_STATE_T
  PTD_UINT16 blocksSent;
  PTD_UINT16 bytesSent;
} BL_MSG_STATUS_T;


#endif