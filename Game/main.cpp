#include "raylib.h"

int main() {
    InitWindow(800,800, "Fuck you!");
    SetTargetFPS(120);
    Vector2 textPos = Vector2{(float)GetScreenHeight() / 2, (float)GetScreenWidth() / 2   };

    Vector2 snelheid = {3.1, 2.5};
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Ik haat dit",textPos.x, textPos.y,20, BLACK);

        if (IsKeyDown(KEY_UP)) {
            textPos.y -= 1;
        }
        if (IsKeyDown(KEY_DOWN)) {
            textPos.y += 1;
        }
        if (IsKeyDown(KEY_LEFT)) {
            textPos.x -= 1;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            textPos.x += 1;
        }

        textPos.x -= snelheid.x;
        textPos.y -= snelheid.y;

        if (textPos.x < 0 | textPos.x > GetScreenWidth()) {
            snelheid.x *= -1;
        }
        if (textPos.y < 0 | textPos.y > GetScreenHeight()) {
            snelheid.y *= -1;
        }




        EndDrawing();
    }
}