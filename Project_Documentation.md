# The Making Process of Musical Wristband
### An interactive wristband that plays musical notes via embedded touch sensors
### An open source project by Thi Yen Thu Nguyen

This project is done as a final project for the 5-day Textile Academy Bootcamp 2017 (from 20.02 to 24.02)

An overview of my Textile Academy Bootcamp experiences can be found <a href="/Textile_Bootcamp_Overview.pdf">here</a>.

=======

<h1> Some insights to choosing materials and parts </h1>

The reason for choosing Neopixel as notification light is straightforward: Adafruit has their own Arduino library for these little RGB LED chips, which makes it super easy to programm one single chip to show different colors (up to 16 million colors).

The reason for choosing the Arduino Pro Micro instead of some other Arduino-based wearable-friendly microcontroller such as the <a href="https://www.sparkfun.com/products/13342">Sparkfun Lilypad Arduino Mainboard</a> is because the Lilypads have to be sewn directly onto the textile as well as all the connections from the Lilypad to the sensors. I find this however not flexible because it would be difficult to troubleshoot when there is some problem with the hardware, as one cannot easily disconnect like wires and pinheaders. As such I made pin headers for all pins of the Arduino Pro Micro so that I can always comfortably connect or disconnect parts from my wristband.

However, if one is more comfortable with sewing and less familiar with soldering, it is possible to make the circuit detachable with Lilypads by sewing snap buttons in between the connection lines, with the button's female part sewn to the Lilypad and the male part sewn to the sensors/ loudspeaker/ Neopixel (or vice versa). As such, only when the snap button is closed would the connection be closed.

=======

<h1> Start making! </h1>

First, make sure that you have gathered all the components and materials as described in <a href="/BOM.xlsx">this BOM list</a>.

Refer to the design of the wristband below to have an overview of what we would be making.

<img src="/Design%20files/Bracelet-design-rev0.2.jpg" width="600" height="400">

<h3>1. 3D Print the pattern </h3>
Start with printing the <a href="/Design%20files/ScalePattern1mm.stl">3D pattern</a>. I printed using the <a href="https://ultimaker.com/en/products/ultimaker-2-plus">Ultimaker 2 Extended</a> 3D printer with a 0.8mm nozzle, first with normal black PLA filament and then with flexible grey PLA filament. The pattern I printed was 200mm wide x 30mm high x 1mm deep, but you can scale it up or down in the <a href="https://ultimaker.com/en/products/cura-software">CURA</a> software.

<img src="/Media/Photo%205.2.jpg" width="300" height="400">

<i>Photo: 3D printed pattern using normal black PLA filament (right) and flexible grey PLA filament (left)</i>


<h3>2. Embroid the conductive pads for touch sensors </h3>
Next, send the <a href="/Design%20files/Embroidery-Pattern">conductive pads pattern</a> to the embroidery machine, which has to be threaded with <b>conductive thread</b>. 

In fact, I had to do a bridging step of converting the image to an embroidery file that the machine can actually read using a trial version of the <a href="https://www.wilcom.com/Hatch/Products/HotcakeStoreAdmin/ProductViewer/tabid/3605/slug/Embroidery-Digitizer/Default.aspx">Hatch embroidery digitizer software</a>. And now you are ready to embroid on your textile of choice.

<img src="/Media/Photo%206.2.jpg" width="400" height="300">

<i>Photo: Conductive pads pattern for touch sensor embroidered using conductive thread</i>

<h3><a name="section3">3. Test electronics and software</a></h3>
While waiting for the embroidery machine and 3D printer to finish their jobs, test out the hardware and the Arduino sketch by preparing the following parts:

<ul>3.1. Solder male pin headers to Arduino Pro Micro. I suggest using male pin headers with 90° bend so that the board is as flat as possible and thus is easy to embed on textile later on.</ul>

<img src="/Media/Photo%205.4a.jpg" width="400" height="300">

