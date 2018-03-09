//
// Created by myst on 3/5/18.
//

#ifndef ASCII_DRAW_TEXT_H
#define ASCII_DRAW_TEXT_H

#include "../Base_component.h"

namespace ASCII_Draw {
    enum class Alignment {LEFT, CENTER, RIGHT};
    enum class Vertical_Alignment {TOP, MIDDLE, BOTTOM};

    class Text: public Base_component {
    private:
        std::vector<std::string> multylineText;
        std::string rawText;
        Alignment alignment;
        Vertical_Alignment vert_alignment;
    protected:
        void _render();
    public:
        Text();
        Text(const std::string & text, const Vector2D & pos, int width, int height);
        const std::string & getText() const;
        const std::vector<std::string> & getMultyText() const;
        void setText(const std::string & text);
        void append(const std::string & text);
        void clear();
        void align(Alignment align);
        const Alignment & getAlignment() const;
        void vertical_align(Vertical_Alignment vert_alignment);
        const Vertical_Alignment & getVertical_alignment() const;
    };
}

#endif //ASCII_DRAW_TEXT_H
