#pragma once
#include "raylib.h"
namespace texture {
    inline Texture2D flowerTex;
    inline void loadTexture() {
        flowerTex = LoadTexture("src/assets/texture/flower.png");
    }
    inline void unloadTexture() {
        UnloadTexture(flowerTex);
    }
} // namespace
