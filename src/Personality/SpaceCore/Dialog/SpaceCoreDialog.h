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

    // Switch-on Hello
    const static SpaceCoreDialog Hello(1);

    // Babble
    const static SpaceCoreDialog Babble1(2);
    const static SpaceCoreDialog Babble2(3);
    const static SpaceCoreDialog Babble3(4);
    const static SpaceCoreDialog Babble4(5);

};

#endif
