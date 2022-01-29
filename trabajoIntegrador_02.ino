#include <IRremote.h>//librería para control remoto 

/*//Declarando variables para el control remoto*/

//Creando el objeto receptor mediante IRrecv
IRrecv receptor(2);
//declarando un objeto que va interpretar el mensjae recibido
//decode_results resultado;
//declaramos 2 variables de tipo decode_results
decode_results codLe; 
decode_results codLeNue;

//Declarando variables para los motores
const int AIA = 6;
const int AIB = 11;
const int BIA = 9;
const int BIB = 10;

//Declarando varioables para leds
const int ledBlanco = 4;
const int ledRojo1 = 7;
const int ledRojo2 = 8;

//Variables Sensor Ultrasonico
int disparo = 5;
const int echo = 3;
long tiempoPulso;
float dstMedida;

int ledTest = 13;

void setup() {

  //Habilitando la recepción de mensaje
  receptor.enableIRIn();
  Serial.begin(9600);
  
  //Entrada-Salida Motores
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT); 
  pinMode(ledTest, OUTPUT);
  //Apagamos los motores y led de test
  analogWrite(AIA, LOW);
  analogWrite(AIB, LOW);
  analogWrite(BIA, LOW);
  analogWrite(BIB, LOW);
  analogWrite(ledTest, LOW);

  //Declarando variables para led

  pinMode(ledBlanco, OUTPUT);
  pinMode(ledRojo1, OUTPUT);
  pinMode(ledRojo2, OUTPUT);

  pinMode(ledTest, OUTPUT);
  pinMode(disparo, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(disparo, LOW);
  
  
  //Saludo Inicial
  parpadeo(1);

  //Inicio de robot con luces led

  digitalWrite(ledBlanco, HIGH);
  digitalWrite(ledRojo1, HIGH);
  digitalWrite(ledRojo2, HIGH);
  delay(1000);
  digitalWrite(ledBlanco, LOW);
  digitalWrite(ledRojo1, LOW);
  digitalWrite(ledRojo2, LOW);

}

void loop() {

  
  digitalWrite(disparo, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparo, LOW);
  tiempoPulso = pulseIn(echo, HIGH);
  dstMedida = 0.0340 / 2 * tiempoPulso;
  delay(200);
  
  if (receptor.decode(&codLeNue)) {
    receptor.resume();
  }

  if (codLeNue.value != 0xFFFFFFFF && dstMedida > 4) {
    digitalWrite(ledTest, HIGH);
    delay(50);
    digitalWrite(ledTest, LOW);
    delay(50);
    
    Serial.println(codLeNue.value,HEX);
    codLe = codLeNue;
    
    switch(codLeNue.value){
      case 0x57439867:                
        adelante();
        break;
      case 0x57439966:                
        adelante();
        break;
      case 0x57437887:                
        izquierda();
        break;
      case 0x57437986:                
        izquierda();
        break;
      case 0x5743B44B:               
        derecha();
        break;
      case 0x5743B54A:               
        derecha();
        break;
      case 0x5743CC33:               
        atras();
        break;
      case 0x5743CD32:               
        atras();
        break;
      case 0x703748B:                 
        parar();
        digitalWrite(ledRojo1, HIGH);
        digitalWrite(ledRojo2, HIGH);
        delay(1500);
        digitalWrite(ledRojo1, LOW);
        digitalWrite(ledRojo2, LOW);
        break;
      case 0x574354AB:               
        parar();
        digitalWrite(ledRojo1, HIGH);
        digitalWrite(ledRojo2, HIGH);
        delay(1500);
        digitalWrite(ledRojo1, LOW);
        digitalWrite(ledRojo2, LOW);
        break;
      case 0x574355AA:               
        parar();
        break;
      //Leds
      //LedRojo Derecha
      case 0x57432CD3:
        digitalWrite(ledRojo1, HIGH);
        delay(500);
        digitalWrite(ledRojo1, LOW);
        delay(500);
        break;
      case 0x57432DD2:
        digitalWrite(ledRojo1, HIGH);
        delay(500);
        digitalWrite(ledRojo1, LOW);
        delay(500);
        break;
      //LedBlanco
      case 0x574332CD:
        digitalWrite(ledBlanco, HIGH);
        digitalWrite(ledRojo1, HIGH);
        digitalWrite(ledRojo2, HIGH);
        break;
      case 0x574333CC:
        digitalWrite(ledBlanco, HIGH);
        digitalWrite(ledRojo1, HIGH);
        digitalWrite(ledRojo2, HIGH);
        break;
      //LedRojo Izquierda
      case 0x5743AA55:
        digitalWrite(ledRojo2, HIGH);
        delay(500);
        digitalWrite(ledRojo2, LOW);
        delay(500);
        break;
      case 0x5743AB54:
        digitalWrite(ledRojo2, HIGH);
        delay(500);
        digitalWrite(ledRojo2, LOW);
        delay(500);
        break;
        
      case 0x57431EE1:
        digitalWrite(ledRojo1, LOW);
        digitalWrite(ledBlanco, LOW);
        digitalWrite(ledRojo2, LOW);
      default:
        parpadeo(2);
    }     
  }
  else{
    digitalWrite(ledRojo1, HIGH);
    digitalWrite(ledRojo2, HIGH);
    parar();
    delay(2000);
    digitalWrite(ledRojo1, LOW);
    digitalWrite(ledRojo2, LOW);
  }

}

//Creación de funciones, adelante, atrás, derecha, izquierda

void adelante(){
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

void atras(){
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);
}

void izquierda(){
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 80);
  analogWrite(BIB, 0);
}

void derecha(){
  analogWrite(AIA, 80);
  analogWrite(AIB, 0);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);
}

void parar(){
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}

void parpadeo(int veces){
  for(int j=0; j<=veces;j++){
    digitalWrite(ledTest, HIGH);
    delay(500);
    digitalWrite(ledTest, LOW);
    delay(500);
  }
}
