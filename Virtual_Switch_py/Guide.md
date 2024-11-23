# Virtual Switching System Using Arduino Uno and Python

## **1. Project Overview**
This project allows you to create a **virtual switching system** where hardware (like LEDs or relays) can be controlled via gestures, GUI, or commands.

### **Key Features**:
- Virtual control of hardware like LEDs or relays.
- Input through gestures or commands.
- Real-time feedback and interaction.

---

## **2. Components and Tools Needed**

### **Hardware**:
- Arduino Uno
- USB cable
- LEDs (or relays for appliances)
- Resistors (220Ω for LEDs)
- Breadboard and jumper wires

### **Software**:
- Python ([Download Python](https://www.python.org/))
- Arduino IDE ([Download Arduino IDE](https://www.arduino.cc/en/software))
- Python libraries:
  - `pyfirmata`
  - `opencv-python`
  - `cvzone`
  - `ediapipe`

---

## **3. System Design**
The system consists of three key parts:
1. **Input Processing**:
   - Gestures via OpenCV or commands via GUI.
2. **Communication**:
   - Sending commands from Python to Arduino using `pyfirmata`.
3. **Hardware Control**:
   - Arduino controlling hardware components like LEDs or relays.

---

## **4. Implementation Steps**

### **Step 1: Set Up Arduino**
1. Connect the Arduino Uno to your PC.
2. Upload the `StandardFirmata` sketch:
   - Open **Arduino IDE** → Go to **File → Examples → Firmata → StandardFirmata**.
   - Upload it to the Arduino board.

### **Step 2: Set Up Python Environment**
1. Install Python libraries:
2. Open `cmd` by clicking `Win` + `R`, then paste the code

   ```bash
   pip install pyfirmata opencv-python cvzone mediapipe
    ```
3. Check the Arduino COM port: Open Device Manager → Check Ports (COM & LPT).

### **Step 3: Write Python Code**

Create a  file named `controller.py` and paste the code below

```python
import pyfirmata2

comport='COM3'

board=pyfirmata2.Arduino(comport)

led_1=board.get_pin('d:8:o')
led_2=board.get_pin('d:9:o')
led_3=board.get_pin('d:10:o')
led_4=board.get_pin('d:11:o')
led_5=board.get_pin('d:12:o')

def led(fingerUp):
    if fingerUp==[0,0,0,0,0]:
        led_1.write(0)
        led_2.write(0)
        led_3.write(0)
        led_4.write(0)
        led_5.write(0)

    elif fingerUp==[0,1,0,0,0]:
        led_1.write(0)
        led_2.write(1)
        led_3.write(0)
        led_4.write(0)
        led_5.write(0)
    elif fingerUp==[0,1,1,0,0]:
        led_1.write(0)
        led_2.write(1)
        led_3.write(1)
        led_4.write(0)
        led_5.write(0)    
    elif fingerUp==[0,1,1,1,0]:
        led_1.write(0)
        led_2.write(1)
        led_3.write(1)
        led_4.write(1)
        led_5.write(0)
    elif fingerUp==[0,1,1,1,1]:
        led_1.write(0)
        led_2.write(1)
        led_3.write(1)
        led_4.write(1)
        led_5.write(1)
    elif fingerUp==[1,1,1,1,1]:
        led_1.write(1)
        led_2.write(1)
        led_3.write(1)
        led_4.write(1)
        led_5.write(1)
```

#### Create a  another file named `script.py` and paste the code below

```python
import cv2
import controller as cnt
from cvzone.HandTrackingModule import HandDetector

detector=HandDetector(detectionCon=0.8,maxHands=1)

video=cv2.VideoCapture(0)

while True:
    ret,frame=video.read()
    frame=cv2.flip(frame,1)
    hands,img=detector.findHands(frame)
    if hands:
        lmList=hands[0]
        fingerUp=detector.fingersUp(lmList)

        print(fingerUp)
        cnt.led(fingerUp)
        if fingerUp==[0,0,0,0,0]:
            cv2.putText(frame,'Finger count:0',(20,460),cv2.FONT_HERSHEY_COMPLEX,1,(255,255,255),1,cv2.LINE_AA)
        elif fingerUp==[0,1,0,0,0]:
            cv2.putText(frame,'Finger count:1',(20,460),cv2.FONT_HERSHEY_COMPLEX,1,(255,255,255),1,cv2.LINE_AA)    
        elif fingerUp==[0,1,1,0,0]:
            cv2.putText(frame,'Finger count:2',(20,460),cv2.FONT_HERSHEY_COMPLEX,1,(255,255,255),1,cv2.LINE_AA)
        elif fingerUp==[0,1,1,1,0]:
            cv2.putText(frame,'Finger count:3',(20,460),cv2.FONT_HERSHEY_COMPLEX,1,(255,255,255),1,cv2.LINE_AA)
        elif fingerUp==[0,1,1,1,1]:
            cv2.putText(frame,'Finger count:4',(20,460),cv2.FONT_HERSHEY_COMPLEX,1,(255,255,255),1,cv2.LINE_AA)
        elif fingerUp==[1,1,1,1,1]:
            cv2.putText(frame,'Finger count:5',(20,460),cv2.FONT_HERSHEY_COMPLEX,1,(255,255,255),1,cv2.LINE_AA) 

    cv2.imshow("frame",frame)
    k=cv2.waitKey(1)
    if k==ord("k"):
        break

video.release()
cv2.destroyAllWindows()
```
## Step 4: Circuit Design
- **Connect the LEDs**:
  - Connect the **anode** of each LED to pins **8-12** on the Arduino.
  - Use **220Ω resistors** in series with the LEDs.
  - Connect the **cathodes** of the LEDs to the Arduino **GND**.

- **Test the LEDs**:
  - Turn the LEDs ON/OFF using Python to verify the connections.
---

![Circuit Diagram.png](https://github.com/Safkat-Khan/MicroPy_Project/blob/main/Virtual_Switch_py/img/Circuit%20Diagram.png)


---

## After Completing Those Step Now You Can `Run` the `script.py` file to Start Your Project.

## 5. Extensions(Optional)

### **Add GUI Control**
- Use **tkinter** or **PyQt5** to add buttons for controlling the hardware.

### **Expand Gesture Control**
- Add more gestures (e.g., swipe left/right) for advanced functionality.

### **Control Real Appliances**
- Replace LEDs with **relays** to control appliances like lights or fans.

### **Feedback Mechanism**
- Display the hardware status in the Python console or a GUI for better monitoring.

---

## 6. Debugging Tips

### **Check COM Port**
- Ensure the correct COM port is specified in Python.

### **Release COM Port**
- Close any other applications using the COM port (e.g., Arduino IDE).

### **Run Python as Administrator**
- Open Command Prompt as Administrator before running the script:
- Change the `your_script` accoding to your `file name`.
  
  ```bash
  python your_script.py
  ```
