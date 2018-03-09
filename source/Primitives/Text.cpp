//
// Created by myst on 3/5/18.
//

#include "Text.h"

void ASCII_Draw::Text::_render() {

    int offsetY;
    switch (vert_alignment)
    {
        case Vertical_Alignment::TOP : {offsetY = 0;break;}
        case Vertical_Alignment::MIDDLE : {offsetY = (getHeight() / 2) - (multylineText.size() / 2);break;}
        case Vertical_Alignment::BOTTOM : {offsetY = getHeight() - multylineText.size();break;}
    }
    for(int i = 0; i < multylineText.size(); i++)
    {
        std::string to_insert = multylineText[i];
        int offsetX;
        switch (alignment)
        {
            case Alignment::LEFT: {offsetX = 0; break;}
            case Alignment::CENTER: {offsetX = (getWidth() / 2) - (to_insert.size() / 2);break;}
            case Alignment::RIGHT: {offsetX = getWidth() - to_insert.size(); break;}
        }

        for(int j = 0; j < to_insert.size(); j++)
        {
            if(i >= getHeight() || j >= getWidth())
                continue;
            Pixel pt = Pixel(getStyle());
            pt.setContent(to_insert.substr((unsigned)j, 1));
            setPixel({offsetX + j,offsetY + i}, pt);
        }
    }
}

ASCII_Draw::Text::Text() {
    rawText = "";
    alignment = Alignment::LEFT;
    vert_alignment = Vertical_Alignment::TOP;
}

ASCII_Draw::Text::Text(const std::string &text, const ASCII_Draw::Vector2D &pos, int width, int height)
:Base_component(width, height, pos)
{
    setText(text);
    alignment = Alignment::LEFT;
    vert_alignment = Vertical_Alignment::TOP;
}

const std::string &ASCII_Draw::Text::getText() const {
    return rawText;
}

const std::vector<std::string> &ASCII_Draw::Text::getMultyText() const {
    return multylineText;
}

void ASCII_Draw::Text::setText(const std::string &text) {
    rawText = text;
    multylineText.clear();
    std::string tmp(text);
    std::istringstream iss(tmp);
    std::string token;
    while(std::getline(iss, token))
    {
        multylineText.push_back(token);
    }
    update();
}

void ASCII_Draw::Text::append(const std::string &text) {
    rawText += text;
    std::string tmp(text);
    std::istringstream iss(tmp);
    std::string token;
    while(std::getline(iss, token))
    {
        multylineText.push_back(token);
    }
    update();
}

void ASCII_Draw::Text::clear() {
    rawText.clear();
    multylineText.clear();
    update();
}

void ASCII_Draw::Text::align(ASCII_Draw::Alignment align) {
    alignment = align;
    update();
}

const ASCII_Draw::Alignment & ASCII_Draw::Text::getAlignment() const {
    return alignment;
}

void ASCII_Draw::Text::vertical_align(ASCII_Draw::Vertical_Alignment vert_alignment) {
    this->vert_alignment = vert_alignment;
    update();
}

const ASCII_Draw::Vertical_Alignment &ASCII_Draw::Text::getVertical_alignment() const{
    return vert_alignment;
}
