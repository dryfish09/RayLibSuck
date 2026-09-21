#pragma once
#include "raylib.h"
namespace texture {
    inline Texture2D flowerTexture;
    inline void loadTexture() {
        flowerTexture = LoadTexture("src/assets/texture/flower.png");
        // make sure texture loaded by check it
        if (flowerTexture.id == 0) {
            TraceLog(LOG_ERROR, "texture is not available or can't be loaded.");
        }
    }
    inline void unloadTexture() {
        UnloadTexture(flowerTexture);
    }
} // namespace
