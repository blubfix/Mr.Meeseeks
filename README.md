# Mr. Meeseeks Button 📦

A Rick and Morty themed IoT button that triggers Alexa actions via IFTTT webhooks. Press the button to summon Mr. Meeseeks!

![Mr. Meeseeks](https://vignette.wikia.nocookie.net/rickandmorty/images/3/37/Mr._Meeseeks.png/revision/latest?cb=20160909153831)

## 🎯 Overview

This project creates a physical button housed in a 3D-printed "Mr. Meeseeks Box" that:
- Connects to your WiFi network
- Sends IFTTT webhooks when pressed
- Triggers Amazon Alexa actions
- Goes into deep sleep mode to save power

When activated, the device sends the message "I need Mr. Meeseeks!" to your configured IFTTT applet.

## 🛠️ Hardware Requirements

- **ESP8266 based microcontroller** (tested on Wemos D1 mini Pro)
  - Should work with any ESP8266 development board
- **Power source** (USB or battery)
- **Optional:** 3D printer for the custom enclosure

## 📦 3D Printable Enclosure

The repository includes 3D models for the Mr. Meeseeks Box enclosure:
- `Mr. Meeseeks Box v4.f3d` - Fusion 360 format (editable)
- `Mr. Meeseeks Box v4.step` - STEP format (universal)

Print the box to create an authentic Rick and Morty themed housing for your button!

## 🔧 Software Requirements

- [PlatformIO](https://platformio.org/) - For building and uploading the code
- [Visual Studio Code](https://code.visualstudio.com/) with PlatformIO extension (recommended)
- Arduino framework support for ESP8266

## 🌐 Online Services Setup

### Required Accounts

1. **Amazon Alexa Account** - For voice control integration
2. **IFTTT Account** - For webhook automation

### IFTTT Configuration

1. Create an account at [ifttt.com](https://ifttt.com)
2. Set up the following services:
   - [Webhooks](https://ifttt.com/maker_webhooks) - To receive button triggers
   - [Alexa Actions by mkZense](https://ifttt.com/AlexaActionsByMkzense) - To control Alexa
     - Visit [mkzense.com](https://mkzense.com/) for more information
3. Create a new applet:
   - **IF**: Webhooks - "Receive a web request" with event name `button_pressed` (or your custom name)
   - **THEN**: Alexa Actions - Configure your desired Alexa action
4. Get your IFTTT Webhooks Key:
   - Go to [Webhooks settings](https://ifttt.com/maker_webhooks/settings)
   - Copy your key from the URL shown

## 💻 Installation

### 1. Clone the Repository

```bash
git clone https://github.com/blubfix/Mr.Meeseeks.git
cd Mr.Meeseeks
```

### 2. Configure WiFi and IFTTT Credentials

Edit `src/main.cpp` and update the following lines with your credentials:

```cpp
// Set WiFi credentials
#define WIFI_SSID "Your_WiFi_SSID"
#define WIFI_PASS "Your_WiFi_Password"

#define IFTTT_Key "Your_IFTTT_Webhooks_Key"
#define IFTTT_Event "button_pressed" // or your custom event name
```

⚠️ **Important:** Never commit your actual credentials to version control!

### 3. Build and Upload

Using PlatformIO:

```bash
# Build the project
pio run

# Upload to your ESP8266
pio run --target upload

# Monitor serial output (optional)
pio device monitor
```

Or use the PlatformIO extension in VS Code for a graphical interface.

## 🔌 Hardware Setup

1. Connect your ESP8266 board to your computer via USB
2. Power up the device
3. The device will:
   - Connect to your WiFi network
   - Send the IFTTT webhook
   - Enter deep sleep mode

To trigger the webhook again, press the reset button on your ESP8266 or power cycle the device.

## 📡 How It Works

1. On startup, the ESP8266 connects to the configured WiFi network
2. Once connected, it sends an IFTTT webhook with:
   - Event name: `button_pressed` (or your custom name)
   - Value1: "I need Mr. Meeseeks!"
   - Value2: "25"
   - Value3: "value 1"
3. IFTTT receives the webhook and triggers your configured Alexa action
4. The device enters deep sleep mode to conserve power

## 🔄 Customization

You can customize the webhook message in `src/main.cpp`:

```cpp
send_webhook(IFTTT_Event, IFTTT_Key, "Your message", "value2", "value3");
```

## 📚 Dependencies

This project uses:
- **AnotherIFTTTWebhook library** by Neil Webber
  - Original: https://github.com/Siytek/AnotherIFTTTWebhook
  - Adapted from: https://www.siytek.com
  - License: MIT
- **ESP8266 Arduino Core**
- **ESP8266WiFi library**

## 📝 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## 🙏 Credits

- **AnotherIFTTTWebhook** library by Neil Webber
- **Rick and Morty** created by Justin Roiland and Dan Harmon
- **mkZense** for Alexa Actions IFTTT integration

## 🐛 Troubleshooting

### WiFi Connection Issues
- Verify your SSID and password are correct
- Check that your WiFi network is 2.4GHz (ESP8266 doesn't support 5GHz)
- Ensure the ESP8266 is in range of your router

### IFTTT Webhook Not Triggering
- Verify your IFTTT key is correct
- Check that the event name matches in both the code and your IFTTT applet
- Test the webhook manually using the IFTTT Webhooks documentation page

### Upload Failures
- Ensure the correct board is selected in `platformio.ini`
- Check that the USB cable supports data transfer (not charge-only)
- Try pressing the flash button during upload if your board requires it

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## ⚠️ Disclaimer

This is a fan project and is not officially affiliated with or endorsed by Rick and Morty, Adult Swim, or Cartoon Network.

---

**"Existence is pain for a Meeseeks, Jerry!"** 🔵
