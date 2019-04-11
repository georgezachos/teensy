
#ifndef SYNTHTEST_H
#define SYNTHTEST_H

#include <stdint.h>
#include <math.h>
#include "vultin.h"
#include "AudioStream.h"

typedef struct Simple_sin__ctx_type_0 {
   float w1;
} Simple_sin__ctx_type_0;

typedef Simple_sin__ctx_type_0 Simple_sin_pinker_type;

void Simple_sin__ctx_type_0_init(Simple_sin__ctx_type_0 &_output_);

void Simple_sin_pinker_init(Simple_sin__ctx_type_0 &_output_);

float Simple_sin_pinker(Simple_sin__ctx_type_0 &_ctx, float x);

typedef struct Simple_sin__ctx_type_1 {
   int x2;
   int x1;
   Simple_sin__ctx_type_0 _inst2;
} Simple_sin__ctx_type_1;

typedef Simple_sin__ctx_type_1 Simple_sin_process_type;

void Simple_sin__ctx_type_1_init(Simple_sin__ctx_type_1 &_output_);

void Simple_sin_process_init(Simple_sin__ctx_type_1 &_output_);

float Simple_sin_process(Simple_sin__ctx_type_1 &_ctx, float color);

typedef Simple_sin__ctx_type_1 Simple_sin_noteOn_type;

void Simple_sin_noteOn_init(Simple_sin__ctx_type_1 &_output_);

void Simple_sin_noteOn(Simple_sin__ctx_type_1 &_ctx, int note, int velocity, int channel);

typedef Simple_sin__ctx_type_1 Simple_sin_noteOff_type;

void Simple_sin_noteOff_init(Simple_sin__ctx_type_1 &_output_);

void Simple_sin_noteOff(Simple_sin__ctx_type_1 &_ctx, int note, int channel);

typedef Simple_sin__ctx_type_1 Simple_sin_controlChange_type;

void Simple_sin_controlChange_init(Simple_sin__ctx_type_1 &_output_);

void Simple_sin_controlChange(Simple_sin__ctx_type_1 &_ctx, int control, int value, int channel);

typedef Simple_sin__ctx_type_1 Simple_sin_default_type;

void Simple_sin_default_init(Simple_sin__ctx_type_1 &_output_);

void Simple_sin_default(Simple_sin__ctx_type_1 &_ctx);



class SynthTest : public AudioStream
{
public:
  SynthTest(void) : AudioStream(0, NULL)
  {
     Simple_sin_process_init(data);
  }

  void begin() {
    Simple_sin_default(data);
  }

  // Handles note on events
  void noteOn(int note, int velocity, int channel){
    // If the velocity is larger than zero, means that is turning on
    if(velocity) Simple_sin_noteOn(data, note, velocity, channel);
    else         Simple_sin_noteOff(data, note, channel);
  }

  // Handles note off events
  void noteOff(int note, int velocity, int channel) {
    Simple_sin_noteOff(data, note, channel);

  }

  // Handles control change events
  void controlChange(int control, int value, int channel) {
    Simple_sin_controlChange(data, control, value, channel);
  }

  virtual void update(void);

private:
  Simple_sin_process_type data;

};

#endif // SYNTHTEST_H
