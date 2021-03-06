/*
 * TOMATE
 */
int analogPinTomate = A0;
int analogTomateValue;
int limitTomate = 500;
/*
 * FINE HERBE
 */
int analogPinFineHerbe = A1;
int analogFineHerbeValue;
int limitFineHerbe = 450;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);//VALVE TOMATE
  pinMode(12, OUTPUT);//VALVE FINE HERBE

  pinMode(11, OUTPUT);
}

void loop() {

  analogTomateValue = analogRead(analogPinTomate);
  analogFineHerbeValue = analogRead(analogPinFineHerbe);
  /*
   * TOMATE
   */
  Serial.println("Analog TOMATE valeur : ");
  Serial.println(analogTomateValue);
  if (analogTomateValue<limitTomate) {
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  Serial.println("Le taux d'humidité des TOMATE est *HAUTE* donc pas besoin d'arroser !");
  }
  else {
  digitalWrite(13, HIGH);
  Serial.println("Le taux d'humidité des TOMATE est *BAS*, la vanne ouvre !");
  delay(1000);
  digitalWrite(11, HIGH);
  Serial.println("** La pompe Start T **");
  }

  /*
   * FINE HERBE
   */
  Serial.println("Analog Fine Herbe valeur : ");
  Serial.println(analogFineHerbeValue);
  if (analogFineHerbeValue<limitFineHerbe) {
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  Serial.println("Le taux d'humidité des FINE HERBE est *HAUTE* donc pas besoin d'arroser !");
  }
  else {
  digitalWrite(12, HIGH);
  Serial.println("Le taux d'humidité des FINE HERBE est *BAS*, la vanne ouvre !");
  delay(1000);
  digitalWrite(11, HIGH);
  Serial.println("** La pompe Start FH **");
  }
  delay(2000); 
}
