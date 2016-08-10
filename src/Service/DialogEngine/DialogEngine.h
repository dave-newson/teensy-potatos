#ifndef _POTATOS_SERVICE_DIALOGENGINE_DIALOGENGINE_H_
#define _POTATOS_SERVICE_DIALOGENGINE_DIALOGENGINE_H_

#include "Dialog.h"
#include "DialogEngineAdapter.h"

/**
 * DialogEngine
 * Provives the interface for Dialog playback
 */
class DialogEngine
{
public:

    /**
     * Dependency Injection
     * Dialog is a facade for the final hardware implmenetation
     */
    DialogEngine(DialogEngineAdapter &adapter);

    /**
     * Say the corresponding line of dialog
     * Each line has a numeric value. Suggest using constants to track them.
     */
    void sayDialog(Dialog dialog);

    /**
     * Returns true if the Dialog system is currently speaking another line
     * Can be used to defer saying another line.
     */
    bool isSpeaking(void);

private:

    /**
     * Hardware Adapter
     */
    DialogEngineAdapter *adapter;

};

#endif
