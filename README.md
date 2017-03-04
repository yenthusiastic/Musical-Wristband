# Musical Wristband
### An interactive wristband that plays musical notes via embedded touch sensors
### An open source project by Thi Yen Thu Nguyen

This project is done as a final project for the 5-day Textile Academy Bootcamp 2017 (from 20.02 to 24.02)

An overview of my Textile Academy Bootcamp experiences can be found under the <a href="/Textile_Bootcamp_Overview.pdf">Textile Bootcamp Overview PDF File</a>.


## The results 

<img src="/Media/Photo%206.4.jpg" width="500" height="400">
<img src="/Media/Photo%206.6.jpg" width="300" height="400">

#### These photos show the current version of my fully functional musical wristband prototype with the following features:

<ul><p>-<b> Textile-based wearable</b> design with extendable 3D printend patterns</p></ul>
<ul><p>- Embroidered dot patterns which act as <b>interface for touch sensors</b> </p></ul>
<ul><p>- Capable of playing <b>12 different musical notes</b>, which can be modified easily in the software </p></ul>
<ul><p>- <b>"DISCO" light</b> which shows a separate color for each note </p></ul>

#### Some videos of the working prototype can be found <a href="https://drive.google.com/drive/u/0/folders/0B77ddV_s5oS_WGxQaGdNdkNOQzA">here</a> and <a href="https://drive.google.com/open?id=1La1Y-eIfwR8ZsLkto_pnXsW72Wj5l-rd9Q">here.</a>



## Motivation 

Initially, the idea for my final project was to make a bracelet out of interlocking textile patterns (see <a href="/Textile_Bootcamp_Overview.pdf">Overview</a> document, Day 1), and embed a <a href="https://www.adafruit.com/products/2023">Contactless Thermopile Infrared Temperature Sensor</a> from <a href="https://www.adafruit.com/">Adafruit Industries</a>, a loudspeaker, and a compact microcontroller like the <a href="https://www.sparkfun.com/products/10899">Sparkfun Lily Tiny</a> or similar. It will function as a <b>safety wristband</b> which will ring an alarm when the hand is near to a hot object or surface and may get injured by contact with it. For example, in the FabLab we have to work a lot with 3D printers which have hot printing bed as well as hot extruders. As such, one always have to pay attention not to touch these spots. But sometimes, we are too excited to get our newly 3D printed model out of the machine and forget about safety instructions. The wristband would come in handy in such cases.


However, being inspired by the interactive poster from Jana which can play melodies through touching (see <a href="/Textile_Bootcamp_Overview.pdf">Overview</a> document, Day 4), I challenged myself to do something similar instead. This would make the wristband more fun to interact with and not so passive as a temperature sensor. Instead of playing fixed programmed melodies, I would prefer the wristband to <b>let users compose their own melodies</b> with different musical notes by touching different spots on the textile. 


Using an <a href="http://www.exp-tech.de/pro-micro-5v-16mhz">Arduino Pro Micro</a> (which can replace Arduino UNO for this project’s purpose but is more compact and also easy to be programmed through its micro-USB port), I would be able to wire up together 1 loudspeaker, <a href="https://www.adafruit.com/category/168">1 Neopixel</a> and easily up to 12 DIY capacitive sensors (see <a href="/Overview.pdf">Overview</a> document, Day 4), meaning the wristband can play up to 12 different musical notes.


## Resources

In this repository I have included the materials and skills required to complete the project:
<ul> <a href="/BOM.xlsx">1. Components, materials and tools list</a></ul>
<ul> <a href="/Design%20files">2. Design files</a></ul>
<ul> <ul> <a href="/Design%20files/Bracelet-design-rev0.2.ai">a. General design of the wristband</a></ul></ul>
<ul> <ul> <a href="/Design%20files/ScalePattern1mm.stl">b. The 3D printed patterns</a></ul></ul>
<ul> <ul> <a href="/Design%20files/Embroidery-Pattern.png">c. The embroidery conductive pattern for touch sensors</a></ul></ul>
<ul> <a href="/Project documentation.txt">3. Documentation of the making process</a></ul>
<ul> <a href="/Arduino%20Sketch">4. Software/ Arduino sketch</a></ul>
<ul> <a href="/Textile_Bootcamp_Overview.pdf">5. Summary of the skills learned through Textile Academy Bootcamp</a></ul>

and <a href="/Media">photos and videos</a> of the making process.

## License

<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.
