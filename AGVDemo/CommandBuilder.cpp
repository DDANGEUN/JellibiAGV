/** 
 *  Copyright (c) 2019 Robot&More, jhlee@robotnmore.com(signaled@gmail.com)
 *  
 *  See the file license.txt for copying permission  
 */

#include "CommandBuilder.h"

// Utility Macro 
#define FCMD(_CMD_) _cmdList[_buildIndex++] = _CMD_


CommandBuilder::CommandBuilder()
: _currentPosition(eInitialPosition)
, _cmdIndex(0)
, _buildIndex(0)
{
    memset(_cmdList, 0x00, sizeof(_cmdList));
}

CommandBuilder::~CommandBuilder()
{

}

void CommandBuilder::Init()
{
    _cmdIndex = 0;
    _buildIndex = 0;
    _currentPosition = eInitialPosition;
}

bool CommandBuilder::BuildCmdList(String strUID)
{
    bool bReturn = false;
    switch (_currentPosition) {
        case eInitialPosition:
            bReturn = BuildCmdInitToAU(strUID);
            break;
        case eAUpPosition: 
            bReturn = BuildAUToBD(strUID);
            break;
        case eBDownPosition:
            bReturn = BuildBDToBU(strUID);
            break;
        case eBUpPosition:
            bReturn = BuildBUToAD(strUID);
            break;
        case eADownPosition:
            bReturn = BuildADToAU(strUID);
            break;
    }
    if (bReturn) {
        _cmdIndex = 0;
    }
    return bReturn;
}

/** 
 * D1 -> A2 
 *
 */

void CommandBuilder::DebugCMDList() 
{
    char msg[32] = {0,};
    for (uint8_t i=0; ;i++) {
        if (_cmdList[i] >= eTr1 && _cmdList[i] <= eTr15 ) {
            sprintf(msg, "IDX[%d]:Line Trace lineCount [%d]", i, _cmdList[i]);
        }
        if (_cmdList[i] == eInit ) {
            sprintf(msg, "IDX[%d]: Init Sensor for LineTracer", i);
        }
        if (_cmdList[i] == eTurnRight) {
            sprintf(msg, "IDX[%d]: TurnRight", i);
        }
        if (_cmdList[i] == eTurnLeft) {
            sprintf(msg, "IDX[%d]: TurnLeft", i);
        }
        if (_cmdList[i] == eStepForward) {
            sprintf(msg, "IDX[%d]: STEP", i);
        } 
        if (_cmdList[i] == eStepBackward) {
            sprintf(msg, "IDX[%d]: BackStep", i);
        }

        if (_cmdList[i] == eStop) {
            sprintf(msg, "IDX[%d]: Stop", i);
        }
        if (_cmdList[i] == eSVLiftUp) {
            sprintf(msg, "IDX[%d]: Servo Lift UP", i);
        }
        if (_cmdList[i] == eSVLiftDown) {
            sprintf(msg, "IDX[%d]: Servo Lift Down", i);
        }
        if (_cmdList[i] == eRFID) {
            sprintf(msg, "IDX[%d]: RFID", i);
        }
        if (_cmdList[i] == eSleep) {
            sprintf(msg, "IDX[%d]: Sleep", i);
        }
        if (_cmdList[i] == eBeep) {
            sprintf(msg, "IDX[%d]: Beep", i);
        }
        Serial.println(msg);
    }

}

bool CommandBuilder::BuildCmdInitToAU(String strUID)
{
  Serial.println(__FUNCTION__);
    if (strUID.compareTo(s_strRFIDUidForStart) == 0) {
        _buildIndex = 0;
        FCMD(eInit);
        FCMD(eTr3);
        FCMD(eStepForward);
        FCMD(eNONE);
        return true;
    }
    DebugCMDList();
    return false;
}
/**
 * A2 -> 
{H1 ~ H4}
 * 
 *
 *
 */
bool CommandBuilder::BuildAUToBD(String strUID)
{
    //bool bKnownUID = false;
    Serial.println(__FUNCTION__);
    _buildIndex = 0;
    FCMD(eBeep);
    FCMD(eSVLiftUp);
    FCMD(eStepBackward);
    FCMD(eTr1);
    FCMD(eTurnRight);
    FCMD(eTr1);
    FCMD(eTurnRight);
    FCMD(eTr1);
    FCMD(eTurnLeft);
    FCMD(eTr1);
    FCMD(eTurnRight);
    FCMD(eTr1);
    FCMD(eStepForward);
    FCMD(eSVLiftDown);
    FCMD(eNONE);
    return true;
}

/**
 * A2 -> 
{H1 ~ H4}
 * 
 *
 *
 */
bool CommandBuilder::BuildBDToBU(String strUID)

{
    //bool bKnownUID = false;
    Serial.println(__FUNCTION__);
    _buildIndex = 0;
    FCMD(eBeep);
    FCMD(eTr1);
    FCMD(eTurnRight);
    FCMD(eTr2);
    FCMD(eStepForward);
    FCMD(ePBeep);
    FCMD(eSleep);
    FCMD(eStepBackward);
    FCMD(eTr1);
    FCMD(eTurnRight);
    FCMD(eTr2);
    FCMD(eTurnRight);
    FCMD(eTr2);
    FCMD(eTurnRight);
    FCMD(eTr1);
    FCMD(eStepForward);
    FCMD(eNONE);
    
    return true;
}

bool CommandBuilder::BuildBUToAD(String strUID)

{
    //bool bKnownUID = false;
    Serial.println(__FUNCTION__);
    _buildIndex = 0;
    FCMD(eBeep);
    FCMD(eSleep);
    FCMD(eSVLiftUp);
    FCMD(eTr1);
    FCMD(eTurnRight);
    FCMD(eTr2);
    FCMD(eTurnRight);
    FCMD(eTr3);
    FCMD(eStepForward);
    FCMD(eSVLiftDown);
    FCMD(eNONE);
    
    return true;
}
bool CommandBuilder::BuildADToAU(String strUID)

{
    //bool bKnownUID = false;
    Serial.println(__FUNCTION__);
    _buildIndex = 0;
    FCMD(eBeep);
    FCMD(eStepBackward);
    FCMD(eTr1);
    FCMD(eTurnRight);
    FCMD(eTr2);
    FCMD(eTurnRight);
    FCMD(eTr3);
    FCMD(eTurnRight);
    FCMD(eTr2);
    FCMD(eStepForward);
    FCMD(ePBeep);
    FCMD(eSleep);
    FCMD(eStepBackward);
    FCMD(eTr1);
    FCMD(eTurnRight);
    FCMD(eTr3);
    FCMD(eStepForward);
    FCMD(eNONE);
    
    return true;
}



CMD CommandBuilder::GetCommand()
{
    CMD cmdReturn = _cmdList[_cmdIndex];
    if (cmdReturn == eNONE) { // CMD FINISHED
        switch (_currentPosition) {
            case eInitialPosition:
                _currentPosition = eAUpPosition;
                break;
            case eAUpPosition:
                _currentPosition = eBDownPosition;
                break;
            case eBDownPosition:
                _currentPosition = eBUpPosition;
                break;
            case eBUpPosition:
                _currentPosition = eADownPosition;
                break;
            case eADownPosition:
                _currentPosition = eAUpPosition;
                break;
        }
    }
    return cmdReturn;
}

void CommandBuilder::Next()
{
    _cmdIndex++;
}
