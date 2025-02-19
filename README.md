Hello! Just assign A and B encoder leads to your free I/O pins.  <br/>
But C button lead **MUST BE** connected to pin supported interrupts (for Arduino Nano pins are D2, D3). <br/>
Encoder ticks and button state are translated to IDE Serial Monitor. <br/>
I used EC11 Encoder, but I hope it can works with many mechanical encoders that use same logics. <br/>
Also it can works with encoders which doesn't have push button.
<p align="center">
Have fun! 
</p>

<hr>
<br/>

<p align="center">
FULL EXPLANATION AND CODE DESCRIPTION
</p>

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

Also it has good quiet click sound and it's very nice feeling to spin it.<br/> <br/>
As every mechanical button encoder leads has bounce: <br/>
(https://www.picotech.com/library/blog/what-is-switch-bounce-how-to-implement-debounce). <br/> <br/>
At first I tried to get rid of AB-encoder leads bounce in the code, but it was really not easy.
I found the idea in internet - using some caps connected to ground on every encoder's lead.
Through testing I settled on a cap with a capacity of 1nF and 5K pull-up resistors: <br/>

<br/>
<p align="center">
<img src="https://github.com/user-attachments/assets/7a107446-8240-4e42-a7ca-a2277a24f916" width="400">
</p>
<br/>

Diagram for Arduino Nano EC11: <br/>
A = D2; <br/>
B = D4; <br/>
C (button) = D3; <br/>
Middle Gnd Pin = GND. <br/>

<p align="center">
<img src="https://github.com/user-attachments/assets/7b78ef99-b868-441d-bdd0-337699783461" width="320">
</p>

<br/>
<br/>

I analysed data comes from encoder A-B leads using Logic Saleae Analyser Software and made this scheme to make it clear:
<br/>
<br/>

<p align="center">
<img src="https://github.com/user-attachments/assets/61c09b7a-e4a7-45c8-9834-b56f862389fa" width="800">
</p>
<br/>

As you can see, when you rotate encoder clockwise the data is 11_01_00_10_11. <br/>
When you rotate encoder counter-clockwise the data is 11_10_00_01_11. <br/>
So the difference is only in 2 paired bits: 2nd and 4th pairs: 11_01_00_10_11 and 11_10_00_01_11. <br/>

The MCU will compare every bit of data which comes from A and B encoder leads in **check_enc()** function. If sequence does not match the patterns described above - the function will not be executed and **enc_value** variable stays the same. <br/>

Encoder button attached to interrupt pin D3.

If you your connections and pins' assignment are correct - you will see this on your Serial Monitor:

<p align="center">
<img src="https://github.com/user-attachments/assets/690fe00f-04c6-44f0-ac98-52990ef6477c" width="200">
</p>






