/*
  Yún HTTP Client
  
  Example code
  http://www.arduino.cc/en/Tutorial/HttpClient
 */

#include <Bridge.h>
#include <HttpClient.h>

boolean done = false;

void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  SerialUSB.begin(9600);

  while (!SerialUSB); // wait for a serial connection
}


void loop() {
  Process p;
  
  if (p.available() > 0) Serial.println((char)p.read());
  if (Serial.read() == 'C') {
    done = true;  //if you send C it closes the ping command
    p.close();
  }
  delay(10);

  while(!done) {
    String command = "curl -H \"Content-Type: application/json\" -X POST -d '{ \"id\" : 100 , \"isFull\" : true , \"string\" : \"some string parameter\"}' http://192.168.43.24:5000/spots";
    
    p.runShellCommand(command);
  
    while (p.running());
  
    delay(5000);  // wait 10 seconds before you do it again 
  }
}


//void loop() {
//  HttpClient http;
//  http.begin("192.168.43.24:5000/spots");
//  //http.addHeader("Content-Type", "application/json");
//  http.POST("{ \"isFull\": true, \"locationId\": 1, \"lotId\": 1, \"spotId\": 2 }");
//  http.writeToStream(&Serial);
//  http.end();
//}



//void loop() {
//  // Initialize the client library
//  HttpClient client;
//
//  // Make a HTTP request:
//  client.get("192.168.43.24:5000/spots");
//
//  // if there are incoming bytes available
//  // from the server, read them and print them:
//  while (client.available()) {
//    char c = client.read();
//    SerialUSB.print(c);
//  }
//  SerialUSB.flush();
//
//  delay(5000);
//}
