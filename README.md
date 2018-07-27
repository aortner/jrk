# jrk
Code for jrk

Anschluss:

SDA (A4) und SCL (A5) und GND Arduino > JRK
Pin 3-5 neben USB

5 V GND > Hall Sensor
AUX input > Hall Sensor


Zeile 46 in Autosteer Ino 

steeringPositionZero = 2046;

Für Steering Zero anpassen 2046 ist genau die Mitte - mann sollte ca 100 abziehen und damit mit Steer Zero den Mittelpunkt zu finden



