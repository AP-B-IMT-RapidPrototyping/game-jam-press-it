#pragma once

#include "./raylib.h"
class Press {

public:
    Vector2 prsPosition;

    Press();

    ~Press();

    void Draw();

    void Crush();

    void Return();
};
