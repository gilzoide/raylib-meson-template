#include "raylib.h"

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

void frame() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}

int main(int argc, const char **argv) {
    InitWindow(800, 450, "Raylib + Meson + C/C++");

    SetTargetFPS(60);

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(&frame, 0, 1);
#else
    while(!WindowShouldClose()) {
        frame();
    }
#endif
    CloseWindow();

    return 0;
}
