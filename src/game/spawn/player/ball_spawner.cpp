#include "raylib.h"
#include "game/logic/logic.h"
#include "game/var.h"
#include "ball_spawner.h"
namespace spawn {
    void spawnBall() {
        Vector2 ballPos = {100, 100};
        ballPos.x = (int)GetRandomValue(ballRadius, windowX - ballRadius);
        ballPos.y = (int)GetRandomValue(ballRadius, windowY - ballRadius);
    }
}
