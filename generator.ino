  /*
 * Generator
 * 
 * by Turril0x
 * 
 * 13/08/2020
 * 
 * 
 * System that automatically starts and stop a gasoline generator.
 */

//Pin definitions.

//Inputs
#define gasEmpty 1 //Gasoline empty level sensor.
#define oilLevel 2 //Oil level warning sensor.
#define voltDetector 3 //Voltage detector.
#define airClosed 4 //Closed air intake endstop.
#define airOpened 5 //Opened air intake endstop.
#define startBtn 6 //Start button.
#define stopBtn 7 //Stop button.

//Analog inputs
#define temp A0 //Thermistor input.

//Outputs
#define contactor 8 //Contactor relay for current output.
#define contact 9 //Contact Relay.
#define startEngine 10 //Stert engine relay.
#define errorLED 13 //Error light.
#define gasEmptyLED 11 //Gasoline empty level light.
#define oilLevelLED A1 //Oil level warning light.
#define airErrorLED A2
#define airMotorOpen A3 //Air intake open relay.
#define airMotorClose A4 //Air intake close relay.
#define readyLED A5

//States
int currState;
//#define INIT 0
//#define CHECK 1
#define IDLE 2
#define IGNITE 3
#define WORKING 4
#define STOP 5
#define ERROR -1
bool errorFlag = false;
bool airError = false;

#define airTimeout 5000
#define igniteAtempts 5
#define currentCheckWait 10000

void setup() {
	pinMode(gasEmpty, INPUT);
	pinMode(oilLevel, INPUT);
	pinMode(voltDetector, INPUT);
	pinMode(airClosed, INPUT);
	pinMode(airOpened, INPUT);
	pinMode(startBtn, INPUT);
	pinMode(stopBtn, INPUT);
	pinMode(temp, INPUT);
	pinMode(contactor, OUTPUT);
	pinMode(contact, OUTPUT);
	pinMode(startEngine, OUTPUT);
	pinMode(errorLED, OUTPUT);
	pinMode(gasEmptyLED, OUTPUT);
	pinMode(airMotorClose, OUTPUT);
	pinMode(airMotorOpen, OUTPUT);
  pinMode(readyLED, OUTPUT);
	currState = 1; //Stores current state.
  openAir();
  closeAir();
  check();
  digitalWrite(readyLED, HIGH);
} 


void loop() {
  switch (currState) {
    case 2:
    	idle();
    	break;
    case 3:
    	ignite();
    	break;
    case 4:
    	working();
    	break;
    case 5:
    	stop();
    	break;
  }
}

void check () {
  if (digitalRead(gasEmpty) == HIGH && digitalRead(oilLevel) == HIGH) {
    error();
  }
}

void idle () {
  while (digitalRead(startBtn) == LOW) {
    //wait
  }
  currState = IGNITE;
}

void ignite () {

  currState = WORKING;
} 

void working () {
  while (digitalRead(stopBtn) == LOW) {
    check();
  }
}

void stop () {

   currState = IDLE;
}

void error () {
	digitalWrite(errorLED, HIGH);
	digitalWrite(gasEmptyLED, digitalRead(gasEmpty));
	digitalWrite(oilLevelLED, digitalRead(oilLevel));
	if (airError) {
		digitalWrite(airErrorLED, HIGH);
	}
	exit(0);
}

void closeAir () {
  unsigned long ct = millis();
  while (digitalRead(airClosed) == LOW && millis() < ct + airTimeout) {
    digitalWrite(airMotorClose, HIGH);
  }
  digitalWrite(airMotorClose, LOW);
  if (millis() >= ct + airTimeout) {
    airError = true;
    error();
  }
}

void openAir (){
  unsigned long ct = millis();
  while (digitalRead(airOpened) == LOW && millis() < ct + airTimeout) {
    digitalWrite(A3, HIGH);
  }
  digitalWrite(airMotorOpen, LOW);
  if (millis() >= ct + airTimeout) {
    airError = true;
    error();
  }
}
