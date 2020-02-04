MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);


double readThermo(){
   return thermocouple.readCelsius();
}
