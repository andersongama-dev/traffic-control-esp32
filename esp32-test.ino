int ledRed = 2;
int ledYellow = 4;
int ledGreen = 5;
int buttonPed = 18;

int currentStatus = HIGH;
int previousState = HIGH;

bool padRequest = false;

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buttonPed, INPUT_PULLUP);
  Serial.begin(115200);
}

void checkButton() {
  currentStatus = digitalRead(buttonPed);
  
  if (previousState == HIGH && currentStatus == LOW) {
    padRequest = true;
    Serial.println("Button press");
  }

  previousState = currentStatus;
}

void waitWithCheck(int time) {
  int inteval = 50;

  for(int i = 0; i < time; i += inteval) {
    checkButton();
    delay(inteval);
  }
}

void led() {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  waitWithCheck(5000);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledRed, LOW);
  waitWithCheck(2000);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, HIGH);

  if (padRequest) {
    Serial.println("Pedestre solicitado");
    waitWithCheck(10000);
    padRequest = false;
  } else {
    waitWithCheck(5000);
  }
}

void loop() {
  led();
}