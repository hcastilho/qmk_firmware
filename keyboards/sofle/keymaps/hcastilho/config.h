#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
#endif
#define ENCODER_RESOLUTION 4