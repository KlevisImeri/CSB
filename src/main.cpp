#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio.h>
#include <iostream>
#include <vector>
using namespace std;

const char* sound_effect_path = "resources/Bruh sound effect.mp3";

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
    float* pOutputF32 = (float*)pOutput;
    const float* pInputF32 = (const float*)pInput;

    // Read sound effect data
    float soundEffectBuffer[frameCount];
    ma_uint64 framesRead;
    ma_decoder_read_pcm_frames(pDecoder, soundEffectBuffer, frameCount, &framesRead);

    // Mix microphone input with sound effect
    for (ma_uint32 i = 0; i < frameCount; ++i) {
        if (i < framesRead) {
            pOutputF32[i] = pInputF32[i] + soundEffectBuffer[i];
        } else {
            pOutputF32[i] = pInputF32[i];
        }
    }
}

int main() {
    ma_result result;
    ma_decoder decoder;
    ma_device_config deviceConfig;
    ma_device device;

    // Initialize the decoder for the sound effect
    result = ma_decoder_init_file(sound_effect_path, NULL, &decoder);
    if (result != MA_SUCCESS) {
        cout << "Failed to initialize decoder." << endl;
        return -1;
    }

    // Configure the device for microphone input and output
    deviceConfig = ma_device_config_init(ma_device_type_duplex);
    deviceConfig.capture.format = ma_format_f32;
    deviceConfig.capture.channels = 1;
    deviceConfig.playback.format = ma_format_f32;
    deviceConfig.playback.channels = 1;
    deviceConfig.dataCallback = data_callback;
    deviceConfig.pUserData = &decoder;

    // Initialize the device
    result = ma_device_init(NULL, &deviceConfig, &device);
    if (result != MA_SUCCESS) {
        cout << "Failed to initialize device." << endl;
        ma_decoder_uninit(&decoder);
        return -1;
    }

    // Start the device
    result = ma_device_start(&device);
    if (result != MA_SUCCESS) {
        cout << "Failed to start device." << endl;
        ma_device_uninit(&device);
        ma_decoder_uninit(&decoder);
        return -1;
    }

    cout << "Press Enter to quit..." << endl;
    cin.get();

    // Clean up
    ma_device_uninit(&device);
    ma_decoder_uninit(&decoder);

    return 0;
}