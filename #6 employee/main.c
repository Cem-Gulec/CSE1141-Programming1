#include <stdio.h>
#include <stdlib.h>

char name,surname,nameb,surnameb;
double salary;
int age,emp_number;

char lowertoupper(char ch1)
{
	char ch2;
	if (ch1>='a'&&ch1<='z')
	{
		ch2=ch1+'A'-'a';
		return ch2;
	}
	else
	ch2=ch1;
	return ch2;
}

void getdata(void)
{
	 
	printf("Name and surname initial:");
	scanf("%c%c",&name,  &surname);
	nameb=lowertoupper(name);
	surnameb=lowertoupper(surname);
	printf("Employee number(5 digits):");
	scanf("%d",&emp_number);
	printf("Age:");
	scanf("%d",&age);
	
	printf("Salary:");
	scanf("%lf",&salary);
	printf("-----------------------------------------\n");
}

void displayinfo()
{
	printf("Name initial: %c%c\n",nameb, surnameb);
	printf("Employee number: %d\n",emp_number);
	printf("Age: %d\n",age);
	printf("Salary: %.2lf\n",salary);
}


int main()
{
	getdata();
	displayinfo();	
	system("pause");
	return 0;
}
