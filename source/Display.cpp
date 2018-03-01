//
// Created by myst on 2/27/18.
//

#include "Display.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <chrono>
#include <thread>

void ASCII_Draw::Display::render(bool force, std::ostringstream &buffer) {
      root->render(force);
//    std::ostringstream buffer;
    ASCII_Draw::ASCII_encoder encoder;

    for (int x = 0; x < root->getWidth(); ++x) {
        for (int y = 0; y < root->getHeight(); ++y) {
            buffer << root->getPixel({x, y});
        }
        buffer << "\n";
    }
    std::cout << encoder.move_left((unsigned short)root->getWidth());
    std::cout << buffer.str();
    std::cout.flush();
    std::cout << encoder.move_left((unsigned short)root->getWidth());
    std::cout << encoder.move_up((unsigned short)(root->getHeight() + 1));
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

    this->root = new Group(100,50, Vector2D(0,0));
}

void ASCII_Draw::Display::clear() {
    ASCII_encoder encoder;
    std::cout << encoder.clear_all();
}
