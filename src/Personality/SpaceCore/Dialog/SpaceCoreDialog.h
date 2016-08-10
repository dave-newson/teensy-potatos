#ifndef _POTATOS_PERSONALITY_SPACECORE_DIALOG_SPACECOREDIALOG_H_
#define _POTATOS_PERSONALITY_SPACECORE_DIALOG_SPACECOREDIALOG_H_

#include "Service/DialogEngine/DialogEngine.h"

/**
 * Library of contacts for Glados Dialog
 */
namespace SpaceCoreDialog
{
    struct SpaceCoreDialog : Dialog
    {
        SpaceCoreDialog(const int aId, const int aColor = Dialog::COLOR_YELLOW) {
            id = aId;
            color = aColor;
        }
    };

    const static SpaceCoreDialog Hello(1);
}

#endif
