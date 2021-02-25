#include <stdio.h>
int main()
{                                       //Angel Raúl Chavez, helps me to understand what to do in this homework//

    int c;
    int state = 0;
    int s;
    int i = 0;
    char strong[7]={"strong"};
    
    while((c = getchar()) != EOF)
{

    if(c == '<' || c == ';' || c == 'B' || c == '"'|| c == '{')
    {
        do
        {
            c = getchar();
        } while(c != EOF && c != '>');
    }
    else
    {
        putchar(c);

    }

}

}
