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
    delay(1);

    // Recalculate the volume from 0-100 to 0-30.
    mp3_set_volume(ceil((config.volume/10)*30));
}

void DialogEngineDfPlayerAdapter::sayDialog(Dialog dialog)
{
    mp3_play(dialog.id);
}

bool DialogEngineDfPlayerAdapter::isSpeaking()
{
    // Read busy-pin state
    boolean play_state = digitalRead(config.busyPin);
    return (play_state == LOW);
}
