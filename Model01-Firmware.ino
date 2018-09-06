// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#define KEYCHORD_HYPER LSHIFT(LALT(LGUI(Key_LeftControl)))
#define KEYCHORD_MEH   LSHIFT(LALT(Key_LeftGui))

// #define ENABLE_MOUSEKEYS
// #define ENABLE_CHASE
// #define ENABLE_RAINBOW
// #define ENABLE_BREATHE
// #define ENABLE_STALKER
// #define ENABLE_ALPHASQUARE

/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for QuKeys (Dual-Use Keys)
#include "Kaleidoscope-Qukeys.h"

// Support for Sticky Modifiers
#include "Kaleidoscope-OneShot.h"

// Support for multiple keys via multitap
#include "Kaleidoscope-TapDance.h"

// TopsyTurvy allows key inversion to flip keys
#include "Kaleidoscope-TopsyTurvy.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
#include "Kaleidoscope-NumPad.h"

// Support for an "LED off mode"
#include "LED-Off.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
// #include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for Keyboardio's internal keyboard testing mode
// #include "Kaleidoscope-Model01-TestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for magic combos (key chords that trigger an action)
#include "Kaleidoscope-MagicCombo.h"

// Support for USB quirks, like changing the key state report protocol
#include "Kaleidoscope-USB-Quirks.h"

// Support for ActiveModColor
#include "Kaleidoscope-LED-ActiveModColor.h"

/** This 'enum' is a list of all the macros used by the Model 01's firmware
 * The names aren't particularly important. What is important is that each
 * is unique.
 *
 * These are the names of your macros. They'll be used in two places.
 * The first is in your keymap definitions. There, you'll use the syntax
 * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
 *
 * The second usage is in the 'switch' statement in the `macroAction` function.
 * That switch statement actually runs the code associated with a macro when
 * a macro key is pressed.
 */

enum { MACRO_VERSION_INFO,
       MACRO_ANY
};


enum { TAPDANCE_LEFT_BRACKET,
       TAPDANCE_RIGHT_BRACKET };

/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
 * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
 * keymap.
 *
 * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
 * of first the left hand's layout, followed by the right hand's layout.
 *
 * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
 * defined as part of the USB HID Keyboard specification. You can find the names
 * (if not yet the explanations) for all the standard `Key_` defintions offered by
 * Kaleidoscope in these files:
 *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
 *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
 *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
 *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
 *
 * Additional things that should be documented here include
 *   using ___ to let keypresses fall through to the previously active layer
 *   using XXX to mark a keyswitch as 'blocked' on this layer
 *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
 *   the special nature of the PROG key
 *   keeping NUM and FN consistent and accessible on all layers
 *
 *
 * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
 * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
 * macros switch to key layers based on this list.
 *
 *

 * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
 * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
 */

/**
 * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
 * The third one is layer 2.
 * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
 * the numbers 0, 1 and 2.
 *
 */

enum { PRIMARY, NUMPAD, FUNCTION }; // layers


/**
  * To change your keyboard's layout from QWERTY to DVORAK or COLEMAK, comment out the line
  *
  * #define PRIMARY_KEYMAP_QWERTY
  *
  * by changing it to
  *
  * // #define PRIMARY_KEYMAP_QWERTY
  *
  * Then uncomment the line corresponding to the layout you want to use.
  *
  */

#define PRIMARY_KEYMAP_QWERTY
// #define PRIMARY_KEYMAP_COLEMAK
// #define PRIMARY_KEYMAP_DVORAK
// #define PRIMARY_KEYMAP_CUSTOM



/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAPS
(
   [QWERTY] = KEYMAP_STACKED
   (
      //
      // left hand
      //
      Key_Escape,      Key_1, Key_2, Key_3, Key_4, Key_5, KEYCHORD_MEH,
      Key_Backtick,    Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
      Key_LeftControl, Key_A, Key_S, Key_D, Key_F, Key_G,
      Key_LeftShift,   Key_Z, Key_X, Key_C, Key_V, Key_B, TD(TAPDANCE_LEFT_BRACKET),

      CTL_T(Spacebar), OSM(LeftAlt), OSM(LeftGui), OSM(LeftShift),

      ShiftToLayer(FUNCTION),

      //
      // right hand
      //
      KEYCHORD_HYPER,             Key_6, Key_7, Key_8,     Key_9,         Key_0,         Key_Backspace,
      Key_Enter,                  Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                                  Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
      TD(TAPDANCE_RIGHT_BRACKET), Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,

      OSM(RightAlt), OSM(RightGui), Key_Backslash, Key_Spacebar,

      ShiftToLayer(FUNCTION)
   ),


   [NUMPAD] =  KEYMAP_STACKED
   (
      //
      // left hand
      //
      ___, ___, ___, ___, ___, ___, ___,
      ___, ___, ___, ___, ___, ___, ___,
      ___, ___, ___, ___, ___, ___,
      ___, ___, ___, ___, ___, ___, ___,

      ___, ___, ___, ___,

      ___,

      //
      // right hand
      //
      M(MACRO_VERSION_INFO), ___, Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, ___,
      ___,                   ___, Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      ___,
                             ___, Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         ___,
      ___,                   ___, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,

      ___, ___, ___, ___,

      ___
   ),

   [FUNCTION] =  KEYMAP_STACKED
   (
      //
      // left hand
      //
      LockLayer(NUMPAD), Key_F1,   Key_F2,     Key_F3, Key_F4, Key_F5, Key_LEDEffectNext,
      Key_Tab,           ___,      ___,        ___,    ___,    ___,    ___,
      Key_PageUp,        Key_Home, ___,        ___,    ___,    ___,
      Key_PageDown,      Key_End,  Key_Insert, ___,    ___,    ___,    Key_PrintScreen,

      ___, Key_Delete, ___, ___,

      ___,

      //
      // right hand
      //
      Consumer_Mute,            Key_F6,            Key_F7,                     Key_F8,                  Key_F9,                 Key_F10, ___,
      Consumer_VolumeIncrement, XXX,               XXX,                        Key_UpArrow,             XXX,                    XXX,     Key_F11,
                                XXX,               Key_LeftArrow,              Key_DownArrow,           Key_RightArrow,         XXX,     Key_F12,
      Consumer_VolumeDecrement, Key_PcApplication, Consumer_ScanPreviousTrack, Consumer_PlaySlashPause, Consumer_ScanNextTrack, XXX,     XXX,

      ___, ___, Key_Enter, ___,

      ___
   )
)

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
   if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
   }
}

