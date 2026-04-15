int ledRed = 2;
int ledYellow = 18;
int ledGreen = 5;

void setup() {
  //pinMode(ledPin, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void led() {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  delay(5000);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledRed, LOW);
  delay(2000);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, HIGH);
  delay(5000);
}

void loop() {
  led();
}