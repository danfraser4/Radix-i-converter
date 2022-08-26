#include<stdio.h> 
#include<math.h>
#define TITLE "DECIMAL TO RADIX-i converter"                              /*define title, author and year*/
#define AUTHOR " Daniel Fraser"
#define YEAR "2022"

void Dec2RadixI(int decValue, int radValue){
    int x=0;                                                               /* initalize variables */
    int i=0;
    int rem=0;
    int size=floor(log2(decValue)/log2(radValue));                         /*calculate the size of the array needed using log laws*/
    int reverse[size];                                                     /*define reverse array*/
    do {                                                                  
        rem=decValue%radValue;                                             /*calculate remainder*/
        decValue=decValue/radValue;                                        /*calculate new decimal value*/
        reverse[i]=rem;                                                    /*store the remainder in reverse array */
        i+=1;                                                              /*count i*/
    }while(decValue>0);                                                    /*set stop condition*/
    for (i=size;i>=0;i--){          
        printf("%0X", reverse[i]);                                         /*print reverse of reverse array :)*/
    }
}

void main()     
{  
    printf("*****************************\n");                             /*print preliminaries*/
    printf("%s\n",TITLE);
    printf("Written by:");
    printf("%s\n",AUTHOR);
    printf("Date:");
    printf("%s \n",YEAR);
    printf("*****************************\n");
    int n;
    do {                                                                  /*initilize do while loop to continue while input is greater than 0*/
     printf("\nEnter a decimal number: ");                                /*scan in decimal number input*/
     scanf("%d",&n);
     if (n>=0){  
        printf("The decimal number you have entered is %d\n",n);
        int r;
        printf("Enter a radix for the converter between 2 and 16: ");     /*scan in radix value*/
        scanf("%d",&r);
        printf("The radix you have entered is %d\n",r);
        printf("The log2 of the number is %.2f\n",log2(n));               /*find log2 of the number (the size of memory in binary that the number will require to be stored)*/
        printf("The integer result of the number divided by %d is %d \n",r,n/r);  /*floor integer result when decimal value is divided by the radix without remainder*/
        printf("The remainder is %d \n",n%r);                             /*find the remainder when dividing by radix*/ 
        printf("The radix-%d value is ",r);                                      /*print the converted number with the specified base radix value*/
        if(n==0){                                                                /*error checking for inputs*/
            printf("0");
        }
        else if(2<=r&&r<=16){                
             Dec2RadixI(n,r);
        }
        else{
            printf("\nERROR Radix not in range specified");
        }
       
        
     }
     else{
        printf("EXIT");                                                            /*print EXIT if decimal value is less than 0*/
    }
    }while(n>=0);                                                                  /*end do while loop with condition*/
    
}     