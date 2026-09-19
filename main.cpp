#include "raylib.h"

int main() {
    constexpr int windowX = 800;
    constexpr int windowY = 700;
    constexpr float ballRange = 60;
    constexpr int coinRange = 15;
    // init windows
    InitWindow(windowX, windowY, "Ball's tiny world 2D");
    // set target fps, 30 is good for mobile compiler
    SetTargetFPS(30);
    // create a ball:
    Vector2 ballPos = {30, 40};
    // coin
    Vector2 coinPos = {0, 0};
    // ishowspeed, lol, it's speed
    float speed = 3.5f; // chill
    while (!WindowShouldClose()) {
        // move ball with arrows
        if (IsKeyDown(KEY_RIGHT)) {
            // right: use <entityPos>.x += speed;
            ballPos.x += speed;
        }
        if (IsKeyDown(KEY_LEFT)) {
            // left: like right, but is <entityPos>.x -= speed;
            ballPos.x -= speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            // down: <entityPos>.y += speed;
            ballPos.y += speed;
        }
        if (IsKeyDown(KEY_UP)) {
            ballPos.y -= speed;
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
        ClearBackground(WHITE);
        // draw a circle
        DrawCircleV(ballPos, ballRange, GREEN);
        DrawCircleV(coinPos, coinRange, GOLD);
        DrawText("Use Arrow keys to move!", 20, 20, 20, BLACK);
        EndDrawing();
    }
    // only close window when it should close
    CloseWindow();
    return 0;
}
