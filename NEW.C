#include<stdio.h>
#include<conio.h>
#define p printf
#define s scanf
char ch;
void newAccount()
{
}
void depositAmount()
{
}
void withdrawAmount()
{
}
void balanceEnquiry()
{
}
void allList()
{
}
void closeAccount()
{
}
void modifyAccount()
{
}
void main()
{
	void (*funPtr[4])(struct Employee emp);
	int choice;
	char pwd[50];
	struct Employee emp;
	funPtr[0] = addInfo;
	funPtr[1] = editInfo;
	funPtr[2] = deleteInfo;
	funPtr[3] = showInfo;
	strcpy(pwd,password());
	if (strcmp(pwd,"vikas@123")==0)
	{
			do
			{
	   //	clrscr();
	    //	strcpy(pwd,password());
	   //	if (strcmp(pwd,"vikas@123")==0)

			p("\n1. add record");
			p("\n2. edit record");
			p("\n3. delete record");
			p("\n4. display records");
			p("\n5. exit");
			p("\n\nEnter your choice [1-5] : ");
			ff;
			s("%d",&choice);
			(*funPtr[choice-1])(emp);
    //		}
	    //	else
	    //	{
		 //	p("Invalid Password..!!");
	   //	}
			}while(choice != 5);
    }
    else
    {
			p("Invalid Password..!!");
    }
}

/*
void Menu()
{

	clrscr();
	p("\n\t\t\t======================");
	p("\n\t\t\tBANK MANAGEMENT SYSTEM");
	p("\n\t\t\t======================");
	p("\n\t\t\t::::::MAIN MENU:::::::");
	p("\n\n\t\t\t1. NEW ACCOUNT");
	p("\n\t\t\t2. DEPOSIT AMOUNT");
	p("\n\t\t\t3. WITHDRAW AMOUNT");
	p("\n\t\t\t4. BALANCE ENQUIRY");
	p("\n\t\t\t5. ALL ACCOUNT HOLDER LIST");
	p("\n\t\t\t6. CLOSE AN ACCOUNT");
	p("\n\t\t\t7. MODIFY AN ACCOUNT");
	p("\n\t\t\t8. EXIT");
	ch=getche();

	getch();
}
void main()
{
  // fp=fopen("cust.txt","rb+");
   while(1)
   {
   Menu();
   switch(ch)
   {
	case '1':
		newAccount();
		break;
	case '2':
		depositAmount();
		break;
	case '3':
		withdrawAmount();
		break;
	case '4':
		balanceEnquiry();
		break;
	case '5':
		allList();
		break;
	case '6':
		closeAccount();
		break;
	case '7':
		modifyAccount();
		break;

	case '8':
		exit(0);
		break;
	default:
		//p("\nplease select valid number");
		p("\n\n\t\t\tSelect Your Option (1-8):");
		break;
   }
   getch();

  }
}