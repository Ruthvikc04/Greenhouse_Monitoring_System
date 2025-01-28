#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// WiFi and ThingSpeak MQTT Credentials
char ssid[] = "Airtel_Sudha"; 
char pass[] = "a1b2c3d4e5f6g7h8"; 

const char* server = "mqtt3.thingspeak.com";
const char mqttUserName[] = "AxQBHx0hMgYzBQopPBo1Dzw";
const char clientID[] = "AxQBHx0hMgYzBQopPBo1Dzw";
const char mqttPass[] = "x/t+JGQSqN3wstiy/V+Ltmuh";
long channelID = 2774946;

// Sensor Pins
#define DHT_PIN 4        
#define MQ135_PIN 36        
#define WATER_PIN 39     
#define LDR_PIN 34           
#define SOIL_PIN 32          

// Soil Moisture Calibration Values
const int airValue = 4000;  // Sensor in air
const int dryValue = 2000;  // Sensor in dry soil
const int wetValue = 800;   // Sensor in wet soil

// Thresholds for optimal greenhouse conditions
const float TEMP_MIN = 20.0, TEMP_MAX = 35.0; // Temperature range in °C
const float HUMIDITY_MIN = 40.0, HUMIDITY_MAX = 70.0; // Humidity range in %

DHT dht(DHT_PIN, DHT22);

WiFiClient client;
PubSubClient mqttClient(client);

// Timer for ThingSpeak updates
long lastPublishMillis = 0;

void setup() 
{
  Serial.begin(115200);
  Serial.println("Initializing Greenhouse Monitoring System...");
  connectWifi();
  mqttClient.setServer(server, 1883);
  dht.begin();
}

void loop() 
{
  if (WiFi.status() != WL_CONNECTED) 
  {
    connectWifi();
  }
  if (!mqttClient.connected()) 
  {
    mqttConnect();
  }
  mqttClient.loop();

  if (millis() - lastPublishMillis >= 15000) 
  {
    publishSensorData();
    lastPublishMillis = millis();
  }
}

void connectWifi() 
{
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
}

void mqttConnect() 
{
  while (!mqttClient.connected()) 
  {
    Serial.println("Attempting MQTT connection...");
    if (mqttClient.connect(clientID, mqttUserName, mqttPass))
    {
      Serial.println("Connected to MQTT");
    } 
    else 
    {
      Serial.print("Failed to connect to MQTT, state: ");
      Serial.println(mqttClient.state());
      delay(5000); 
    }
  }
}

void mqttPublish(long pubChannelID, String message) 
{
  String topicString = "channels/" + String(pubChannelID) + "/publish";
  if (mqttClient.publish(topicString.c_str(), message.c_str())) 
  {
    Serial.println("Data published successfully: " + message);
  } 
  else 
  {
    Serial.println("Failed to publish data");
  }
}

void publishSensorData() 
{
  // Read Temperature and Humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check for DHT read errors
  if (isnan(temperature) || isnan(humidity)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return; // Skip publishing if DHT fails
  }

  Serial.print("Temperature: ");
  Serial.print(temperature, 2);
  Serial.println("°C");

  Serial.print("Humidity: ");
  Serial.print(humidity, 2);
  Serial.println("%");

  // Read Gas Sensor (MQ-135)
  int gasRaw = analogRead(MQ135_PIN);
  float airPollutants = map(gasRaw, 200, 4095, 0, 100);
  airPollutants = constrain(airPollutants, 0, 100);

  Serial.print("Air Pollutants Level: ");
  Serial.print(airPollutants, 2);
  Serial.println("%");

  // Read Water Level Sensor
  int waterRaw = analogRead(WATER_PIN);
  float waterPercent = map(waterRaw, 500, 3500, 0, 100);
  waterPercent = constrain(waterPercent, 0, 100);

  Serial.print("Water Level: ");
  Serial.print(waterPercent, 2);
  Serial.println("%");

  // Read Light Sensor (LDR)
  int lightRaw = analogRead(LDR_PIN);
  float lightPercent = 100.0 - map(lightRaw, 300, 3500, 0, 100);
  lightPercent = constrain(lightPercent, 0, 100);

  Serial.print("Light Intensity: ");
  Serial.print(lightPercent, 2);
  Serial.println("%");

  // Read Soil Moisture Sensor
  int soilRaw = analogRead(SOIL_PIN);
  float soilPercent = map(soilRaw, wetValue, dryValue, 100, 0);
  soilPercent = constrain(soilPercent, 0, 100);

  Serial.print("Soil Moisture: ");
  Serial.print(soilPercent, 2);
  Serial.println("%");

  // Prepare MQTT message
  String message = String("field1=") + String(temperature, 2) +
                   "&field2=" + String(humidity, 2) +
                   "&field3=" + String(airPollutants, 2) +
                   "&field4=" + String(soilPercent, 2) +
                   "&field5=" + String(waterPercent, 2) +
                   "&field6=" + String(lightPercent, 2);

  // Publish to ThingSpeak
  mqttPublish(channelID, message);

  // Print to Serial Monitor
  Serial.println("Data Sent to ThingSpeak:");
  Serial.println(message);
}
