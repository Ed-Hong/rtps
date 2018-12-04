#include <Bridge.h>
#include <HttpClient.h>
#include <string.h>
#include <SoftwareSerial.h>

#define LEDPIN 13
#define INLEN 128
char instr[INLEN + 1];

SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);
  Bridge.begin();
  digitalWrite(LEDPIN, HIGH);

  // baud rate MUST be 115200
  mySerial.begin(115200);
  Serial.begin(115200);
  digitalWrite(LEDPIN, LOW);

  // stops the program until Serial Monitor is opened
   while (!Serial) ;
   Serial.println("STARTED SER1");
   digitalWrite(LEDPIN, HIGH);

  // these params will have to change to fit the new DetectionDNN module params
  mySerial.println("setpar serlog None");
  mySerial.println("setpar serout All");
  mySerial.println("setpar serstyle Normal");
  //mySerial.println("setpar netdir spots");
}

void loop()
{ 
  postReset();
  
  byte len = mySerial.readBytesUntil('\n', instr, INLEN);

  instr[len] = 0;
  char * tok = strtok(instr, " \r\n");

  
  // these strcpy()'s seem to be giving trouble - try strncpy() instead
  // could be because the destination buffer size is too small? --- yeah, okay that was the problem.
  
  
  char str[INLEN];  // Serial Output Style - "N2"
  strncpy(str, tok, INLEN);
  Serial.print("tok1: ");
  Serial.println(str);
  //Serial.println(tok);
  
  tok = strtok(0, " \r\n");
  char categ[INLEN];  // Object Class / ID with confidence - "car:50"
  strncpy(categ, tok, INLEN);
  Serial.print("tok2: ");
  Serial.println(categ);
  //Serial.println(tok);
  
  tok = strtok(0, " \r\n");
  char xcoord[INLEN];  // Bounding Box x-coordinate
  strncpy(xcoord, tok, INLEN);
  Serial.print("tok3: ");
  Serial.println(xcoord);
  //Serial.println(tok);

  tok = strtok(0, " \r\n");
  char ycoord[INLEN];  // Bounding Box y-coordinate
  strncpy(ycoord, tok, INLEN);
  Serial.print("tok4: ");
  Serial.println(ycoord);
  //Serial.println(tok);
  
  Serial.println("--------------------");

  // Parse x and y coordinates
  int x = atoi(xcoord);
  int y = atoi(ycoord);


  // Compare x and y coordinates against coordinates of desired spot(s)
  isSpotFull(x,y);
  
  //String category = tok;
  //Process p;
  //String command = "curl -H \"Content-Type: application/json\" -X POST -d '{ \"id\" : 100 , \"isFull\" : true , \"topcateg\" : \"" + category + "\"}' http://192.168.43.24:5000/spots";
  //p.runShellCommand(command);
  //while (p.running());
  delay(1000);

}

bool isSpotFull(int x, int y) {
  int xcoordsMin[] = {-1000, -500, -150, 400}; 
  int xcoordsMax[] = {-600, -100, 350, 800};

  for(int i = 0; i<sizeof xcoordsMin/sizeof xcoordsMin[0]; i++) {
    int xMin = xcoordsMin[i];
    int xMax = xcoordsMax[i];
    
    // Check that the bounding box is within spot range
    if(xMin <= x && x <= xMax) {
      Serial.println("~~~~~~~~~~~~~~~~~~~~ SPOT IS FULL ~~~~~~~~~~~~~~~~~~~~");
      Serial.print("~~~~~~~~~~~~~~~~~~~~ Number = ");
      char str[16];
      itoa(i, str, 10);
      Serial.println(str);

      postSpot(str);
    }
  }
}

void postSpot(String idStr) {
  Process p;
  String command = "curl -H \"Content-Type: application/json\" -X PUT http://192.168.43.24:5000/spots/" + idStr + "/1";
  p.runShellCommand(command);
  while (p.running());
}

void postReset() {
  Process p;
  String command = "curl -H \"Content-Type: application/json\" -X PUT http://192.168.43.24:5000/spots";
  p.runShellCommand(command);
  while (p.running());
}

// --------------------STATE MACHINE SAMPLE CODE--------------------
//  int state = 0;
//  while (tok)
//  {  
////    Serial.print("tok: ");
////    Serial.println(tok);
//
//
//    // State machine:
//    // 0: start parsing
//    // 1: TO command, parse topcateg
//    // 2: print
//    // 1000: unknown command
//    switch (state)
//    {
//      case 0:
//        if (strcmp(tok, "TO") == 0) state = 1;
//        if (strcmp(tok, "NO") == 0) state = 1;
//        if (strcmp(tok, "DO") == 0) state = 1;
//        if (strcmp(tok, "FO") == 0) state = 1;
//        else state = 1000;
//        break;
//        
//      case 1: topCateg = tok; state = 2; break;
//      default: break; // Skip any additional tokens
//    }
//    tok = strtok(0, " \r\n");
//  }
//  
//  if (state == 2)
//  {
//    Serial.print("topCateg: ");
//    Serial.println(topCateg);
//  }
