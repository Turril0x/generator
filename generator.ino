/*
 * Generador
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
#define gasWarning 0 //Gasoline warning level sensor.
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

void setup() {
	pinMode(gasWarning, INPUT);
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
} 


void loop() {
  // put your main code here, to run repeatedly:
  
}
