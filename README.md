# WM-Pratik_Tiwari-St._Vincent_Pallotti_College_of_Engineering_and_Technology
An IoT-enabled Smart Waste Management System conceptualized for the IISCIT Hyderabad Living Lab. Features real-time bin level monitoring using ESP32 &amp; LoRaWAN, and optimized collection routing to enhance urban hygiene and reduce operational costs.

Project Objectives
Enable real-time monitoring of waste bin fill levels
Prevent bin overflow and improve urban hygiene
Optimize garbage collection routes using data-driven decisions
Reduce fuel consumption, manpower, and operational costs
Provide a scalable and low-power smart city solution

Data Flow Description
Ultrasonic sensor measures the distance between bin lid and waste surface
ESP32 calculates bin fill percentage and battery status
Data is packed into a lightweight JSON payload
Payload is transmitted via LoRa to the LoRaWAN Gateway
Gateway forwards data to AWS IoT Core using MQTT
Cloud services process, store, and analyze data
GIS dashboard displays real-time bin status and alerts

Dashboard & Visualization Concept
A web-based GIS dashboard is provided for city authorities to monitor bin status in real time.
Color-Coded Bin Status
 Red: Fill level > 80% (Immediate collection required)
 Yellow: Fill level 50–80% (Monitor)
 Green: Fill level < 50% (Normal)
Dashboard Features
Real-time city map visualization
Zone-wise bin filtering
Priority bin alerts
Optimized garbage truck routing suggestions
Historical data analysis

Route Optimization Strategy
Bins exceeding 80'%' fill level are marked as high priority
High-priority bins are grouped based on geographical proximity
Shortest-path and priority-based routing logic is applied

Power Management Strategy
ESP32 operates mostly in deep sleep mode
Periodic sensing every 30–60 minutes
Data transmission only when threshold changes
Low-power LoRa communication enables multi-year battery life

Scalability & Network Considerations
Designed to support 100+ bins per gateway
City divided into zones for efficient management
LoRaWAN Star-of-Stars topology ensures scalability
New bins can be added without modifying existing infrastructure

Author
Pratik Tiwari
Electronics & IoT Enthusiast
St. Vincent Pallotti College of Engineering and Technology
Smart City | Embedded Systems | IoT
