#include "DialogEngine.h"

DialogEngine::DialogEngine(DialogEngineDriver &driverInstance)
{
    driver = &driverInstance;
}

void DialogEngine::boot()
{
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
