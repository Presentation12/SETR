/*
  Declaração de variáveis:
    vermelho: variavel que contem o pinSlot para o LED de cor vermelha
    amarelo: variavel que contem o pinSlot para o LED de cor amarelo
    verde: variavel que contem o pinSlot para o LED de cor verde
*/
int vermelho = 8;
int amarelo = 9;
int verde = 10;


void setup()
{
  //Atribuição de função de cada pin (todos serão OUTPUT)
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop()
{
  //Acende luz vermelha e espera 5 segundos
	digitalWrite(vermelho, HIGH);
  delay(5000);

  //Apaga luz vermelha, acende luz verde e espera 5 segundos
	digitalWrite(vermelho, LOW);
	digitalWrite(verde, HIGH);
  delay(5000);

  //Acende luz amarela, mantendo a verde e espera 2 segundos
	digitalWrite(amarelo, HIGH);
  delay(2000);	

  //Apaga a luz verde e amarela
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);

  //Programa dá loop, acendendo logo de início a luz vermelha
}
