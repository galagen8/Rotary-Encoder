I tried many encoder libraries for Arduino and I didn't find library which is really works how I want. I decided to wrote my own code. <br/>
List of components been used: 

Arduino Nano = 1 pc,            <br/>
EC11 Encoder = 1 pc,            <br/>
Ceramic Caps 1nF = 3 pcs,       <br/>
Resistors 5K = 3 pcs,           <br/>
PCB Protoboard 90x70mm = 1 pcs. <br/>

I used EC11 Mechanical Encoder with push button. It's one of the cheapest and reliable solution on market - only 1$ for 1 pc.  

<br/>

<img src="https://github.com/user-attachments/assets/ee62ad6e-cf64-40ab-ba48-58848bedf7d2" width="400">

<br/>
<br/>

Also it has good quiet click sound and it's very nice feeling to spin it.
As every mechanical button encoder leads has a bounce: <br/>
(https://www.picotech.com/library/blog/what-is-switch-bounce-how-to-implement-debounce). <br/> <br/>
At first I tried to get rid of buttons bounce in the code, but it was really not easy.
I found the idea in internet - using some caps on every encoder's lead.
Through testing I settled on a cap with a capacity of 1nF and 5K pull-up resistors. <br/>

Schematics for Arduino Nano EC11:

<img src="https://github.com/user-attachments/assets/7b78ef99-b868-441d-bdd0-337699783461" width="320">

