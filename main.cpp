#include "raylib.h"

int main() {
    // init windows
    InitWindow(800, 700, "First Raylib program");
    // set target fps, 30 is good for mobile compiler
    SetTargetFPS(30);
    // create a ball:
    Vector2 ballPos = {30, 40};
    // ishowspeed, lol, it's speed
    float speed = 3.5f; // chill
    // wall to prevent player go out of screen, try to use constexpr
    constexpr int wall = 5;
    while (!WindowShouldClose()) {
        // move ball with arrows
        // IsKeyPressed for one move at a time
        if (IsKeyDown(KEY_RIGHT)) {
            // right: use <entityPos>.x += speed;
            ballPos.x += speed;
        }
        if (IsKeyDown(KEY_LEFT)) {
            // left: like right, but is <entityPos>.x -= speed;
            ballPos.x -= speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            // right: <entityPos>.y += speed;
            ballPos.y += speed;
        }
        if (IsKeyDown(KEY_UP)) {
            ballPos.y -= speed;
        }
        // wall
        if (ballPos.x - wall <= 0) {
            ballPos.x = wall;
        }
        if (ballPos.x + wall >= 800) {
            ballPos.x = wall;
        }
        if (ballPos.y - wall <= 0) {
            ballPos.y = wall;
        }
        if (ballPos.y + wall >= 700) {
            ballPos.y = wall;
        }
        // draw it!
        BeginDrawing();
        ClearBackground(WHITE);
        // draw a circle
        DrawCircleV(ballPos, 60, GREEN);
        DrawText("Use Arrow keys to move!", 20, 20, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 10; // i like 10, not 0
}
