LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void init_lcd();
void refreshLcd(double t);
int h_state = 0;


void init_lcd(){
  lcd.begin(16, 2);
  //lcd.clear();
  //lcd.setCursor(0, 0);
  lcd.print("#_Hot air gun_#");
  Serial.println("LCD ready");
}

void refreshLcd(double t, double s){
  lcd.clear();
  lcd.print("Temp: " + String(t) );
  lcd.setCursor(0,1);
  lcd.print("Set: " + String(s));
}
