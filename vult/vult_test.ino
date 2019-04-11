#include <Audio.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <Wire.h>

#include "SynthTest.h"

AudioOutputTDM tdm2; // xy=785,328
SynthTest sig1;
AudioConnection patchCord1(sig1, 0, tdm2, 4);
AudioConnection patchCord2(sig1, 0, tdm2, 6);

AudioControlCS42448 cs42448_1; // xy=464,731

void setup() {
  AudioMemory(120);
  cs42448_1.enable();
  cs42448_1.volume(0.1);

  sig1.begin();
}

void loop() {
  Serial.print("CPU: ");
  Serial.print("  ");
  Serial.print("all=");
  Serial.print(AudioProcessorUsage());
  Serial.print("    ");
  Serial.print("Memory: ");
  Serial.print(AudioMemoryUsage());
  Serial.print("    ");
  Serial.println();

  // very simple timing   :-)
  delay(500);
}
