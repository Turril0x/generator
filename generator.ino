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
#define contactor 8 //Contactor relay.
#define contact 9 //Contact Relay.
#define startEngine 10 //Stert engine relay.
#define errorLED 11 //Error light.
#define gasWarningLED 12 //Gasoline warning level light.
#define gasEmptyLED 13 //Gasoline empty level light.
#define oilLevelLED A1 //Oil level warning light.
#define airMotorClose A2 //Air intake close relay.
#define airMotorOpen A3 //Air intake open relay.

//States
#define INIT 0
#define CHECK 1
#define IDLE 2
#define IGNITE 3
#define WORKING 4
#define STOP 5

//Error states
#define stdError -1
#define gasError -2
#define oilError -3
#define igniteError -4
#define indetError -5

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
	pinMode(gasWarningLED, OUTPUT);
	pinMode(gasEmptyLED, OUTPUT);
	pinMode(airMotorClose, OUTPUT);
	pinMode(airMotorOpen, OUTPUT);
  int currState = 0; //Stores current state.
  openAir();
} 


void loop() {
  // put your main code here, to run repeatedly:
  
}
