#pragma once
#include "raylib.h"
#include "texture.h"
namespace texture {
    Texture2D flowerTexture;
    Texture2D bg;
    void drawBackground(Texture2D tex) {
    DrawTexturePro(tex,
        (Rectangle){ 0, 0, (float)tex.width, (float)tex.height },
        (Rectangle){ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() },
        (Vector2){ 0, 0 }, 0.0f, WHITE);
    }
    void loadTexture() {
        flowerTexture = LoadTexture("src/assets/texture/flower.png");
        // make sure texture loaded by check it
        if (flowerTexture.id == 0) {
            TraceLog(LOG_ERROR, "texture is not available or can't be loaded.");
        }
    }
    void loadBg() {
        bg = LoadTexture("src/assets/texture/bg.png");
    }
    void unloadBg() {
        UnloadTexture(bg);
    }
    void unloadTexture() {
        UnloadTexture(flowerTexture);
    }
} // namespace
