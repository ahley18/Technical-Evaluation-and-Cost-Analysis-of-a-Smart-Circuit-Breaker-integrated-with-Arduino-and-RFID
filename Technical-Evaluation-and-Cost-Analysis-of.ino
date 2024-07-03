#include <PZEM004Tv30.h>
#include <Wire.h>

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         5         // Configurable, see typical pin layout above
#define SS_PIN          53        // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

#include <SoftwareSerial.h>

#define rxPin 19
#define txPin 18

SoftwareSerial sim800(rxPin, txPin);


String rfidUID;  // Variable to store the UID

// Define your card UIDs
String card1 = "49F49D79";
String card2 = "59EC4A79";
String card3 = "6981E279";
String card4 = "39E9BA79";

int stat1;
int stat2;
int stat3;
int stat4;

int stat1a;
int stat2a;
int stat3a;
int stat4a;

//branch 1
int cb1a = 22;
int cb1b = 24;

//branch 2
int cb2a = 26;
int cb2b = 28;

//branch 3
int cb3a = 34;
int cb3b = 30;

int d1 = 4;
int d2 = 6;
int d3 = 3;

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  sim800.begin(9600);
  SPI.begin();          // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  delay(5000);
  Serial.println("Scan an RFID card...");
  Serial.println(stat1);
  Serial.println(stat2);
  Serial.println(stat3);
  Serial.println(stat4);
  pinMode(cb1a, OUTPUT);
  pinMode(cb1b, OUTPUT);
  pinMode(cb2a, OUTPUT);
  pinMode(cb2b, OUTPUT);
  pinMode(cb3a, OUTPUT);
  pinMode(cb3b, OUTPUT);
  

  pinMode(d1, INPUT_PULLUP);
  pinMode(d2, INPUT_PULLUP);
  pinMode(d3, INPUT_PULLUP);
  
  digitalWrite(cb1a,0);
  digitalWrite(cb2a,0);
  digitalWrite(cb3a,0);

  digitalWrite(cb1b,0);
  digitalWrite(cb2b,0);
  digitalWrite(cb3b,0);

}

//sms
void branch1_on_sms(){
  sim800.println("AT");
    delay(250);
    Serial.println("SIM800L is ready");
    sim800.println("AT+CMGF=1");
    delay(250);
    sim800.println("AT+CMGS=\"+639915160805\"");
    delay(250);
    sim800.print("RFID 2 Detected\nBRANCH 1 Status: ON");
    sim800.write(0x1A);
    delay(1000);
    Serial.println("Message sent");
    delay(5000);
}

void branch2_on_sms(){
  sim800.println("AT");
    delay(250);
    Serial.println("SIM800L is ready");
    sim800.println("AT+CMGF=1");
    delay(250);
    sim800.println("AT+CMGS=\"+639915160805\"");
    delay(250);
    sim800.print("RFID 3 Detected\nBRANCH 2 Status: ON");
    sim800.write(0x1A);
    delay(1000);
    Serial.println("Message sent");
    delay(5000);
}

void branch3_on_sms(){
  sim800.println("AT");
    delay(250);
    Serial.println("SIM800L is ready");
    sim800.println("AT+CMGF=1");
    delay(250);
    sim800.println("AT+CMGS=\"+639915160805\"");
    delay(250);
    sim800.print("RFID 4 Detected\nBRANCH 3 Status: ON");
    sim800.write(0x1A);
    delay(1000);
    Serial.println("Message sent");
    delay(5000);
}

void branch1_off_sms(){
  sim800.println("AT");
    delay(250);
    Serial.println("SIM800L is ready");
    sim800.println("AT+CMGF=1");
    delay(250);
    sim800.println("AT+CMGS=\"+639915160805\"");
    delay(250);
    sim800.print("RFID 2 Detected\nBRANCH 1 Status: OFF");
    sim800.write(0x1A);
    delay(1000);
    Serial.println("Message sent");
    delay(5000);
}

void branch2_off_sms(){
  sim800.println("AT");
    delay(250);
    Serial.println("SIM800L is ready");
    sim800.println("AT+CMGF=1");
    delay(250);
    sim800.println("AT+CMGS=\"+639915160805\"");
    delay(250);
    sim800.print("RFID 3 Detected\nBRANCH 2 Status: OFF");
    sim800.write(0x1A);
    delay(1000);
    Serial.println("Message sent");
    delay(5000);
}

void branch3_off_sms(){
  sim800.println("AT");
    delay(250);
    Serial.println("SIM800L is ready");
    sim800.println("AT+CMGF=1");
    delay(250);
    sim800.println("AT+CMGS=\"+639915160805\"");
    delay(250);
    sim800.print("RFID 4 Detected\nBRANCH 3 Status: OFF");
    sim800.write(0x1A);
    delay(1000);
    Serial.println("Message sent");
    delay(5000);
}

