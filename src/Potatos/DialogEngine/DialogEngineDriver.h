#ifndef _POTATOS_POTATOS_DIALOGENGINE_DIALOGENGINEDRIVER_H_
#define _POTATOS_POTATOS_DIALOGENGINE_DIALOGENGINEDRIVER_H_

#include "Dialog.h"

/**
 * Hardware implementaton of the Dialog system
 */
class DialogEngineDriver
{

public:

    /**
     * Boot the hardware
     */
    virtual void boot() = 0;

    /**
     * Hardware implementation of SayLine
     */
    virtual void sayDialog(Dialog dialog) = 0;

    /**
     * Hardware implmenetation of isSpeaking
     */
    virtual bool isSpeaking() = 0;
};

#endif
