#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <graphics.h>
//===========================================================================
void timeset();
void AddData();
void RemoveData();
void ModifyData();
void diplaylist();
void SortList();
void Appned();
void SortData();
void menu();
//===========================================================================
FILE *fp,*ft,*lp,*lt;
char ch;
//===========================================================================
struct detail
{
	char name[20];
	int age;
	char dest[50];
	char ti[50];
}e;
//===========================================================================
typedef struct costumer
{
	char name[20];
	int age;
	char dest[50];
	char ti[50];
	struct costumer *next;
}costumer;
struct costumer *start;
long int size=sizeof(e);
//===========================================================================
void timeset()
{
	time_t timer;
	struct tm *tblock;
	timer = time(NULL);
	tblock = localtime(&timer);
	strftime(e.ti,50,"%d/%m/%Y %H:%M:%S",tblock);
}
//===========================================================================
void AddData()
{
	int flag=0;
	if(fp==NULL)
	{
		printf("file can not open");
	}
	else
	{
		timeset();
		printf("\n Enter Costumer name:");
		scanf("%s",e.name);
		printf("\n Enter Costumer Age:");
		scanf("%d",&e.age);
		printf("\n Enter your destination: ");
		scanf("%s",e.dest);
		printf("\n Your Booking Time:%s",e.ti);
		flag=1;
		fseek(fp,0,SEEK_END);
		fwrite(&e,size,1,fp);
		if(flag==1)
		{
			printf("Your ticket has been Booked..!!");
		}
		else
		{
			printf("Your Ticket hasn't booked..!!");
		}
	}
}

//===========================================================================
void RemoveData()
{
	int age;
	char name[20];
	int flag=0;
	ft=fopen("tairport.dat","ab+");
	if(fp==NULL)
	{
		printf("file can not open");
	}
	else
	{
		printf("\n Please Enter name:");
		scanf("%s",name);
		printf("\n Please Enter the age of %s:",name);
		scanf("%d",&age);
		rewind(fp);
		while(fread(&e,size,1,fp)==1)
		{
			if((strcmp(name,e.name)&&age==e.age)!=0)
			{
			  fwrite(&e,size,1,ft);
			}
			else
			{
				flag=1;
			}
		}
		fclose(fp);
		fclose(ft);
		remove("airport.dat");
		rename("tairport.dat","airport.dat");
		fp=fopen("airport.dat","a+");
		if(flag==1)
		{
			printf("Reservation of %s has been Cancelled..!!",name);
		}
		else
		{
			printf("Reservation couldn't Found.");
		}

	}
}
//===========================================================================
void ModifyData()
{
	int age;
	float dest[50];
	char name[20];
	if(fp==NULL)
	{
		printf("file can not open");
	}
	else
	{
		printf("\n Enter name:");
		scanf("%s",name);
		printf("\n Enter Age:");
		scanf("%d",&age);
		rewind(fp);
		while(fread(&e,size,1,fp)==1)
		{
			if(strcmp(name,e.name)==0 && e.age==age)
			{
				fseek(fp,-size,SEEK_CUR);
				printf("\n Enter new name");
				scanf("%s",e.name);
				printf("\n Enter new age");
				scanf("%d",&e.age);
				printf("\n Enter Your destination:");
				scanf("%s",e.dest);
				fwrite(&e,size,1,fp);
				printf("You information has been updated.");
			}
		}
	}
}
//---------------------------------------------------------------------------
void displist(costumer *p)
{

	costumer *tmp;
	int r=2;
	clrscr();
	tmp=p;
	printf("\n");
	gotoxy(1,1);
	printf("Name");
	gotoxy(12,1);
	printf("Age");
	gotoxy(18,1);
	printf("Destination");
	gotoxy(30,1);
	printf("Booking time");
	while(tmp!=NULL)
	{
		printf("\n");
		gotoxy(1,r);
		printf("%s",tmp->name);
		gotoxy(12,r);
		printf("%d",tmp->age);
		gotoxy(18,r);
		printf("%s",tmp->dest);
		gotoxy(30,r);
		printf("%s",tmp->ti);
		tmp=tmp->next;
		r++;
	}
	getch();
}
//--------------------------------------------------------------------------
void sortlist(costumer *p)
{
	int i,j,n=0,t_age;
	char t_dest[50];
	char t_name[20];
	costumer *tmp,*tmp1;
	tmp=p;
	while(tmp!=NULL)
	{
		n++;
		tmp=tmp->next;
	}
	for(i=0,tmp=p;tmp!=NULL;i++,tmp=tmp->next)
	{
		for(j=0,tmp1=p;j<n-i-1;j++,tmp1=tmp1->next)
		{
			  if(strcmp(tmp1->name,tmp1->next->name)>0)
			  {
					t_age=tmp1->age;
					strcpy(t_dest,tmp1->dest);
					strcpy(t_name,tmp1->name);

					tmp1->age=tmp1->next->age;
					strcpy(tmp1->dest,tmp1->next->dest);
					strcpy(tmp1->name,tmp1->next->name);

					tmp1->next->age=t_age;
					strcpy(tmp1->next->dest,t_dest);
					strcpy(tmp1->next->name,t_name);
			  }
		}
	}
}
//---------------------------------------------------------------------------
void Append(costumer **p,struct detail e)
{
	 costumer *tmp,*r;
	 tmp=(costumer*)malloc(sizeof(costumer));
	 tmp->age=e.age;
	 strcpy(tmp->dest,e.dest);
	 strcpy(tmp->name,e.name);
	 strcpy(tmp->ti,e.ti);
	 tmp->next=NULL;
	 if((*p)==NULL)
	 {
		*p=tmp;
	 }
	 else
	 {
		r=*p;
		while(r->next!=NULL)
		{
			r=r->next;
		}
		r->next=tmp;
	 }
}
//---------------------------------------------------------------------------
void SortData()
{
	start=NULL;
	if(fp==NULL)

	{
		printf("file can not open");
	}
	else
	{
		rewind(fp);
		while(fread(&e,size,1,fp)==1)
		{
			Append(&start,e);
		}
		sortlist(start);
		displist(start);
	}
}
//==========================================================================
void menu()
{
	clrscr();
	gotoxy(25,1);
	cprintf("\n Welcome to Airline Reservation");
	printf("\n1.Ticket Reservation");
	printf("\n2.Cancel Reservation");
	printf("\n3.Edit Ticket Details");
	printf("\n4.Display All Reservation");
	printf("\n5.exit");
	printf("\nPlease Enter your choice: ");
	ch=getche();
}
//==========================================================================
void menuCall()
{
	char x='y',y='0',z='n';
	fp=fopen("airport.dat","rb+");
	while(1)
	{
	menu();
	switch(ch)
	{
	case '1':
		AddData();
		break;
	case '2':
		RemoveData();
		break;
	case '3':
		ModifyData();
		break;
	case '4':
		SortData();
		break;
	case '5':
		clrscr();
		gotoxy(25,1);
		cprintf("\n Welcome to Airline Reservation");
		printf("\nAre you sure u want to exit the program(Y/N):");
		while(1)
		{
			if(y==x||y==z)
			{
				break;
			}
			scanf("%c",&y);
			y=tolower(y);
		}
		if(y==x)
		{
			exit(0);
		}
		else if(y==z)
		{
			menuCall();
		}
		else
		{
			printf("Invalid Choice1....!!!");
			getch();
			menuCall();
		}
		break;
	default:
		printf("\n Invalid Choice..!!!");
		break;
	}
	getch();
	}
}
void main()
{
	clrscr();
	menuCall();
	getch();
}