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
    while (!WindowShouldClose()) {
        // move ball with arrows
        // IsKeyPressed for one move at a time
        if (IsKeyDown(KEY_RIGHT)) {
            // right: use <entityPos>.x += speed;
            ballPos.x += speed;
        }
        else if (IsKeyDown(KEY_LEFT)) {
            // left: like right, but is <entityPos>.x -= speed;
            ballPos.x -= speed;
        }
        else if (IsKeyDown(KEY_DOWN)) {
            // right: <entityPos>.y += speed;
            ballPos.y += speed;
        }
        else if (IsKeyDown(KEY_UP)) {
            ballPos.y -= speed;
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
