//
// Created by lukas on 22/05/2026.
//

#include "Press.h"
#include "./raylib.h"
#include "Constants.h"


Press::Press() {
    prsPosition = {(screenWidth/2) - 50, -400};
    //Draw();
};

Press::~Press() {

};

void Press::Draw() {
    DrawRectangle(prsPosition.x, prsPosition.y, 100, 600, BLUE);
};

void Press::Crush() {
    prsPosition.y = -37.5;
};

void Press::Return() {
    prsPosition.y -= 12;
}
