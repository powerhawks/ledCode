#include <FastLED.h>

#define LED_PIN     10
#define COLOR_ORDER GBR
#define CHIPSET     WS2811
#define NUM_LEDS    34

#define BRIGHTNESS  255
#define FRAMES_PER_SECOND 60

bool gReverseDirection = false;

CRGB leds[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];
void setup() {
  delay(3000); // sanity delay

  FastLED.addLeds<CHIPSET, 7, COLOR_ORDER>(leds2, NUM_LEDS).setCorrection( TypicalLEDStrip ); //blue
  FastLED.addLeds<CHIPSET, 8 , COLOR_ORDER>(leds3, NUM_LEDS).setCorrection( TypicalLEDStrip ); //red

  FastLED.setBrightness( BRIGHTNESS );
}

void loop()
{
  // Add entropy to random number generator; we use a lot of it.
  // random16_add_entropy( random());


  blynk();
  FastLED.show(); // display this frame
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}



void blynk() {
  #undef colour
  #define colour CRGB::Red
  #define colour1 CRGB::Blue
  int DELAY = 28 ;
  int numInSeq = 7;
  
  #define colourB CRGB::Black;
  for(int ex = (numInSeq - 1); ex < NUM_LEDS; ex++)
  {
    for(int x = 0; x < numInSeq; x++) {
        leds2[ex -x] = colour;
        
        leds3[ex -x -1] = colour1;
        
    }

    FastLED.show();
    delay(DELAY);
    // Now turn the LED off, then pause
    for(int x = 0; x < numInSeq; x++) {
        leds2[ex -x] = colourB;
        
        leds3[ex -x] = colourB;
        
    }
    FastLED.show();
  }
  for(int ex = NUM_LEDS; ex > (numInSeq - 1); ex--)
  {
    for(int x = 0; x < numInSeq; x++) {
        leds2[ex -x] = colour;
        
        leds3[ex -x -1] = colour1;
        
    }
   
    FastLED.show();
    delay(DELAY);
    // Now turn the LED off, then pause
  
    for(int x = 0; x < numInSeq; x++) {
        leds2[ex -x] = colourB;
        ;
        leds3[ex -x] = colourB;
        
    }
    FastLED.show();

  }
  delay(5);
  
}
