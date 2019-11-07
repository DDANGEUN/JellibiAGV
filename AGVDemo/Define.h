/** 
 *  Copyright (c) 2019 Robot&More, jhlee@robotnmore.com(signaled@gmail.com)
 *  
 *  See the file license.txt for copying permission  
 */

#ifndef __DEFINE_H__
#define __DEFINE_H__
#include <Arduino.h>

/* 
     Playground 


       1             2             3           4             5            6            7             8
       ┬            ┬            ┬           ┬            ┬            ┬           ┬            ┬
 A  ├─┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼─┤
       │            │            │           │            │            │           │            │
       │            │            │           │            │            │           │            │
 B  ├─┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼─┤
       │            │            │           │            │            │           │            │
       │            │            │           │            │            │           │            │
 C  ├─┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼─┤
       │            │            │           │            │            │           │            │
       │            │            │           │            │            │           │            │
 D  ├─┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼─┤
       │            │            │           │            │            │           │            │
       │            │            │           │            │            │           │            │
 E  ├─┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼─┤
       │            │            │           │            │            │           │            │
       │            │            │           │            │            │           │            │
 F  ├─┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼─┤
       │            │            │           │            │            │           │            │
       │            │            │           │            │            │           │            │
 G  ├─┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼─┤
       │            │            │           │            │            │           │            │
       │            │            │           │            │            │           │            │
 H  ├─┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼─┤
       ┴            ┴            ┴           ┴            ┴            ┴           ┴            ┴
     Seoul       InCheon        SeJong       Daejeon       Daegu        KwangJu     ChunCeon       Jeju


*/

#define MAX_CMD 70

enum CMD {
    eNONE = 0,          // None 
    eTr1 = 1,           // {{{ LineTrace 
    eTr2 = 2,
    eTr3 = 3, 
    eTr4 = 4,
    eTr5 = 5, 
    eTr6 = 6, 
    eTr7 = 7, 
    eTr8 = 8,
    eTr9 = 9, 
    eTr10 = 10, 
    eTr11 = 11, 
    eTr12 = 12, 
    eTr13 = 13, 
    eTr14 = 14, 
    eTr15 = 15,         // }}} 
    eInit = 100,    // INIT LineTracer
    eTurnRight,     // Turn Right 
    eTurnLeft,      // Turn Left
    eStepForward,   // STEP
    eStepBackward,
    eStop,            // STOP
    eSVLiftUp,      // Servo Lift
    eSVLiftDown,    // Servo Down
    eRFID,          // Start Card detect
    eSleep,         // Sleep 1sec 
    eBeep,           // Beep
    ePBeep
};


static const String s_strRFIDUidForStart = String("09D0047F");

static const String s_strRFIDUidForSeoul = String("04C0B58A8A5F80");
static const String s_strRFIDUidForIncheon = String("040AB58A8A5F81");
static const String s_strRFIDUidForSejong = String("04A1AF8A8A5F80");
static const String s_strRFIDUidForDaejeon= String("04D1B58A8A5F80"); 

/*
static const String s_strRFIDUidForDaegu;
static const String s_strRFIDUidForGwangju;
static const String s_strRFIDUidForChuncheon;
static const String s_strRFIDUidForJeju;
*/


#define STEP_FORWARD_DURATION       270
#define STEP_BACKWARD_DURATION      600
#define SLEEP_DURATION             1000

#define NORMAL_DRIVE_SPEED    65

#define TURN_INITIAL_WHEEL_SPEED 90
#define TURN_INSIDE_WHEEL_SPEED  40
#define TURN_OUTSIDE_WHEEL_SPEED 65

#define LINEDETECT_THRESHOLD_MIN 700
#define BLANKDETECT_THERSHOLD_MAX 500

#define SERVO1_PUTDOWN_ANGLE 90
#define SERVO1_LIFTUP_ANGLE 0
#define SERVO2_PUTDOWN_ANGLE 0
#define SERVO2_LIFTUP_ANGLE 90


#endif//__DEFINE_H__
