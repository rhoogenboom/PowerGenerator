#define EngineVersion 4

#define EngineStartFolder 1
#define EngineLowFolder 2
#define EngineUpFolder 3
#define EngineHighFolder 4
#define EngineDownFolder 5
#define EngineStopFolder 6
#define InitializedBeep 7

#define WarningBeepTrackNumber 1

void StartPlayingWarningBeep() {
  if (!crusherIsMoving) {
    StartPlayingIntercut(WarningBeepTrackNumber);
  }
}

void StopPlayingWarningBeep() {
  if (crusherIsMoving) {
    StopPlayingIntercut();
  }
}

void PlayInitializedBeep() {
  PlayFolderTrack(InitializedBeep, EngineVersion);
}

void StartEngine() {
  if (!engineIsRunning) {
    engineIsRunningHigh = false;
    engineIsRunning = true;

    //Play startup
    PlayFolderTrack(EngineStartFolder, EngineVersion);
    //always wait 1 sec to allow the player to start playing

    //Wait till ready / delay Xms
    wait(1);//wait(500);

    //Start loop engine low
    RepeatPlaybackFolder(EngineLowFolder);
  }
}

void EngineUp() {
//  StartQuickRedBlink();  
  SmokeOn();
  //Play rev up
  PlayFolderTrack(EngineUpFolder, EngineVersion);
  //Wait till ready / delay Xms
  wait(1);//wait(1500);

  //Start loop engine high
  RepeatPlaybackFolder(EngineHighFolder);
//  StopSlowGreenBlink();
  engineIsRunningHigh = true;
}

void EngineDown() {
//  StartSlowGreenBlink();  
  //Play rev down
  PlayFolderTrack(EngineDownFolder, EngineVersion);

  //Wait till ready / delay Xms
  wait(1);//wait(2500);

  //Start loop engine low
  RepeatPlaybackFolder(EngineLowFolder);
//  StopQuickRedBlink();
  engineIsRunningHigh = false;
  SmokeOff();
}

void StopEngine() {
  if (engineIsRunning) {
    //check if engine is high
    if (engineIsRunningHigh) {
      EngineDown();
    }
    //Play engine stop
    PlayFolderTrack(EngineStopFolder, EngineVersion);
    wait(1);//wait(1500);
    engineIsRunning = false;
  }
}

bool PlaySequence(int sequenceLength, int sequence[5]) {
  for (int i = 0; i < sequenceLength; i++) {
    //Play sequence item

    //Play folder sequence[i];

    //Wait till ready / delay Xms

  }
  return true;
}

bool PlaySequenceAndLoop(int sequenceLength, int sequence[5]) {
  for (int i = 0; i < sequenceLength - 1; i++) {
    //Play sequence item

    //Play folder sequence[i];

    //Wait till ready / delay Xms
  }
  //PlayLoop last item from sequence

  return true;
}


