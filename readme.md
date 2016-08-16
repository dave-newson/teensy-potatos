# PotatOS, Aperture Science Multiple-Personality Core

No documentation here yet. See below for rambling concepts.


## Space Core Test Behaviour

Space Core - Zero-G - Space message
Fires an interrupt - plays dialog if possible.

Repeat throws change mood of Space core. From good response (SPAAAACE) to bad response (want to go home now)


## State Machine Behaviours

Dialog State
    - Freestyle (rest of behaviour tree, for whoever is primary)
    - Scripted

// No overlapping dialog timings, as not supported.
Script (supports tree-ing)

    Script.say(space, "0001"); <-- Line is defined by GladosDialog, and fed to the entity?
    Script.say(glados, "0005");

    if (space.isInSpace()) {
        Script.say(space, "0006");
    }


    How to block between say? Say queue? Mutex?

 Space {
    Director.startScript<SomeFunScript>();
 }


## LED Switching method

// Method to switch LED Control pattern
// This seems a bit poor-mans. Could this be done with some signalling system at the Dialog level?

 Space.startSpeak()
 {
     // Engage LED Control
 }

 Space.speak(line)
 {
    // Invoke dialog system
 }

 Space.stopSpeak()
 {
    // Disengage LED control
 }

## RTOS48 Delegates

Need to fix the issue of OS48 not supporting Delegate functions. That's kind of annoying.