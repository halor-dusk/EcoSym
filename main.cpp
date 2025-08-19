#include "raylib.h"
#include "rsrc/entity.hpp"
#include "rsrc/plants/plants.hpp"
#include "rsrc/creatures/creature.hpp"

int main(void) {
    InitWindow(800, 450, "Ecosym");
    std::vector<Entity *> world;
    Creature bunny(&world, 0, 0, 32, 32);
    Plant bush(&world, 48, 48, 32, 32);
    while (!WindowShouldClose()) {
        // draw
        BeginDrawing();
            ClearBackground(BLACK);
            for (Entity *entity : world)
                entity->draw();
        EndDrawing();
        // update
        float deltaTime = GetFrameTime();
        for (Entity *entity : world)
            entity->update(deltaTime);
    }

    CloseWindow();
}
