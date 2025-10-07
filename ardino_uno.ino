#define MQ135_PIN A0         // Analog input from smoke sensor
#define LED_POSITIVE 6       // LED Anode (PWM pin)
#define LED_NEGATIVE 7       // LED Cathode (acts as GND)
#define BUZZER_PIN 5         // Passive Buzzer +ve pin

void setup() {
  pinMode(LED_POSITIVE, OUTPUT); // Set LED anode pin as output
  pinMode(LED_NEGATIVE, OUTPUT); // Set LED cathode pin as output (used as GND)
  pinMode(BUZZER_PIN, OUTPUT); // Set buzzer pin as output
  Serial.begin(9600); // Optional: Monitor sensor value // Start serial communication to monitor smoke level
}

void loop() {
  int smokeLevel = analogRead(MQ135_PIN); // Read analog value from smoke sensor
  Serial.print("Smoke Level: ");
  Serial.println(smokeLevel); // Print value to Serial Monitor

  if (smokeLevel > 50) { // If smoke level crosses the threshold
    analogWrite(LED_POSITIVE, 30);     // LED ON (dim for safety)   //analogWrite()	Output PWM (for dimming LED / soft buzzer)
    digitalWrite(LED_NEGATIVE, LOW);   // Virtual GND, Simulate GND using pin D7  //digitalWrite()	Output HIGH/LOW (used here for virtual GND)
    analogWrite(BUZZER_PIN, 40);       // Buzzer ON (low volume)
  } else {
    analogWrite(LED_POSITIVE, 0);      // LED OFF
    analogWrite(BUZZER_PIN, 0);        // Buzzer OFF
  }

  delay(1000); // Read every 1 second
}
