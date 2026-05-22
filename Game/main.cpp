#include <vector>
#include <bits/regex_constants.h>

#include "raylib.h"
#include "CodeFiles/Constants.h"
#include "CodeFiles/Manneke.h"


int main() {
    //Make window
    InitWindow(screenWidth, screenHeight, "Press It");
    SetTargetFPS(30);

    //Variabelen
    auto mannekes = std::vector<Manneke*>();
    int teller = 0;
    //Window running
    while (!WindowShouldClose()) {
        BeginDrawing();
        teller++;
        if (teller == 30) {

            mannekes.push_back(new Manneke());
            teller = 0;
        }

        for (auto m: mannekes) {
            m->Draw();
            m->Move();
            if (m->position.x >screenWidth - 75) {
                mannekes.erase(mannekes.begin());
                delete m;
            }
        }

        //Hydraulic press code

        ClearBackground(backgroundColor);
        EndDrawing();
    }
    return 0;
}