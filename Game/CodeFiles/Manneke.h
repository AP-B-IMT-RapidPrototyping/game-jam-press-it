#pragma once
#include "./raylib.h"
#include "Constants.h"


class Manneke {
public:
    bool isEnemy;
    Vector2 position;
    Vector2 moveSpeed;
    Color color;

    Manneke();
    ~Manneke();

    void Draw();
    void Move();
    bool PickType();
};