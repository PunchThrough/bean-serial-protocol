/**
  @headerfile:    AppMessageTypes.h

  @mainpage     Application Message Types

  Types that define the application messages.<BR><BR>

  Reference: @ref APP_MESSAGE_TYPES <BR><BR>

  Copyright 2014 Punch Through Design, LLC. All rights reserved.

  Should you have any questions regarding your right to use this Software,
  contact Punch Through Design at contact@punchthrough.com
*/

/* ------------------------------------------------------------------------------------------------
 *                               Memory Attributes and Compiler Macros
 * ------------------------------------------------------------------------------------------------
 */

#ifndef APPMESSAGETYPES_H
#define APPMESSAGETYPES_H


/* ----------- IAR Compiler ----------- */
#ifdef __IAR_SYSTEMS_ICC__

typedef uint32 PTD_UINT32;
typedef uint16 PTD_UINT16;
typedef uint8 PTD_UINT8;
typedef int16 PTD_INT16;

/* ----------- Arduino ----------- */
#elif __cplusplus

typedef uint32_t PTD_UINT32;
typedef uint16_t PTD_UINT16;
typedef uint8_t  PTD_UINT8;
typedef int16_t PTD_INT16;

/* ----------- Objective-C ----------- */
#elif __objectivec

typedef Uint32 PTD_UINT32;
typedef Uint16 PTD_UINT16;
typedef Uint8  PTD_UINT8;
typedef Int16 PTD_INT16;

#endif


#endif