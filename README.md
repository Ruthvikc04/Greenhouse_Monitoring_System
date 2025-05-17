# **Greenhouse Monitoring System**  
*IoT-based smart monitoring system for optimal greenhouse conditions.*  

---

## **Project Description**  
This project focuses on designing a smart greenhouse monitoring system using ESP32 and multiple sensors to track essential environmental parameters. It ensures plant health by monitoring temperature, humidity, air quality, soil moisture, light intensity, and water level in real-time. Data is displayed via Serial Monitor or sent to the cloud using MQTT and ThingSpeak.

---

### **Key Features**  
- **Multi-Parameter Monitoring**: Tracks temperature, humidity, air pollutants, soil moisture, water level, and light intensity.  
- **Threshold Alerts**: Notifies abnormal conditions like low water, dry soil, or high pollution.  
- **IoT Integration**: Uses WiFi and MQTT to send data to ThingSpeak for cloud monitoring.  
- **Local & Cloud Modes**: Supports both Serial Monitor-based local analysis and remote dashboard via ThingSpeak.  
- **Energy Efficient**: Compact, wireless setup suitable for greenhouses or garden beds.

---

## **Technologies Used**  
- **Hardware**: ESP32, DHT22, MQ135, Soil Moisture Sensor, Water Level Sensor, LDR  
- **Software**: Arduino IDE, ThingSpeak MQTT, Serial Monitor  
- **Protocols**: WiFi, MQTT for IoT connectivity  

---

## **What I Learned**  
- Built a complete **IoT solution** from sensor input to cloud data visualization.  
- Improved skills in **embedded C/C++ programming** and **sensor calibration**.  
- Learned to work with **MQTT protocols** and **cloud services** (ThingSpeak).  
- Strengthened understanding of **agriculture-tech applications** using smart sensing.

---

## **Future Scope**  
- Add **automated irrigation** based on soil moisture levels.  
- Use **ultrasonic sensors** for more precise water level monitoring.  
- Include **actuator controls** (fans, lights) for full environmental automation.  
- Add **mobile alerts** via Blynk or Telegram bot integration.  
- Enable **web-based dashboard** for real-time charts and control toggles.

---

## **Screenshots**

![Serial Monitor Output](https://github.com/your-username/greenhouse-monitoring-system/assets/serial_monitor_example.png)  
![ThingSpeak Dashboard](https://github.com/your-username/greenhouse-monitoring-system/assets/thingspeak_dashboard.png)  

> *(Replace with your actual GitHub image URLs or upload via GitHub Issues/Discussions if needed.)*

---

## **Acknowledgments**  
- Grateful to my mentors for technical guidance and project advice.  
- Appreciation to my teammates for hands-on collaboration and brainstorming.  
- Thanks to the creators of libraries and open-source tools used in this project.

---

## **License**  
This project is licensed under the [MIT License](LICENSE).
