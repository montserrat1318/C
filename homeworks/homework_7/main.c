///Instructions: Compila el programa entrando al compilador online, pon los files main.c, file.h y funcion.c (el .txt aparece de manera autom)///

///Cuando das "run" al programa, primero inicia con la opcion de ADMIN, y de PIN utiliza el numero 0. Al añadir un user (worker) desde ADMIN al ser la 1era vez su PIN sera 1///

#include "file.h"

int main()
{
    FILE *flux;
    int temporalPin,
    temporalTime,
    flag = 1,
    PIN,
    opt,
    bucle = 1, 
    user_system;
    time_t temp = time(0);
   
    struct tm *tlocal = localtime(&temp);
    char output[128],
    buffer[32];
    
printf("Hello! Feel very welcome! Today date is %2d/%2d/%d", tlocal->tm_mday,tlocal->tm_mon+1,tlocal->tm_year+1900); ///DATE SHOWN///
printf("\nRight now it is %d:%d:%2d",tlocal->tm_hour-5,tlocal->tm_min,tlocal->tm_sec); //Mostrar Hora
printf("\nCould you be so nice of identify yourself as admin or user, please?\nIf you are USER, please enter 1... If you are ADMIN, please enter 2...\n"); ///WELCOME TO THE SYSTEM///
scanf("%d", &opt);
    if (opt == 1){ ///OPTS OF ADMIN OR USER WORKER I MEAN///
        opt = 0;
    printf("Welcome, could you please introduce your PIN: \n");
    scanf("%d", &PIN);
        if (checkOutPin(PIN) != 1){ //verify PIN in the system (exist?)///
        printf("Ups, sorry! But this PIN does not exixt in this system, please check out the register of the valid PINS in system.tx// or create user as ADMIN\n");
        printf("See you later, have a nice day!\n");
            exit(1);
        }
    printf("Hey! #%d  -- Welcome to the register!-- \nWhat do you want to do in the system?\n", PIN);
    printf("-Put please 1 for ENTRY-\n-Put please 2 for DEPARTURE-\n");
    scanf("%d", &opt);
    
        switch (opt)
        {
            
        case 1: ///ENTRY///
            flux = fopen("log.txt", "a");
        printf("It has been register your PIN of entry:%d Today:%s %s\n", PIN, output, buffer);
        fprintf(flux, "e%d %lu %s %s\n", PIN, (unsigned long)time(NULL), output, buffer);
        printf("BE SUCCESSFUL AT YOUR JOB! YOU CAN DO IT!");
        fflush(flux);
        fclose(flux);
            break;
            
        case 2: ///DEPARTURE///
            flux = fopen("times.txt", "r+");
            while (flag != 0)
            {
        fscanf(flux, "%d %d", &temporalPin, &temporalTime);
                if (temporalPin == PIN)
                {
                    temporalTime += watchTimeofWork(PIN);
                fseek(flux, -3, SEEK_CUR);
                fprintf(flux, "%d %d", PIN, temporalTime);
                fflush(flux);
                fclose(flux);
                    flag = 0;
                }
            }
        flux = fopen("log.txt", "a");
            printf("It has been register your PIN of output:%d Today:%s %s\n", PIN, output, buffer);
            fprintf(flux, "s%d %lu %s %s %d\n", PIN, (unsigned long)time(NULL), output, buffer, watchTimeofWork(PIN));
            printf("\n You have worked for %d secs \n See you soon! Thanks!\n", watchTimeofWork(PIN));
            fflush(flux);
            fclose(flux);
            fprintf(flux, "%d %d\n", PIN, watchTimeofWork(PIN));
                   break;
        }
    }
    
    else if (opt == 2) ///OPTS FOR ADMIN OPTION///
    { 
        opt = 0;
    printf("Welcome! Please introduce your PIN: \n");
    scanf("%d", &PIN);
        if (PIN != 000){
        printf("YOU ARE NOT AN ACTUAL ADMIN...\n");
            EOF;
        }
        else
        {
            while (bucle == 1){
                opt= 0;
            printf("\nHello, ADMIN, what would you like to do now?\n");
            printf("Press 8 to watch assistances of users\tPress 9 to watch a new user (worker)\n");
            printf("Press 4 to watch hours worked of users\tPress 7 to go out\n");
            fflush(stdin);
            scanf("%d", &opt);
            
                switch (opt) // CASES OF THOSE OPTIONS FOR ADMIN///
                {
                    
                case 8: ///LOOK ASSITANCES///
                    printf("Please write down the PIN of the user to watch their assistances:\n");
                    fflush(stdin);
                    scanf("%d", &PIN);
                    if (checkOutPin(PIN) != 1) ///VERIFY PIN IN THE SYSTEM (exist?)///
                    { 
                    printf("Ups, sorry! But this PIN does not exixt in this system, please check out the register of the valid PINS in system.tx// or create user as ADMIN \n");
                    printf("See you later, have a nice day!\n");
                        exit(1);
                    }
                    watchRollAssistance(PIN);
                         break;
                         
                case 9:///create USER///
                    creatRegis();
                         break;
                    
                case 4://LOOK REGISTER OF USERS///
                    printf("Please write down the PIN of the user to watch their hours working: \n");
                    fflush(stdin);
                    scanf("%d", &PIN);
                        if (checkOutPin(PIN) != 1) ///VERIFY PIN IN THE SYSTEM (exist?)///
                        { 
                    printf("Ups, sorry! But this PIN does not exixt in this system, please check out the register of the valid PINS in system.tx// or create user as ADMIN \n");
                    printf("See you later, have a nice day!\n");
                    exit(1);
                    }
                    printf("The USER with the PIN: %d,  HAVE WORKED FOR %d secs \n", PIN, calcHoursLab(PIN));
                           break;
                    
                    case 7: ///EXIT of the program or system///
                        exit(1);
                        break;
                }
            }
        }
    }
    else
    {
        printf("We are so sorry for not to be able to assist you right now with our system, but you did not write a valid option. Press ENTER to go out!");
        exit(1);
    }
}
 ////Raul Chavez explain me how must work this homework, got based on code func by Crdit.AntonioCortes/// 
