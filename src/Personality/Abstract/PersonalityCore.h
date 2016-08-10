#ifndef _POTATOS_PERSONALITY_ABSTRACT_PERSONALITYCORE_H_
#define _POTATOS_PERSONALITY_ABSTRACT_PERSONALITYCORE_H_

#include "Service/DialogEngine/DialogEngine.h"

class PersonalityCore
{

public:

    /**
     * Dependency Injection
     */
    PersonalityCore(DialogEngine &dialogEngine);

    /**
     * Boot the Personality module.
     * Use this to attach handlers and interrupts for this personality.
     */
    virtual void boot() = 0;

    /**
     * Shutdown the Personality module.
     * Use this to detach event handlers and interrupts
     */
    virtual void shutdown() = 0;

    /**
     * Personality Tick. Called periodically.
     * Usually used to update state machines.
     */
    virtual void tick() = 0;

    /**
     * Say a given line of dialog
     */
    virtual void SayDialog(Dialog dialog) = 0;

protected:
    DialogEngine *dialogEngine;

};

#endif
