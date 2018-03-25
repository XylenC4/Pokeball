#define roAveCounts 20
float roAveData[roAveCounts];
int roAveAct;

void roAveAdd(float lngValue)
{
  roAveData[roAveAct] = lngValue;
  roAveAct++;
  if(roAveAct>=roAveCounts) {roAveAct=0;}
}

float roAve()
{
  float lngValue;
  for(int x = 0; x < roAveCounts; x++)
  {
   lngValue = lngValue + roAveData[x];
  }
 
  //Serial.print(lngValue, 4);
  //Serial.print("-");
  lngValue = lngValue / (long)roAveCounts;
  //Serial.println(lngValue, 4);
  return lngValue;
}

