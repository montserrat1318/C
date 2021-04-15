#include <stdio.h>                                   ///Based and modify on: Example Reverse Polish Calculator of the book "The C programming Language"///
#include <stdlib.h>                                 ///Credit.Me BASE en el orden y ciertas funciones de un código en internet: http://codigomaldito.blogspot.com/2008/04/calculadora-con-notacin-polaca-inversa.html///
#include <ctype.h> 
#include "calc.h"

#define MAXOP 100 

int main()                                                       ///*Me explico el funcionamiento del programa y me ayudo Raul Chavez*///
{
    int type;
    int quantity_letters=0; 
    int quantity_numbers=0; 
    int quantity_errors=0; 


    double op2;
    char s[MAXOP];
    int found_letter=0;
    int question=0;
    int assignment=0;
    int found_number =0;
    int move=0;
    int answer_no=0;
    int answer_yes=0;
    int error=0;

    int abc[26]={0};     ///Las 26 letras del alfabeto son especificadas///
    int contador[26]={0}; 

              printf("Please input your variable and the value: like... m= 3 ");

     while ((type = getop(s)) != EOF) 
     {
        if (move==0) 
        {
        switch (tolower(type)) 
        {
            case NUMBER:
            push(atof(s));
            found_number = atof(s);
            quantity_numbers++;
            break;
            
            case '+':
            push(pop() + pop());
            break;
            
            case '*':
            push(pop() * pop());
            break;
            
            case '-':
            op2 = pop();
            push(pop() - op2);
            break;
            
            case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("ERROR: Zero divisor\n");

            break;
            case '\n':
            if (!assignment&&!question)
            { 
            printf("\t%.4f\n", pop());

            assignment=0;                    ///se regresa inicialmente a los valores de nuevo ///
            found_letter=0;
            question=0;
            found_number =0;
            quantity_numbers=0;
            quantity_letters=0;
            quantity_errors=0;
            }
            
    else if (assignment==1&&!question&&quantity_numbers==1&&quantity_letters==1)
    { 
            if (contador[found_letter]==0){
                abc[found_letter]=found_number;
                printf("Assignment Prepare \n");
                contador[found_letter]++;

                assignment=0;      ///se regresa inicialmente a los valores de nuevo ///
                found_letter=0;
                question=0;
                pop();
                pop();
                found_number=0;
                quantity_numbers=0;
                quantity_letters=0;
                quantity_errors=0;

            }

    else
    {

                move=1;
                printf("Do you need to rewrite the value of the variable? yes-> y No-->n\n");
                pop();
                pop();
            }
            }

    else if (assignment==1&&question==1&&quantity_numbers==1&&quantity_letters==1)
    {
                abc[found_letter]=found_number;
                pop();
                pop();
                printf("Assignment Prepare\n");
                contador[found_letter]++;           ///Si el contador de assignment checa que es la primera vez dando valor, no debe preguntar///

                assignment=0;
                found_letter=0;
                question=0;
                found_number=0;
                quantity_numbers=0;
                quantity_letters=0;
                quantity_errors=0;
            }
    else{
                printf("ERROR: Please check the input\n");
                assignment=0;                               ///se regresa inicialmente a los valores de nuevo ///
                found_letter=0;
                question=0;
                found_number=0;
                quantity_numbers=0;
                quantity_letters=0;
                pop();
                pop();
                quantity_errors=0;
            }

            break;
            case '=':
            assignment=1;
            break;
            case ':':
            question=1;
            break;
            default:
            if (type>=97&&type<=122)   ///letras minusculas van del 97 al 122///
            {
                push(abc[type-97]);    ///push el arreglo en la posicion type-97///
                found_letter=type-97;  ///la letra encontrada///
                quantity_letters++;    ///la letra encontrada///

            }
            else 
            {
            quantity_errors++;
            printf("ERROR: Ir is found an unknown command %s\n", s);
            }
            break;
        }

     }

     else
     {

     switch (tolower(type)) 
     {
     case 'y':
     answer_yes++;
     push(0); 
     break;
     case 'n':
     answer_no++;
     push(0); 
     break;
     case '\n':

     if (answer_yes==1&&answer_no==0&&error==0)
     {
        abc[found_letter]=found_number;
        pop();
        printf("Assignment Prepare\n");

        contador[found_letter]++;

        assignment=0;                     ///se regresa inicialmente a los valores de nuevo ///
        found_letter=0;
        question=0;
        found_number=0;
        answer_no=0;
        answer_yes=0;
        error=0;
        move=0;
        quantity_numbers=0;
        quantity_letters=0;
        quantity_errors=0;

     }
     else if (answer_yes==0&&answer_no==1&&error==0)
     {
        pop();
        printf("The assignment did not work (check)\n");

        assignment=0;                       ///se regresa inicialmente a los valores de nuevo ///
        found_letter=0;
        question=0;
        found_number=0;
        answer_no=0;
        answer_yes=0;
        move=0;
        error=0;
        quantity_numbers=0;
        quantity_letters=0;
        quantity_errors=0;

     }
     else{
        pop();
        printf("error: Check your input\n\n");
        printf("Do you want to rewrite the variable? y -> YES n->NO");
        answer_no=0;
        answer_yes=0;
        error=0;
        quantity_numbers=0;
        quantity_letters=0;
        quantity_errors=0;
     }
     break;
     default:
     error++;
     break;
     }
     }
    }
    return 0;
}

/////////LOS SIGUIENTES ARCHIVOS SON NECESARIOS PARA EL FUNCIONAMIENTO DE LA CALCULADORA Y SE ENCUENTRAN COMO EJEMPLOS EN EL LIBRO DE REFERENCIA//////

#include <ctype.h>                               ///archivo: getop.c///
int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';

    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
    {                                      ///Credits."If" basado de code Raúl Chavéz.///
        if (!isalpha(c))                  ///Si no es alpha (letra del alfabeto) que regrese el caracter///
        return c;                         
        if (isalpha(c))
        {
        return tolower(c);              ///se especifica que regrese la letra minuscula de dicha letra///
        }

    }

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }

    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;

    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}


#define BUFSIZE 100      ///archivo: getch.c///
char buf[BUFSIZE];
int bufp = 0;


int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

#define MAXVAL 100       ///archivo:stack.c///
int sp=0;
double val[MAXVAL];
void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
