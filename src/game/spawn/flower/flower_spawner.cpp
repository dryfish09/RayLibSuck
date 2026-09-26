#include "raylib.h"
#include "game/var.h"
#include "flower_spawner.h"
namespace spawn {
    Vector2 flowerPos;
    Vector2 flowerPos2;
    Vector2 flowerPos3;
    Vector2 flowerPos4;
    Vector2 flowerPos5;
    Vector2 flowerPos6;
    const int flowerRadius = 20;
    void spawnFlower() {
        flowerPos = {0, 0};
        flowerPos2 = {0, 0};
        flowerPos3 = {0, 0};
        flowerPos4 = {0, 0};
        flowerPos5 = {0, 0};
        flowerPos6 = {0, 0};
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
    }
}
