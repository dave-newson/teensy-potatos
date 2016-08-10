#ifndef _POTATOS_HARDWARE_DIALOGENGINEDFPLAYERADAPTER_H_
#define _POTATOS_HARDWARE_DIALOGENGINEDFPLAYERADAPTER_H_

#include "Service/DialogEngine/DialogEngineAdapter.h"
#include "SoftwareSerial.h"

/**
 * Implements DialogAdapter on the DFPlayer MP3 Mini
 */
class DialogEngineDfPlayerAdapter : public DialogEngineAdapter
{

public:

    /**
     * Hardware pin configuration
     */
    struct Config {
        int busyPin;
        int volume; // 0 - 100
    };

    /**
     * Dependency Injction
     * Requires a serial port on boot
     */
    DialogEngineDfPlayerAdapter(SoftwareSerial &pSerial, Config userConfig);

    void boot();

    void sayDialog(Dialog dialog);

    bool isSpeaking();

private:

    /**
     * Configuration
     */
    Config config;

    /**
     * Software Serial connection
     * This could have been HW serial if the host device supported it.
     */
    SoftwareSerial *serial;
};

#endif
