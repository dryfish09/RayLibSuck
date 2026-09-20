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
    sound::loadFootstepSound();
    // set target fps
    SetTargetFPS(60);
    // create a ball:
    Vector2 ballPos = {30, 40};
    // ishowspeed, lol, it's speed
    constexpr float speed = 5.3f; // not chill
    while (!WindowShouldClose()) {
        // move ball with arrows
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
            // right: use <entityPos>.x += speed;
            ballPos.x += speed;
            // play sound
            sound::playFootstepSound();
        }
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
            // left: like right, but is <entityPos>.x -= speed;
            ballPos.x -= speed;
            sound::playFootstepSound();
        }
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            // down: <entityPos>.y += speed;
            ballPos.y += speed;
            sound::playFootstepSound();
        }
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            ballPos.y -= speed;
            sound::playFootstepSound();
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
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            // right: use <entityPos>.x += speed;
            ballPos.x += speed;
        }
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            // left: like right, but is <entityPos>.x -= speed;
            ballPos.x -= speed;
        }
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
            // down: <entityPos>.y += speed;
            ballPos.y += speed;
        }
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
            ballPos.y -= speed;
        }
        // draw it!
        BeginDrawing();
        ClearBackground(GREEN);
        // draw a circle
        DrawCircleV(ballPos, ballRange, GOLD);
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
