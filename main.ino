#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <Servo.h>

RH_ASK driver;
Servo dish;

const int servoPin = 9;
const int uplinkLEDPin = 3;
const int downlinkLEDPin = 6;

String currentCommand = "";

void setup()
{
    Serial.begin(9600);	  // Debugging only
    while (!Serial); // Wait for Serial to be ready
    if (!driver.init())
    {  
      Serial.println("init failed");
      while(1);
    }
    Serial.println("TX/RX ready!");

    dish.attach(servoPin);
    dish.write(90);  // Start at center (0°)

    pinMode(uplinkLEDPin, OUTPUT);
    pinMode(downlinkLEDPin, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {
    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toLowerCase();
    if (command == "uplink" || command == "downlink")
    {
      currentCommand = command;
      Serial.print("Switched to: ");
      Serial.println(currentCommand);
    }
    else
    {
      Serial.println("Unrecognized command");
    }
  }

  if (currentCommand == "uplink")
  {
    // transmit data
    //driver.init();
    const char *msg = "Hello World!";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    Serial.println("Data Transmitted!");
    digitalWrite(uplinkLEDPin, HIGH);
    digitalWrite(downlinkLEDPin, LOW);
    digitalWrite(uplinkLEDPin, HIGH);
    digitalWrite(downlinkLEDPin, LOW);
    delay(3000);
  }
  else if (currentCommand == "downlink")
  {
    // listen for data
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen))
    {
      Serial.println("Data Received");
      for (int i = 0; i < buflen; i++)
      {
        Serial.print((char)buf[i]);
      }
      Serial.println();
    }
    else
    {
      Serial.println("No data received!");
    }

    digitalWrite(uplinkLEDPin, LOW);
    digitalWrite(downlinkLEDPin, HIGH);

    // Simulate dish pointing to signal
    for (int angle = 0; angle <= 180; angle += 1) 
    {
      dish.write(angle);   // rotate from 0 to 180
      delay(15);           // smooth movement
    }
    for (int angle = 180; angle >= 0; angle -= 1) 
    {
      dish.write(angle);   // rotate back
      delay(15);
    }
  }
  else
  {
    digitalWrite(uplinkLEDPin, LOW);
    digitalWrite(downlinkLEDPin, LOW);
  }
}