<i>Photo: Arduino Pro Micro with 90° bent male pin header</i>

Otherwise, you can sew the Lilypad to the textile and make snap button connections as explained above.

<ul>3.2. Solder wires with female pin headers to the loudspeaker, following your loudspeaker's datasheet.</ul>

<img src="/Media/Photo%205.4b.jpg" width="400" height="300">

<i>Photo: Lilypad buzzer soldered with wires and optional components</i>

If you are using the Lilypad buzzer like mine, you can either leave it as is or solder extra parts like signal diode, NPN transistor and resistor as described in the <a href="http://cdn.sparkfun.com/datasheets/Components/General/CCV-084B16-CUI-datasheet-29139.pdf">Datasheet</a>. I've tried both and in both cases the buzzer works similarly. What you need to note is that, without extra component, you only have 2 connections from this buzzer PCB to the Arduino (+ and -). However, with extra components, you will have 3 connections: + (red wire), - (white wire) and PWM (yellow wire). The PWM connection (yellow wire) goes to one of those certain pins on the Arduino that have a "~" sign next to them, for example, pin ~9.


<ul>3.3. Solder wires with female pin headers to the Neopixel. We only need 3 wires for 3 pins: VCC, GND and Data IN</ul>

<ul>3.4. Prepare 1 row of 6 female pin headers and 5 medium to high value resistors (100 kilohm - 50 megohm). Solder one end of all 5 resistors to the first pin and the other end of each resistor to each of the remaining pin. An explanation of the capacitive sensors is available on the <a href="http://playground.arduino.cc/Main/CapacitiveSensor?from=Main.CapSense">Arduino website</a>. Here I use a 4.7M Ohm resistor and I find it fairly good and responsive enough. Using higher-value resistor would give you a more responsive sensor.</ul>


<img src="/Media/Photo%205.4c.jpg" width="400" height="300">

<i>Photo: Row of pin headers with resistors, <b><a name="firstpin">first pin</a> is the upper most pin</b></i>

Since we are only testing the circuit, you do not have to solder on all 5 resistors but I suggest you do this in one go because it would be difficult to solder on top of the first resistor later on.  

<ul>3.5. Prepare a few pieces of wire of various length (5-15 cm). Make the DIY capacitive sensors by soldering one end of the wire to a small piece of copper tape (5mmx5mm) and then wrap both sides of copper tape with normal scotch tape or similar type of tape. Repeat for as many sensors as you want to test.</ul>

<img src="/Media/Photo%205.4d.jpg" width="400" height="300">

<i>Photo: DIY capacitive sensors made with wire, copper tape and Kapton tape</i>

Finally, solder the other end of each sensor's wire to each of the female pin headers from the row above, <b> except for </b> the [first pin](#firstpin).

<ul>3.6. Now wire up the loudspeaker, Neopixel, sensors and resistors-pin headers to the Arduino Pro Micro as in the photo below:</ul>

<img src="/Media/Photo%205.5.jpg" width="400" height="300">

A table of connections:

<b>Component's pin</b> ------------ <b>Arduino's pin</b>

Loudspeaker VCC ------------- VCC

Loudspeaker GND ------------ GND

Loudspeaker PWM ------------ ~9 

NeoPixel VCC ------------------ VCC

NeoPixel GND ----------------- GND

NeoPixel DIN ------------------ 8

Female pin headers 1-6 ------- 2-7, which also means 

Sensors 1-5 -------------------- 3-7

