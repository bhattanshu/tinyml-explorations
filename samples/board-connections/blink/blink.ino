const int LED_PIN = LED_BUILTIN;  // Use built-in LED

void setup() {
    pinMode(LED_PIN, OUTPUT);  // Initialize LED pin as output
}

void loop() {
    digitalWrite(LED_PIN, HIGH);  // Turn LED on
    delay(1000);                  // Wait for 1 second
    digitalWrite(LED_PIN, LOW);   // Turn LED off
    delay(1000);                  // Wait for 1 second
}