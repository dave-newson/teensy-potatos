# PotatOS, Aperture Science Multiple-Personality Core

No documentation here yet. See below for rambling concepts.

## Renaming

### Hardware vs Drivers (adapters?)

Consider renaming the Hardware to Driver.

```
DialogEngine->driver->sayDialog();
DialogEngineDriverDfPlayer {}
```

### Util vs Framework

Util becomes Framework. Framework are bits and bobs?
PotatOS is not the framework. IT's the app.

### Service vs PoatOS

PotatOS is the core - so that becomes the main body?
 DialogDriver? Gesture? All run from PotatOS Core?


## Space Core Test Behaviour

Space Core - Zero-G - Space message
Fires an interrupt - plays dialog if possible.

Repeat throws change mood of Space core. From good response (SPAAAACE) to bad response (want to go home now)


## State Machine Behaviours

Dialog State
    - Freestyle (rest of behaviour tree, for whoever is primary)
    - Scripted

```cpp
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
```

## LED Switching method

```cpp
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
```

## RTOS48 Delegate Support

Need to fix the issue of OS48 not supporting Delegate functions. That's kind of annoying.

Delegates for the tasks don't need arguments, right? Can just invoke on the delegate memory address
and the rest is taken care of?

Pretty sure the library will need extending to accommodate that; don't think it can be
crowbarred in as a peripheral feature.

## Mock Drivers

Hardware interfaces; we can use Mock drivers providing the Delegate and OS48 systems work.
The mock can have their own timers, and simulate the actual hardware (Eg. Serial calls, freeing delays)

This is great for off-line development of the core features (Eg. State machines) without having
to worry about realistic hardware behaviour. It also simplifies the systems for unit-testing
scenarios.
