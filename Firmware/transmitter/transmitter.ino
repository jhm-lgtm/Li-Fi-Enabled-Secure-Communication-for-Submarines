/*
  Li-Fi Enabled Secure Communication for Submarines
  Transmitter Unit

  Hardware:
  Arduino UNO
  LED connected to Pin 9

  Function:
  Converts text message into optical signals using LED ON/OFF switching.
*/

#define LED_PIN 9

String message = "SUBMARINE SECURE LINK";

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  Serial.println("Li-Fi Transmitter Started");
}

void loop() {

  Serial.println("Sending Message:");

  for (int i = 0; i < message.length(); i++) {

    char data = message[i];

    sendByte(data);

    delay(100);
  }

  // End transmission signal
  sendByte('#');

  delay(3000);
}


// Convert character into binary and transmit using LED

void sendByte(char data) {

  for (int bit = 7; bit >= 0; bit--) {

    int bitValue = bitRead(data, bit);

    if (bitValue == 1) {
      digitalWrite(LED_PIN, HIGH);
    }
    else {
      digitalWrite(LED_PIN, LOW);
    }

    delay(50);
  }

  digitalWrite(LED_PIN, LOW);
}
