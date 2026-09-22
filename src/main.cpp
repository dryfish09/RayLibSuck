#include "raylib.h"
#include "./sound.hpp"
#include "./texture.hpp"

int main() {
    const int windowX = 800;
    const int windowY = 700;
    const float ballRadius = 9.5f;
    // init windows
    InitWindow(windowX, windowY, "Ball's tiny world 2D");
    // init sound:
    InitAudioDevice();
    sound::loadFootstepSound();
    sound::loadRunSound();
    //load texture
    texture::loadTexture();
    // set target fps
    SetTargetFPS(60);
    // create a ball:
    Vector2 ballPos = {30, 40};
    Vector2 flowerPos = {0, 0};
    Vector2 flowerPos2 = {0, 0};
    Vector2 flowerPos3 = {0, 0};
    const int flowerRadius = 20;
    flowerPos.x = (int)GetRandomValue(flowerRadius, windowX - flowerRadius);
    flowerPos.y = (int)GetRandomValue(flowerRadius, windowY - flowerRadius);
    flowerPos2.x = (int)GetRandomValue(flowerRadius, windowX - flowerRadius);
    flowerPos2.y = (int)GetRandomValue(flowerRadius, windowY - flowerRadius);
    flowerPos3.x = (int)GetRandomValue(flowerRadius, windowX - flowerRadius);
    flowerPos3.y = (int)GetRandomValue(flowerRadius, windowY - flowerRadius);
    // ishowspeed, lol, it's speed
    float speed = 5.3f; // not chill
    while (!WindowShouldClose()) {
        // move ball with arrows
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
            speed = 5.3f;
            // right: use <entityPos>.x += speed;
            ballPos.x += speed;
            // play sound
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
            // left: like right, but is <entityPos>.x -= speed;
            speed = 5.3f;
            ballPos.x -= speed;
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            // down: <entityPos>.y += speed;
            speed = 5.3f;
            ballPos.y += speed;
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            speed = 5.3f;
            ballPos.y -= speed;
            sound::playFootstepSound();
        }
        // player will move slower when player hold to move
        else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            speed = 3.5f;
            // right: use <entityPos>.x += speed;
            ballPos.x += speed;;
            sound::playRunSound();
        }
        else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            speed = 3.5f;
            // left: like right, but is <entityPos>.x -= speed;
            ballPos.x -= speed;
            sound::playRunSound();
        }
        else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
            speed = 3.5f;
            // down: <entityPos>.y += speed;
            ballPos.y += speed;
            sound::playRunSound();
        }
        else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
            speed = 3.5f;
            ballPos.y -= speed;
            sound::playRunSound();
        }
        // prevent player go out of screen
        if (ballPos.x - ballRadius <= 0) {
            ballPos.x = ballRadius;
        }
        if (ballPos.x + ballRadius >= windowX) {
            ballPos.x = windowX - ballRadius;
        }
        if (ballPos.y - ballRadius <= 0) {
            ballPos.y = ballRadius;
        }
        if (ballPos.y + ballRadius >= windowY) {
            ballPos.y = windowY - ballRadius;
        }
        // draw it!
        BeginDrawing();
        ClearBackground(GREEN);
        // draw some circle
        DrawCircleV(ballPos, ballRadius, GOLD);
        DrawTextureV(texture::flowerTexture, flowerPos, WHITE);
        DrawTextureV(texture::flowerTexture, flowerPos2, WHITE);
        DrawTextureV(texture::flowerTexture, flowerPos3, WHITE);
        DrawText("Use arrow keys or WASD to move!", 20, 20, 20, BLACK);
        EndDrawing();
    }
    // close sound:
    sound::unloadDeclaredSound();
    // unload texture
    texture::unloadTexture();
    CloseAudioDevice();
    // close windows
    CloseWindow();
    return 0;
}

