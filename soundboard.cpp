#include <iostream>
#include <thread>
#include "include/raylib.h"
#include <vector>
using namespace std;
#define vec vector
#define str string

const vec<str> sound_files = {
    "sound1.wav", "sound2.wav", "sound3.wav", "sound4.wav",
    "sound5.wav", "sound6.wav", "sound7.wav", "sound8.wav", "sound9.wav"
};

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "C Sound Board");
    SetTargetFPS(60);

    InitAudioDevice(); 

    Sound fxWav = LoadSound("resources/sound.wav");  
    Sound fxOgg = LoadSound("resources/target.ogg"); 

    
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE))
            PlaySound(fxWav);
        if (IsKeyPressed(KEY_ENTER))
            PlaySound(fxOgg);
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Press SPACE to PLAY the WAV sound!", 200, 180, 20, LIGHTGRAY);
        DrawText("Press ENTER to PLAY the OGG sound!", 200, 220, 20, LIGHTGRAY);
        EndDrawing();
        
    }


    UnloadSound(fxWav); 
    UnloadSound(fxOgg); 
    CloseAudioDevice(); 
    CloseWindow(); 
    return 0;
}
