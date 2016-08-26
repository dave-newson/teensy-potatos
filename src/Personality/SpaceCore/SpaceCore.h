#ifndef _POTATOS_PERSONALITY_SPACECORE_SPACECORE_H_
#define _POTATOS_PERSONALITY_SPACECORE_SPACECORE_H_

#include "Potatos/Personality/PersonalityCore.h"
#include "Potatos/DialogEngine/DialogEngine.h"
#include "Dialog/SpaceCoreDialog.h"


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
    void SayDialog(Dialog dialog);;

};

#endif
