// Rotary Encoder EC11 code

int a = 2;  // pin assigned to A encoder lead
int b = 4;  // pin assigned to B encoder lead
int c = 3; // pin assigned to switch encoder lead

int enc_value;  // encoder value var

bool flag_00; // flag which will set when encoder make all small cycle

bool lastButtonState; // look at button func...
bool buttonState; // look at button func...

//  reads encoder pinstate A - when encoder stopped - always HIGH !!!
bool a_state()
{
  return digitalRead(a);
}

//  reads encoder pinstate B - when encoder stopped - always HIGH !!!
bool b_state()
{
  return digitalRead(b);
}

void check_enc()
{
  if(a_state() == 0 && b_state() == 1)  // starts roll cw
  {
    while(a_state() == 0) //  3 iteration
    {
      if(b_state() == 0)  // 3 iteration
      {                
        while(b_state() == 0) // 4 iteration
        {
          if(a_state() == 1)  // 4 iteration
          {
            enc_value += 1;
            flag_00 = true;
            Serial.println(enc_value);
          }

          if(flag_00 == true) // exit "while"-cycle in iteration 4
          {
            flag_00 = false;
            break;
          }
        }
      }
    }    
  }
  
  if(b_state() == 0 && a_state() == 1)  // starts roll ccw
  {
    while(b_state() == 0) //  3 iteration
    {
      if(a_state() == 0)  // 3 iteration
      {
        while(a_state() == 0) // 4 iteration
        {
          if(b_state() == 1)  // 4 iteration
          {
            enc_value -= 1;
            flag_00 = true;
            Serial.println(enc_value);
          }

          if(flag_00 == true) // exit "while"-cycle in iteration 4
          {
            flag_00 = false;
            break;
          }
        }    
      }
    }
  }
}

void check_button()
{
  // do an action, for example print on Serial
  Serial.println("Button released");
}


void setup()
{
  Serial.begin(9600);

  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(c, INPUT);

  enc_value = 0;  // encoder value set to "0"

  //  init flags
  flag_00 = false;

  // enable interrupt on button pin
  attachInterrupt(digitalPinToInterrupt(c), check_button, RISING);

  bool lastButtonState = LOW;
}


void loop() 
{
  check_enc();



  
} //loop_end bracket
