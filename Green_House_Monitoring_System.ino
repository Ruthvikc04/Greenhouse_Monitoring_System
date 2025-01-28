#include <DHT.h>

#define DHT_PIN 4          
#define MQ135_PIN 36        
#define WATER_PIN 39      
#define LDR_PIN 34         r
#define SOIL_PIN 32         

DHT dht(DHT_PIN, DHT22);

// Soil Moisture Calibration Values
const int airValue = 4000;  // Sensor in air
const int dryValue = 2000;  // Sensor in dry soil
const int wetValue = 800;   // Sensor in wet soil

// Thresholds for optimal greenhouse conditions
const float TEMP_MIN = 20.0, TEMP_MAX = 35.0; // Temperature range in °C
const float HUMIDITY_MIN = 40.0, HUMIDITY_MAX = 70.0; // Humidity range in %
const float LIGHT_MIN = 40.0; // Minimum light intensity in %
const float WATER_MIN = 20.0; // Minimum water level in %
const float SOIL_MIN = 30.0;  // Minimum soil moisture level in %

void setup() 
{
  Serial.begin(115200);
  Serial.println("Initializing Greenhouse Monitoring System...");
  dht.begin();
}

void loop() 
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) 
  {
    Serial.println("Failed to read from DHT sensor!");
  } 
  else 
  {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
  }

  // Read Gas Sensor (MQ-135)
  int gasRaw = analogRead(MQ135_PIN);
  float airPollutants = map(gasRaw, 200, 4095, 0, 100); // Convert to percentage
  airPollutants = constrain(airPollutants, 0, 100); // Clamp values
  Serial.print("Air Pollutants Level: ");
  Serial.print(airPollutants);
  Serial.println("%");

  // Read Water Level Sensor
  int waterRaw = analogRead(WATER_PIN);
  float waterPercent = map(waterRaw, 500, 3500, 0, 100);
  waterPercent = constrain(waterPercent, 0, 100); // Clamp values
  Serial.print("Water Level: ");
  Serial.print(waterPercent, 2);
  Serial.println("%");

  // Read Light Sensor (LDR)
  int lightRaw = analogRead(LDR_PIN);
  float lightPercent = 100.0 - map(lightRaw, 300, 3500, 0, 100);
  lightPercent = constrain(lightPercent, 0, 100); // Clamp values
  Serial.print("Light Intensity: ");
  Serial.print(lightPercent, 2);
  Serial.println("%");

  // Read Soil Moisture Sensor
  int soilRaw = analogRead(SOIL_PIN);
  float soilPercent = map(soilRaw, wetValue, dryValue, 100, 0);
  soilPercent = constrain(soilPercent, 0, 100); // Clamp values
  Serial.print("Soil Moisture: ");
  Serial.print(soilPercent, 2);
  Serial.println("%");

  // Check for Abnormal Conditions
  if (temperature < TEMP_MIN || temperature > TEMP_MAX) 
  {
    Serial.println("Temperature out of range!");
  }
  if (humidity < HUMIDITY_MIN || humidity > HUMIDITY_MAX) 
  {
    Serial.println("Humidity out of range!");
  }
  if (airPollutants > 50.0) 
  { // Example threshold for air pollutants
    Serial.println("High air pollutant levels!");
  }
  if (waterPercent < WATER_MIN) 
  {
    Serial.println("Low water level detected!");
  }
  if (lightPercent < LIGHT_MIN)
  {
    Serial.println("Low light intensity detected!");
  }
  if (soilPercent < SOIL_MIN) 
  {
    Serial.println("Low soil moisture detected!");
  }

  delay(2000);
}
