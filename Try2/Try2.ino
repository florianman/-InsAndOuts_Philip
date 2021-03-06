

const int LED1=13;
const int LED2=12;
const int LED3=11;//LED pin
const int LED4=10;
const int SENSOR = A0;  //potentiometer middle pin
//int reading = 0; // to track potentiometer reading
int val=0;

void setup() {
  pinMode (LED1, OUTPUT);
  pinMode (LED2,OUTPUT);
  pinMode (LED3,OUTPUT);
  pinMode (LED4,OUTPUT);// initialize LED pin as digital output
  
  pinMode(SENSOR,INPUT);
 // Serial.begin(9600);
  Serial.begin(9600);  // initialize serial communication at 9600 bits per second
}

void loop() {
  val = analogRead(SENSOR);     // reads pot 0 to 1023            
  val /= 4;
  delay(100);
  analogWrite (LED1, val);  
  analogWrite(LED2, val);
  analogWrite (LED3, val);
  analogWrite(LED4, val);// reduces value to match PWM output range 0-255

  Serial.println (val);  // prints to Serial monitor
  Serial.write(val);
}
