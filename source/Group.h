//
// Created by myst on 2/26/18.
//

#include "Base_component.h"
#include <algorithm>

#ifndef ASCII_DRAW_GROUP_H
#define ASCII_DRAW_GROUP_H

namespace ASCII_Draw
{

    class Group: public ASCII_Draw::Base_component
    {
    private:
        std::vector<ASCII_Draw::Base_component *> children;
    protected:
        void _render();
    public:
        void compose();
        Group(unsigned int, unsigned int, Vector2D);
        void add(Base_component *);
        void remove(ASCII_Draw::Base_component *);
        void remove_all();
        void delete_child(ASCII_Draw::Base_component *);
        void delete_all();
    };
}

#endif //ASCII_DRAW_GROUP_H
