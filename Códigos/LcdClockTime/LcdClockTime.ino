/*Tips:
    //lcd.setCursor(coluna,linha);
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int lcd_botao    = 0;
int botao_A0     = 0;
const char botaoRIGHT  0
const char botaoUP     1
const char botaoDOWN   2
const char botaoLEFT   3
const char botaoSELECT 4
const char botaoNONE   5

// Função de Leitura de botoes
int leitura_LCD_botoes() {
 botao_A0 = analogRead(0);      // leitura do pino A0 
 // Verifica se leitura é maior de 1000, significa que não foi apertado nenhum botão
 if (botao_A0 > 1000) return botaoNONE; 
 
 // Verifica se leitura é menor que 50, botao right foi pressionado
 if (botao_A0 < 50)   return botaoRIGHT;  
 
 // Verifica se leitura é menor que 250, botao up foi pressionado
 if (botao_A0 < 250)  return botaoUP; 
 
 // Verifica se leitura é menor que 450, botao down foi pressionado
 if (botao_A0 < 450)  return botaoDOWN; 
 
 // Verifica se leitura é menor que 650, botao left foi pressionado
 if (botao_A0 < 650)  return botaoLEFT; 
 
 // Verifica se leitura é menor que 850, botao select foi pressionado
 if (botao_A0 < 850)  return botaoSELECT;  

 return botaoNONE;  // caso nenhuma condição for atendida
}

void executar (lcd_botao) {
   case botaoRIGHT:
     {
      // chama função luminosidade
     temperaturaC(); 
     break;
     }
   case botaoLEFT:
     {
      // chama função temperatura
     temperaturaF();
     break;
     }
   case botaoUP:
     {
      // chama função temperatura
     luminosidadeP();
     break;
     }
   case botaoDOWN:
     {
      // chama função luminosidade
        luminosidade();
        break;
     }
     case botaoSELECT:
     {
      lcd.setCursor(0,1); 
      lcd.print("Pressione botoes ");
      break;
     }
    }

void setup()
  {
    lcd.begin(16, 2); 
   }
 
void loop()
{
    lcd_botao = leitura_LCD_botoes(); 
    executar();
}
