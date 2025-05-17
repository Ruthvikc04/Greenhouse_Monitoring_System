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

![Block Diagram](https://github.com/user-attachments/assets/bf955680-4710-4e68-b25a-1909272fa349)

![Circuit Image](https://github.com/user-attachments/assets/2bc7e395-0b2f-4c92-8452-e5e319f23d73)

![Prototype](https://github.com/user-attachments/assets/3061169c-d98a-46fb-a5ca-65b4bcc6767e)

![ThingSpeak Dashboard](https://github.com/user-attachments/assets/1ea066e1-cf12-4832-8955-fe4cc98a661d)

![](https://github.com/user-attachments/assets/606ce007-8df4-4037-bb8d-d0c5575ac585)

---

## **Acknowledgments**  
- Grateful to my mentors for technical guidance and project advice.  
- Appreciation to my teammates for hands-on collaboration and brainstorming.  
- Thanks to the creators of libraries and open-source tools used in this project.

---

## **License**  
This project is licensed under the [MIT License](LICENSE).
