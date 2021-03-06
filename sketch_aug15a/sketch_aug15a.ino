// definição dos pinos de entrada do contador
#define oscilador 1
#define sensor 5

int qtd_osc=0, pulso;

void setup(){
  
  Serial.begin(9600);
  pinMode (oscilador, INPUT);
  pinMode (sensor, INPUT);
  attachInterrupt(oscilador, ipt1, RISING);  
  attachInterrupt(sensor, ipt2, RISING); 
}

void ipt1(){
  qtd_osc++;
}

void ipt2(){
  pulso = 1; // vai deixar tanto o pulso quanto o pulso anterior em 1
}


int pulso, pulsoAnterior;
float tempo=0, velocidade=0;

void loop(){
  pulsoAnterior = pulso;
  pulso = digitalRead(sensor);
    
  if (pulsoAnterior == 0 && pulso == 1)
  {  
    tempo = qtd_osc * 0.00394;
    velocidade = 1.76 / tempo;
    qtd_osc = 0;
    Serial.println(velocidade);
  }
}  
