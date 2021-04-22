#include <assert.h>  ///-assert ///          ////Me base en el libro: Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988); para poder ubicarme en el orden mas adecuado para el código///
#include <ctype.h>   ///-toupper ///
#include <stdio.h>   ///-printf, scanf ///
#include <stdlib.h>  ///-rand ///
#include <unistd.h> ///-getpid ///           ///Credits para conocer sobre Unistd.h :https://en.wikipedia.org/wiki/Unistd.h////
#include "calc.h"                                               ///Utilice "the c-refcard" para poder colocar varias funciones que no recuerdaba o que no conocia totalmente///

#define error_minefound 1
#define error_spacefound 2
#define error_none 3
#define columns 10
#define rows 10
#define undiscovered_space '#'
#define discovered_space ' '
#define mine '*'
#define mine_quantity 15  
#define debugger 0                           ///*usado para probar y depurar (eliminar) los errores de otros programas (el programa "objetivo")*///


int getNearbyMines(int fila, int columna, char tablero[rows][columns])      ///Me base en conceptos de aqui https://www.youtube.com/watch?v=yjGrbcD_yRk///
{
  int conteo = 0, filaInicio, filaFin, columnaInicio, columnaFin;
  if (fila <= 0) 
  {
    filaInicio = 0;
  } 
  
  else 
  {
    filaInicio = fila - 1;
  }

  if (fila + 1 >= rows)
  {
    filaFin = rows - 1;
  }
  
  else 
  {
    filaFin = fila + 1;
  }

  if (columna <= 0) 
  {
    columnaInicio = 0;
  } 
  
  else 
  {
    columnaInicio = columna - 1;
  }
  
  if (columna + 1 >= columns) 
  {
    columnaFin = columns - 1;
  } 
  
  else
  {
    columnaFin = columna + 1;
  }
  
  
  int d;
    for (d = filaInicio; d <= filaFin; d++)
  {
      
  int b;
    for (b = columnaInicio; b <= columnaFin; b++) 
    {
        
    if (tablero[d][b] == mine)
    {
        conteo++;
      }
    }
  }
  return conteo;
}


int randomInRange(int min, int max)                                   ///*Para poder obtener numero aleatorio///
{                                                                    /// Credit. pag web: https://parzibyte.me/blog/2019/03/21/obtener-numeros-aleatorios-c///
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}


void startDashboard(char tablero[rows][columns])
{
    
  int b;
  for (b = 0; b < rows; b++)
  {
      
  int d;
    for (d = 0; d < columns; d++)
    {
      tablero[b][d] = undiscovered_space;
    }
  }
}


void placeMine(int fila, int columna, char tablero[rows][columns]) 
{
  tablero[fila][columna] = mine;
}


void placeMineRandomly(char tablero[rows][columns]) 
{
    
  int b;
  for (b = 0; b < mine_quantity; b++) 
  {
    int fila = randomInRange(0, rows - 1);
    int columna = randomInRange(0, columns - 1);
    placeMine(fila, columna, tablero);
  }
}

void printHeaderSeparator()
{
    
  int d;
  for (d = 0; d <= columns; d++) 
  {
    printf("----");
    if (d + 2 == columns)
    {
      printf("-");
    }
  }
      printf("\n");
}

void printRowsSeparator() 
{
    
  int d;
  for (d = 0; d <= columns; d++) 
  {
    printf("+---");
    if (d == columns) 
    {
      printf("+");
    }
  }
      printf("\n");
}

void printHeader() 
{
  printHeaderSeparator();
  printf("|   ");
  
  int b;
  for (b = 0; b < columns; b++)
  {
    printf("| %d ", b + 1);
    if (b + 1 == columns) 
    {
      printf("|");
    }
  }
      printf("\n");
}

char wholeACharacter(int numero) 
{
  return numero + '0';
}

void printDashboard(char tablero[rows][columns], int shouldShowMines) 
{
  printHeader();
  printHeaderSeparator();
  char letra = 'A';
  int b;
  for (b = 0; b < rows; b++) 
  {
    int d;
    printf("| %c ", letra);
    letra++;
    for (d = 0; d < columns; d++) 
    {
      
      char verdaderaLetra = undiscovered_space;
      char letraActual = tablero[b][d];
      
      if (letraActual == mine)
      {
        verdaderaLetra = undiscovered_space;
      } 
      
      else if (letraActual == discovered_space)
      {
        int minasCercanas = getNearbyMines(b, d, tablero);
        verdaderaLetra = wholeACharacter(minasCercanas);
      }
      
      if (letraActual == mine && (debugger || shouldShowMines))
      {
        verdaderaLetra = mine;
      }
      printf("| %c ", verdaderaLetra);
      
      if (d + 1 == columns) 
      {
        printf("|");
      }
    }
    printf("\n");
    printRowsSeparator();
  }
}

int openBox(char filaLetra, int columna, char tablero[rows][columns]) 
{
  
  filaLetra = toupper(filaLetra);
  columna--;
  
  int fila = filaLetra - 'A';
  assert(columna < columns && columna >= 0);
  assert(fila < rows && fila >= 0);
  
  if (tablero[fila][columna] == mine)
  {
    return error_minefound;
  }
  
  if (tablero[fila][columna] == discovered_space) 
  {
    return error_spacefound;
  }
  
  tablero[fila][columna] = discovered_space;
  return error_none;
}

int noUnopenedBoxes(char tablero[rows][columns])
{
  int b;
  
  for (b = 0; b < rows; b++)
  {
    int d;
    for (d = 0; d < columns; d++)
    {
      char actual = tablero[b][d];
      
      if (actual == undiscovered_space) 
      {
        return 0;
      }
    }
  }
  return 1;
}

int main() 
{
  printf("Welcome to The Buscaminas Game!\n\nEnjoy your game! Be careful and good luck!\n\nObjective of this game: Clear a minefield without detonating any.\nAre you ready player 1? GO!\n///Design game by Marcela Montserrat Orozco Hernandez///\n");
  char tablero[rows][columns];
  int shouldShowMines = 0;
  
  srand(getpid());
  startDashboard(tablero);
  placeMineRandomly(tablero);

  while (1) 
  {
    printDashboard(tablero, shouldShowMines);
    if (shouldShowMines) 
    {
      break;
    }
    
    int columna;
    char fila;
    printf("Please, enter the row: ");
    scanf(" %c", &fila);
    printf("Please, enter the column: ");
    scanf("%d", &columna);
    int status = openBox(fila, columna, tablero);
    
    if (noUnopenedBoxes(tablero))
    {
      printf("Congratulations! YOU WON!\n");
      shouldShowMines = 1;
    } 
    
    else if (status == error_spacefound)
    {
      printf("Sorry, you've already opened this box, please try again!\n");
    } 
    
    else if (status == error_minefound)
    {
      printf("You've already lost ... Try again! GO!\n");
      shouldShowMines = 1;
    }
  }
  return 0;
}
