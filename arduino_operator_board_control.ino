#include <singleLEDLibrary.h>

sllib lightCone(2);
sllib lightCube(3);
// Unused
sllib lightGround(4);
// Unused
sllib lightPortal(5);
sllib lightTL(6);
sllib lightTM(7);
sllib lightTR(8);
sllib lightML(9);
sllib lightMM(10);
sllib lightMR(11);
sllib lightBL(12);
sllib lightBM(13);
sllib lightBR(14);

sllib allLights[] = {
  lightCone, lightCube, 
  lightTL, lightTM, lightTR, 
  lightML, lightMM, lightMR, 
  lightBL, lightBM, lightBR,
};
sllib coneLights[] = {
  lightCone, 
  lightTL, lightTR, 
  lightML, lightMR, 
  lightBL, lightBR,
};
sllib cubeLights[] = {
  lightCube, 
  lightTM, 
  lightMM, 
  lightBM,
};

void setup() {
 Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) {
    static char message[256];
    static unsigned int message_pos = 0;
    char inByte = Serial.read();

    if (inByte != '\n') {
      message[message_pos] = inByte;
      message_pos++;
    }
    else {
      message_pos = 0;
      // process message
    
      for (sllib light : allLights) light.update();
      // cone
      if (message[0] == '1') {
        for (sllib light : cubeLights) light.setOffSingle();
        for (sllib light : coneLights) light.setOnSingle();
      }
      // cube
      if (message[0] == '0') {
        for (sllib light : cubeLights) light.setOnSingle();
        for (sllib light : coneLights) light.setOffSingle();
      }
   }
 }
}
