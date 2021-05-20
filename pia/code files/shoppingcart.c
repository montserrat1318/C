#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <math.h>
#include "menus.h"


// Estructura para darle varios parametros o caracteristicas a cada producto
typedef struct{
	int precio;
	int cantidad;
	char nombre[15];
}producto;

//Cuentas de cada categoria y cuenta total
float cuentat[6] = {0,0,0,0,0,0};

// declaración global de un vector de 15 productos, (declaración global para no complicar el codigo con punteros)
producto w[15];


int main(){
	char yn,opc[5];
	int m=0,num,i,j;
	int precio[15]={20,18,22,180,120,100,5,10,7,30,50,80,7,12,15};
	char nombre[][15]={"Coca-Cola","Water Ciel","Pepsi Light","Pizza","Hamburger","Hot Dog","Tomato","Avocado","Apple","Olive Oil","Roll Paper","ACE Detergent","Duvalin","Marzipan","Lolly Pop"};
	
//Limpio y relleno la variable cantidad para todos los productos
//relleno los datos con el precio y nombre de las variables cantidad y nombre respectivamente

		for(i=0;i<15;i++){
		w[i].cantidad=0;
		w[i].precio=precio[i];
		strcpy(w[i].nombre,nombre[i]);
		}
	
// do while que me devuelve siempre al menu a menos de termine de comprar		
do{
	//do while que sirve para validar la entrada de numeros dentro del rango 1-6
	do{
	//impresión del menú
	printf("The Fastest & Coolest - Market\n\n");
	printf("--> Categories <--\n\n");
	printf("1.- Sodas\n");
	printf("2.- Fast Food\n");
	printf("3.- Fruits and Vegetables\n");
	printf("4.- Products of Basic Basket\n");
	printf("5.- Candies\n");
	printf("6.- See the shopping cart to finish\n\n");
	printf("Please, select the categorie you need to type: ");
	
	//hago un scanf de un string para la entrada de la función valnum
	fflush(stdin);
	scanf("%s",&opc);
	m=valnum(opc);
	//validación de entrada de un numero entre el 1 al 6
	if((atoi(opc)>6 || atoi(opc)<1) && m==1){
		system("cls");
		printf("Introduce only numbers from 1 to 6\n");
		system("pause");
		system("cls");
		m=0;
	}
	}while(m==0);
	num=atoi(opc);
	
	//dependiendo de la entrada del valor de la variable num va a entrar en la opción da la función menu
	// si se escogio 6 va directo a preguntar si quieres eliminar productos o imprimir ticket
	if(num!=6){
		menu(num);
	}
	else{
		do{
				system("cls");
				printf ("\n Would you like to delete any product y/n?: ");
				fflush(stdin);
				scanf("%c",&yn);
				m=valyn(yn);
				}while(m==0);
				if(yn=='y'){
				menu_cancelar();
				}
				else{
				factura();
				}
		
	}
}while(num!=6);

	return 0;
}
// la función menu te mete al menu de compra de productos de la sección seleccionada 
int menu(int cat){
system("cls");
 char opc[5];
int m=0,num,i;
do{

	//do while que sirve para validar la entrada de numeros dentro del rango 1-4 
	do{
	switch(cat){
		case 1:{
				printf("Products of Categorie: Sodas\n\n");
    			printf("1.- Coca-Cola 500ml (20 pesos)\n");
				printf("2.- Water Ciel 500 ml (18 pesos)\n");
    			printf("3.- Pepsi Light 500 ml (22 pesos)\n");
			break;
		}
		
		case 2:{
				printf("Products of Categorie: Fast Food\n\n");
    			printf("1.- Pizza (4 people) (180 pesos)\n");
  			 	printf("2.- Hamburger with fries (120 pesos)\n");
  				printf("3.- Hot Dog with gelatin (100 pesos)\n");
			break;
		}
		
		case 3:{
				printf ("Products of Categorie: Fruits and Vegetables\n\n");
    			printf("1.- Tomato  c/u (5 pesos)\n");
				printf("2.- Avocado c/u (10 pesos)\n");
    			printf("3.- Apple c/u (7 pesos)\n");
			
			break;
		}
		
		case 4:{
				printf ("Products of Categorie: Products of Basic Basket\n\n");
				printf("1.- Olive Oil (30 pesos)\n");
    			printf("2.- Roll Paper (50 pesos)\n");
    			printf("3.- ACE Detergent (80 pesos)\n");
			
			break;
		}
		
		case 5:{
				printf ("Products of Categorie: Candies\n\n");
    			printf("1.- Duvalin (7 pesos)\n");
    			printf("2.- Marzipan (12 pesos)\n");
    			printf("3.- Lolly Pop (15 pesos)\n");
			
			break;
		}	
	}	
	printf("4.- Back to main Categories\n\n");
	printf("Select the option: ");
   
    
    //validación con la función valnum
	fflush(stdin);
	scanf("%s",&opc);
	m=valnum(opc);
	if((atoi(opc)>4 || atoi(opc)<1) && m==1){
		system("cls");
		printf("Introduce only numbers from 1 to 4\n");
		system("pause");
		system("cls");
		m=0;
	}
	
	}while(m==0);
	num=atoi(opc);
	
		// dependiendo de la entrada de opción a cada producto se agrega la cantidad deseada
		if(num!=4){
		i=num-1+(cat-1)*3;
			do{
				system("cls");
				printf("Amount to add of this product:");
               	fflush(stdin);
				scanf("%s",&opc);
				m=valnum(opc);
               	}while(m==0);
               		
               	w[i].cantidad=w[i].cantidad+atoi(opc);
               		
              	printf("\n*****Added %d to cart %s\n\n",atoi(opc),w[i].nombre);
               	fflush(stdin);
				system("pause");
				system("cls");
				}

}while(num!=4);
system("cls");
}

