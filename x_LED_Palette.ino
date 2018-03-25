extern const TProgmemPalette16 paletteRedOrangeRed PROGMEM;
extern const TProgmemPalette16 paletteGrayLightSlateGray PROGMEM;
extern const TProgmemPalette16 paletteLawnGreenLightGreen PROGMEM;
extern const TProgmemPalette16 palettePurpleMediumPurple PROGMEM;
extern const TProgmemPalette16 paletteGray PROGMEM;
extern const TProgmemPalette16 paletteBlack PROGMEM;

void FillLEDsFromPaletteColors(uint8_t colorIndex)
{
//    uint8_t brightness = 255;
//    
//    for( int i = 0; i < NUM_LEDS_UP; i++) {
//        ledUp[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
//        colorIndex += 3;
//    }

}

void FillLeds(uint8_t colorIndex, CRGB arLED[], int iLeds, CRGBPalette16 palette, TBlendType Blending, int brightness)
{
 for( int i = 0; i < iLeds; i++) {
 arLED[i] = ColorFromPalette(palette, colorIndex, brightness, currentBlending);
 colorIndex += 3;
 }
}

void ChangePalettePeriodically(bool bFirstRun)
{
    uint8_t secondHand = (millis() / 1000) % 60;
    static uint8_t lastSecond = 5;
    
    if( lastSecond != secondHand || bFirstRun) {
        lastSecond = secondHand;
        if( secondHand ==  0 || bFirstRun)  { 
          arPalette[0] = palettePurpleMediumPurple;
          arPalette[1] = CloudColors_p;
          arPalette[2] = paletteGrayLightSlateGray;
         }
//        if( secondHand ==  5)  { currentPalette = RainbowStripeColors_p;}
//        if( secondHand == 10)  { SetupPurpleAndGreenPalette();}
//        if( secondHand == 15)  { currentPalette = CloudColors_p;}
//        if( secondHand == 20)  { currentPalette = PartyColors_p;}
//        if( secondHand == 25)  { currentPalette = myRedWhiteBluePalette_p;}
    }
}

const TProgmemPalette16 paletteRedOrangeRed PROGMEM =
{
    CRGB::Red,
    CRGB::Red, // 'white' is too bright compared to red and blue
    CRGB::Red,
    CRGB::Red,
    
    CRGB::OrangeRed,
    CRGB::OrangeRed,
    CRGB::OrangeRed,
    CRGB::OrangeRed,
    
    CRGB::Red,
    CRGB::Red,
    CRGB::Red,
    CRGB::Red,
    
    CRGB::Red,
    CRGB::Red,
    CRGB::Red,
    CRGB::Red
};

const TProgmemPalette16 paletteGrayLightSlateGray PROGMEM =
{
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    
    CRGB::LightSlateGray,
    CRGB::LightSlateGray,
    CRGB::LightSlateGray,
    CRGB::LightSlateGray,
    
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray
};

const TProgmemPalette16 paletteGray PROGMEM =
{
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Gray
};

const TProgmemPalette16 paletteLawnGreenLightGreen PROGMEM =
{
    CRGB::LawnGreen,
    CRGB::LawnGreen,
    CRGB::LawnGreen,
    CRGB::LawnGreen,
    
    CRGB::LightGreen,
    CRGB::LightGreen,
    CRGB::LightGreen,
    CRGB::LightGreen,
    
    CRGB::LawnGreen,
    CRGB::LawnGreen,
    CRGB::LawnGreen,
    CRGB::LawnGreen,
    
    CRGB::LawnGreen,
    CRGB::LawnGreen,
    CRGB::LawnGreen,
    CRGB::LawnGreen
};

const TProgmemPalette16 palettePurpleMediumPurple PROGMEM =
{
    CRGB::Purple,
    CRGB::Purple,
    CRGB::Purple,
    CRGB::Purple,
    
    CRGB::MediumPurple,
    CRGB::MediumPurple,
    CRGB::MediumPurple,
    CRGB::MediumPurple,
    
    CRGB::Purple,
    CRGB::Purple,
    CRGB::Purple,
    CRGB::Purple,
    
    CRGB::Purple,
    CRGB::Purple,
    CRGB::Purple,
    CRGB::Purple
};

const TProgmemPalette16 paletteBlack PROGMEM =
{
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black
};
