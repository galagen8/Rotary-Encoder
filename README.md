Hello! Just assign A and B encoder leads to your free pins and take a fast look on schematic below. <br/>
But Encoder Button pin (c) **MUST BE** connected to pin which supports interrupts (for Arduino Nano pins are D2, D3). <br/>
Encoder ticks and button state are translated to IDE Serial Monitor. <br/>
Have fun! 

<hr>
<br/>

<p align="center">
FULL EXPLANATION AND CODE DESCRIPTION
</p>

<br/>
<br/>

I tried many encoder libraries for Arduino and I didn't find library which is really works how I want. I decided to write my own code. <br/>
List of components been used: 

Arduino Nano = 1 pc,            <br/>
EC11 Encoder = 1 pc,            <br/>
Ceramic Caps 1nF = 3 pcs,       <br/>
Resistors 5K = 3 pcs,           <br/>
PCB Protoboard 90x70mm = 1 pcs. <br/>

I used EC11 Mechanical Encoder with push button. It's one of the cheapest and reliable solution on market - only 1$ for 1 pc.  

<br/>
<p align="center">
<img src="https://github.com/user-attachments/assets/ee62ad6e-cf64-40ab-ba48-58848bedf7d2" width="400">
</p>
<br/>
<br/>

Also it has good quiet click sound and it's very nice feeling to spin it.
As every mechanical button encoder leads has a bounce, as encoder leads: <br/>
(https://www.picotech.com/library/blog/what-is-switch-bounce-how-to-implement-debounce). <br/> <br/>
At first I tried to get rid of AB-encoder leads bounce in the code, but it was really not easy.
I found the idea in internet - using some caps on every encoder's lead.
Through testing I settled on a cap with a capacity of 1nF and 5K pull-up resistors. <br/>

Schematics and connections for Arduino Nano EC11: <br/>
A = D2; <br/>
B = D4; <br/>
C (button) = D3; <br/>
Middle Gnd Pin = GND. <br/>

<p align="center">
<img src="https://github.com/user-attachments/assets/7b78ef99-b868-441d-bdd0-337699783461" width="320">
</p>

<br/>
<br/>

I analysed the data comes encoder using Logic Saleae Analyser Software and draw scheme to make it clear:
<br/>
<br/>

<p align="center">
<img src="https://github.com/user-attachments/assets/61c09b7a-e4a7-45c8-9834-b56f862389fa" width="800">
</p>
<br/>
<br/>

As you can see when you rotate encoder clockwise the data is 11_01_00_10_11. <br/>
When you rotate encoder counter-clockwise the data is 11_10_00_01_11. <br/>
So the difference is only in 2 paired bits: 2nd and 4th pairs: 11_01_00_10_11 and 11_10_00_01_11. <br/>

The MCU will compare every bit of data which comes from A and B encoder leads in **check_enc()** function. If sequence does not match the patterns described above - MCU will wait for correct sequence. <br/>

Encoder button attached to interrupt pin D3.

If you your connection and pin assignment are correct - you will see this on your Serial Monitor:

<p align="center">
<img src="https://github.com/user-attachments/assets/690fe00f-04c6-44f0-ac98-52990ef6477c" width="200">
</p>






