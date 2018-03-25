bool bMemIsDark = 0;
int iDarknessDelay = 0;

void SetupSwitches() {
    pinMode(14,INPUT_PULLUP);
    pinMode(15,INPUT_PULLUP);
    pinMode(16,INPUT_PULLUP);
    pinMode(17,INPUT_PULLUP);
    pinMode(18,INPUT_PULLUP);
    pinMode(19,INPUT_PULLUP);
}

void ReadSwitches() {
    bool iLeft1 = !digitalRead(14);
    bool iLeft2 = !digitalRead(15);
    bool iLeft3 = !digitalRead(16);
    iSwitchLeft = iLeft1*1+iLeft2*2+iLeft3*3;

    bool iRight1 = !digitalRead(17);
    bool iRight2 = !digitalRead(18);
    bool iRight3 = !digitalRead(19);
    iSwitchRight = iRight1*1+iRight2*2+iRight3*3;

//   Serial.print(iLeft1);
//   Serial.print(";");
//   Serial.print(iLeft2);
//   Serial.print(";");
//   Serial.print(iLeft3);
//   Serial.print(";");
//   Serial.print(iRight1);
//   Serial.print(";");
//   Serial.print(iRight2);
//   Serial.print(";");
//   Serial.print(iRight3);
//    
//   Serial.print(";left: ");
//   Serial.print(iSwitchLeft);
//   Serial.print(":right: ");
//   Serial.println(iSwitchRight);
}


void SwitchLeft(bool bFirstRun) {

  if(bFirstRun) {
    iSwitchLeft = 1;
    FastLED.setBrightness(BRIGHTNESS);
  }
  
  switch(iSwitchLeft) {
    case 1:
          if(iDarknessDelay>0) {
           arPalette[0] = paletteRedOrangeRed;
           arPalette[1] = CloudColors_p;
           arPalette[2] = paletteGrayLightSlateGray;
           ledBrightness[0] = 100;
           ledBrightness[1] = 255;
           ledBrightness[2] = 100;
          }
          else {
           arPalette[0] = paletteBlack;
           arPalette[1] = CloudColors_p;
           arPalette[2] = paletteBlack;
           ledBrightness[0] = 100;
           ledBrightness[1] = 255;
           ledBrightness[2] = 100;
          }
    break;
    case 2:          
         if(iDarknessDelay>0) {
          arPalette[0] = LavaColors_p;
          arPalette[1] = CloudColors_p;
          arPalette[2] = OceanColors_p;
           ledBrightness[0] = 100;
           ledBrightness[1] = 50;
           ledBrightness[2] = 100;
          }
          else {
           arPalette[0] = paletteBlack;
           arPalette[1] = LavaColors_p;
           arPalette[2] = paletteBlack;
           ledBrightness[0] = 100;
           ledBrightness[1] = 75;
           ledBrightness[2] = 100;
          }
    break;
    case 3:
         if(iDarknessDelay>0) {
          arPalette[0] = paletteLawnGreenLightGreen;
          arPalette[1] = paletteGrayLightSlateGray;
          arPalette[2] = CloudColors_p;
           ledBrightness[0] = 100;
           ledBrightness[1] = 255;
           ledBrightness[2] = 100;
          }
          else {
           arPalette[0] = paletteBlack;
           arPalette[1] = LavaColors_p;
           arPalette[2] = paletteBlack;
           ledBrightness[0] = 100;
           ledBrightness[1] = 75;
           ledBrightness[2] = 100;
          }
    break;
    default:
     ChangePalettePeriodically(bFirstRun);
    break;
    }
}

void SwitchRight(bool bFirstRun) {
  //if(bFirstRun) {Timer1.attachInterrupt(ResetBrightness);}
  
  switch(iSwitchRight) {
    case 1:
     //FastLED.setBrightness(BRIGHTNESS-(BRIGHTNESS*roAve()));
     if(roAve()>0.9) {
       if(!bMemIsDark) {
        //Timer1.attachInterrupt(ResetBrightness);
       }
       bMemIsDark = 1;
     }
     else {
       FastLED.setBrightness(BRIGHTNESS);
       iDarknessDelay = HighlightByDistanceShort;
       bMemIsDark = 0;
     }
    break;
    case 2:
     if(roAve()>0.9) {
       if(!bMemIsDark) {
       //Timer1.attachInterrupt(ResetBrightness);
       }
       bMemIsDark = 1;
     }
     else {
       FastLED.setBrightness(BRIGHTNESS);
       iDarknessDelay = HighlightByDistanceLong;
       bMemIsDark = 0;
     }
    break;
    case 3:
    
     FastLED.setBrightness(BRIGHTNESS);
    break;
    default:
     FastLED.setBrightness(BRIGHTNESS);
    break;
    }
}



