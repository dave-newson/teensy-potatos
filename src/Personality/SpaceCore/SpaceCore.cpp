#include "SpaceCore.h"
#include "Dialog/SpaceCoreDialog.h"
#include "Framework/Collection/Collection.hpp"
#include "os48.h"
#include "Arduino.h"

void SpaceCore::boot()
{
    // Say Hello
    SayDialog(SpaceCoreDialog::Hello);
}

void SpaceCore::shutdown()
{
    // TODO: Destroy state machine
}

void SpaceCore::tick()
{
    // Random selectable collection
    const SpaceCoreDialog::SpaceCoreDialog arr[4] = {
        SpaceCoreDialog::Babble1,
        SpaceCoreDialog::Babble2,
        SpaceCoreDialog::Babble3,
        SpaceCoreDialog::Babble4
    };
    Collection<const SpaceCoreDialog::SpaceCoreDialog> babble(arr, 4);

    // Babble incessantly
    if (!dialogEngine->isSpeaking()) {

        // Random selectable collection
        SpaceCoreDialog::SpaceCoreDialog line = babble.pickRandom();
        SayDialog(line);
    }
}

void SpaceCore::SayDialog(Dialog dialog)
{
    dialogEngine->sayDialog(dialog);
}
