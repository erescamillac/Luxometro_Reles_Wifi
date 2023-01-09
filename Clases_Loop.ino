void Clas_Luxometro(){
  uint16_t lux = Luxometro.readLightLevel();  //Realizamos una lectura del sensor
  Serial.print("Luz (iluminancia): ");
  Serial.print(lux);
  Serial.println(" lx");

  sent_nr_1 = lux;
  Serial.println( "sent_nr_1 :: " );
  Serial.println( sent_nr_1 );

  if (lux <= Lux_noche) {
    digitalWrite(Rele1, LOW);
    digitalWrite(Rele2, LOW);
    digitalWrite(Rele3, HIGH);
    Serial.println(" Noche  - Todos los Focos Encendidos");

  } else if (lux >= Lux_tarde && lux <= Lux_medio_dia) {
    digitalWrite(Rele1, LOW);
    digitalWrite(Rele2, LOW);
    digitalWrite(Rele3, LOW);
    Serial.println(" Tarde  - Dos Focos Encendidos");

  } else if (lux > Lux_medio_dia && lux < Lux_dia) {
    digitalWrite(Rele1, LOW);
    digitalWrite(Rele2, HIGH);
    digitalWrite(Rele3, LOW);
    Serial.println(" Medio Dia  - Un Focos Encendidos");

  } else if (lux > Lux_dia) {
    digitalWrite(Rele1, HIGH);
    digitalWrite(Rele2, HIGH);
    digitalWrite(Rele3, LOW);
    Serial.println(" Dia - Focos Apagados");
  }

  //delay(50000);
  delay(3000);
}