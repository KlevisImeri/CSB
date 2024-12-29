#include <raylib.h>

#include <iostream>
#include <vector>
#define vec vector
#define str string
using namespace std;

const int Width = 800;
const int Height = 450;
const vec<str> sound_effects = {
    "resources/Bruh sound effect.mp3",
};

int main(void) {
  InitWindow(Width, Height, "C Sound Board");
  SetTargetFPS(60);
  InitAudioDevice();
  vec<Sound> sounds = {};
  for (auto s : sound_effects) {
    sounds.push_back(LoadSound(s.c_str()));
  }

  while (!WindowShouldClose()) {
    for (int i = 0; i < sounds.size(); i++) {
      if (IsKeyPressed(KEY_ONE + i)) {
        PlaySound(sounds[i]);
      }
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Press 1 to 9 to play sound!", 200, 180, 20, LIGHTGRAY);
    EndDrawing();
  }

  for (auto sound : sounds) {
    UnloadSound(sound);
  }
  CloseAudioDevice();
  CloseWindow();

  return 0;
}
