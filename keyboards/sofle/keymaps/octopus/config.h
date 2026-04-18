#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
#endif
#define ENCODER_RESOLUTION 4


#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Home row mods tuning
// Tap vs hold threshold in ms: <200 = tap (letter), >=200 = hold (modifier)
#define TAPPING_TERM 200
// If another key is pressed before release, treat as hold immediately (snappy cross-hand mods)
#define HOLD_ON_OTHER_KEY_PRESS
// Disable tap-then-hold auto-repeat so fast tap+hold always = modifier, never repeated letter
#define QUICK_TAP_TERM 0
