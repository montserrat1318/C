#include <stdio.h>
#include <time.h>
#include <math.h>

int funcday();
float cuentat=0,iva=0;
int cocacola=0, waterciel=0, pepsilight=0, pizza=0, hamburger=0, hotdog=0, tomato=0, avocado=0, apple=0, oil=0, paper=0, detergent=0, duva=0, maza=0, lollyp=0;
int pec=0, opcnl=0, opcc=0, prod=0, eli=0;
float cuentat_1,cuentat_2,cuentat_3,cuentat_4,cuentat_5;
char eliminar;


int main (){
    int opcnl=0, opcc=0;
    int a;
    FILE *f;
    
do{
      
      printf("The Fastest & Coolest - Market\n\n");
      printf("--> Categories <--\n\n");
      printf("1.- Sodas\n");
      printf("2.- Fast Food\n");
      printf("3.- Fruits and Vegetables\n");
      printf("4.- Products of Basic Basket\n");
      printf("5.- Candies\n");
      printf("6.- See the shopping cart to finish\n\n");
      
      printf("Please, select the categorie you need to type:\n\n");
      scanf("%d",&opcnl);
      switch (opcnl)
      {
          case 1:
            
            printf("Products of Categorie: Sodas\n\n");
            printf("1.- Coca-Cola 500ml (20 pesos)\n");
            printf("2.- Water Ciel 500 ml (18 pesos)\n");
            printf("3.- Pepsi Light 500 ml (22 pesos)\n");
            printf("4.- Back to main Categories\n");
            
            printf("Select the product\n\n");
            scanf ("%d",&opcc);
            switch (opcc)
            {
                case 1:
                	printf("Amount to add of this product:");
                	scanf("%d",&cocacola);
                  printf ("\n*****Added %d to cart Coca-Cola 500 ml\n\n",cocacola);
                  break;
                case 2:
                	printf("Amount to add of this product:");
                	scanf("%d",&waterciel);
                  printf ("\n*****Added %d to cart Water Ciel 500 ml\n\n",waterciel);
                  break;
                case 3:
                	printf("Amount to add of this product:");
                	scanf("%d",&pepsilight);
                  printf ("\n*****Added %d to cart Pepsi Light 500 ml\n\n",pepsilight);
                  break;
                
            }
            break;
       case 2:
          
            printf("Products of Categorie: Fast Food\n\n");
            printf("1.- Pizza (4 people) (180 pesos)\n");
            printf("2.- Hamburger with fries (120 pesos)\n");
            printf("3.- Hot Dog with gelatin (100 pesos)\n");
            printf("4.- Back to main Categories\n");
            
            printf ("Select the Product\n\n");
            scanf("%d", &opcc); 
            switch (opcc)
            {
                case 1:
                	printf("Amount to add of this product:");
                	scanf("%d",&pizza);
                printf ("\n*****Added %d to cart Pizza (4 people)\n\n",pizza);
                break;
                
                case 2:
                	printf("Amount to add of this product:");
                	scanf("%d",&hamburger);
                printf ("\n*****Added %d to cart Hamburger with fries\n\n",hamburger);
                break;
                
                case 3:
                	printf("Amount to add of this product:");
                	scanf("%d",&hotdog);
                printf("\n*****Added %d to cart Hot Dog with gelatin\n\n",hotdog);
                break;
                
            }
        break;
    case 3:
         
           printf ("Products of Categorie: Fruits and Vegetables\n\n");
           printf("1.- Tomato  c/u (5 pesos)\n");
            printf("2.- Avocado c/u (10 pesos)\n");
            printf("3.- Apple c/u (7 pesos)\n");
            printf("4.- Back to main Categories\n");
            
            printf ("Select the Product\n\n");
            scanf("%d", &opcc); 
            switch (opcc)
            {
                case 1:
                	printf("Amount to add of this product:");
                	scanf("%d",&tomato);
                printf ("\n*****Added %d to cart Tomato (c/u)\n\n",tomato);
                break;
                
                case 2:
                	printf("Amount to add of this product:");
                	scanf("%d",&avocado);
                printf ("\n*****Added %d to cart Avocado (c/u)\n\n",avocado);
                break;
                
                case 3:
                    printf("Amount to add of this product:");
                	scanf("%d",&apple);
                printf("\n*****Added %d to cart Apple (c/u)\n\n",apple);
                break;
                
            }
        break;
        case 4:
         
           printf ("Products of Categorie: Products of Basic Basket\n\n");
           printf("1.- Olive Oil (30 pesos)\n");
            printf("2.- Roll Paper (50 pesos)\n");
            printf("3.- ACE Detergent (80 pesos)\n");
            printf("4.- Back to main Categories\n");
            
            printf ("Select the Product\n\n");
            scanf("%d", &opcc); 
            switch (opcc)
            {
                case 1:
                    printf("Amount to add of this product:");
                	scanf("%d",&oil);
                printf ("\n*****Added %d to cart Olive Oil\n\n",oil);           
                break;
                
                case 2:
                    printf("Amount to add of this product:");
                	scanf("%d",&paper);
                printf ("\n*****Added %d to cart Roll Paper\n\n",paper);
                break;
                
                case 3:
                    printf("Amount to add of this product:");
                	scanf("%d",&detergent);
                printf("\n*****Added %d to cart Detergent ACE\n\n",detergent);
                break;
                
               
            }
        break;
        case 5:
         
           printf ("Products of Categorie: Candies\n\n");
           printf("1.- Duvalin (7 pesos)\n");
            printf("2.- Marzipan (12 pesos)\n");
            printf("3.- Lolly Pop (15 pesos)\n");
            printf("4.- Back to main Categories\n");
            
            printf ("Select the Product\n\n");
            scanf("%d", &opcc); 
            switch (opcc)
            {
                case 1:
                    printf("Amount to add of this product:");
                	scanf("%d",&duva);
                printf ("\n*****Added %d to cart Duvalin\n\n",duva);
                break;
                
                case 2:
                    printf("Amount to add of this product:");
                	scanf("%d",&maza);
                printf ("\n*****Added %d to cart Marzipan\n\n",maza);
                break;
                
                case 3:
                    printf("Amount to add of this product:");
                	scanf("%d",&lollyp);
                printf("\n*****Added %d to cart Lolly Pop\n\n",lollyp);
                break;
                
            }
        break;
    case 6:
       
       printf ("\n Would you like to delete any product Y/N?");
       fflush (stdin);
       scanf("%c", &eliminar);
       if (eliminar== 'Y'){
           printf ("\n 1.- Delete Coca-Cola 500 ml\n");
           printf ("\n 2.- Delete Water Ciel 500 ml\n");
           printf ("\n 3.- Delete Pepsi Light 500 ml\n");
           printf ("\n 4.- Delete Pizza (4 people)\n");
           printf ("\n 5.- Delete Hamburger with Fries\n");
           printf ("\n 6.- Delete Hot dog with gelatin\n");
           printf ("\n 7.- Delete Tomato (c/u)\n");
           printf ("\n 8.- Delete Avocado (c/u)\n");
           printf ("\n 9.- Delete Apple (c/u)\n");
           printf ("\n 10.-Delete Olive Oil\n");
           printf ("\n 11.-Delete Roll Paper\n");
           printf ("\n 12.-Delete Detergent ACE\n");
           printf ("\n 13.-Delete Duvalin\n");
           printf ("\n 14.-Delete Marzipan\n");
           printf ("\n 15.-Delete Lolly Pop\n");
           scanf ("%d", &prod);
           switch (prod)
           {
               case 1:
               if (cocacola > 0){
               		printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Coca-Cola 500 ml)\n",eli);
                   cocacola = cocacola-eli;
               }
               break;
               case 2:
               if (waterciel > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Water Ciel 500 ml)\n",eli);
                   waterciel = waterciel-eli;
               }
               break;
               case 3:
               if (pepsilight > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Pepsi Light 500 ml)\n",eli);
                   pepsilight = pepsilight -eli;
               }
               break;
               case 4:
               if (pizza > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Pizza 4 people)\n",eli);
                   pizza = pizza -eli;
               }
               break;
               case 5:
               if (hamburger > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Hamburger with fries)\n",eli);
                   hamburger = hamburger -eli;
               }
               break;
               case 6:
               if (hotdog > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Hot Dog with gelatin)\n",eli);
                   hotdog = hotdog -eli;
               }
               break;
               case 7:
               if (tomato > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\nDelete %d of the Cart Shop (Tomato c/u)\n",eli);
                   tomato = tomato -eli;
               }
               break;
               case 8:
               if (avocado > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Avocado c/u)\n",eli);
                  avocado = avocado -eli;
               }
               break;
               case 9:
               if (apple > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Apple c/u)\n",eli);
                   apple= apple -eli;
               }
               break;
               case 10:
               if (oil > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Olive Oil)\n",eli);
                   oil= oil -eli;
               }
               break;
               case 11:
               if (paper > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Roll Paper)\n",eli);
                   paper= paper -eli;
               }
               break;
               case 12:
               if (detergent > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Detergent ACE)\n",eli);
                   detergent= detergent -eli;
               }
               break;
               case 13:
               if (duva > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Duvalin)\n",eli);
                   duva= duva -eli;
               }
               break;
               case 14:
               if (maza > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Marzipan)\n",eli);
                   maza= maza -eli;
               }
               break;
               case 15:
               if (lollyp > 0){
                    printf("Amount to delete of this product:");
               		scanf("%d",&eli);
                   printf ("\n Delete %d of the Cart Shop (Lolly Pop)\n",eli);
                   lollyp= lollyp -eli;
               }
               break;
           }
           
           
       }
       printf ("See the shopping cart to finish\n\n");
       pec=0;
       pec= cocacola + waterciel + pepsilight;
       if (pec>0){
           printf ("\n Sodas");
           printf("\n Coca-Cola: %d",cocacola);
           printf("\n Water ciel: %d",waterciel);
           printf("\n Pepsi Light: %d",pepsilight);
       }
       cuentat_1 = cocacola * 20 + waterciel * 18 + pepsilight * 22;
       pec=0;
       pec= pizza + hamburger + hotdog;
       if (pec>0){
           printf ("\n Fast Food ");
           printf("\n Pizza (4 people): %d",pizza);
           printf("\n Hamburger with Fries: %d",hamburger);
           printf("\n Hot Dog with gelatin: %d",hotdog);
       }
       cuentat_2 =pizza * 180 + hamburger *120 + hotdog *100;
       pec= 0;
       pec= tomato + avocado + apple;
       if (pec>0){
         printf ("\n Fruits and Vegetables ");
         printf("\n Tomato (c/u): %d",tomato);
         printf ("\n Avocado (c/u): %d",avocado);
         printf("\n Apple (c/u): %d",apple);  
       }
       cuentat_3 =tomato * 5 + avocado * 10 + apple * 7;
       pec= 0;
       pec= oil + paper + detergent;
       if (pec>0){
         printf ("\n Basic Basket");
         printf("\n Olive Oil: %d",oil);
         printf ("\n Roll Paper: %d",paper);
         printf("\n ACE Detergent: %d",detergent);  
       }
       cuentat_4 =oil * 30 + paper * 50 + detergent * 80;
       pec= 0;
       pec= duva + maza + lollyp;
       if (pec>0){
         printf ("\n Candies");
         printf("\n Duvalin: %d",duva);
         printf ("\n Marzipan: %d",maza);
         printf("\n Lolly Pop: %d",lollyp);  
       }
       cuentat_5 =duva * 7 + maza * 12 + lollyp * 15;
        
		f=fopen("Ticket.txt","w");
		if(f == NULL){
			printf("No se ha podido abrir.\n");
			exit(1);
		}
		fprintf(f,"\t\t\tThe Fastest & Coolest - Market\n\n");
		fprintf(f,"\tProducts:\t\t\tAmount:\t\tPrice:\n");
		
		if(cocacola!=0){
			fprintf(f,"\tcocacola \t\t\t%d\t\t%d\n",cocacola,cocacola*20);
		}
		if(waterciel!=0){
			fprintf(f,"\twaterciel\t\t\t%d\t\t%d\n",waterciel,waterciel*18);
		}
		if(pepsilight!=0){
			fprintf(f,"\tpepsilight\t\t\t%d\t\t%d\n",pepsilight,pepsilight*22);
		}
		
		
		if(pizza!=0){
			fprintf(f,"\tpizza\t\t\t%d\t\t%d\n",pizza,pizza*180);
		}
		if(hamburger!=0){
			fprintf(f,"\thamburger\t\t\t%d\t\t%d\n",hamburger,hamburger*120);
		}
		if(hotdog!=0){
			fprintf(f,"\thotdog\t\t\t%d\t\t%d\n",hotdog,hotdog*100);
		}
		
		
		if(tomato!=0){
			fprintf(f,"\ttomato\t\t\t%d\t\t%d\n",tomato,tomato*5);
		}
		if(avocado!=0){
			fprintf(f,"\tavocado\t\t\t%d\t\t%d\n",avocado,avocado*10);
		}
		if(apple!=0){
			fprintf(f,"\tapple\t\t\t%d\t\t%d\n",apple,apple*7);
		}
	
		
		
		
		if(oil!=0){
			fprintf(f,"\toil\t\t\t%d\t\t%d\n",oil,oil*30);
		}
		if(paper!=0){
			fprintf(f,"\tpaper\t\t\t%d\t\t%d\n",paper,paper*50);
		}
		if(detergent!=0){
			fprintf(f,"\tdetergent\t\t\t%d\t\t%d\n",detergent,detergent*80);
		}
		
		
		if(duva!=0){
			fprintf(f,"\tduva\t\t\t%d\t\t%d\n",duva,duva*7);
		}
		
		if(maza!=0){
			fprintf(f,"\tmaza\t\t\t%d\t\t%d\n",maza,maza*12);
		}
		
		if(lollyp!=0){
			fprintf(f,"\tlollyp\t\t\t%d\t\t%d\n",lollyp,lollyp*15);
		}
		
		fprintf(f,"\n\n\tDiscount Codes Applied:\n");
		a=funcday();
		switch(a){
    	case 0:{
    			if(cuentat_1!=0 || cuentat_2!=0 || cuentat_5!=0){
    				fprintf(f,"\tProSatSunday\t\t\t10%c\t\t%.02f\n",37,-(cuentat_1+cuentat_2+cuentat_5)*0.10);
				}
    			
				break;
			}
			
		case 1:{
				if(cuentat_1!=0){
    				fprintf(f,"\tProMonday\t\t\t13%c\t\t%.02f\n",37,-(cuentat_1+cuentat_2+cuentat_5)*0.13);
    			}
				break;
			}
		case 2:{
    			if(cuentat_3!=0){
    				fprintf(f,"\tProTuesday&Wednesday\t\t\t15%c\t\t%.02f\n",37,-(cuentat_3)*0.15);
    			}
				break;
			}
		case 3:{
    		if(cuentat_3!=0){
    				fprintf(f,"\tProTuesday&Wednesday\t\t\t15%c\t\t%.02f\n",37,-(cuentat_3)*0.15);
    			}
				break;
			}
		case 4:{
    			if(cuentat_4!=0){
    				fprintf(f,"\tProTuesday\t\t\t20%c\t\t%.02f\n",37,-(cuentat_4)*0.20);
    			}
				break;
			}
		case 5:{
    		if(cuentat_2!=0 ){
    				fprintf(f,"\tProFriyay\t\t\t18%c\t\t%.02f\n",37-(cuentat_2)*0.18);
    			}
				break;
			}
		case 6:{
				if(cuentat_1!=0 || cuentat_2!=0 || cuentat_5!=0){
    				fprintf(f,"\tProSatSunday\t\t\t10%c\t\t%.02f\n",37-(cuentat_1+cuentat_2+cuentat_5)*0.10);
    			}
				break;
			}
	}
		iva=(cuentat_1+cuentat_2+cuentat_3+cuentat_4+cuentat_5)*0.16;
		fprintf(f,"\t\t\t\tIva:\t16%c\t\t%.02f\n",37,iva);
		
    	switch(a){
    	case 0:{
    			cuentat_1=cuentat_1*0.9;
    			cuentat_2=cuentat_2*0.9;
    			cuentat_5=cuentat_5*0.9;
				break;
			}
		case 1:{
				cuentat_1=cuentat_1*0.87;
				break;
			}
		case 2:{
    			cuentat_3=cuentat_3*0.85;
				break;
			}
		case 3:{
    			cuentat_3=cuentat_3*0.85;
				break;
			}
		case 4:{
    			cuentat_4=cuentat_4*0.80;
				break;
			}
		case 5:{
    			cuentat_2=cuentat_2*0.82;
				break;
			}
		case 6:{
				cuentat_1=cuentat_1*0.9;
    			cuentat_2=cuentat_2*0.9;
    			cuentat_5=cuentat_5*0.9;
				break;
			}
		}
		
           cuentat=cuentat_1+cuentat_2+cuentat_3+cuentat_4+cuentat_5+iva;
           fprintf(f,"\n\t\t\t\tTotal:\t\t\t%.02f",cuentat);
       if (cuentat >=1000)
                   cuentat = cuentat - (cuentat*0.15);
        printf("\nTotal= %.02f",cuentat);  
		 fclose(f);      
      }
      
    } while (opcnl !=6);
}


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
			if(div(year-2000,4) && (month==0 || month==1)){
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
