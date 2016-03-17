/**
 * Programación para el dispositivo Arduino Mega 2560.
 * ---------------------------------------------------
 *
 * Este script configura el dispositivo arduino para trabajar
 * junto con la aplicación java Led4Serial, activando los diodos
 * leds en los pines 2, 3, 4 y 5, siendo respectivamente, el led
 * azul, el led rojo, el led rojo y el led amarillo.
 */

// Declaramos las variables utilizadas.
const int azul = 2;
const int verde = 3;
const int rojo = 4;
const int amarillo = 5;

char caracter;
String orden = "";

// Método setup(): Parámetros de los pines y del puerto serie.
void setup() {

  // Inicializamos los pines como output.
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);

  // Iniciamos y apagamos el led interno. Pin 13.
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  // Inicializamos el puerto serie de comunicaciones.
  Serial.begin(9600);
  Serial.println("Conexion Serie Realizada.");

}

// Método loop(): Envío y recepción de mensajes.
void loop() {

  if (Serial.available() > 0) {

    while (Serial.available() > 0) {
      caracter = Serial.read();
      orden.concat(caracter);
      delay(200);
    }

    if (orden == "azulon") {
      digitalWrite(azul, HIGH);
      Serial.println("Led azul Encendido.");
      orden = "";
    }

    else if (orden == "azuloff") {
      digitalWrite(azul, LOW);
      Serial.println("Led azul Apagado.");
      orden = "";
    }

    else if (orden == "verdeon") {
      digitalWrite(verde, HIGH);
      Serial.println("Led verde Encendido.");
      orden = "";
    }

    else if (orden == "verdeoff") {
      digitalWrite(verde, LOW);
      Serial.println("Led verde Apagado.");
      orden = "";
    }

    else if (orden == "rojoon") {
      digitalWrite(rojo, HIGH);
      Serial.println("Led rojo Encendido.");
      orden = "";
    }

    else if (orden == "rojooff") {
      digitalWrite(rojo, LOW);
      Serial.println("Led rojo Apagado.");
      orden = "";
    }

    else if (orden == "amarilloon") {
      digitalWrite(amarillo, HIGH);
      Serial.println("Led amarillo Encendido.");
      orden = "";
    }

    else if (orden == "amarillooff") {
      digitalWrite(amarillo, LOW);
      Serial.println("Led amarillo Apagado.");
      orden = "";
    }

    else if (orden == "allon") {
      digitalWrite(azul, HIGH);
      digitalWrite(verde, HIGH);
      digitalWrite(rojo, HIGH);
      digitalWrite(amarillo, HIGH);
      Serial.println("Todos los leds Encendidos.");
      orden = "";
    }

    else if (orden == "alloff") {
      digitalWrite(azul, LOW);
      digitalWrite(verde, LOW);
      digitalWrite(rojo, LOW);
      digitalWrite(amarillo, LOW);
      Serial.println("Todos los leds Apagados.");
      orden = "";
    }

    else {
      Serial.println(orden);
      orden = "";
    }
  }
}
