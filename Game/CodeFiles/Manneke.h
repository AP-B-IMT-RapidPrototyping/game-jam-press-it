#pragma once
#include "./raylib.h"
#include "Constants.h"


class Manneke {
public:
    bool isEnemy;
    Vector2 position;
    Color color;

    Manneke();
    ~Manneke();

    void Draw();
    void Move(int speed);
    void Squish();
    void PickType();
};