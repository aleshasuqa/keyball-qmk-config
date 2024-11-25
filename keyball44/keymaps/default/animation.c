#include "animation.h"

static void render_anim(void) {
    uint16_t frame_sizes[2] = {
        sizeof(f_arr[0]),
        sizeof(f_arr[1]),
    };

    // Run animation
    if (timer_elapsed(timer) > FRAME_DURATION) {
        // Set timer to updated time
        timer = timer_read();

        // Increment frame
        c_frame = (c_frame + 1) % (sizeof(f_arr) / sizeof(f_arr[0]));

        // Draw frame to OLED
        oled_write_raw_P(f_arr[c_frame], frame_sizes[c_frame]);
    }
}
