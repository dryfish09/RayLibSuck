#include "raylib.h"
#include "./sound.hpp"

int main() {
    constexpr int windowX = 800;
    constexpr int windowY = 700;
    constexpr float ballRange = 9.5f;
    constexpr float flowerRange = 7.0f;
    // init windows
    InitWindow(windowX, windowY, "Ball's tiny world 2D");
    // init sound:
    InitAudioDevice();
    sound::loadFootstepSound();
    sound::loadRunSound();
    // set target fps
    SetTargetFPS(60);
    // create a ball:
    Vector2 ballPos = {30, 40};
    Vector2 flowerPos = {0, 0};
    Vector2 flowerPos2 = {0, 0};
    Vector2 flowerPos3 = {0, 0};
    flowerPos.x = (int)GetRandomValue(flowerRange, windowX - flowerRange);
    flowerPos.y = (int)GetRandomValue(flowerRange, windowY - flowerRange);
    flowerPos2.x = (int)GetRandomValue(flowerRange, windowX - flowerRange);
    flowerPos2.y = (int)GetRandomValue(flowerRange, windowY - flowerRange);
    flowerPos3.x = (int)GetRandomValue(flowerRange, windowX - flowerRange);
    flowerPos3.y = (int)GetRandomValue(flowerRange, windowY - flowerRange);
    // ishowspeed, lol, it's speed
    float speed = 5.3f; // not chill
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        // move ball with arrows
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
            speed = 5.3f;
            // right: use <entityPos>.x += speed;
            ballPos.x += speed * deltaTime;
            // play sound
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
            // left: like right, but is <entityPos>.x -= speed;
            speed = 5.3f;
            ballPos.x -= speed * deltaTime;
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            // down: <entityPos>.y += speed;
            speed = 5.3f;
            ballPos.y += speed * deltaTime;
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            speed = 5.3f;
            ballPos.y -= speed * deltaTime;
            sound::playFootstepSound();
        }
        // player will move slower when player hold to move
        else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            speed = 3.5f;
            // right: use <entityPos>.x += speed;
            ballPos.x += speed * deltaTime;
            sound::playRunSound();
        }
        else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            speed = 3.5f;
            // left: like right, but is <entityPos>.x -= speed;
            ballPos.x -= speed * deltaTime;
            sound::playRunSound();
        }
        else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
            speed = 3.5f;
            // down: <entityPos>.y += speed;
            ballPos.y += speed * deltaTime;
            sound::playRunSound();
        }
        else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
            speed = 3.5f;
            ballPos.y -= speed * deltaTime;
            sound::playRunSound();
        }
        // prevent player go out of screen
        if (ballPos.x - ballRange <= 0) {
            ballPos.x = ballRange;
        }
        if (ballPos.x + ballRange >= windowX) {
            ballPos.x = windowX - ballRange;
        }
        if (ballPos.y - ballRange <= 0) {
            ballPos.y = ballRange;
        }
        if (ballPos.y + ballRange >= windowY) {
            ballPos.y = windowY - ballRange;
        }
        // draw it!
        BeginDrawing();
        ClearBackground(GREEN);
        // draw some circle
        DrawCircleV(ballPos, ballRange, GOLD);
        DrawCircleV(flowerPos, flowerRange, RED);
        DrawCircleV(flowerPos2, flowerRange, GOLD);
        DrawCircleV(flowerPos3, flowerRange, WHITE);
        DrawText("Use arrow keys or WASD to move!", 20, 20, 20, BLACK);
        EndDrawing();
    }
    // close sound:
    sound::unloadDeclaredSound();
    CloseAudioDevice();
    // close windows
    CloseWindow();
    return 0;
}

