//Giullia, Heloisa, Lucinaria, Marco, Renato
//TERMOPAR TIPO K

#include<LiquidCrystal.h> // inclui a biblioteca LCD
LiquidCrystal lcd (13,12,11,10,9,8); // define os pinos ligados ao LCD

//botões do menu
#define botao_mais 2
#define botao_menos 3

//botões do setpoint
#define MAIS 4
#define MENOS 7

// constante do sensor
const int sensorPin = A0;

// variáveis globais
int setpoint=0, sensorVal = 0, valorLido = 0;
char  menu = 1;
int voltage = 0, temperatura = 0, corrente = 0, conversao = 0, temp = 0, tensao = 0, sensor = 0, temperature = 0;


// funções auxiliares
void changeMenu();
void lcdMenu();
void telaInicial();
void RangeCorrente();
void RangeTensao();
void Setpoint();

void setup()
{
  lcd.begin(16,2);
  pinMode(botao_mais, INPUT_PULLUP);
  pinMode(botao_menos, INPUT_PULLUP);
  pinMode(MAIS, INPUT_PULLUP);
  pinMode(MENOS, INPUT_PULLUP);
}

void loop()
{
  //LCD
  changeMenu(); //função dos botões
  lcdMenu(); //função das telas do LCD

  sensorVal = analogRead(sensorPin); //efetua a leitura da porta analógica 0 
  voltage = (sensorVal/1024.0)*5.0;
  temperatura = (sensorVal/256)*100; // temperatura em graus celsius
  temp = map(sensorVal, 48,256, 0,100); 
  conversao = map(temp, 0, 100, 0,255);
  analogWrite (5, conversao); //pino RangeCorrente
  analogWrite (6, conversao); //pino RangeTensao
  corrente = map(conversao, 0, 255, 0, 20);
  tensao = map(conversao, 0, 255, 0, 12);
}

// Funções Auxiliares

void changeMenu() //configuração dos botões
{
  //botão mais
  if(!digitalRead(botao_mais)) //botão mais pressionado? 
  {
    if(menu==4)
    {
      menu=1;
    }
    else
    {
      menu++;
      delay(200);
    }
      
  }//end botao_mais
  
  //botao menos
  if(!digitalRead(botao_menos)) //botão menos pressionado? 
  {
    if(menu==1)
    {
      menu=4;
    }
    else
    {
      menu--;
      delay(200);
    }
    
  }//end botao_menos 
}//end changeMenu

void lcdMenu() //mostra menu atual
{
  switch(menu) //controle da variável menu
  {
    case 1: 
      telaInicial();
      break;

    case 2:
      RangeCorrente();
      break;

    case 3:
      RangeTensao();
      break;

    case 4:
      Setpoint();
      break;
  }//end switch menu
}//end lcdMenu

void telaInicial()
{
  /*sensorVal = analogRead(sensorPin); //efetua a leitura da porta analógica 0 
  voltage = (sensorVal/1024.0)*5.0;
  temperatura = (sensorVal/256)*100; // temperatura em graus celsius
  temp = map(sensorVal, 0,256, 0,100);  //382
  conversao = map(temp, 0, 100, 0,255);
  analogWrite (5, conversao); //pino RangeCorrente
  analogWrite (6, conversao); //pino RangeTensao
  corrente = map(conversao, 0, 255, 0, 20);
  tensao = map(conversao, 0, 255, 0, 12);*/
  
  lcd.setCursor(0,0); //seleciona o cursor na posição 0 da linha 0
  lcd.print("TEMPERATURA: ");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.println(" C ");
  delay(200);
}

void RangeCorrente()
{
  /*sensorVal = analogRead(sensorPin); //efetua a leitura da porta analógica 0 
  voltage = (sensorVal/1024.0)*5.0;
  temperatura = (sensorVal/256)*100; // temperatura em graus celsius
  temp = map(sensorVal, 0,256, 0,100); 
  conversao = map(temp, 0, 100, 0,255);
  analogWrite (5, conversao); //pino RangeCorrente
  analogWrite (6, conversao); //pino RangeTensao
  corrente = map(conversao, 0, 255, 0, 20);
  tensao = map(conversao, 0, 255, 0, 12);*/
  
  lcd.setCursor(0,0); //seleciona o cursor na posição 0 da linha 0
  lcd.print("RANGE CORRENTE: ");
  lcd.setCursor(0,1);
  lcd.print(corrente);
  lcd.println(" mA ");
  delay(200); 
}

void RangeTensao()
{
  /*sensorVal = analogRead(sensorPin); //efetua a leitura da porta analógica 0 
  voltage = (sensorVal/1024.0)*5.0;
  temperatura = (sensorVal/256)*100; // temperatura em graus celsius
  temp = map(sensorVal, 0,256, 0,100); 
  conversao = map(temp, 0, 100, 0,255);
  analogWrite (5, conversao); //pino RangeCorrente
  analogWrite (6, conversao); //pino RangeTensao
  corrente = map(conversao, 0, 255, 0, 20);
  tensao = map(conversao, 0, 255, 0, 12);*/
  
  lcd.setCursor(0,0); //seleciona o cursor na posição 0 da linha 0
  lcd.print("RANGE TENSAO: ");
  lcd.setCursor(0,1);
  lcd.print(tensao);
  lcd.println(" V ");
  delay(200);
}

void Setpoint()
{
  /*sensorVal = analogRead(sensorPin); //efetua a leitura da porta analógica 0 
  voltage = (sensorVal/1024.0)*5.0;
  temperatura = (sensorVal/256)*100; // temperatura em graus celsius
  temp = map(sensorVal, 0,256, 0,100); //382
  conversao = map(temp, 0, 100, 0,255);
  analogWrite (5, conversao); //pino RangeCorrente
  analogWrite (6, conversao); //pino RangeTensao
  corrente = map(conversao, 0, 255, 0, 20);
  tensao = map(conversao, 0, 255, 0, 12);*/
  
  lcd.setCursor(0,0); 
  lcd.print("SETPOINT: ");
  lcd.setCursor(0,1);
  lcd.print(setpoint); 
  lcd.println(" C ");
  delay(200);

  if(!digitalRead(MAIS))
  {
    setpoint++;  
    delay(100);
  }

  if(!digitalRead(MENOS))
  {
    setpoint--;
    delay(100); 
  } 
}
