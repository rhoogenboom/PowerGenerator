#include <OSL_SimpleTimer.h>
#include <JC_Button.h>
#include <ESC.h>
#include <Servo.h>
#include "defines.h"
#include "variables.h"
#include <PinChangeInterrupt.h>

// v1 - initial control of smoke unit


void setup() {
  //initialize boot vars
  Serial.begin(9600);
  Serial.println(F("Setting up"));

  //initialize pins
  pinMode(SMOKE_STEERING_POT_PIN, INPUT);
  pinMode(SMOKE_THROTTLE_POT_PIN, INPUT);
  pinMode(SMOKE_CHANNEL3_POT_PIN, INPUT);

  //buttons
  powerButton.begin();

  //handler for next audio track
  attachInterrupt(digitalPinToInterrupt(PLAYER_BUSY_PIN), SetPlayerFree, RISING);

  //initialize audio items
  

  delay(2500);
  
  //connect ESCs
  SmokeSteering.arm();
  SmokeThrottle.arm();
  SmokeChannel3.arm();
  //timer.setInterval(SERVO_ADJUSTMENT_INTERVAL, AdjustServos);

  onOffCommand = POWER_IS_OFF;

  //debug timer
  //timer.setInterval(DEBUG_PRINT_INTERVAL, PrintDebugInfo);

  delay(2500);
  
  Serial.println(F("Setup done"));
}

void loop() {
  if (startup) {
    Serial.println(F("Startup loop entering"));

    Serial.println(F("Setting volume"));
    setVolume(15);

    PlayInitializedBeep();
    delay(2500);
    StartEngine();

//    SmokeSteering.speed(2000);
//    SmokeThrottle.speed(2000);
//    SmokeChannel3.speed(2000);  
    startup = false;
    Serial.println(F("Startup loop completed"));
  }
  powerButton.read();
  HandleOnOffButton();

  timer.run();

}
