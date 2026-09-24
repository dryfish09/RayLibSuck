#pragma once
#include "raylib.h"
namespace texture {
    inline Texture2D flowerTexture;
    inline Texture2D bg;
    inline void drawBackground(Texture2D tex) {
    DrawTexturePro(tex,
        (Rectangle){ 0, 0, (float)tex.width, (float)tex.height },
        (Rectangle){ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() },
        (Vector2){ 0, 0 }, 0.0f, WHITE);
    }
    inline void loadTexture() {
        flowerTexture = LoadTexture("src/assets/texture/flower.png");
        // make sure texture loaded by check it
        if (flowerTexture.id == 0) {
            TraceLog(LOG_ERROR, "texture is not available or can't be loaded.");
        }
    }
    inline void loadBg() {
        bg = LoadTexture("src/assets/texture/bg.png");
    }
    inline void unloadBg() {
        UnloadTexture(bg);
    }
    inline void unloadTexture() {
        UnloadTexture(flowerTexture);
    }
} // namespace
