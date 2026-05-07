#define sensorPin D5     // Soil moisture sensor connected to D5
#define relaypin D4

int threshold = 600;     // Adjust this based on testing: dry > threshold, wet <= threshold
int sensorValue;

void setup() {
  Serial.begin(9600);           // For debugging
  pinMode(sensorPin, INPUT);    // Soil sensor
  pinMode(relayPin, OUTPUT);    // Relay control
  digitalWrite(relayPin, HIGH); // Initially turn OFF pump (HIGH = OFF for active LOW relay)
}

void loop() {
  sensorValue = analogRead(sensorPin); // Read soil moisture
  Serial.print("Soil Moisture: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    // Soil is dry → Turn ON pump
    digitalWrite(relayPin, LOW);  // LOW = relay ON
    Serial.println("Soil is dry → Pump ON");
  } else {
    // Soil is wet → Turn OFF pump
    digitalWrite(relayPin, HIGH); // HIGH = relay OFF
    Serial.println("Soil is wet → Pump OFF");
  }

  delay(5000); // Wait 5 seconds before next read
}