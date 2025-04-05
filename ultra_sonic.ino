#define TRIG_PIN D1   // GPIO5
#define ECHO_PIN D2   // GPIO4
#define LED_PIN  D5   // GPIO14

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Send a 10us pulse to trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance (in cm)
  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if object is within 20 cm
  if (distance > 0 && distance <= 20) {
    digitalWrite(LED_PIN, HIGH);
    Serial.print("Object dectected at ");
    Serial.print(distance);
    Serial.print(" cm\n");
    // Turn on LED
  } else {
    digitalWrite(LED_PIN, LOW);  // Turn off LED
  }

  delay(200); // Small delay between measurements
}
