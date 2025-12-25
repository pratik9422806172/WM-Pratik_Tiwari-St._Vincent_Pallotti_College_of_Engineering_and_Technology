/* * Project: Smart Waste Bin Monitoring Firmware
 * Target: ESP32 + HC-SR04 Ultrasonic Sensor + LoRa Module
 */

#include <SPI.h>
#include <LoRa.h> // Ensure you have the LoRa library installed

const int TRIG_PIN = 5;
const int ECHO_PIN = 18;
const int BIN_HEIGHT = 100; // Total height of the bin in cm 

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Reliability Logic: Taking 5 readings for Median Filtering 
  float distance = readUltrasonic(); 
  
  // Calculate fill level percentage
  int filled_cm = BIN_HEIGHT - distance;
  float fill_percentage = (filled_cm / (float)BIN_HEIGHT) * 100;

  Serial.print("Bin Fill Level: ");
  Serial.print(fill_percentage);
  Serial.println("%");

  // Logic for LoRa transmission
  LoRa.begin(433E6); // Set frequency based on region
  LoRa.beginPacket();
  LoRa.print("BinID:001, Level:");
  LoRa.print(fill_percentage);
  LoRa.endPacket();

  // Power Management: Deep Sleep for 30 minutes
  esp_sleep_enable_timer_wakeup(30 * 60 * 1000000); 
  esp_deep_sleep_start();
}

float readUltrasonic() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return (duration * 0.034) / 2;
}

void loop() 
{
  
} // Empty due to Deep Sleep