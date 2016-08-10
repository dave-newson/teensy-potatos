#ifndef _POTATOS_PERSONALITY_SPACECORE_SPACECORE_H_
#define _POTATOS_PERSONALITY_SPACECORE_SPACECORE_H_

#include "Personality\Abstract\PersonalityCore.h"
#include "Service\DialogEngine\DialogEngine.h"

class SpaceCore : public PersonalityCore
{
public:
    SpaceCore(DialogEngine &dialogEngineImpl) : PersonalityCore(dialogEngineImpl) {}

    /**
     * Boot the AI
     * Starts the State Machine
     */
    void boot();

    /**
     * Shutdown the AI
     * Disengages the state machine
     */
    void shutdown();

    /**
     * Tick the state machine.
     * Causes state changes where needed
     */
    void tick();

    /**
     * Say a line of dialog
     */
    void SayDialog(Dialog dialog);

};

#endif
