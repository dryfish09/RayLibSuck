
#include "raylib.h"
#include "game/var.h"
#include "game/sound/sound.h"
#include "game/texture/texture.h"
#include "./logic.h"
inline const float ballRadius = 9.5f;
void insertLogic() {
    Vector2 ballPos = {30, 40};
    Vector2 flowerPos = {0, 0};
    Vector2 flowerPos2 = {0, 0};
    Vector2 flowerPos3 = {0, 0};
    Vector2 flowerPos4 = {0, 0};
    Vector2 flowerPos5 = {0, 0};
    Vector2 flowerPos6 = {0, 0};
    const int flowerRadius = 20;
    flowerPos.x = (int)GetRandomValue(flowerRadius, windowX - flowerRadius);
    flowerPos.y = (int)GetRandomValue(flowerRadius, windowY - flowerRadius);
    flowerPos2.x = (int)GetRandomValue(flowerRadius, windowX - flowerRadius);
    flowerPos2.y = (int)GetRandomValue(flowerRadius, windowY - flowerRadius);
    flowerPos3.x = (int)GetRandomValue(flowerRadius, windowX - flowerRadius);
    flowerPos3.y = (int)GetRandomValue(flowerRadius, windowY - flowerRadius);
    flowerPos4.x = (int)GetRandomValue(flowerRadius, windowX - flowerRadius);
    flowerPos4.y = (int)GetRandomValue(flowerRadius, windowY - flowerRadius);
    flowerPos5.x = (int)GetRandomValue(flowerRadius, windowX - flowerRadius);
    flowerPos5.y = (int)GetRandomValue(flowerRadius, windowY - flowerRadius);
    flowerPos6.x = (int)GetRandomValue(flowerRadius, windowX - flowerRadius);
    flowerPos6.y = (int)GetRandomValue(flowerRadius, windowY - flowerRadius);
    // speed: 
    float speed = 5.5f;
    float runSpeed = 4.5f;
    float dashSpeed = 6.0f;
    // play background music 
    sound::playBgm();
    while (!WindowShouldClose()) {
        UpdateMusicStream(sound::bgm);
        // check is bgm are playing and replay it
        if(!IsMusicStreamPlaying()) {
            sound::playBgm();
        }
        // move ball with arrows and W, A, S, D
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
            ballPos.x += speed;
            // play sound
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
            ballPos.x -= speed;
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            ballPos.y += speed;
            sound::playFootstepSound();
        }
        else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            ballPos.y -= speed;
            sound::playFootstepSound();
        }
        // player will move slower when player hold to move
        else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            ballPos.x += runSpeed;
            sound::playRunSound();
        }
        else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
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
        // draw background
        texture::drawBackground(texture::bg);
        // draw some circle
        DrawTextureV(texture::ball, ballPos, WHITE);
        DrawTextureV(texture::flowerTexture, flowerPos, WHITE);
        DrawTextureV(texture::flowerTexture, flowerPos2, WHITE);
        DrawTextureV(texture::flowerTexture, flowerPos3, WHITE);
        DrawTextureV(texture::flowerTexture, flowerPos4, WHITE);
        DrawTextureV(texture::flowerTexture, flowerPos5, WHITE);
        DrawTextureV(texture::flowerTexture, flowerPos6, WHITE);
        DrawText("Use arrow keys or WASD to move!", 20, 20, 20, BLACK);
        EndDrawing();
    }
}
