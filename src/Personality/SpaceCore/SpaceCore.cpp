#include "SpaceCore.h"
#include "Dialog/SpaceCoreDialog.h"
//#include "Framework/Collection/Collection.h"
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
    /* TODO: Enable when Collection works
    // Random selectable collection
    SpaceCoreDialog::SpaceCoreDialog arr[] = {
        SpaceCoreDialog::Babble1,
        SpaceCoreDialog::Babble2,
        SpaceCoreDialog::Babble3,
        SpaceCoreDialog::Babble4
    };
    Collection<SpaceCoreDialog::SpaceCoreDialog> babble(arr, 4);

    // Babble incessantly
    if (!dialogEngine->isSpeaking()) {

        // Random selectable collection
        SpaceCoreDialog::SpaceCoreDialog line = babble.pickRandom();
        SayDialog(line);
    }
    */

    // TODO: Reinstate above code when Collection works.
    if (!dialogEngine->isSpeaking()) {
        SayDialog(SpaceCoreDialog::Babble1);
    }
}

void SpaceCore::SayDialog(Dialog dialog)
{
    dialogEngine->sayDialog(dialog);
}
