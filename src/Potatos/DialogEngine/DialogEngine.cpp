#include "DialogEngine.h"

DialogEngine::DialogEngine(DialogEngineDriver &driverInstance)
{
    driver = &driverInstance;
    driver->boot();
}

void DialogEngine::sayDialog(Dialog dialog)
{
    driver->sayDialog(dialog);
}

bool DialogEngine::isSpeaking()
{
    return driver->isSpeaking();
}
