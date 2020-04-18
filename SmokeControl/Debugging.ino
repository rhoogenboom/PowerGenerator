void PrintDebugInfo() {
  PrintPotValues();
  Serial.println(F("--------"));
}

void PrintPotValues() {
  PrintSteering();
  PrintThrottle();
  PrintChannel3();
}

void PrintPotValue(String pot, int potPin) {
  Serial.print(pot);
  Serial.println(getPotValue(potPin));
}

void PrintThrottle() {
  PrintPotValue(F("Throttle: "), 1);
}

void PrintSteering() {
  PrintPotValue(F("Steering: "), 0);
}

void PrintChannel3() {
  PrintPotValue(F("Channel3: "), 2);
}

