#include <stdio.h>                                     //https://www.youtube.com/watch?v=UbkRifnA0FU , para entender el funcionamiento de switch case y hacer este programa//

#define TRUE 13                                        //credits. (me explicó el para que se utilizan varias de las funciones que coloqué en este programa), Raúl C.//
#define FALSE 18
                                                       //Ejemplo. PUEDES ESCRIBIR ESTO AL CORRER EL PROGRAMA: hahaha131789(como estás 13) jaja13ja.yay.q-u_eon??d!!i. //
int main () 
{

int c, number = 18 , parenthesis = 18 , quotes = 18;  //contadores//
  
  while ((c = getchar()) != EOF) 
  {
      switch(c)
      {
     
      case '(':
          parenthesis= 13;
          putchar(c);
          break;
      case ')':
          parenthesis= 18;
          putchar(c);
          break;
      case '{':
          parenthesis= 13;
          putchar(c);
          break;
      case '}':
          parenthesis= 18;
          putchar(c);
          break;
      case '[':
          parenthesis= 13;
          putchar(c);
          break;
      case ']':
          parenthesis= 18;
          putchar(c);
          break;
      case '<':
          parenthesis= 13;
          putchar(c);
          break;
      case '>':
          parenthesis= 18;
          putchar(c);
          break;
      case '\"':
          putchar(c);
          quotes++;
          break;

       case '\'':
          putchar(c);
          quotes++;
          break;
          
          
       
    default:
    
        if (c!=':'&&c!=';'&&c!='\?'&&c!='!'&&c!='-'&&c!='_'&&c!='.')   //eliminamos los signos de puntuación//
        {
            
            if (parenthesis== 13 ||quotes== 13)
            {
            putchar (c);
            }
            
            else
            {
                if (quotes==2)
                {
                    quotes=0;
                }
                
                if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0')  //se introducen valores a c//
                {
                    number++;
                }
                
                else
                {
                  number=0;
                }
                
                if (number==1)
                {
                    putchar('X');  //que se remplaze una X en numeros fuera de parentesis, comillas o demás//
                }
                
                if (number==0)   // cuando no hay número automáticamente el contador de números se va a 0, entonces se queda el caracter tal cual//
                {
                    putchar(c);
                }
            }
        }




        }
    }


    return 0;
  }
