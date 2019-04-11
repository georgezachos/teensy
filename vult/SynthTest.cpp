
#include "SynthTest.h"

void Simple_sin__ctx_type_0_init(Simple_sin__ctx_type_0 &_output_){
   Simple_sin__ctx_type_0 _ctx;
   _ctx.w1 = 0.f;
   _output_ = _ctx;
   return ;
}

void Simple_sin_pinker_init(Simple_sin__ctx_type_0 &_output_){
   Simple_sin__ctx_type_0_init(_output_);
   return ;
}

float Simple_sin_pinker(Simple_sin__ctx_type_0 &_ctx, float x){
   float b0;
   b0 = 0.0277129863191f;
   float b1;
   b1 = 0.0277129863191f;
   float a1;
   a1 = -0.944574027362f;
   float w0;
   w0 = (x + (- (a1 * _ctx.w1)));
   float y0;
   y0 = ((b0 * w0) + (b1 * _ctx.w1));
   _ctx.w1 = w0;
   return y0;
}

void Simple_sin__ctx_type_1_init(Simple_sin__ctx_type_1 &_output_){
   Simple_sin__ctx_type_1 _ctx;
   _ctx.x2 = 0;
   _ctx.x1 = 0;
   Simple_sin__ctx_type_0_init(_ctx._inst2);
   _output_ = _ctx;
   return ;
}

void Simple_sin_process_init(Simple_sin__ctx_type_1 &_output_){
   Simple_sin__ctx_type_1_init(_output_);
   return ;
}

float Simple_sin_process(Simple_sin__ctx_type_1 &_ctx, float color){
   _ctx.x1 = (((_ctx.x1 * 17389) + 7919) % 32768);
   float y1;
   y1 = (int_to_float(_ctx.x1) * 3.0517578125e-05f);
   _ctx.x2 = (((_ctx.x2 * 27449) + 12553) % 32768);
   float y2;
   y2 = (int_to_float(_ctx.x2) * 3.0517578125e-05f);
   float out;
   uint8_t _cond_7;
   _cond_7 = (color > 0.5f);
   if(_cond_7){ out = Simple_sin_pinker(_ctx._inst2,(y1 + (- y2))); }
   else
   { out = (y1 + (- y2)); }
   return (0.1f * out);
}

void Simple_sin_noteOn_init(Simple_sin__ctx_type_1 &_output_){
   Simple_sin__ctx_type_1_init(_output_);
   return ;
}

void Simple_sin_noteOn(Simple_sin__ctx_type_1 &_ctx, int note, int velocity, int channel){
}

void Simple_sin_noteOff_init(Simple_sin__ctx_type_1 &_output_){
   Simple_sin__ctx_type_1_init(_output_);
   return ;
}

void Simple_sin_noteOff(Simple_sin__ctx_type_1 &_ctx, int note, int channel){
}

void Simple_sin_controlChange_init(Simple_sin__ctx_type_1 &_output_){
   Simple_sin__ctx_type_1_init(_output_);
   return ;
}

void Simple_sin_controlChange(Simple_sin__ctx_type_1 &_ctx, int control, int value, int channel){
}

void Simple_sin_default_init(Simple_sin__ctx_type_1 &_output_){
   Simple_sin__ctx_type_1_init(_output_);
   return ;
}

void Simple_sin_default(Simple_sin__ctx_type_1 &_ctx){
}



void SynthTest::update(void)
{
  audio_block_t *block;
  short *bp;

  block = allocate();
  if (block) {
    bp = block->data;
      for(int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        fix16_t v = Simple_sin_process(data, 0);
        *bp++ = (int16_t)(v / 2);
      }

    transmit(block, 0);
    release(block);
  }
}

