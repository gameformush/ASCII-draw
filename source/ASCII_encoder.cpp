//
// Created by myst on 2/26/18.
//

#include "ASCII_encoder.h"
#include <cmath>

namespace ASCII_Draw {
    namespace ASCII_encoder {
        encoded_style background(unsigned short code) {
            return _ESCAPE_SEQ + _BG + std::to_string(code) + _CLOSER;
        }

        encoded_style foreground(unsigned short code) {
            return _ESCAPE_SEQ + _FG + std::to_string(code) + _CLOSER;
        }

        encoded_style bold() {
            return _ESCAPE_SEQ + _BOLD + _CLOSER;
        }

        encoded_style underline() {
            return _ESCAPE_SEQ + _UNDERLINE + _CLOSER;
        }

        encoded_style reverse() {
            return _ESCAPE_SEQ + _REVERSE + _CLOSER;
        }

        encoded_style move_up(unsigned int units) {
            return _ESCAPE_SEQ + std::to_string(units) + _MOVE_UP;
        }

        encoded_style move_down(unsigned int units) {
            return _ESCAPE_SEQ + std::to_string(units) + _MOVE_DOWN;
        }

        encoded_style move_left(unsigned int units) {
            return _ESCAPE_SEQ + std::to_string(units) + _MOVE_LEFT;
        }

        encoded_style move_right(unsigned int units) {
            return _ESCAPE_SEQ + std::to_string(units) + _MOVE_RIGHT;
        }

        encoded_style clear_all() {
            return _ESCAPE_SEQ + _CLEAR_ALL;
        }

        encoded_style reset() {
            return _ESCAPE_SEQ + _RESET;
        }

        encoded_style hideCursor() {
            return _ESCAPE_SEQ + _HIDE_CURSOR;
        }

        encoded_style saveCursor() {
            return _ESCAPE_SEQ + _SAVE;
        }

        encoded_style restoreCursor() {
            return _ESCAPE_SEQ + _RESTORE;
        }

        encoded_style showCursor() {
            return _ESCAPE_SEQ + _SHOW_CURSOR;
        }

        unsigned short rgbTo256(const RGB &color) {
            // handle extended gray scale
            if(color.r == color.b && color.b == color.g)
            {
                if(color.r < 8)
                    return 16;
                if(color.r > 248)
                    return 231;
                return (unsigned short)((unsigned short)( ((color.r - 8)/247) * 24 + 0.5) + 232);
            }
            // other colors
            return (unsigned short)(16 + (36 * ((double)color.r / (255 * 5) )) + (6 * ((double)color.g / (255 * 5) ))
                      + ((double)color.b / (255 * 5)) + 0.5 );
        }
    };
}