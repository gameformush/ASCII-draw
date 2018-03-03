//
// Created by myst on 2/26/18.
//

#ifndef ASCII_DRAW_VECTOR2D_H
#define ASCII_DRAW_VECTOR2D_H

namespace ASCII_Draw {
    class Vector2D {
        int x;
        int y;
    public:
        Vector2D();
        Vector2D(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
        Vector2D(const Vector2D & other);
        int getX() const;

        void setX(int x);

        int getY() const;

        void setY(int y);

    };
}

#endif //ASCII_DRAW_VECTOR2D_H
