const int sensorPinX = A1; // x axis
const int sensorPinY = A3; // y axis
const int buttonPin1 = 2; //clear button
const int buttonPin2 = 4; // color change button

unsigned long targetTime = 0;
const unsigned long interval = 100;

int buttonState1 = 0;
int buttonState2 = 0;

int x = 0;
int y = 0;

void setup() {
  // initialize inputs   
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  
  pinMode(sensorPinX, INPUT);
  pinMode(sensorPinY, INPUT);
  
  Serial.begin(115200);
}

void loop() {
  if (millis() >= targetTime) {

    int buttonState1 = digitalRead(buttonPin1);
    int buttonState2 = digitalRead(buttonPin2);

    if (buttonState2 == HIGH) {
      Serial.println(String("cch"));
    }

    if (buttonState1 == HIGH) { //If button is pressed, reset
      Serial.println(String("rst"));
      x = 0;
      y = 0;
    } 
    else {
      int x_axis = analogRead(sensorPinX);
      int y_axis = analogRead(sensorPinY);
      
      if (x_axis= x or y_axis != y) {
        x = x_axis;
        y = y_axis;
        
        String data = String(x_axis) + String(",") + String(y_axis);
        Serial.println(data);

        targetTime = millis() + interval;
      }
    }

  }
}
