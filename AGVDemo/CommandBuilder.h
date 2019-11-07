#ifndef __COMMANDBUILDER_H__
#define __COMMANDBUILDER_H__
/** 
 *  Copyright (c) 2019 Robot&More, jhlee@robotnmore.com(signaled@gmail.com)
 *  
 *  See the file license.txt for copying permission  
 */

#include "Define.h"

class CommandBuilder
{
private:
    enum {
        eInitialPosition = 0, 
        eAUpPosition, 
        eBDownPosition,
        eBUpPosition,
        eADownPosition
    } _currentPosition;

    CMD _cmdList[MAX_CMD];
    uint8_t _cmdIndex;
    uint8_t _buildIndex;
    
    void DebugCMDList();
    bool BuildCmdInitToAU(String strUID);
    bool BuildAUToBD(String strUID);
    bool BuildBDToBU(String strUID);
    bool BuildBUToAD(String strUID);
    bool BuildADToAU(String strUID);
public:
    CommandBuilder();
    ~CommandBuilder();
    void Init();
    bool BuildCmdList(String strUID);
    CMD GetCommand();
    void Next();
};



#endif//__COMMANDBUILDER_H__
