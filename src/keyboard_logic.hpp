#include "raylib.h"
inline void insertLogic() {
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
        // dash:
        else if (IsKeyDown(KEY_SPACE) && IsKeyDown(KEY_Y)) {
            ballPos.y += dashSpeed;
        }
        else if (IsKeyDown(KEY_SPACE) && IsKeyDown(KEY_X)) {
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
    }
}