void all_branch_on_sms(){
  sim800.println("AT");
    delay(250);
    Serial.println("SIM800L is ready");
    sim800.println("AT+CMGF=1");
    delay(250);
    sim800.println("AT+CMGS=\"+639915160805\"");
    delay(250);
    sim800.print("RFID 1 Detetected\nBRANCH 1 Status: ON\nBRANCH 2 Status: ON\nBRANCH 3 Status: ON");
    sim800.write(0x1A);
    delay(1000);
    Serial.println("Message sent");    delay(5000);
}

void all_branch_off_sms(){
  sim800.println("AT");
    delay(250);
    Serial.println("SIM800L is ready");
    sim800.println("AT+CMGF=1");
    delay(250);
    sim800.println("AT+CMGS=\"+639915160805\"");
    delay(250);
    sim800.print("RFID 1 Detetected\nBRANCH 1 Status: OFF\nBRANCH 2 Status: OFF\nBRANCH 3 Status: OFF");
    sim800.write(0x1A);
    delay(1000);
    Serial.println("Message sent");
    delay(5000);
}



void allB_on(){

digitalWrite(cb1b,1);
digitalWrite(cb2b,1);
digitalWrite(cb3b,1);
  
}

void allB_off(){
digitalWrite(cb1b,0);
digitalWrite(cb2b,0);
digitalWrite(cb3b,0);
}

void card1_on(){
digitalWrite(cb1b,1);
digitalWrite(cb2b,0);
digitalWrite(cb3b,0);
}

void card1_off(){
digitalWrite(cb1b,1);
}

void loop() {
  int in1 = digitalRead(d1);
  int in2 = digitalRead(d2);
  int in3 = digitalRead(d3);

  if(in1 == HIGH){
    digitalWrite(cb1a, LOW);
  }
  else{
    digitalWrite(cb1a, HIGH);
  }
  
  if(in2 == HIGH){
    digitalWrite(cb2a, LOW);
  }
  else{
    digitalWrite(cb2a, HIGH);
  }
  
  if(in3 == HIGH){
    digitalWrite(cb3a, LOW);
  }
  else{
    digitalWrite(cb3a, HIGH);
  }
  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Read UID and store it in a variable
  rfidUID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    rfidUID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    rfidUID += String(mfrc522.uid.uidByte[i], HEX);
  }
  rfidUID.toUpperCase();  // Convert to uppercase for consistency

  // Print UID to the serial monitor
  Serial.print("UID tag: ");
  Serial.println(rfidUID);

  // Simulate switch-case using a function
  handleCard(rfidUID);

  // Add a delay to avoid reading the same card multiple times quickly
  delay(1000);
  
}

void handleCard(String uid) {
  if (uid == card1) {
    Serial.println("CARD 1");
    Serial.println(card1);
    stat1+=1;
    stat1a = stat1%2;
    Serial.print("Status 1: ");
    Serial.println(stat1a);

    if(stat1a == 0){
      Serial.println("ALL BRANCHES OFF");
      allB_off();
      all_branch_off_sms();
    }
    else{
      Serial.println("ALL BRANCHES ON");
      allB_on();
      all_branch_on_sms();
      
    }
  } 
  
  else if (uid == card2) {
    Serial.println("CARD 2");
    Serial.println(card2);
    stat2+=1;
    stat2a = stat2%2;
    Serial.print("Status 2: ");
    Serial.println(stat2a);

    if(stat2a == 0){
      Serial.println("Branch 1 OFF");
      digitalWrite(cb1b,0);
      branch1_off_sms();
    }
    else{
      Serial.println("Branch 1 ON");
      digitalWrite(cb1b,1);
      branch1_on_sms();
    }
  } 
  
  else if (uid == card3) {
    Serial.println("CARD 3");
    Serial.println(card3);
    stat3+=1;
    stat3a = stat3%2;
    Serial.print("Status 3: ");
    Serial.println(stat3a);

    if(stat3a == 0){
      Serial.println("Branch 2 OFF");
      digitalWrite(cb2b,0);
      branch2_off_sms();
      }
    else{
      Serial.println("Branch 2 ON");
      digitalWrite(cb2b,1);
      branch2_on_sms();
    }
  } 
  
  else if (uid == card4) {
    Serial.println("CARD 4");
    Serial.println(card4);
    stat4+=1;
    stat4a = stat4%2;
    Serial.print("Status 4: ");
    Serial.println(stat4a);

    if(stat4a == 0){
      Serial.println("Branch 3 OFF");
      digitalWrite(cb3b,0);
      branch3_off_sms();
    }
    else{
      Serial.println("Branch 3 ON");
      digitalWrite(cb3b,1);
      branch3_on_sms();
    }
  } 
  
  else {
    Serial.println("Unknown Card");
  }
  delay(100);
}
