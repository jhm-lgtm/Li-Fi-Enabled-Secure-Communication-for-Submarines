/*
  Li-Fi Enabled Secure Communication for Submarines
  Receiver Unit

  Hardware:
  Arduino UNO
  LDR connected to Analog Pin A0

  Function:
  Detects LED light variations and reconstructs transmitted data.
*/


#define LDR_PIN A0

int threshold = 500;

String receivedMessage = "";

void setup() {

  Serial.begin(9600);

  Serial.println("Li-Fi Receiver Started");

}


void loop() {


  char receivedChar = receiveByte();


  if(receivedChar == '#')
  {
    Serial.println("Received Message:");
    Serial.println(receivedMessage);

    receivedMessage = "";

    delay(2000);
  }

  else
  {
    receivedMessage += receivedChar;
  }

}



// Receive 8 bits from optical signal

char receiveByte()
{

  byte data = 0;


  for(int bit = 7; bit >=0; bit--)
  {

    int lightValue = analogRead(LDR_PIN);


    if(lightValue > threshold)
    {
      bitWrite(data, bit, 1);
    }

    else
    {
      bitWrite(data, bit, 0);
    }


    delay(50);
  }


  return char(data);

}
