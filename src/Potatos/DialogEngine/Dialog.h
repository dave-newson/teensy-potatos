#ifndef _POTATOS_POTATOS_DIALOGENGINE_DIALOG_H_
#define _POTATOS_POTATOS_DIALOGENGINE_DIALOG_H_

/**
 * Definition for a single line of dialog.
 * Extend this Struct to define your own custom Dialog line
 */
struct Dialog {

    // Avaialble colours
    const static int COLOR_RED = 1;
    const static int COLOR_GREEN = 2;
    const static int COLOR_BLUE = 3;
    const static int COLOR_YELLOW = 4;
    const static int COLOR_ORANGE = 5;
    const static int COLOR_CYAN = 6;

    int id;
    int color;
};

#endif
