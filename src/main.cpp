#include "raylib.h"
#include "./sound.hpp"
#include "./texture.hpp"
#include "./logic.hpp"
#include "./initializer.hpp"

int main() {
    init();
    // set target fps
    SetTargetFPS(60);
    insertLogic();
    closeAndUnload();
    return 0;
}

