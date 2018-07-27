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


Arduino IDE > Biblothek einbinden > JRK Biblothek suchen und einbinden.

Software für Polulu runderladen.
https://www.pololu.com/file/0J1494/pololu-jrk-g2-1.3.0-win.msi

Pololu muss am Anfang einmalig mittels USB verbunden werden und konfiguriert werden.

Tab Input

muss auf serial/i2c/usb stehen

immer dann auf apply drücken

Tap Feedback

Learn drucken:

Soweit einschlagen das Maximal Reading erreicht wird - learn
andere Richtung einschlagen 2. learn drucken

fertig.

Tap PID

P oben 10-20 untern Strich 1
I 4-7 untern Strich 5
D 4-7 unterm Strich 1

Prinzipielles Einleren:

Alles auf 0

mit Drive spielen und dabei:

P soweit erhöhen das beim Anfahren ordenlich übersteuert wird
dann die Hälfte einstellen

I soweit einstellen das die Lenkung grad nicht nervös wird ( i schaut in die Zukunft)

D auch das das ganze Ruhig wird  ( d schaut in die Vergangenheit)


wenn das ganze passt kann der usb kabel entfernt werden.


void updatejrk()

ist erstmal auskommentiert. Dazu muss das autosteer fenster in agopengps angepasst werden.




