# 🧊 Smart Koozie

Smart Koozie is a Bluetooth-enabled, drink-cooling device that lets users toggle a thermoelectric cooler from their phone using the RemoteXY mobile app. Built with an Arduino Nano ESP32 and a Peltier module, the system includes a temperature sensor to monitor the drink's temperature in real-time, while the RemoteXY interface provides a simple on/off control for cooling.

## 🔧 Features

- ❄️ On-demand cooling via Peltier module
- 📱 Remote control using RemoteXY mobile app with custom-designed GUI
- 🌡️ Real-time temperature display on the phone
- 🔋 Battery-powered and portable
- 🧠 Powered by Arduino Nano ESP32

## 🛠️ System Components

- **Microcontroller:** Arduino Nano ESP32
- **Cooler:** Peltier Thermoelectric Module
- **Temperature Sensor:** IR Sensor
- **Switching Circuit:** N-Channel MOSFET with Buck Converter
- **User Interface:** RemoteXY app (custom GUI)
- **Connectivity:** Bluetooth Low Energy (BLE)

## 🚀 How to Use

1. **Hardware Setup**
   - Wire up the Arduino Nano ESP32 with the Peltier module, temperature sensor, MOSFET, and power supply as per `/hardware` schematics.

2. **Upload Firmware**
   - Flash the Arduino code from `/firmware` to the Arduino Nano ESP32.
   - Make sure the code includes the RemoteXY interface definition.

3. **Connect with RemoteXY**
   - Download the [RemoteXY mobile app](https://remotexy.com/en/app/) on your iOS or Android device.
   - Pair your device with the Arduino via Bluetooth.
   - Load the custom GUI using the RemoteXY code or QR import.

4. **Start Cooling**
   - Use the on/off toggle in the app to activate the Peltier cooler.
   - View the current temperature live on your phone.

## 🧪 Future Improvements

- 🔄 Automatic cooling based on temperature threshold
- 🔋 Optimize for energy efficiency and longer battery life
- 🌍 Add cloud monitoring with RemoteXY or other platforms

## 📸 Demo

Will upload later

## 👨‍💻 Author

- Juan Salas – [@jujo2005](https://github.com/jujo2005)
- Rober McKay
- Yohan Ksor

## 📄 License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.
