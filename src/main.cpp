#include "Arduino.h"

#include "os48.h"
#include "Personality/SpaceCore/SpaceCore.h"

// Delegate
#include "srutil/delegate.hpp"

// DialogEngine
#include "SoftwareSerial.h"
#include "Service/DialogEngine/DialogEngine.h"
#include "Service/DialogEngine/DialogEngineAdapter.h"
#include "Hardware/DialogEngineDfPlayer/DialogEngineDfPlayerAdapter.h"

os48::Scheduler* scheduler = os48::Scheduler::get();
os48::Task* task1 = NULL;
os48::Task* task2 = NULL;
os48::Task* task3 = NULL;

// Asynchronous Blink: 1s external LED
void blink1()
{
    pinMode(9, OUTPUT);

    for(;;) {
        digitalWrite(9, HIGH);
        os48::task()->sleep(1000);
        digitalWrite(9, LOW);
        os48::task()->sleep(1000);
    }
}

// Asynchronous Blink: 250ms on-board LED
void blink2()
{
    pinMode(13, OUTPUT);

    for(;;) {
        digitalWrite(13, HIGH);
        os48::task()->sleep(300);
        digitalWrite(13, LOW);
        os48::task()->sleep(300);
    }
}

// FIXME: Fix this hack - OS48 needs to support Delegate functions
// We must define SpaceCore globally so it can be used in a static for os48.
SpaceCore *spaceCore = NULL;
// Now define a static Tick function so we can use os48 Task Function Pointers
void SpaceCoreTick()
{
    for(;;) {
        spaceCore->tick();
        os48::task()->sleep(2000);
    }
}
// FIXME: end

void setup()
{
    // Debug Serial
    Serial.begin(9600);
    Serial.println("KERNEL BOOT");

    // DialogEngine Hardware
    SoftwareSerial serial(10, 11); // RX, TX
    DialogEngineDfPlayerAdapter::Config dialogConfig;
    dialogConfig.busyPin = 3;
    dialogConfig.volume = 20;

    // DialogEngine
    DialogEngineDfPlayerAdapter dialogAdapter(serial, dialogConfig);
    DialogEngine dialogEngine(dialogAdapter);

    // Create Space Core
    spaceCore = new SpaceCore(dialogEngine);
    spaceCore->boot();

// TODO: OR48 needs to support Delegate functions in order to use object
//       instances instead of statics. Boo I say. Boo.
//    typedef srutil::delegate<void (void)> TaskDelegate;
//    TaskDelegate d = TaskDelegate::from_method<SpaceCore, &SpaceCore::tick>(&spaceCore);

    // Personality core tick
    task1 = scheduler->createTask(&SpaceCoreTick, 60, os48::PrHigh);

    // Begin blick subtasks
    task2 = scheduler->createTask(&blink1, 60);
    task3 = scheduler->createTask(&blink2, 60);

    // Run
    scheduler->start();
}

void loop()
{
    // No code here. Refer to OS48 Scheduler
}
