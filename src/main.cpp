#include "raylib.h"
#include "./sound.hpp"
#include "./texture.hpp"
#include "./logic.hpp"

int main() {
    // set target fps
    SetTargetFPS(60);
    insertLogic();
    return 0;
}

