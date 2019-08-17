#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int a,sonuc,sonuca,status1,status2,status3;  //defining global input variables

int randomOp() //function which is used to call rand operations
{
	time_t t;
	srand((unsigned)time(&t));  //changing calling order of random depends on the time
	a=rand()%6; //creating a rand number which is assigning to 'a'
	return a; //returning a value 
}

void outputCons(void) //function which is used to call and show arithmetic operations
{
	randomOp(); //using randomOp which was defined before
	switch(a) //do some cases depends on the value of a
	{	
		case 0: //do the following codes if a is 0
			printf("   Selected as nothing. Please pick a new one\n");
			break;	
		case 1: //do the following codes if a is 1
			printf("+\n");
			break;	
		case 2: //do the following codes if a is 2
			printf("-\n");
			break;	
		case 3: //do the following codes if a is 3
			printf("*\n");
			break;	
		case 4: //do the following codes if a is 4
			printf("/\n");
			break;	
		case 5: //do the following codes if a is 5
			printf("%%\n");
			break;
		default: //to check switch control structure whether it is working correctly or not
			printf("error");
			break;
	}
}

int islem(void)
{
	int sayi1,sayi2,diger,sum,sub,div,multi,mod; //defining variables
	
	randomOp();
	do{
		printf("Enter first number :"); //displaying a message to take a number from user
		status1=scanf("%d",&sayi1); //reading number which is entered from keyboard by user.
		if(status1==EOF) //shut downs application when EOF(CTRL-Z) is entered
		return 0;
		else if(status1<1) //checking if integer value is entered
		{
		printf("Please enter an integer\n"); //displaying a message
		fflush(stdin); //clearing the buffer
		continue; //returning back to starting point of do-while loop
		}
}while(status1!=1); //exit condition

	do{
	printf("Enter second number :"); //displaying a message to take a number from user
	status2=scanf("%d",&sayi2); //reading number which is entered from keyboard by user.
	if(status2==EOF) //shut downs application when EOF(CTRL-Z) is entered
	return 0;
	else if(status2<1) //checking if integer value is entered
	{
		printf("Please enter an integer\n"); //displaying a message
		fflush(stdin); //clearing the buffer
		continue; //returning back to starting point of do-while loop	
	}       
	
}while(status2!=1); //exit condition
	printf("your operator :"); 
	outputCons(); //calling arithmetic operation function

	switch(a) //do some cases depends on the value of a
	{
		case 0: //do the following codes if a is 0
			break;
		case 1: //do the following codes if a is 1
			sum=sayi1+sayi2; //sum sayi1 and sayi2 and assign to sum variable
			printf("%d+%d = %d\n",sayi1,sayi2,sum); //displaying result message
			sonuc=sum; //assigning sum to sonuc variable
			break;	
		case 2:
			sub=sayi1-sayi2; //substract sayi1 and sayi2 and assign to sub variable
			printf("%d-%d = %d\n",sayi1,sayi2,sub); //displaying result message
			sonuc=sub; //assigning sub to sonuc variable
			break;	
		case 3:	
			multi=sayi1*sayi2; //multipliying sayi1 and sayi2 and assign to multi variable
			printf("%d*%d = %d\n",sayi1,sayi2,multi); //displaying result message
			sonuc=multi; //assigning multi to sonuc variable
			break;	
		case 4:
			div=sayi1/sayi2; //dividing sayi1 and sayi2 and assign to div variable
			printf("%d/%d = %d\n",sayi1,sayi2,div); //displaying result message
			sonuc=div; //assigning div to sonuc variable
			break;	
		case 5:	
			mod=sayi1%sayi2; //taking modula value of sayi1 and sayi2 and assign to mod variable
			printf("%d%%%d = %d\n",sayi1,sayi2,mod); //displaying result message
			sonuc=mod; //assigning mod to sonuc variable
			break;
		default: //to check switch control structure whether it is working correctly or not
			printf("error"); //error message
			break;
	}	
}

int islem2(void)
{
	int diger,sum,sub,div,multi,mod; //defining variables
	while(diger!=EOF){ //run this loop while diger variable is not EOF(CTRL-Z)
		
		randomOp(); //calling rand
		printf("-----------------------\n");
		printf("Result: %d\n",sonuca); 
		do{
			printf("Next number: "); //displaying a message to request a new number
			status3=scanf("%d",&diger); //getting new number 
			if(status3==EOF) //shuts down the program if it is EOF(CTRL-Z)
			return 0;
			else if(status3<1) //checks if it is entered as an integer value
			{
				printf("Please enter an integer value\n");
				fflush(stdin);
				continue;
			}
			
		}while(status3!=1);
		
		printf("Your operator :");
		outputCons();		
	switch(a)
	{	case 0: //do the following codes if a is 0
			break;
		case 1:	 //do the following codes if a is 1
			sum=sonuca+diger; //sum sonuca and diger and assign to sum variable
			printf("%d+%d = %d\n",sonuca,diger,sum); //displaying result message
			sonuca=sum; //assigning sum to sonuca variable
			break;	
		case 2:	//do the following codes if a is 2
			sub=sonuca-diger; //substracting sonuca and diger and assign to sub variable
			printf("%d-%d = %d\n",sonuca,diger,sub); //displaying result message
			sonuca=sub; //assigning sub to sonuca variable
			break;	
		case 3:	//do the following codes if a is 3
			multi=sonuca*diger; //multiplicating sonuca and diger and assign to multi variable
			printf("%d*%d = %d\n",sonuca,diger,multi); //displaying result message
			sonuca=multi; //assigning multi to sonuca variable
			break;	
		case 4:	//do the following codes if a is 4
			div=sonuca/diger; //dividing sonuca and diger and assign to multi variable
			printf("%d/%d = %d\n",sonuca,diger,div); //displaying result message
			sonuca=div; //assigning div to sonuca variable
			break;	
		case 5:	//do the following codes if a is 5
			mod=sonuca%diger; //dividing sonuca and diger and assign to multi variable
			printf("%d%%%d = %d\n",sonuca,diger,mod); //displaying result message
			sonuca=mod; //assigning mod to sonuca variable
			break;
		default:
			printf("error");
			break;
	}	
		
	}
}

int main() 
{
	islem(); //calling the islem function which is defined before
	sonuca=sonuc; //assigning sonuc to sonuca
	islem2(); //calling the islem2 function which is defined before
	
	system("pause");
	return 0;
}
