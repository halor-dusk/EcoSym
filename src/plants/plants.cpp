#include "../../rsrc/plants/plants.hpp"

void Plant::draw() {
    DrawRectangleLines(this->collider.x, this->collider.y, this->collider.width, this->collider.height, GREEN);
}

void Plant::update(float deltaTime) {

}
