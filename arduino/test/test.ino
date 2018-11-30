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
//  int x = atoi(xcoord);
//  int y = atoi(ycoord);
//
//
//  // Compare x and y coordinates against coordinates of desired spot(s)
//  int spotX = 225;
//  int spotY = -147;
//
//  int xDiff = abs(spotX - x);
//  int yDiff = abs(spotY - y);
//
//  // Check that the bounding box is within tolerance range
//  if(xDiff < 10 && yDiff < 10) {
//    Serial.println("~~~~~ SPOT 1 IS FULL ~~~~~");
//  }
  
  //String category = tok;
  //Process p;
  //String command = "curl -H \"Content-Type: application/json\" -X POST -d '{ \"id\" : 100 , \"isFull\" : true , \"topcateg\" : \"" + category + "\"}' http://192.168.43.24:5000/spots";
  //p.runShellCommand(command);
  //while (p.running());
  //delay(5000);

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
