//
// Created by myst on 2/26/18.
//

#include "Group.h"

namespace ASCII_Draw
{

    Group::Group(unsigned int width, unsigned int height, Vector2D position):Base_component(width, height, position) {
        this->children = std::vector<ASCII_Draw::Base_component *>(0);
    }

    void Group::remove(ASCII_Draw::Base_component *) {

    }

    void Group::remove_all() {

    }

    void Group::delete_child(ASCII_Draw::Base_component *) {

    }

    void Group::delete_all() {

    }

    void Group::_render() {
        for(auto child : children)
        {
            if (child->is_dirt())
            {
                this->update();
                child->render();
            }
        }
        if (this->is_dirt())
        {
            clear_buffer();
            this->compose();
        }
    }

    //Simplest compose implementation should change
    // inorder to use transformations
    void Group::compose() {
        for(auto child : children)
        {
            Vector2D pos = child->getPosition();
            int w = child->getWidth();
            int h = child->getHeight();
            for (int x = pos.getX(); x < w + pos.getX(); ++x) {
                for (int y = pos.getY(); y < h + pos.getY(); ++y) {
                     setPixel(
                             {x, y},
                             child->getPixel({x - pos.getX(), y - pos.getY()})
                     );
                }
            }
        }
    }

    void Group::add(Base_component *child) {
        child->setParent(this);
        children.push_back(child);
    }
}