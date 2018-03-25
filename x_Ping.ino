long pingSonic(int pingPin, int inPin, int minValue, int maxValue)
{
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  float duration, cm, percent;
  
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH, maxValue*29*2);
  
  //Serial.println(duration, DEC); 
  cm = duration / 29 / 2;

  //Serial.println(cm, DEC); 
  percent = (cm-(float)minValue)/((float)maxValue-(float)minValue);

  if(duration <5 || percent > 1){percent=1;};
  
  //Serial.println(percent,4); 
  
  return percent;
}
