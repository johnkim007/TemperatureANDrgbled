void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor = analogRead(A0);
  float volt = (sensor / 1024.0) *5.0;
  float temp = (volt - 0.5) *100;

  Serial.print("Sensor Value: ");
  Serial.print(sensor);
  Serial.print(", ");
  Serial.print("Volts: ");
  Serial.print(volt);
  Serial.print(", ");
  Serial.print("Degree C: ");
  Serial.println(temp);
  delay(500);

  if (temp >=30) {  // 코딩 할 때 가장 중요한 것은 괄호 확인
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  } else if(temp >=25 && temp <30) {  // 겹치는 부분이 없도록 반드시 정확한 조건을 주어야 함
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
  } else if( temp < 25) {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
  } 
}
