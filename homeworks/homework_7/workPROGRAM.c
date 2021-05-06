#include "file.h"                                 

int creatRegis(void)
{
       int newPIN = 1,
       PIN, 
       flag = 0;
       char horaee[30],
       hours[30], 
       days [40];
       FILE *fich;
    fich = fopen("system.txt", "a");
      if (fich == NULL)
      {
    printf("ERROR: The file system.txt could not be created right now\n");
    }
    
    else
	{
        while (1)
		{
            if (checkOutPin(newPIN))
			{
                newPIN++;
            }
            else
			{
                     break;                                    
            }
        }

fich = fopen("system.txt", "a");
    printf("The new pin generated automatically is : %d\n", newPIN);
    printf("Introduce the days that it works, without spaces (example: MondayTuesday   or   FridaySaturdayMonday\n");
    fflush(stdin);
    scanf("%s", days);
    printf("Introduce the hour of entry of the worker/user, please (example: 12:30 , 21:00 , etc)\n");
    fflush(stdin);
    scanf("%s", horaee);
    printf("Introduce the hour of departure of the worker/user, please  (example: 12:30 , 21:00 , etc)\n");
    fflush(stdin);
    scanf("%s", hours);
    fprintf(fich, "c%d e%s s%s d%s\n", newPIN, horaee, hours, days);
    printf("Successfully added, thanks!");
    fflush(fich);
    fclose(fich);
       fich = fopen("times.txt", "a");
    fprintf(fich, "%d 0 \n", newPIN);
    fflush(fich);
    fclose(fich);
    printf("\n");
    }
}

int checkOutPin(int PIN)
{
    int pins[9], 
    j = 0;
    int d;
    FILE *fich;
    fich = fopen("system.txt", "r");
    
if (fich == NULL)
	{
    printf("ERROR: The file system.txt could not be created right now\n");
    }
    
    else
	{
        while ((d = fgetc(fich)) != EOF)
		{
            if (d == 'd')
			{
                d = fgetc(fich);
                pins[j] = d - '0';
                if (PIN == pins[j])
				{
                fflush(fich);
                fclose(fich);
                    return 1;
                }
                j = +1;
            }
        }
    }
            fflush(fich);
            fclose(fich);
}

int watchRollAssistance(int PIN)
{
    int d, 
    assistance = 0;
    FILE *fich;
        fich = fopen("log.txt", "r");
    while ((d = fgetc(fich)) != EOF)
	{
        if (d == 's')
        {
            d = fgetc(fich) - '0';
            if (d == PIN)
			{
            assistance++;
            }
        }
    }
fflush(fich);
fclose(fich);
  printf("\nThe user %d have : %d assistances\n", PIN, assistance);
}

int watchTimeofWork(int PIN)
{
    char time1[20], 
    time2[20];
    int t1, t2, tempo;
    int d, assistance = 0;
       FILE *fich;
    fich = fopen("log.txt", "r");
while ((d = fgetc(fich)) != EOF)
{
    if (d == 'e')
	{
        d = fgetc(fich) - '0';
        if (d == PIN)
		{
            d = fgetc(fich) - '0';
            fgets(time1, 11, fich);
            t1 = atoi(time1);
            }
        }
    }
tempo= (unsigned long)time(NULL) - t1;
    fflush(fich);
    fclose(fich);
        return tempo;
}
int calcHoursLab(int PIN)
{
    int hours, d, pinarch;
      FILE *fich;
    fich = fopen("times.txt", "r");
while (1)
{
 fscanf(fich, "%d %d", &pinarch, &hours);
    if (pinarch == PIN)
	{
        return hours;
            break;
        }
    }
}
 ////Raul Chavez explain me how must work this homework, got based on code func by Crdit.AntonioCortes///