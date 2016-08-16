#include "DialogEngine.h"

DialogEngine::DialogEngine(DialogEngineAdapter &adapterImpl)
{
    adapter = &adapterImpl;
    adapter->boot();
}

void DialogEngine::sayDialog(Dialog dialog)
{
    adapter->sayDialog(dialog);
}

bool DialogEngine::isSpeaking()
{
    return adapter->isSpeaking();
}