The loudspeaker PWM pin can be redefined as any other PWM ~ pin in [line 15](/Arduino%20Sketch/Musical_wristband_rev0.2.ino#L15) of the [final sketch](/Arduino%20Sketch/Musical_wristband_rev0.2.ino), as long as it is not the same pin as the sensor pin.

Similary, the NeoPixel DIN pin can be redefined as any other I/O pin in [line 17](/Arduino%20Sketch/Musical_wristband_rev0.2.ino#L17) of the [final sketch](/Arduino%20Sketch/Musical_wristband_rev0.2.ino), as long as it is not the same pin as the sensor pin.

Depending on the number of sensors you are testing, you will also need to change [line 23](/Arduino%20Sketch/Musical_wristband_rev0.2.ino#L17) of the [final sketch](/Arduino%20Sketch/Musical_wristband_rev0.2.ino), for example, to 5.

<ul>3.7. Connect the Arduino Pro Micro to PC via micro USB cable, open the Arduino IDE and upload the sketch to the board. Make sure you choose the right Port and Board under the Tools menu of the IDE.</ul>

I also suggest you keep the "debug" variable as "true" ([line 27](/Arduino%20Sketch/Musical_wristband_rev0.2.ino#L27)). Now if you open the Serial Monitor, you will be able to see the sensor values running. Try touching your sensors and see how the values change. When you find the value that is good enough to be used as a trigger for the loudspeaker, set it as the "SENSOR_THRESHOLD" in [line 25](/Arduino%20Sketch/Musical_wristband_rev0.2.ino#L25).

It is possible to change the brightness of the Neopixel in [line 21](/Arduino%20Sketch/Musical_wristband_rev0.2.ino#L21) and also the note that each sensor would trigger to play in the function [toneController()](/Arduino%20Sketch/Musical_wristband_rev0.2.ino#L151-L191).

Each note is basically represented as a frequency which is defined in the [pitches.h](/Arduino%20Sketch/pitches.h) (a C++ header) file.

If the hardware is working fine, continue with making your wristband. Else, I suggest you check your wiring, components' values, and solder joints.

<h3>4. Sewing the wristband together</h3>

Now that the conductive pads have been embroidered on the front of the textile, we can cut out the piece of the size we need for the wristband. I cut a piece of around 250mmx85mm and then sew the edges into the back side. We can now make a pocket for the microcontroller at the back side.

<img src="/Media/Photo%206.3a.jpg" width="300" height="400">

<i>Photo: Pocket for microcrontroller, with some cut-outs for the pin headers and microUSB-port</i>

I also use velcro loop and hook to make it easy to open and close the pocket for inserting and removing the microcontroller.

Next, sew in the velcro loop and hook to the end of both top and bottom side of the wristband. You can also already make some cut-outs for mounting the Neopixel and the loudspeaker.

<img src="/Media/Photo%206.3b.jpg" width="300" height="400">
<img src="/Media/Photo%206.3c.jpg" width="500" height="400">

<i>Photo: Sew velcros to both side of wristband </i>

Finally, mount the 3D printed patterns, loudspeaker and Neopixel to the front of the wristband using tape of glue.

<img src="/Media/Photo%206.4.jpg" width="500" height="400">

<h3>5. Final assembly</h3>

If you wish to add more sensors at this point, repeat the steps 3.4 to 3.6 of [Section3](#section3). For the additional sensors, the wiring to the Arduino would be:

<b>Component's pin</b> ------------- <b>Arduino's pin</b>

Female pin headers 7-12 ------ 10-A3, which also means 

Sensors 6-12 ------------------- 11-A3

And the final wiring would look like this:

<img src="/Media/Photo%206.5.jpg" width="500" height="400">

You can use tape or glue to keep the sensors aligned with the embroidered conductive pads on the wristband.

Now you are ready to power your Arduino board and get your wristband playing!

<img src="/Media/Photo%206.7.jpg" width="500" height="400">

Here I use a cheatsheet for the notes and also the notes are not in any order (excuse my musical incapability) :D

If you would like to play the instrument while wearing it on your wrist, I suggest that you cover the electronics with an extra layer of textile to prevent the sensors having direct contact with your skin and being triggered all the time.

THAT'S IT. HAVE FUN WITH YOUR NEW HANDY INSTRUMENT :)