void tapDanceAction(uint8_t tap_dance_index, byte row, byte col, uint8_t tap_count,
                    kaleidoscope::TapDance::ActionType tap_dance_action) 
{
    switch (tap_dance_index) 
    {
        case TAPDANCE_LEFT_BRACKET:
            return tapDanceActionKeys(tap_count, tap_dance_action,
                                      TOPSY(9), Key_LeftBracket, Key_LeftCurlyBracket);
            break;
        case TAPDANCE_RIGHT_BRACKET:
            return tapDanceActionKeys(tap_count, tap_dance_action, 
                                      TOPSY(0), Key_RightBracket, Key_RightCurlyBracket);
            break;
    }
}


/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(uint8_t keyState) {
   static Key lastKey;
   if (keyToggledOn(keyState))
      lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);

   if (keyIsPressed(keyState))
      kaleidoscope::hid::pressKey(lastKey);
}


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

*/

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
   switch (macroIndex) {

      case MACRO_VERSION_INFO:
         versionInfoMacro(keyState);
         break;

      case MACRO_ANY:
         anyKeyMacro(keyState);
         break;
   }
   return MACRO_NONE;
}



// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.


// static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
// static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
// static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
// static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
// static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
// static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
// static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);

static kaleidoscope::LEDSolidColor rnpGreen(0, 100, 0);
static kaleidoscope::LEDSolidColor rnpOrange(128, 64, 32);
static kaleidoscope::LEDSolidColor rnpBlue(27, 101, 144);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
   switch (event) {
      case kaleidoscope::HostPowerManagement::Suspend:
         LEDControl.paused = true;
         LEDControl.set_all_leds_to({0, 0, 0});
         LEDControl.syncLeds();
         break;
      case kaleidoscope::HostPowerManagement::Resume:
         LEDControl.paused = false;
         LEDControl.refreshAll();
         break;
      case kaleidoscope::HostPowerManagement::Sleep:
         break;
   }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
   toggleLedsOnSuspendResume(event);
}

/** This 'enum' is a list of all the magic combos used by the Model 01's
 * firmware The names aren't particularly important. What is important is that
 * each is unique.
 *
 * These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 */
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE
};

/** A tiny wrapper, to be used by MagicCombo.
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }
                 });

// First, tell Kaleidoscope which plugins you want to use.
   // The order can be important. For example, LED effects are
   // added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
    // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
    // BootGreetingEffect,

    Qukeys,     // dual-use keys; should be first to minimize typing event collisions
    OneShot,    // sticky modifiers
    TopsyTurvy, // flipped keys
    TapDance,   // multiple keybindings per key

    // The hardware test mode, which can be invoked by tapping Prog, LED and the left Fn button at the same time.
    // TestMode,

    // LEDControl provides support for other LED modes
    LEDControl,

    // We start with the LED effect that turns off all the LEDs.
    LEDOff,

    // These static effects turn your keyboard's LEDs a variety of colors
    // solidRed, solidOrange, solidYellow, solidGreen, solidBlue, solidIndigo, solidViolet,
    rnpBlue, rnpOrange, rnpGreen,

    // The numpad plugin is responsible for lighting up the 'numpad' mode
    // with a custom LED effect
    NumPad,

    // The macros plugin adds support for macros
    Macros,

    // The MagicCombo plugin lets you use key combinations to trigger custom
    // actions - a bit like Macros, but triggered by pressing multiple keys at the
    // same time.
    MagicCombo,

    // The USBQuirks plugin lets you do some things with USB that we aren't
    // comfortable - or able - to do automatically, but can be useful
    // nevertheless. Such as toggling the key report protocol between Boot (used
    // by BIOSes) and Report (NKRO).
    USBQuirks,

    // ActiveModColor lights up the mod keys when they're active
    ActiveModColorEffect
    );

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

   // While we hope to improve this in the future, the NumPad plugin
   // needs to be explicitly told which keymap layer is your numpad layer
   NumPad.numPadLayer = NUMPAD;

   // We want the keyboard to be able to wake the host up from suspend.
   HostPowerManagement.enableWakeup();

   // We want to make sure that the firmware starts with LED effects off
   // This avoids over-taxing devices that don't have a lot of power to share
   // with USB devices
   LEDOff.activate();

   ActiveModColorEffect.highlight_color = CRGB(0xd0, 0xd0, 0xd0);
   ActiveModColorEffect.sticky_color    = CRGB(0xd0, 0xd0, 0x00);
}

/** loop is the second of the standard Arduino sketch functions.
 * As you might expect, it runs in a loop, never exiting.
 *
 * For Kaleidoscope-based keyboard firmware, you usually just want to
 * call Kaleidoscope.loop(); and not do anything custom here.
 */

void loop() {
   Kaleidoscope.loop();
}
