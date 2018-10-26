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

  mySerial.println("setpar serlog None");
  mySerial.println("setpar serout All");
  mySerial.println("setpar serstyle Terse");
}

void loop()
{ 
  byte len = mySerial.readBytesUntil('\n', instr, INLEN);

  instr[len] = 0;
  char * tok = strtok(instr, " \r\n");
  Serial.print("tok1: ");
  Serial.println(tok);
  
  tok = strtok(0, " \r\n");
  Serial.print("tok2: ");
  Serial.println(tok);

  String category = tok;

  Process p;
  String command = "curl -H \"Content-Type: application/json\" -X POST -d '{ \"id\" : 100 , \"isFull\" : true , \"topcateg\" : \"" + category + "\"}' http://192.168.43.24:5000/spots";
  p.runShellCommand(command);
  while (p.running());
  delay(5000);

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
