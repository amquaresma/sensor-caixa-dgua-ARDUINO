//MATHEUS QUARESMA & SOPHIA MARQUES - autoria 
long distancia = 0;
const int PINO_GATILHO = 3;
const int PINO_ECHO = 5;

const int LED_VERDE = 13;
const int LED_AMARELO = 11;
const int LED_LARANJA = 9;
const int LED_VERMELHO = 7;

const int PINO_MOTOR = 0;

void setup() {
  pinMode(PINO_GATILHO, OUTPUT);
  pinMode(PINO_ECHO, INPUT);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_LARANJA, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  distancia = medirDistancia();
  analogWrite(PINO_MOTOR, distancia);

  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia < 5) {
    acenderLED(LED_VERMELHO);
  } else if (distancia >= 5 && distancia < 50) {
    acenderLED(LED_LARANJA);
  } else if (distancia >= 50 && distancia < 95) {
    acenderLED(LED_AMARELO);
  } else if (distancia >= 95 && distancia < 140) {
    acenderLED(LED_VERDE);
  } else {
    apagarTodosLEDs();
  }

  delay(100); 
}

long medirDistancia() {
  digitalWrite(PINO_GATILHO, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_GATILHO, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_GATILHO, LOW);

  long duracao = pulseIn(PINO_ECHO, HIGH);
  long distanciaCalculada = (duracao / 2) / 29.1;
  return distanciaCalculada;
}

void acenderLED(int led) {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_LARANJA, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(led, HIGH);
}

void apagarTodosLEDs() {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_LARANJA, LOW);
  digitalWrite(LED_VERMELHO, LOW);
}