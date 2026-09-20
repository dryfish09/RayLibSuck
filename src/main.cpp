#include "raylib.h"
#include "./sound.hpp"

int main() {
    constexpr int windowX = 800;
    constexpr int windowY = 700;
    constexpr float ballRange = 60;
    // init windows
    InitWindow(windowX, windowY, "Ball's tiny world 2D");
    // init sound:
    InitAudioDevice();
    loadFootstepSound();
    // set target fps
    SetTargetFPS(60);
    // create a ball:
    Vector2 ballPos = {30, 40};
    // ishowspeed, lol, it's speed
    float speed = 4.0f; // chill
    while (!WindowShouldClose()) {
        // move ball with arrows
        if (IsKeyDown(KEY_RIGHT)) {
            // right: use <entityPos>.x += speed;
            ballPos.x += speed;
            // play sound
            PlaySound(footstepSound);
        }
        if (IsKeyDown(KEY_LEFT)) {
            // left: like right, but is <entityPos>.x -= speed;
            ballPos.x -= speed;
            PlaySound(footstepSound);
        }
        if (IsKeyDown(KEY_DOWN)) {
            // down: <entityPos>.y += speed;
            ballPos.y += speed;
            PlaySound(footstepSound);
        }
        if (IsKeyDown(KEY_UP)) {
            ballPos.y -= speed;
            PlaySound(footstepSound);
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
        // draw a circle
        DrawCircleV(ballPos, ballRange, GOLD);
        DrawText("Use arrow keys to move!", 20, 20, 20, BLACK);
        EndDrawing();
    }
    // close sound:
    unloadDeclaredSound();
    CloseAudioDevice();
    // close windows
    CloseWindow();
    return 0;
}
