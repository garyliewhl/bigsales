#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int year, menu;
	int i;
	int quantity[4] = {0,0,0,0};
    double product_price[4] = {45.20,14.50,3.45,7.80};
	double hours, roundHours, parkPrice;
	double total_price,  subtotal, subtax, grandTotal, discount;

	int alternating = 0;
    int index = 0;
    int number = 0; 

	printf("||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
	printf("|| **************	  ***       *****************      **************             **               **                ************      ************** ||\n");			
	printf("|| **           **	  ***		*****       *****      *****                     ****              **                ************      *****          ||\n");		
	printf("|| **            **	  ***		*****                  *****                   ***  ***            **                **                *****          ||\n");		
	printf("|| **            **	  ***		*****                  **************         ***    ***           **                **                ************** ||\n");		
	printf("|| **************	  ***		*****                  **************        ****    ****          **                ************      ************** ||\n");			
	printf("|| **             **  ***		*****    ********               *****      ***************         **                **                         ***** ||\n");		
	printf("|| **             **  ***		*****        ****	            *****     ******************       **                **                         ***** ||\n");		
	printf("|| **            **	  ***		*****        ****      **************    ****            ****      **************    ************      ************** ||\n");		
	printf("|| ****************	  ***		*****************      **************   ****              ****     **************    ************      ************** ||\n");    
	printf("||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
	printf("\n");
	printf ("Welcome to the BIGSALES Shopping Mall\n");
	printf ("Enter Your Year of Birth: \n");
	scanf ("%d", &year);

	while(1)
    {
        printf("1. Enter Products Purchased\n");
        printf("2. Enter Parking Duration\n");
        printf("3. Calculate Total Bill\n");
        printf("4. Exit\n");
        scanf("%d", &menu);

    switch(menu){

        case 1: {

            char * str = (char*) malloc(1024);

            printf("Enter Product Code Follow By The Quantity Purchased\n");
            scanf(" %[^\n]s", str);

            
            while(*str != '\0') {
                if(*str != ' ') {

                    index = alternating? index : *str - '0' - 1;
                    number = alternating? *str - '0': number;
                    if(alternating) quantity[index] += number;
                    alternating = alternating? 0 : 1;
                    }
                    str++;
                }


            total_price = 0;

            for(i=0;i<4;i++) {
                total_price += quantity[i]*product_price[i];
            }

			printf("--------------------------------------------\n");
            printf("Product                   Quantity          \n");
            printf("--------------------------------------------\n");
            printf("Product Code 1            %d                \n" ,quantity[0]);
            printf("Product Code 2            %d                \n" ,quantity[1]);
            printf("Product Code 3            %d                \n" ,quantity[2]);
            printf("Product Code 4            %d                \n" ,quantity[3]);
            printf("--------------------------------------------\n");
            printf("%.2lf\n", total_price);
            break;
        }

        case 2:{

            printf("Enter Parking Hours: \n");
            scanf("%lf", &hours);

            roundHours = ceil(hours);

            if ( roundHours<=3){
                parkPrice = 2;
            }

            else if (roundHours >3 && roundHours <24){
                parkPrice = 2 + 0.5*(roundHours-3);
            }

            else {
                parkPrice =10;
            }

            break;
        }

        case 3:{

            double price1, price2, price3, price4;
            price1 = quantity[0]*product_price[0];
            price2 = quantity[1]*product_price[1];
            price3 = quantity[2]*product_price[2];
            price4 = quantity[3]*product_price[3];
			
            printf("-------------------------------------------------------------------\n");
            printf("Product                   RPrice(RM)      Quantity       TPrice(RM)\n");
            printf("-------------------------------------------------------------------\n");
			printf("Product Code 1            45.20           %d             %.2lf\n" ,quantity[0], price1);
            printf("Product Code 2            14.50           %d             %.2lf\n" ,quantity[1], price2);
            printf("Product Code 3             3.45           %d             %.2lf\n" ,quantity[2], price3);
            printf("Product Code 4             7.80           %d             %.2lf\n" ,quantity[3], price4);
            printf("-------------------------------------------------------------------\n");

            printf("Subtotal                                                %.2lf\n", total_price);

            subtax = (0.1*total_price) + total_price;
            printf("Subtotal with 10%% Government Tax                        %.2lf\n" , subtax);

            printf("Total Parking Hours  : %.2lf\n", roundHours );
            printf("Total Parking Fees   : %.2lf\n", parkPrice);

            if(year < 60){
            grandTotal = subtax + parkPrice;
			printf("-------------------------------------------------------------------\n");
            printf("Grand Total                                             %.2lf\n", grandTotal);
            }

            else{
            discount = (0.1*(subtax + parkPrice));
            grandTotal = (subtax + parkPrice) - discount;
            printf("10%% Discount        : -%.2lf\n");
			printf("-------------------------------------------------------------------\n");
            printf("Grand Total                                             %.2lf\n", grandTotal);
            }

            break;
        }

        case 4:{
            exit(0);
            break;
        }

        default:
            printf("Error! Please Enter Again!\n");

    }
    }

}