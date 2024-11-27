import cv2
import serial
import time

# Initialize serial communication with Arduino
arduino = serial.Serial('COM3', 9600)  # Replace 'COM3' with your Arduino's port
time.sleep(2)  # Give time for the connection to establish

# Initialize the webcam
cap = cv2.VideoCapture(0)

# Load OpenCV's pre-trained Haar cascade for face detection
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5)

    if len(faces) > 0:
        arduino.write(b'1')  # Send '1' to turn on the LED
    else:
        arduino.write(b'0')  # Send '0' to turn off the LED

    # Draw rectangles around detected faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

    cv2.imshow('Face Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
arduino.close()
