#include "SpaceCore.h"
#include "Dialog/SpaceCoreDialog.h"

void SpaceCore::boot()
{
    // TODO: Load state machine
}

void SpaceCore::shutdown()
{
    // TODO: Destroy state machine
}

void SpaceCore::tick()
{
    // Say hello repeatedly
    if (!dialogEngine->isSpeaking()) {
        SayDialog(SpaceCoreDialog::Hello);
    }
}

void SpaceCore::SayDialog(Dialog dialog)
{
    dialogEngine->sayDialog(dialog);
}
