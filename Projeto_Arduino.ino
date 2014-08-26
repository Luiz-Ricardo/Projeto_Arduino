/*Luiz Ricardo 26/08/2014 - Recupera a umidade e mostra no monitor serial. Fiz usando um relé para simular um motor */
int umidade;

void setup()
{
  Serial.begin(9600); //Inicia a porta serial com velocidade de 9600
  pinMode(13, OUTPUT); // Habilita a porta 13 do Arduino para mandar impulsos
}
void loop()
{
  umidade = analogRead(A0); //Lê o valor analógico da porta A0 do Arduino
  int Porcento = map(umidade, 1023, 0, 0, 100); // Faz a variável "Porcento" receber o valor da Umidade

  Serial.print(Porcento); //Mostra o valor da umidade no monitor serial
  Serial.println("%");
  if(Porcento <=70)
  {
    //Serial.println("Irrigando...");
    digitalWrite(13, HIGH);//Aciona o relé ou mostra uma mensagem no monitor serial
  }

  else
  {
    digitalWrite(13, LOW); //Desliga o rele
  }
  delay(1000);//Tempo em que o valor da Umidade é atualizado.
}

