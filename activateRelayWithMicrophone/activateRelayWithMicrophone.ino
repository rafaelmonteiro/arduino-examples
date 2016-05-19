//Setting variables
int microphone = 10;
int relay = 9;
int clapCounter = 0;
int requiredClaps = 2;
unsigned long maxSoundDelay = 1000;
unsigned long minSoundDelay = 300;
unsigned long soundwaveLength = 100;
unsigned long time;
unsigned long startTime = 0;
boolean lightState = false;

void setup() {                
  pinMode(microphone, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH); // turn off relay (HIGH=off/LOW=on)
}

void loop() {
  //start counting
  time = millis();
  //measure delay between initial pulse and next one
  unsigned long delayAfterClap = time - startTime;

  //check if soundwave length is equal or higher than 100ms and if mic was triggered
  if (delayAfterClap >= soundwaveLength && digitalRead(microphone) == HIGH) {
    
    //check if listened pulse respects the defined interval 
    if (delayAfterClap < minSoundDelay || delayAfterClap > maxSoundDelay) {
      clapCounter = 0;
    } else {
      clapCounter ++;
    }
    startTime = millis();

    if(clapCounter == requiredClaps-1){
        if(!lightState){
          lightState = true;
          digitalWrite(relay, LOW);
        } else {
          lightState = false;
          digitalWrite(relay, HIGH);
        }
        clapCounter = 0;
    }
  }
}
