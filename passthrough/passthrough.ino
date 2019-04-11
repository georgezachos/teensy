#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputTDM            tdm1;           //xy=480,338
AudioOutputTDM           tdm2;           //xy=785,328
AudioConnection          patchCord1(tdm1, 0, tdm2, 0);
AudioConnection          patchCord3(tdm1, 2, tdm2, 2);

AudioConnection          patchCord5(tdm1, 4, tdm2, 4);
AudioConnection          patchCord7(tdm1, 6, tdm2, 6);

AudioConnection          patchCord9(tdm1, 8, tdm2, 8);
AudioConnection          patchCord11(tdm1, 10, tdm2, 10);

AudioConnection          patchCord13(tdm1, 8, tdm2, 12);
AudioConnection          patchCord15(tdm1, 10, tdm2, 14);


AudioControlCS42448      cs42448_1;      //xy=464,731
// GUItool: end automatically generated code

void setup() {
  AudioMemory(32);
  cs42448_1.enable();
  cs42448_1.volume(1.0);
  cs42448_1.inputLevel(1.0);
}

void loop() {
}
