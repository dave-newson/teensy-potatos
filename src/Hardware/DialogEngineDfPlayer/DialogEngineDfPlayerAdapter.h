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
        /**
         * Busy pin
         * Moves to HIGH when not speaking
         */
        int busyPin;

        /**
         * Audio Volume (0-100)
         */
        int volume;
    };

    /**
     * Dependency Injction
     * Requires a serial port on boot
     */
    DialogEngineDfPlayerAdapter(SoftwareSerial &pSerial, Config userConfig);

    /**
     * Boot the DialogEngine.
     * Sets up serial and pins for DfPlayer
     */
    void boot();

    /**
     * Tell DfPlayer to play the numbered dialog item
     */
    void sayDialog(Dialog dialog);

    /**
     * Check the BusyPin signal.
     * If low; speaking.
     */
    bool isSpeaking();

private:

    /**
     * Configuration struct
     */
    Config *config;

    /**
     * Software Serial connection
     * This could have been HW serial if the host device supported it.
     */
    SoftwareSerial *serial;
};

#endif
