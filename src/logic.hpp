#pragma once
#include "raylib.h"
#include "./gvar.hpp"
inline const float ballRadius = 9.5f;
inline void insertLogic() {
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
    // speed: 
    float speed = 5.5f;
    float runSpeed = 4.5f;
    float dashSpeed = 6.0f;
    while (!WindowShouldClose()) {
        // move ball with arrows
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
            // right: use <entityPos>.x += speed;
            ballPos.x += speed;
            // play sound
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
            // left: like right, but is <entityPos>.x -= speed;
            ballPos.x -= speed;
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            // down: <entityPos>.y += speed;
            ballPos.y += speed;
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            ballPos.y -= speed;
            sound::playFootstepSound();
        }
        // player will move slower when player hold to move
        else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            // right: use <entityPos>.x += speed;
            ballPos.x += runSpeed;;
            sound::playRunSound();
        }
        else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            // left: like right, but is <entityPos>.x -= speed;
            ballPos.x -= runSpeed;
            sound::playRunSound();
        }
        else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
            ballPos.y += runSpeed;
            sound::playRunSound();
        }
        else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
            ballPos.y -= runSpeed;
            sound::playRunSound();
        }
        // easter egg for who knows some code
        else if (IsKeyDown(KEY_Y)) {
            ballPos.y += dashSpeed;
        }
        else if (IsKeyDown(KEY_X)) {
            ballPos.x += dashSpeed;
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
        BeginDrawing();
        ClearBackground(GREEN);
        // draw some circle
        DrawCircleV(ballPos, ballRadius, GOLD);
        drawBackground(texture::bg);
        DrawTextureV(texture::flowerTexture, flowerPos, WHITE);
        DrawTextureV(texture::flowerTexture, flowerPos2, WHITE);
        DrawTextureV(texture::flowerTexture, flowerPos3, WHITE);
        DrawText("Use arrow keys or WASD to move!", 20, 20, 20, BLACK);
        EndDrawing();
    }
}