//La función menu cancelar te mete a un menu para eliminar productos que ya han sido agregados al carrito de compra

int menu_cancelar(){
	char opc[5];
	int m=0,num,num1,eli,i;
	
	//impresión de las categorias a eliminar
	do{
	do{
	system("cls");
	printf("--> Categories <--\n\n");
	printf("1.- Sodas\n");
	printf("2.- Fast Food\n");
	printf("3.- Fruits and Vegetables\n");
	printf("4.- Products of Basic Basket\n");
	printf("5.- Candies\n");
	printf("6.- Finish\n\n");	
	printf("Please, select the categorie you need to type: ");
	fflush(stdin);
	scanf("%s",&opc);
	m=valnum(opc);
	if((atoi(opc)>6 || atoi(opc)<1) && m==1){
		system("cls");
		printf("Introduce only numbers from 1 to 6\n");
		system("pause");
		system("cls");
		m=0;
	}
	}while(m==0);
	num=atoi(opc);
		//el if sirve para cuando el usuario de una opción dentro del rango de 1 a 5 de los menus seleccionados
		//si el usuario ejecuta la opción 6 significa que ya termino
			system("cls");
			if(num!=6){
			do{
				//impresión de los productos de cada categoria
			switch(num){
				case 1: {
				printf ("\n 1.- Delete Coca-Cola 500 ml\n");
          		printf ("\n 2.- Delete Water Ciel 500 ml\n");
          		printf ("\n 3.- Delete Pepsi Light 500 ml\n");
					break;
				}
				
				case 2: {
				printf ("\n 1.- Delete Pizza (4 people)\n");
				printf ("\n 2.- Delete Hamburger with Fries\n");
				printf ("\n 3.- Delete Hot dog with gelatin\n");
					break;
				}
				
				case 3: {
				printf ("\n 1.- Delete Tomato (c/u)\n");
           		printf ("\n 2.- Delete Avocado (c/u)\n");
          		printf ("\n 3.- Delete Apple (c/u)\n");
					break;
				}
				
				case 4: {
				printf ("\n 1.-Delete Olive Oil\n");
          		printf ("\n 2.-Delete Roll Paper\n");
          		printf ("\n 3.-Delete Detergent ACE\n");
					break;
				}
				
				case 5: {
				printf ("\n 1.-Delete Duvalin\n");
          		printf ("\n 2.-Delete Marzipan\n");
           		printf ("\n 3.-Delete Lolly Pop\n");
					break;
				}
			}
				printf ("\n 4.- Back to main Categories\n\n");
				printf("Please, select the product that you want to delete: ");
				fflush(stdin);
				scanf("%s",&opc);
				m=valnum(opc);
				if((atoi(opc)>4 || atoi(opc)<1) && m==1){
				system("cls");
				printf("Introduce only numbers from 1 to 4\n");
				system("pause");
				system("cls");
				m=0;
				}
			}while(m==0);
			
					system("cls");
					num1=atoi(opc);
					if(num1!=4){
					i=num1-1+(num-1)*3;
					if (w[i].cantidad>0){
						do{
               			printf("\n\nAmount to delete of this product: ");
               			scanf("%s",&opc);
               			m=valnum(opc);
               			if((atoi(opc)>w[i].cantidad || atoi(opc)<0) && m==1){
						system("cls");
						printf("Introduce a valid amount\n");
						system("pause");
						system("cls");
						m=0;
						}
               			}while(m==0);
               			eli=atoi(opc);
                   		printf("\n Delete %d of the Cart Shop (%s)\n",eli,w[i].nombre);
                   		system("pause");
                   		w[i].cantidad=w[i].cantidad-eli;
              			}
              			 else{
              			 	system("cls");
              			 	printf("Tiene 0 %s\n\n",w[i].nombre);
              			 	system("pause");
						   }
						}
						else{
							system("cls");
						}
						
					}
//////
}while(num!=6);
factura();
}

