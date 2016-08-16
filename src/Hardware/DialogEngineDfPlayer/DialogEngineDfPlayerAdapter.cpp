#include "DialogEngineDfPlayerAdapter.h"
#include "DFPlayer_Mini_Mp3.h"

DialogEngineDfPlayerAdapter::DialogEngineDfPlayerAdapter(SoftwareSerial &pSerial, Config userConfig)
{
    config = userConfig;
    serial = &pSerial;
}

void DialogEngineDfPlayerAdapter::boot()
{
    // Establish link to DfPlayer using Serial
    serial->begin(9600);
    mp3_set_serial(*serial);

    // Have to delay 1ms after Serial init before setting the volume (?)
    delay(10);

    // Recalculate the volume from 0-100 to 0-30.
    mp3_set_volume(ceil((config.volume/10)*30));

    pinMode(config.busyPin, INPUT);
}

void DialogEngineDfPlayerAdapter::sayDialog(Dialog dialog)
{
    // mp3_play_physical(dialog.id);
    Serial.println("SAY");
}

bool DialogEngineDfPlayerAdapter::isSpeaking()
{
    // Read busy-pin state
    bool play_state = digitalRead(config.busyPin);
    return (play_state == LOW);
}
