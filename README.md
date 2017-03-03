# Musical Wristband
### An interactive wristband that plays musical notes via embedded touch sensors
### An open source project by Thi Yen Thu Nguyen

This project is done as a final project for the 5-day Textile Academy Bootcamp 2017 (from 20.02 to 24.02)

An overview of the Textile Academy Bootcamp documentation can be found here.

############


<h1> The results </h1>



<h1> Motivation </h1>

Initially, the idea for my final project was to make a bracelet out of interlocking textile patterns (see <a href="/Overview.pdf">Overview</a> document, Day 1), and embed a <a href="https://www.adafruit.com/products/2023">Contactless Thermopile Infrared Temperature Sensor</a> from <a href="https://www.adafruit.com/">Adafruit Industries</a>, a loudspeaker, and a compact microcontroller like the <a href="https://www.sparkfun.com/products/10899">Sparkfun Lily Tiny</a> or similar. It will function as a <b>safety wristband</b> which will ring an alarm when the hand is near to a hot object or surface and may get injured by contact with it. For example, in the FabLab we have to work a lot with 3D printers which have hot printing bed as well as hot extruders. As such, one always have to pay attention not to touch these spots. But sometimes, we are too excited to get our newly 3D printed model out of the machine and forget about safety instructions. The wristband would come in handy in such cases.


However, being inspired by the interactive poster from Jana which can play melodies through touching (see <a href="/Overview.pdf">Overview</a> document, Day 4), I challenged myself to do something similar instead. This would make the wristband more fun to interact with and not so passive as a temperature sensor. Instead of playing fixed programmed melodies, I would prefer the wristband to let users compose their own melodies with different musical notes by touching different spots on the textile. 


Using an <a href="http://www.exp-tech.de/pro-micro-5v-16mhz">Arduino Pro Micro</a> (which can replace Arduino UNO for this project’s purpose but is more compact and also easy to reprogram through its micro-USB port), I would be able to wire up 1 loudspeaker, <a href="https://www.adafruit.com/category/168">1 Neopixel</a> and easily up to 12 DIY capacitive sensors (see <a href="/Overview.pdf">Overview</a> document, Day 4), meaning <b>the wristband can play up to 12 different musical notes</b>.


<h1> Resources </h1>

In this repository I have included the materials required to complete the project:
<ul> <a href="/BOM.xlsx">1. Electronic components list</a></ul>
<ul> <a href="/Design%20files">2. Design files</a></ul>
<ul> <ul> <a href="/Design%20files/Bracelet-design-rev0.2.ai">a. General design of the wristband</a></ul></ul>
<ul> <ul> <a href="/Design%20files/ScalePattern1mm.stl">b. The 3D printed patterns</a></ul></ul>
<ul> <a href="/Project documentation.txt">3. Documentation of the steps to finish the project</a></ul>
<ul> <a href="/Media">4. Photos of the process</a></ul>
<ul> <a href="/Arduino%20Sketch">5. Software/ Arduino sketch for Arduino Pro Micro</a></ul>

and an <a href="/Overview.pdf">overview</a> of the Textile Academy Bootcamp experiences.


<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.
