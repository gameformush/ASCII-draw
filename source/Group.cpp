//
// Created by myst on 2/26/18.
//

#include "Group.h"
#include <tuple>

namespace ASCII_Draw
{

    Group::Group(unsigned int width, unsigned int height, Vector2D position):Base_component(width, height, position) {

    }

    void Group::remove(ASCII_Draw::Base_component * child) {
        auto i = std::find(children.begin(), children.end(), child);
        if(i != children.end())
        {
            children.erase(i);
        }
        child->setParent(nullptr);
        update();
    }

    void Group::remove_all() {
        for(auto child: children)
        {
            child->setParent(nullptr);
        }
        children.clear();
        update();
    }

    void Group::delete_child(ASCII_Draw::Base_component * child) {
        auto i = std::find(children.begin(), children.end(), child);
        if(i != children.end())
        {
            children.erase(i);
        }
        delete child;
        update();
    }

    void Group::delete_all() {
        for(auto child: children)
        {
            delete child;
        }
        children.clear();
        update();
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

    void Group::compose() {
        for(auto child : children)
        {
            Vector2D pos = child->getPosition();
            int w = child->getWidth();
            int h = child->getHeight();
            for (int x = 0; x < w; ++x) {
                for (int y = 0; y < h; ++y) {

                    // avoid unnecessary work
                    Pixel pixel = child->getPixel({x, y});
                    if(pixel == getDefault_pixel()) continue;

                    // transformation stuff
                    int xn = 0, yn = 0;
                    std::pair<int, int> new_coord = child->transfrom_point({x, y});
                    std::tie(xn, yn) = new_coord;
                    xn += pos.getX();
                    yn += pos.getY();
                    if (xn < 0 || yn < 0 ||
                        xn >= getWidth() || yn >= getHeight())
                    {
                        continue; // skip all that doesn't fit into group buffer;
                    }

                    setPixel({xn , yn}, pixel);
                }
            }
        }
    }


    // insert preserving order by z-index property
    void Group::add(Base_component *child) {
        child->setParent(this);
        children.insert
                (
                  std::upper_bound(children.begin(), children.end(), child,
                  [](const Base_component * a, const Base_component * b) -> bool {
                      return a->getZ_index() <= b->getZ_index();
                  }),
                  child
                );
        update();
    }
}