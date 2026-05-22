#include <vector>
#include <bits/regex_constants.h>

#include "raylib.h"
#include "CodeFiles/Constants.h"
#include "CodeFiles/Manneke.h"
#include "CodeFiles/Press.h"


int main() {
    //Make window
    InitWindow(screenWidth, screenHeight, "Press It");
    SetTargetFPS(30);

    //Variabelen
    auto mannekes = std::vector<Manneke *>();
    int teller = 0;
    auto *prs = new Press();

    //Window running
    while (!WindowShouldClose()) {
        BeginDrawing();

        //Teller
        teller++;
        if (teller == 30) {
            mannekes.push_back(new Manneke());
            teller = 0;
        }

        //Mannekes bewegen
        for (auto m: mannekes) {
            m->Draw();
            m->Move();
            if (m->position.x > screenWidth - 75) {
                mannekes.erase(mannekes.begin());
                delete m;
            }
            if (m->position.x > 500 && m->position.x < 700 && prs->prsPosition.y == -37.5 && m->isEnemy) {
                m->color = backgroundColor;
            }
        }

        //Hydraulic press code
        prs->Draw();
        if (IsKeyPressed(KEY_DOWN) && prs->prsPosition.y < -37.5) {
            prs->Crush();
        } else {
            if (prs->prsPosition.y > -400) {
                prs->Return();
            }
        }
        ClearBackground(backgroundColor);
        EndDrawing();
    }
    return 0;
}
