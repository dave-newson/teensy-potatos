#include "SpaceCore.h"
#include "Dialog/SpaceCoreDialog.h"
#include "Util/Collection/Collection.h"

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
    SpaceCoreDialog::SpaceCoreDialog arr[] = {
        SpaceCoreDialog::Babble1,
        SpaceCoreDialog::Babble2,
        SpaceCoreDialog::Babble3,
        SpaceCoreDialog::Babble4
    };
    Collection<SpaceCoreDialog::SpaceCoreDialog> babble(arr);

    // Babble incessently
    if (!dialogEngine->isSpeaking()) {
        SpaceCoreDialog::SpaceCoreDialog line = babble.pickRandom();
        SayDialog(line);
    }
}

void SpaceCore::SayDialog(Dialog dialog)
{
    dialogEngine->sayDialog(dialog);
}
