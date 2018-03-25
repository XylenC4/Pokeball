#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>

#define NUM_LEDS    NUM_LEDS_UP+NUM_LEDS_MID+NUM_LEDS_LOW
#define NUM_LEDS_UP 13
#define NUM_LEDS_MID 1
#define NUM_LEDS_LOW 13
#define BRIGHTNESS  30
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

#define HighlightByDistanceShort 60
#define HighlightByDistanceLong 600


#define SECONDS_SWITCH_PALETTE 5
CRGB leds[NUM_LEDS];
CRGB ledUp[NUM_LEDS_UP];
CRGB ledMid[NUM_LEDS_MID];
CRGB ledLow[NUM_LEDS_LOW];

int ledBrightness[NUM_LEDS] = {100,255,100};

bool bFirstRun = 1;
int iSwitchLeft, iSwitchRight;
long lngDistance;

bool bDisableLED = false;

#define UPDATES_PER_SECOND 60

CRGBPalette16 arPalette[3] = {RainbowColors_p, RainbowColors_p, RainbowColors_p};
CRGBPalette16 currentPalette = RainbowColors_p;
TBlendType    currentBlending = LINEARBLEND;

unsigned long time;

void setup() {
    Serial.begin(9600);

    SetupSwitches();
  
    delay( 500 ); // power-up safety delay
    FastLED.addLeds<NEOPIXEL, 10>(ledUp, 0, 13);
    FastLED.addLeds<NEOPIXEL, 9>(ledMid, 0, 1);
    FastLED.addLeds<NEOPIXEL, 8>(ledLow, 0, 13);
    FastLED.setBrightness(0);
        
    //setupBluetooth();
}


void loop()
{
    ReadSwitches();
    
    SwitchLeft(bFirstRun);
    SwitchRight(bFirstRun);
    
    bFirstRun = 0;
  
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLeds(startIndex,ledUp ,NUM_LEDS_UP  ,arPalette[0],currentBlending, ledBrightness[0]);
    FillLeds(startIndex,ledMid,NUM_LEDS_MID ,arPalette[1],currentBlending, ledBrightness[1]);
    FillLeds(startIndex,ledLow,NUM_LEDS_LOW ,arPalette[2],currentBlending, ledBrightness[2]);
     
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);

  
  lngDistance = pingSonic(12,11,50,150);
  roAveAdd(lngDistance); 

   // loopBluetooth();
}


