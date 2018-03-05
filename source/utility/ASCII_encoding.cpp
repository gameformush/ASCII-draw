//
// Created by myst on 2/26/18.
//
#include <string>
#pragma once

namespace ASCII_Draw
{
    // ASCII encoding
    const std::string _ESCAPE_SEQ = "\33[";
    const std::string _BG = "48;5;";
    const std::string _FG = "38;5;";
    const std::string _CLOSER = "m";
    const std::string _BOLD = "1";
    const std::string _UNDERLINE = "4";
    const std::string _REVERSE = "7";
    const std::string _RESET = "0" + _CLOSER;
    const std::string _CLEAR_ALL = "2J";
    const std::string _MOVE_UP = "A";
    const std::string _MOVE_LEFT = "D";
    const std::string _MOVE_RIGHT = "C";
    const std::string _MOVE_DOWN = "B";
    const std::string _SAVE = "s";
    const std::string _RESTORE = "u";
    const std::string _HIDE_CURSOR = "?25l";
    const std::string _SHOW_CURSOR = "?25h";

}