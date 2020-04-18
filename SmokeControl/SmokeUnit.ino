void AdjustServos() {
//    SmokeSteering.speed(getPotValue(SMOKE_STEERING_POT_PIN));
//    SmokeThrottle.speed(getPotValue(SMOKE_THROTTLE_POT_PIN));
//    SmokeChannel3.speed(getPotValue(SMOKE_CHANNEL3_POT_PIN));
}

int getPotValue(int pin) {
  int val = analogRead(pin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1000, 2000);     // scale it to use it with the servo (value between 0 and 180)
  return val;
}


