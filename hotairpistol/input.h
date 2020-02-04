class Button
{
public:
  Button();
  void init(int pin, bool type);                                             //inizializzo motore con funzionalita bloccanti e non bloccanti
  
  bool isPressed();
  bool getState();
  

private:
  int pin;
  bool type;
  bool state;
  
};

Button::Button(){
  
}

void Button::init(int pin, bool type){
  this->pin = pin;
  this->type = type;
  pinMode(pin,INPUT);
}

bool Button::isPressed(){
  if(digitalRead(pin) && type){
    state = 1;
    return 1;
  }

  if(!digitalRead(pin) && !type){
    state = 1;
    return 1;
  }
  state = 0;
  return 0;
}

bool Button::getState(){
  if(digitalRead(pin) && type){
    state = 1;
    return 1;
  }

  if(!digitalRead(pin) && !type){
    state = 1;
    return 1;
  }
  state = 0;
  return 0;
}

Button bt0;
Button bt1;
Button bt2;

void init_button(){
  bt0.init(PIN_BT0, false);
  bt1.init(PIN_BT1, false);
  bt2.init(REED, false);
  Serial.println("Button ready");
}
