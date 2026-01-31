const int LED_PIN = 10;

int number = 0;
int ledcounter = 0;

bool digits[10][8] = {
// a  b  c  d  e  f  g  dp
  {1, 1, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},
  {1, 0, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0, 1, 1, 0},
};

void setup() {
  for (int i = 0; i < 11; ++i) {
    pinMode(i, OUTPUT);
  }

  for (int i = PIN_A0; i <= PIN_A5; ++i) {
    pinMode(i, OUTPUT);
  }
}

void drawNumber() {
  int digit1 = number / 10;
  int digit2 = number % 10;

  for (int i = 0; i < 8; ++i) {
    digitalWrite(i, digits[digit2][i]);
  }

  for (int i = 0; i < 8; ++i) {
    int index = 0;
    if (i < 6) {
      index = PIN_A0 + i;
    } else {
      index = i + 2;
    }

    digitalWrite(index, digits[digit1][i]);
  }
}

void loop() {
  drawNumber();
  number = (number + 1) % 100;

  if (number == 0) {
    ledcounter = 10;
  }

  if (ledcounter != 0) {
    ledcounter -= 1;
    digitalWrite(LED_PIN, ledcounter % 2);
  }
  delay(100);  
}
