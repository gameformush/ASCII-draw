//
// Created by myst on 2/27/18.
//

#include "Display.h"
#include "ASCII_encoder.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <chrono>
#include <thread>

void ASCII_Draw::Display::render(bool force, std::ostringstream &buffer) {
      root->render(force);
//    std::ostringstream buffer;

    // resize of needed
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    if ((unsigned int)w.ws_col != root->getWidth() ||
        (unsigned int)w.ws_row != root->getHeight())
    {
        root->resize((unsigned int)w.ws_col, (unsigned int)w.ws_row - 1);
        root->update();
    }
    // end of resize

    for (int y = 0; y < root->getHeight(); ++y) {
        for (int x = 0; x < root->getWidth(); ++x) {
            buffer << root->getPixel({x, y});
        }
        buffer << "\n";
    }
    std::cout << ASCII_encoder::move_left((unsigned short)root->getWidth());
    std::cout << buffer.str();
    std::cout.flush();
    std::cout << ASCII_encoder::move_left((unsigned short)root->getWidth());
    std::cout << ASCII_encoder::move_up((unsigned short)(root->getHeight()));
    std::cout.flush();
    buffer.str("");
    buffer.clear();
}

void ASCII_Draw::Display::add(ASCII_Draw::Base_component *child) {
    root->add(child);
}

void ASCII_Draw::Display::remove(ASCII_Draw::Base_component *child) {

}

ASCII_Draw::Display::Display() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);


    this->root = new Group((unsigned int)w.ws_col ,(unsigned int)w.ws_row - 1, Vector2D(0,0));
}

void ASCII_Draw::Display::clear() {
    std::cout << ASCII_encoder::clear_all();
}
