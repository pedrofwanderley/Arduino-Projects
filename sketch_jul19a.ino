
// Carrega a biblioteca do LCD
#include <LiquidCrystal.h>

// Inicializa o LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600);
  // Define o LCD com 20 colunas e 4 linhas
  // As linhas nao de 0 à 3 e as colunas de 0 à 19;
  lcd.begin(20, 4);
  
  // Mostra informacoes no display
  lcd.setCursor(1,0);
  lcd.print("Velocidade");
  lcd.setCursor(1,1);
  lcd.print("Rpm");
  lcd.setCursor(1,3);
  lcd.print("Combustivel");
}

void loop()
{
   // read the first tension;
  int firstRead = analogRead(A0);

  // read the second tension;
  int secondRead = analogRead(A0);

  //Calculates the medium tension between frist and second read;
  float media = (firstRead + secondRead) / 2.0;
  // Set the lcd cursor to forth column and third line;
  lcd.setCursor(3,10);
  // Should print on the lcd the calculated media, instanteneously;
  lcd.print(media)
  delay(1);        // delay in between reads for stability
}
