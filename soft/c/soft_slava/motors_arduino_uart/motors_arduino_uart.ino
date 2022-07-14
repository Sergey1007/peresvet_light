#define frequency 2000
#define STEP_PIN1 2
#define DIR_PIN1 3
#define STEP_PIN2 4
#define DIR_PIN2 5 
#define ms1_1mot_pin 8
#define ms1_2mot_pin 9


#define ms1_for_first 1
#define ms1_for_second 1

/*
void rmotor (int motor,int steps,int dir)            //функция не работает
{
 int DIR_PIN,STEP_PIN; 
     switch(motor) 
     {
      case 1: 
        DIR_PIN=STEP_PIN1;
        STEP_PIN=DIR_PIN1;
        break;
      case 2:
        DIR_PIN=STEP_PIN2;
        STEP_PIN=DIR_PIN2;
        break;
     }
 digitalWrite(DIR_PIN,dir);
 for (int i=0;i<4*steps;i++) {
  digitalWrite(STEP_PIN,HIGH);
  delayMicroseconds(frequency);
  digitalWrite(STEP_PIN,LOW);
  }
  
}

*/


void setup() {
  // put your setup code here, to run once:
Serial.begin(1000000);
pinMode(STEP_PIN1,OUTPUT);
pinMode(DIR_PIN1,OUTPUT);
pinMode(STEP_PIN2,OUTPUT);
pinMode(DIR_PIN2,OUTPUT);

  pinMode(ms1_1mot_pin,OUTPUT);
  digitalWrite(ms1_1mot_pin,HIGH);


  pinMode(ms1_2mot_pin,OUTPUT);
  digitalWrite(ms1_2mot_pin,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
int a[6]={0};
int i=0;
while (Serial.available() > 0) {
 for (i=0;i<6;i++)
 {a[i]=Serial.parseInt(); }
 Serial. read();
 for (i=0;i<6;i++)
 {Serial.println(a[i]);}
  }

//rmotor(2,200,0);
/*
if (a[0]==1){                    //code for one motor
digitalWrite(DIR_PIN1,a[2]);
 for (int i=0;i<a[1];i++) {
  digitalWrite(STEP_PIN1,HIGH);
  delayMicroseconds(frequency);
  digitalWrite(STEP_PIN1,LOW);
  }}

if (a[0]==2){
digitalWrite(DIR_PIN2,a[2]);
 for (int i=0;i<a[1];i++) {
  digitalWrite(STEP_PIN2,HIGH);
  delayMicroseconds(frequency);
  digitalWrite(STEP_PIN2,LOW);
  }}
 */
 
digitalWrite(DIR_PIN1,a[2]);       //code for two motors
digitalWrite(DIR_PIN2,a[5]);
while (a[1]>0||a[4]>0)
{
  if (a[1]>0) digitalWrite(STEP_PIN1,HIGH);
  if (a[4]>0) digitalWrite(STEP_PIN2,HIGH);
  delayMicroseconds(frequency);
  digitalWrite(STEP_PIN1,LOW);
  digitalWrite(STEP_PIN2,LOW);
  a[1]--;
  a[4]--;
}

delay(100);



}
