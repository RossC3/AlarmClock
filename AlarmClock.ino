
const int buzzer = 9; 
int setButton = 4;
int hButton = 8;
int mButton = 12;
int t;
int d;
bool set = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  pinMode(setButton, INPUT);
  pinMode(hButton, INPUT);
  pinMode(mButton, INPUT);
  Serial.begin(9600);
 
}

void loop() {
//    if(digitalRead(setButton) == HIGH){
//      Serial.println("Pushed");
//      delay(1000);
//    }
  if(millis() >= t + d && set){
    wakeUp();
    set = false;
  }
  if(digitalRead(setButton) == HIGH && set == false){
    Serial.println(digitalRead(setButton));
    delay(1000);
    settingTime();
    set = true;
    d = millis();
  }

  if(set){
    Serial.println("Waiting");
    delay(60000);
  }
  

}

void settingTime(){
  int h = 0;
  int m = 0;
  String Time;
  String hours = "hours: ";
  String mins = " min: ";
  while(digitalRead(setButton)!= HIGH){
    
    if(digitalRead(hButton) == HIGH){
      delay(1000);
      if(h < 24){
         h = h+ 1;
      }else{
        h = 0;
      }
       
    }

    if(digitalRead(mButton) == HIGH){
      delay(1000);
      if(m < 60){
        m = m + 1;
      }else{
        m = 0;
      }
    }

    
    Time = hours + h + mins + m;
    Serial.println(Time);
  }

  t = h *(3600*60000) + m*(60000);
}

void wakeUp(){
  tone(buzzer,1000);
  delay(10000);
  noTone(buzzer);
}
