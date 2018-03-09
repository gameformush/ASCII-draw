//
// Created by myst on 3/5/18.
//

#ifndef ASCII_DRAW_RGB_H
#define ASCII_DRAW_RGB_H

/*
 * Container for rbg data type nothing more
 */

namespace ASCII_Draw
{
    struct RGB
    {
        unsigned short r;
        unsigned short b;
        unsigned short g;
        RGB() {
            r = 0;
            b = 0;
            g = 0;
        }
        RGB(unsigned short r, unsigned short g, unsigned short b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }
        RGB(const RGB & other) {
            this->r = other.r;
            this->b = other.b;
            this->g = other.g;
        }
        bool operator ==(const RGB & other) const
        {
            return (
                    r == other.r &&
                    g == other.g &&
                    b == other.b
            );
        }
    };
}

#endif //ASCII_DRAW_RGB_H
