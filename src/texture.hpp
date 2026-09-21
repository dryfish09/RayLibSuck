#pragma once
#include "raylib.h"
namespace texture {
    inline void loadTexture() {
        inline Texture2D flowerTex = LoadTexture("src/assets/texture/flower.png");
    }
    inline void unloadTexture() {
        UnloadTexture(flowerTex);
    }
} // namespace
