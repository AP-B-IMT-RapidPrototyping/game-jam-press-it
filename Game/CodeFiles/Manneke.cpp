//
// Created by lukas on 22/05/2026.
//

#include "Manneke.h"

#include <cstdlib>

#include "./raylib.h"

Vector2 moveSpeed;
Vector2 position;
Color color;



Manneke::Manneke(){
    position = {0, 525};
    PickType();
    Draw();
};

Manneke::~Manneke() {

};

void Manneke::Draw(){
    DrawRectangle(position.x, position.y, 75, 75, color);
};


void Manneke::Move() {
    position.x +=8;
};

void Squish() {

};

void Manneke::PickType() {
    int random = rand();
    if (random % 4 == 0) {
        color = enemyColor;
        isEnemy = true;
        return;
    }
    color = civColor;
    isEnemy = false;
};