// La función factura te crea un ticket en un archivo .txt 
int factura(){
	int i,j,a;
	float iva;
	FILE *f;
	system("cls");
	printf ("See the shopping cart to finish\n\n");
	for(i=0;i<15;i++){
		if(w[i].cantidad>0){
		printf("\n %13s: \t\t\t%d\t%c%d",w[i].nombre,w[i].cantidad,36,w[i].precio*w[i].cantidad);
		}
	}
	
	a=funcday();
	
	f=fopen("Ticket.txt","w"); //modo w = modo escritura
		if(f == NULL){
			printf("No se ha podido abrir.\n");
			exit(1);
		}
		fprintf(f,"\t\t\tThe Fastest & Coolest - Market\n\n");
		fprintf(f,"\tProducts:\t\t\tAmount:\t\tPrice:\n");
		
		for(i=0;i<15;i++){
		if(w[i].cantidad>0){
		fprintf(f,"\t%13s\t\t\t%d\t\t%c%d\n",w[i].nombre,w[i].cantidad,36,w[i].precio*w[i].cantidad);
		}
		}
		fprintf(f,"\n\n\tDiscount Codes Applied:\n");
		
		for(i=0;i<5;i++){
			for(j=0;j<3;j++){
				cuentat[i]=cuentat[i]+w[i*3+j].cantidad*w[i*3+j].precio;
			}
			
		}
		
		iva=(cuentat[0]+cuentat[1]+cuentat[2]+cuentat[3]+cuentat[4])*0.16;
		switch(a){
    	case 0:{
    			if(cuentat[0]+cuentat[1]+cuentat[4]!=0){
    				fprintf(f,"\tProSatSunday\t\t\t10%c\t\t%.02f\n",37,-(cuentat[0]+cuentat[1]+cuentat[4])*0.10);
				}
    			
				break;
			}
			
		case 1:{
				if(cuentat[0]!=0){
    				fprintf(f,"\tProMonday\t\t\t13%c\t\t%.02f\n",37,-(cuentat[0])*0.13);
    			}
				break;
			}
		case 2:{
    			if(cuentat[2]!=0){
    				fprintf(f,"\tProTuesday&Wednesday\t\t15%c\t\t%.02f\n",37,-(cuentat[2])*0.15);
    			}
				break;
			}
		case 3:{
    		if(cuentat[2]!=0){
    				fprintf(f,"\tProTuesday&Wednesday\t\t15%c\t\t%.02f\n",37,-(cuentat[2])*0.15);
    			}
				break;
			}
		case 4:{
    			if(cuentat[3]!=0){
    				fprintf(f,"\tProThursday\t\t\t20%c\t\t%.02f\n",37,-(cuentat[3])*0.20);
    			}
				break;
			}
		case 5:{
    		if(cuentat[2]!=0 ){
    				fprintf(f,"\tProFriyay\t\t\t18%c\t\t%.02f\n",37,-(cuentat[2])*0.18);
    			}
				break;
			}
		case 6:{
				if(cuentat[0]+cuentat[1]+cuentat[4]!=0){
    				fprintf(f,"\tProSatSunday\t\t\t10%c\t\t%.02f\n",37,-(cuentat[0]+cuentat[1]+cuentat[4])*0.10);
    			}
				break;
			}
			}
			
			
		switch(a){
    	case 0:{
    			cuentat[0]=cuentat[0]*0.9;
    			cuentat[1]=cuentat[1]*0.9;
    			cuentat[4]=cuentat[4]*0.9;
				break;
			}
		case 1:{
				cuentat[0]=cuentat[0]*0.87;
				break;
			}
		case 2:{
    			cuentat[2]=cuentat[2]*0.85;
				break;
			}
		case 3:{
    			cuentat[2]=cuentat[2]*0.85;
				break;
			}
		case 4:{
    			cuentat[3]=cuentat[3]*0.80;
				break;
			}
		case 5:{
    			cuentat[1]=cuentat[1]*0.82;
				break;
			}
		case 6:{
				cuentat[0]=cuentat[0]*0.9;
    			cuentat[1]=cuentat[1]*0.9;
    			cuentat[4]=cuentat[4]*0.9;
				break;
			}
		}
		
		cuentat[5]=cuentat[0]+cuentat[1]+cuentat[2]+cuentat[3]+cuentat[4];
			if (cuentat[5] >=1000){
				fprintf(f,"\tProMil\t\t\t\t15%c\t\t%.02f\n",37,-(cuentat[5])*0.15);
				cuentat[5]=cuentat[5]*0.85;
			}
			fprintf(f,"\t\t\t\tIva:\t16%c\t\t%.02f\n",37,iva);
		
		cuentat[5]=cuentat[5]+iva;
           fprintf(f,"\n\t\t\t\tTotal:\t\t\t%.02f",cuentat[5]);
        printf("\nTotal= %.02f",cuentat[5]);  
		 fclose(f);      
		
	
	 
	
}

