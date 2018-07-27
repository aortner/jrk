# jrk
Code für jrk

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




Tuning the PID constants
Tuning PID constants is a complicated process that can be approached in many different ways. Here we will give a basic procedure that works for some systems, but you will probably want to try various different methods for finding the best possible values. You will want to have the Plots window open, displaying a nice view of the Error, Target, Scaled Feedback, and Duty Cycle. When setting the Integral Coefficient, it will also be useful to look at the value of the Integral.

Increase your Max. duty cycle, Max. current, and other limits to reasonable values for high-performance operation of your system.
Try increasing the Proportional Coefficient until you reach a point where the system becomes unstable. Note that the stability could be different at different target positions, so try the full range of motion when hunting for instability.
Decrease the value from the point of instability by about 40-50%. This is the first step of the Ziegler-Nichols Method.

Note how close your system gets to an error of zero using just the proportional term. You can use the integral term to get it much lower: with the integral limit set at 1000, try increasing the Integral Coefficient until you see a correction that brings the error closer to zero. In the plot window shown here, you can see that the proportional term gets the error down to about 10, then the integral term builds up and, half a second later, moves the motor just a bit, reducing the error to ±1.
For systems that have a lot of friction relative to external forces, enable a Feedback dead zone so that the integral term doesn’t cause a slow oscillation very close to an error of zero. Watch how the integral term and duty cycle build up over time to achieve this. The plot was created with a dead zone of 4; without this, the integral term would have continued to build up, but at a slower rate, after the first adjustment.
Enable the Reset integral when proportional term exceeds max duty cycle option to prevent the integral from winding up during large motions. This is also shown in the plot: the integral term does not start increasing until the error is close to zero.

Have your system take large steps (for example, by clicking the bar area of the Input tab scrollbar to move the target by 200) and use the graph to examine whether it consistently overshoots (crosses zero before coming to a stop and moving back) or undershoots (does not reach zero before slowing down). The plot window shown here, drawn for a system using a Derivative Coefficient of zero, shows clear overshooting. In this example, the error actually oscillates back and forth several times before settling down.

Increase the Derivative Coefficient to get rid of any overshooting, but not so much that it undershoots. The plot window shown here demonstrates undershooting, using a Derivative Coefficient of 10. You can see that the error never reaches zero. Instead, it gradually approaches zero after each step.
Experiment with your system. Adjust any parameters as necessary to get the behavior that you need.


The following example plot shows a well-tuned system, with Proportional, Integral, and Derivative Coefficients of 6.0, 0.25, and 7.5. When taking steps, the system stops very quickly at a position with very small error, randomly overshooting or undershooting by a small amount.


