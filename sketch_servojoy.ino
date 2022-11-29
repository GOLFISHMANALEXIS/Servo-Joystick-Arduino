//Libreria correspondiente al servo
#include <Servo.h>
Servo servomotor;

int direccionX = A0;  //Pin para leer los movimientos en el eje X
int direccionY = A1;  //Pin para leer los movimientos en el eje Y
int pulsador_joystick = 22;  //Pin para leer el pulsador

int lecturaX;  //Almacena el valor leido en el eje X
int lecturaY;  //Almacena el valor leido en el eje Y
int lectura_pulsador;  //Almacena el valor leido del pulsador

//Variable para el control de la posicion del servo
//El servo inicialmente esta en 90 grados
int posicion_servo = 90;

void setup() {

  servomotor.attach(6); //Pin PWM 6 del Arduino

  pinMode(direccionX, INPUT);
  pinMode(direccionY, INPUT);
  //Activamos la resistencia PULL-UP interna del Arduino
  //Si el pulsador está presionado, muestra un 0
  pinMode(pulsador_joystick, INPUT_PULLUP);

}

void loop() {

  int lecturaX = analogRead(A0);  //Lee y almacena el valor del joystick en X
  int lecturaY = analogRead(A1);  //Lee y almacena el valor del joystick en Y
  int lectura_pulsador = digitalRead(22);  //Lee y almacena el valor del pulsador del joystick

  //Si se mueve el joystick a la derecha, el angulo aumenta
  if (lecturaX >= 550)
  {
    posicion_servo++;

    if (posicion_servo > 180)  //El angulo no puede ser mayor a 180
    {
      posicion_servo = 180;
    }
  }

  //Si se mueve el joystick a la izquierda, el angulo disminuye
  if (lecturaX <= 450)
  {
    posicion_servo--;

    if (posicion_servo < 0)  //El angulo no puede ser menor a cero
    {
      posicion_servo = 0;
    }
  }

  //Si se presiona el pulsador del joystick, el servo vuelve a los 90 grados
  if (lectura_pulsador == LOW)
  {
    posicion_servo = 90;
  }

  //Escribimos el angulo en el servo
  servomotor.write(posicion_servo);
  delay(10);

}
