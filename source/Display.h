//
// Created by myst on 2/27/18.
//

#ifndef ASCII_DRAW_DISPLAY_H
#define ASCII_DRAW_DISPLAY_H

#include "Group.h"

namespace ASCII_Draw {


    class Display {
    private:
        Group * root;
//        std::ostringstream buffer;
    public:
        Display();
        void render(bool force, std::ostringstream &buffer);
        void clear();
        void add(Base_component * child);
        void remove(Base_component * child);
    };
}


#endif //ASCII_DRAW_DISPLAY_H
