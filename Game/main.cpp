#include <string>
#include <vector>


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
    double teller = 0;
    double snelheid = 5;
    bool lost = false;
    auto *prs = new Press();
    int punten = 0;

    //Window running
    while (!WindowShouldClose()) {
        BeginDrawing();
        if (!lost) {
            DrawText(TextFormat("Score: %d", punten), 10, screenHeight / 2 - 50, 32, BLACK);

            //Teller
            teller++;
            if (teller == 30 && snelheid <= 15) {
                mannekes.push_back(new Manneke());

                snelheid += 0.5;

                teller = 0;
            }
            if (teller == 15 && snelheid >= 15 && snelheid <= 25) {
                mannekes.push_back(new Manneke());

                snelheid += 0.5;

                teller = 0;
            }
            if (teller == 7 && snelheid >= 25 && snelheid <= 35) {
                mannekes.push_back(new Manneke());

                snelheid += 0.5;

                teller = 0;
            }
            if (teller == 4 && snelheid >= 35 && snelheid <= 45) {
                mannekes.push_back(new Manneke());

                snelheid += 0.5;

                teller = 0;
            }

            //Mannekes bewegen
            for (auto m: mannekes) {
                m->Draw();
                m->Move(snelheid);
                if (m->position.x > screenWidth - 75) {
                    mannekes.erase(mannekes.begin());
                    delete m;
                }
                if (m->position.x > 500 && m->position.x < 700 && prs->prsPosition.y == -37.5 && m->isEnemy) {
                    m->color = backgroundColor;
                    punten++;
                }
                if (m->position.x > 500 && m->position.x < 700 && prs->prsPosition.y == -37.5 && !m->isEnemy) {
                    lost = true;
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
        } else {
            ClearBackground(backgroundColor);
            DrawText("U bent verloren", 10, screenHeight / 2, 50, BLACK);
        }


        ClearBackground(backgroundColor);
        EndDrawing();
    }
    return 0;
}
