#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<time.h>
void pinc();

int delay(unsigned long milisec)
{
	 struct timespec req={0};   
    time_t sec=(int)(milisec/1000);   
    milisec=milisec-(sec*1000);   
    req.tv_sec=sec;   
    req.tv_nsec=milisec*1000000L;   
    while(nanosleep(&req,&req)==-1)   
        continue;   
    return 1;   
}
void fpage()
{
	system("cls");
	system("COLOR 0C");
	for (int i =0; i<110;i++)
		printf("_");
	printf("\n\t\t\t\tWELCOME TO"); delay(1000);
	system("COLOR 0B");
	printf(" De-CODE\n");delay(1000);
	system("COLOR 09");
	printf("\t\t\t\t\tCODE ");delay(1000);
	printf("TO ");delay(1000);
	printf("MYSTERY..."); delay(1000);
	system("COLOR 0F");
	printf("\n\nDisclaimer: This software is created for the purpose of secured messages to be transfered from one user to another.");
	printf(" In  case of any difficulties faced or a bad memory, contact the Developers"); delay(2000);
	printf("\n\n\n\n Press any key to continue...");getch();
}
// coding of encipher***********************************************
void encipher()
{
	system("cls");
	int a, b, d[1002];
	FILE *p;
	char str[1002];
	system("COLOR F2");
	printf("\t\t\t\t~~~Enciphering~~~\n");
	printf("Type in your Message and press Enter to terminate\n");
	gets(str);
	fflush(stdin);
	printf("Please wait while Enciphering");delay(1000);
	printf(".");delay(1000);
	printf(".");delay(1000);printf(".\n");delay(1000);
// converting every alphabet into number*******************************
	a = 1;
	for (int s=0;s<strlen(str);s++)
	{
		if(str[s]==' ')
		{
			a = 1; 
			continue;
		}
		b = 26 * a;
		d[s] = str[s]+b;
		d[s] -= 96;
		a++;
	}
	printf("Code Generated:\n");delay(1000);
	for (int s=0;s<strlen(str);s++)
	{       if(str[s]!=' ')
		{
			printf("%d ",d[s]);
		}
	}
// making new file and storing *****************************
	p = fopen("ciphered.txt","w");
	for (int s=0;s<strlen(str);s++)
		fprintf(p,"%d\n",d[s]);
	fclose(p);
}
void decipher(int c)
{
	int a, b, g[1002];
	char m[10002];
	FILE *p;
	p = fopen("CIPHERED.txt","r");
	printf("Please wait while Deciphering");delay(1000);
	printf(".");delay(1000);
	printf(".");delay(1000);
	printf(".\n");delay(1000);
	printf("Code Retrieved: ");
	for (int s=0;s<c;s++)
	{
		fscanf(p,"%d\n", &a);
		if (a>2000||a<26)
		{
			printf("");
			continue;	
		}
		printf("%d ",a);
		b = a % 26;
		g[s] = a;
		m[s]=96+b;
	}
	fclose(p);
	delay(1000);
	printf("\nDeciphered Message: \n--> ");
	for (int s=0;s<c;s++)
	{
		if (g[s]<g[s-1])
			printf(" %c",m[s]);
		else
			printf("%c",m[s]);
	}
}
void demain()
{
	system("cls");
	system("COLOR 20");
	int a,n=0,b=0;
	FILE *p;
	p = fopen("CIPHERED.txt","r");
	while ((n=fgetc(p)) != EOF)
	{
		if (n == '\n')
			b++;
	}
	printf("\t\t\t\t~~~Deciphering~~~\n");
	fclose(p);
	if (b == 0)
	{
		system("cls");
		system("COLOR 4F");
		printf("\tError 404:\n\t\tFile not found or may be present by different name.");delay(2000);
		printf("\n\t\tIn case of neither, contact the developers.");delay(6000);
		pinc();
	}
	else
		decipher(b);
}
void pinc()
{
	int a;
	m: system("cls");
	system("COLOR F4");
	printf("Select from the following: \n   1) To Encipher\n   2) To Decipher\n Your Selection: ");
	scanf("%d",&a);
	fflush(stdin);
	if (a==1)
		encipher();
	else if (a==2)
		demain();
	else
	{
		printf("Incorrect Selection!");
		fflush(stdin);
		getch();
		goto m;
	}
}
int main()
{
	system("TITLE De-CODE: Code to Mystery");
	fpage();
	s: system("cls");
	int a;
	char pin[4];
	printf("Enter PIN: ");
	for(int i =0;i<4;i++)
	{
		pin[i]=getch();
		printf("*");
	}

	if (pin[0]=='2'&&pin[1]=='3'&&pin[2]=='2'&&pin[3]=='8')
	{
		pinc();
	}
	else
	{
		printf("\nIncorrect PIN!");
		getch();
		goto s;
	}
	getch();
	system("cls");
	system("COLOR 70");
	printf("\n\t\t\tCredits\n\t\t\t--------\n");delay(1000);
	printf("\t\tCreated By: \n\t\t\tPraman Kasliwal\n\t\t\tAanjaneya Singh Dhoni\n\t\t\tMohit Khemchandani\n\t\t\tHarshit Jain");
	delay(3000);
	return 0;
}
