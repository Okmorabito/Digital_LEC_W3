bool buttonState1 = LOW;
bool lastButtonState1 = HIGH;
bool buttonState2 = LOW;
bool lastButtonState2 = HIGH;
bool buttonState3 = LOW;
bool lastButtonState3 = HIGH;
int buttonPin1 = 34;
int buttonPin2 = 33;
int buttonPin3 = 35;
int buttonPin4 = 36;
int potVal = 0;
int mappedPotVal = 0;
int lastPotVal = 0;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin4) == LOW) {
    lastPotVal = mappedPotVal;
    potVal = analogRead(A13);
    mappedPotVal = map(potVal, 0, 1023, 0, 10);

    if (mappedPotVal != lastPotVal) {
      delay(100);
      Serial.println(mappedPotVal);
    }

    lastButtonState1 = buttonState1;
    lastButtonState2 = buttonState2;
    lastButtonState3 = buttonState3;
    buttonState1 = digitalRead(buttonPin1);
    if (lastButtonState1 == LOW and buttonState1 == HIGH) {
      usbMIDI.sendNoteOn(56, 127, 1);
      delay(5);
    } else if (lastButtonState1 == HIGH and buttonState1 == LOW) {
      usbMIDI.sendNoteOff(56, 0, 1);
      delay(5);
    }
    buttonState2 = digitalRead(buttonPin2);
    if (lastButtonState2 == LOW and buttonState2 == HIGH) {
      usbMIDI.sendNoteOn(60, 127, 1);
      delay(5);
    } else if (lastButtonState2 == HIGH and buttonState2 == LOW) {
      usbMIDI.sendNoteOff(60, 0, 1);
      delay(5);
    }
    buttonState3 = digitalRead(buttonPin3);
    if (lastButtonState3 == LOW and buttonState3 == HIGH) {
      usbMIDI.sendNoteOn(63, 127, 1);
      delay(5);
    } else if (lastButtonState3 == HIGH and buttonState3 == LOW) {
      usbMIDI.sendNoteOff(63, 0, 1);
      delay(5);
    }
  }
  if (digitalRead(buttonPin4) == HIGH) {
    lastButtonState1 = buttonState1;
    lastButtonState2 = buttonState2;
    lastButtonState3 = buttonState3;
    buttonState1 = digitalRead(buttonPin1);
    lastPotVal = mappedPotVal;
    potVal = analogRead(A13);
    mappedPotVal = map(potVal, 0, 1023, 0, 10);

    if (mappedPotVal != lastPotVal) {
      delay(100);
      Serial.println(mappedPotVal);
    }
    if (lastButtonState1 == LOW and buttonState1 == HIGH) {
      usbMIDI.sendNoteOn(68, 127, 1);
      delay(5);
    } else if (lastButtonState1 == HIGH and buttonState1 == LOW) {
      usbMIDI.sendNoteOff(68, 0, 1);
      delay(5);
    }
    buttonState2 = digitalRead(buttonPin2);
    if (lastButtonState2 == LOW and buttonState2 == HIGH) {
      usbMIDI.sendNoteOn(72, 127, 1);
      delay(5);
    } else if (lastButtonState2 == HIGH and buttonState2 == LOW) {
      usbMIDI.sendNoteOff(72, 0, 1);
      delay(5);
    }
    buttonState3 = digitalRead(buttonPin3);
    if (lastButtonState3 == LOW and buttonState3 == HIGH) {
      usbMIDI.sendNoteOn(75, 127, 1);
      delay(5);
    } else if (lastButtonState3 == HIGH and buttonState3 == LOW) {
      usbMIDI.sendNoteOff(75, 0, 1);
      delay(5);
    }
  }
}