// La función funcday calcula el dia de hoy a partir de la fecha con la libreria time.h que sirve con presición desde el dia de hoy hasta el 2100
int funcday(){
	int day, month, year,A,B,C,D,numd;
    time_t ahora;
    struct tm *fecha;
    time(&ahora);
    		fecha = localtime(&ahora);
    		day=fecha->tm_mday;
    		month=fecha->tm_mon+1;
    		year=fecha->tm_year+1900;
    
			A=floor(year-2000+(year-2000)/4);
			if((year-2000)%4==0 && (month==0 || month==1)){
			B=-1;
			}
			else B=0;
	switch(month){
	case 1: {
			C=6;
		break;
		}	
	case 2: {
			C=2;
		break;
		}	
	case 3: {
			C=2;
		break;
		}
	case 4: {
			C=5;
		break;
		}
	case 5: {
			C=0;
		break;
		}
	case 6: {
			C=3;
		break;
		}
	case 7: {
			C=5;
		break;
		}
	case 8: {
			C=1;
		break;
		}
	case 9: {
			C=4;
		break;
		}
	case 10: {
			C=6;
		break;
		}		
	case 11: {
			C=2;
		break;
		}
	case 12: {
			C=4;
		break;
		}		
	}
	D=day;
	numd=(A+B+C+D)%7;
    return numd;
}

// La función valyn valida que solo se puedan ingresar los caracteres "y" y "n"
int valyn (char num){
	
	int i;
		
		if(!(num=='y'|| num=='n')){
			printf("\nIntroduce only the characters 'y'  or 'n'\n\n",163);
			system("pause");
			system("cls");		
			return 0;
			}
			return 1;
}

// La función valnum valida la entrada de datos de tipo string para verificar que se ingreso un número
// donde devuelve un 1 si solo se ingreso un número y un 0 si no lo hizo
int valnum (char num[]){
	
		int i;
		for(i=0;i<strlen(num);i++){
		if(!(isdigit(num[i]))){
			printf("\nIntroduce only numbers\n\n",163);
			system("pause");
			system("cls");		
			return 0;
			}}
			return 1;
			}
