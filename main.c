#include<stdio.h>
#include<conio.h>
#include<string.h>
//list of global files that can be accessed form anywhere in program
FILE *fp,*ft,*fs;

//***********************FUNCTIONS***********************
void Add_Books();
void Search_Books();
void Renew_Books();
void View_list_Of_Books();
void Delete_Books();
void add_member();
void Search_member_Record();
void Renew_member_Record();
void member_list();
void Delete_members_record();
void exit();

//*******************STURUCTURES USED IN PROJECT****************

struct books
{
    int ID;
    char name[20];
    char Author[20];
    int Price;
    char sections[50];
};
struct books a;
struct members
{
    char reDate_issued[20];
    char reDate_return[20];
    int ID_no;
    char mname[50];
    int mnum;
};
struct members m;
void main()
{
 printf("\t\t\t  LIBRARY MANAGEMENT SYSTEM");
 printf("\n\t\t\t     >>>PUBLIC LIBRARY<<< ");
 printf("\n\t\t\t      DHAKA,BANGLADESH ");
int a;
char ch;

int pass=123456;
int userPass;
printf("\n \n \n \n \t \t Enter Password:  ");
scanf("%d",&userPass);
if(pass!=userPass)
{
    printf("\n \n \t \t Sorry, Wrong Password. \n \n \n");
    return 1;
}

system("cls");
 printf("\t\t\t  LIBRARY MANAGEMENT SYSTEM");
 printf("\n\t\t\t     >>>PUBLIC LIBRARY<<< ");
 printf("\n\t\t\t      DHAKA,BANGLADESH \n");

do{

printf("\n\t\t    =====================================");
printf("\n\t\t    |              CHOICES:             | ");
printf("\n\t\t    |                                   | ");
printf("\n\t\t    |  [1] Add Books                    | ");
printf("\n\t\t    |  [2] Search Books                 | ");
printf("\n\t\t    |  [3] Renew Books                  | ");
printf("\n\t\t    |  [4] View list Of Books           | ");
printf("\n\t\t    |  [5] Delete Books                 | ");
printf("\n\t\t    |  [6] ADD MEMBERS                  | ");
printf("\n\t\t    |  [7] SEARCH MEMBERS               | ");
printf("\n\t\t    |  [8] RENEW MEMBERS                | ");
printf("\n\t\t    |  [9] MEMBER LIST                  | ");
printf("\n\t\t    |  [10] DELETE MEMBERS              | ");
printf("\n\t\t    |  [11] EXIT                        | ");
printf("\n\t\t    =====================================");
printf("\n\t\t    Enter Your Choice : ");
scanf("%d",&a);
switch(a)
{
case 1:
Add_Books();
break;
case 2:
Search_Books();;
break;
case 3:
Renew_Books();
break;
case 4:
View_list_Of_Books();
break;
case 5:
Delete_Books();
break;
case 6:
add_member();
break;
case 7:
Search_member_Record();
break;
case 8:
Renew_member_Record();
break;
case 9:
member_list();
break;
case 10:
Delete_members_record();
break;
case 11:
exit();
break;


default :
printf("Invalid Choice!");
}
printf("\n More Actions ? (Y/N) :");
fflush(stdin);
scanf("%c", &ch);
}while(ch=='y'|| ch=='Y');
}

//*******************FUNCTION TO WRITE IN FILE*****************
void Add_Books()
{
int i,n;
struct books a;
FILE *fp;
fp=fopen("books.txt", "a");  //here we have to change some file name
if(fp==NULL)
{
printf("Book Addition Failed!");
exit(0);
}

printf("Enter the Book ID Number : ");
scanf("%d", &a.ID);
printf("Enter the Book Name : ");
fflush(stdin);
gets(a.name);
printf("Enter the name of the Author : ");
fflush(stdin);
gets(a.Author);
printf("Enter the Price of the Book : ");
fflush(stdin);
scanf("%d",&a.Price);
printf("Enter the Section of the Book : ");
fflush(stdin);
gets(a.sections);
printf("\n\n");
fwrite((char *)&a, sizeof(a), 1, fp);

fclose(fp);

}

// ************FUNCTION TO READ SPECIFIC RECORD FROM FILE***********

void Search_Books()
{
int s,recno;
char bname[20];
struct books a;
FILE *fp;
fp=fopen("books.txt", "rb");

       printf("\n\t\t      [1] Search by Book ID:      ");

       printf("\n\t\t    Enter Your Choice:");

scanf("%d", &s);
switch(s)
{
case 1:
printf("Enter the Book ID Number to Search : ");
scanf("%d", &recno);
while((fread((char *)&a, sizeof(a), 1, fp))==1)
{
if(a.ID==recno)
{
printf("\n The Book ID Number : %d", a.ID);
printf("\n The Book Name : %s",a.name);
printf("\n The Author's name: %s",a.Author);
printf("\n The price of the Book  : %d",a.Price);
printf("\n The Section of the Book : %s",a.sections);

printf("\n\n\n");
}
}
break;
}
}

//*********************FUNCTION TO RENEW BOOK'S RECORD*******************

void Renew_Books()
{
int recno, nofrec=0;
char ch;
struct books a;
FILE *fp;
fp=fopen("books.txt", "rb+");
printf("Enter the Book ID Number to modify : ");
scanf("%d", &recno);
while((fread((char *)&a, sizeof(a), 1, fp))==1)
{
nofrec++;
if(a.ID==recno)
{
printf("\n The Book ID Number : %d", a.ID);
printf("\n The Book  Name : %s",a.name);
printf("\n The Author's name: %s",a.Author);
printf("\n The Price of the book  : %d",a.Price);
printf("\n The Section of the Book : %s",a.sections);
printf("\n\n\n");
printf("\t\t\tDo you want to modify this record : ? (Y/N)");
fflush(stdin);
scanf("%c", &ch);
fseek(fp, ((nofrec-1)*sizeof(a)), 0);
if(ch=='Y'|| ch=='y')
{
printf("Enter Book ID Number : ");
scanf("%d", &a.ID);
printf("Enter the Book  Name : ");
fflush(stdin);
gets(a.name);
printf("Enter the Author's name : ");
fflush(stdin);
gets(a.Author);
printf("Enter Price of the book : ");
scanf("%d", &a.Price);
printf("Enter The Section of the Book : ");
fflush(stdin);
gets(a.sections);
fwrite((char *)&a, sizeof(a), 1, fp);
printf("Record Modified");
}
else
printf("No modifications were made\n\n");
fclose(fp);
}
}
}

//*********************FUNCTION TO VIEW LIST OF BOOKS*******************

void View_list_Of_Books()
{
int nofrec=0;
struct books a;
FILE *fp;
fp=fopen("books.txt", "rb");
if(fp==NULL)
{
printf("\n\n\tFile doesn’t exist!!! TRY AGAIN");
exit(0);
}
while((fread((char *)&a, sizeof(a), 1, fp))==1)
{
nofrec++;
printf("\n The Book ID Number : %d", a.ID);
printf("\n The Book  Name : %s",a.name);
printf("\n The Author's name: %s",a.Author);
printf("\n The Price of the book  : %d",a.Price);
printf("\n The Section of the Book : %s",a.sections);

printf("\n\n\n");
}
printf("\n\n\t\t  Total number of records present are : %d\n\n", nofrec);
fclose(fp);
}

//*********************FUNCTION TO DELETE BOOKS FROM FILE **************************

void Delete_Books()
{
int recno;
char ch;
struct books a;
FILE *fp, *ft;
fp=fopen("books.txt", "rb");
ft=fopen("Temp.txt", "wb");
printf("Enter the Book ID Number to delete : ");
scanf("%d", &recno);
while((fread((char *)&a, sizeof(a), 1, fp))==1)
{
if(a.ID==recno)
{
printf("\n The Book ID Number : %d", a.ID);
printf("\n The Book  Name : %s",a.name);
printf("\n The Author's name: %s",a.Author);
printf("\n The Price of the book  : %d",a.Price);
printf("\n The Section of the Book : %s",a.sections);

printf("\n\n\n");
printf("Do you want to delete this record : ? (Y/N)");
fflush(stdin);
scanf("%c", &ch);
}
}
if(ch=='y'||ch=='Y')
{
rewind(fp);
printf("\n\n\t     Record is delete       \n\n");
while((fread((char *)&a, sizeof(a), 1, fp))==1)
{
if(recno!=a.ID)
{
fwrite((char *)&a, sizeof(a), 1, ft);
}
}
}
else
printf("\n\n\t\t\tNo Record was deleted");
fclose(fp);
fclose(ft);
remove("books.txt");
rename("Temp.txt", "books.txt");
}
//******************MEMBERS****************

void add_member()
{
int i,n;
struct members m;
FILE *fp;
fp=fopen("member.txt", "a");  //here we have to change some file name
if(fp==NULL)
{
printf("File Creation Failed!");
exit(0);
}
printf("Enter The member ID Number : ");
scanf("%d", &m.ID_no);
printf("Enter The member  Name : ");
fflush(stdin);
gets(m.mname);
printf("Enter The member's contact number : ");
scanf("%d", &m.mnum);
printf("\n The Books Issued from Library : ");
fflush(stdin);
gets(m.reDate_issued);
printf("\n The Books Returned Date : ");
fflush(stdin);
gets(m.reDate_return);
printf("\n\n");
fwrite((char *)&m, sizeof(m), 1, fp);

fclose(fp);

}
//*********FUNCTION TO READ SPECIFIC RECORD FROM FILE**********

void Search_member_Record()
{
int s,recno;
char mname[20];
struct members m;
FILE *fp;
fp=fopen("member.txt", "rb");

       printf("\n\t\t      [1] Search by member ID_No :      ");

       printf("\n\t\t    Enter Your Choice:");

scanf("%d", &s);
switch(s)
{
case 1:
printf("Enter the member ID Number to Search : ");
scanf("%d", &recno);
while((fread((char *)&m, sizeof(m), 1, fp))==1)
{
if(m.ID_no==recno)
{
printf("\n The member ID Number : %d", m.ID_no);
printf("\n The member First Name : %s",m.mname);
printf("\n The member's Contact Number  : %d",m.mnum);
printf("\n The Books Issued from Library : %s",m.reDate_issued);
printf("\n The Books Returned Date : %s",m.reDate_return);

printf("\n\n\n");
}
}
break;
}
}

//*********************FUNCTION TO RENEW MEMBERS'S RECORD*******************
void Renew_member_Record()
{
int recno, nofrec=0;
char ch;
struct members m;
FILE *fp;
fp=fopen("member.txt", "rb+");
printf("Enter the member ID Number to modify : ");
scanf("%d", &recno);
while((fread((char *)&m, sizeof(m), 1, fp))==1)
{
nofrec++;
if(m.ID_no==recno)
{
printf("\n The Member's ID Number : %d", m.ID_no);
printf("\n The Member's First Name : %s",m.mname);
printf("\n The Member's Contact Number  : %d",m.mnum);
printf("\n The Books Issued from Library : %s",m.reDate_issued);
printf("\n The Books Returned Date : %s",m.reDate_return);
printf("\n\n\n");
printf("\t\t\tDo you want to modify this record : ? (Y/N)");
fflush(stdin);
scanf("%c", &ch);
fseek(fp, ((nofrec-1)*sizeof(m)), 0);
if(ch=='Y'|| ch=='y')
{
printf("Enter the member ID Number : ");
scanf("%d", &m.ID_no);
printf("Enter the member  Name : ");
fflush(stdin);
gets(m.mname);
printf("Enter the member's Contact Number : ");
scanf("%d", &m.mnum);
printf("\n The Books Issued from Library : ");
fflush(stdin);
gets(m.reDate_issued);
printf("\n The Books Returned Date : ");
fflush(stdin);
gets(m.reDate_return);
fwrite((char *)&m, sizeof(m), 1, fp);
printf("Record Modified");
}
else
printf("No modifications were made\n\n");
fclose(fp);
}
}
}

//*********************FUNCTION TO VIEW LIST OF MEMBERS*******************

void member_list()
{
int nofrec=0;
struct members m;
FILE *fp;
fp=fopen("member.txt", "rb");
if(fp==NULL)
{
printf("\n\n\tFile doesn’t exist!!! TRY AGAIN");
exit(0);
}
while((fread((char *)&m, sizeof(m), 1, fp))==1)
{
nofrec++;
printf("\n The Member's ID Number : %d", m.ID_no);
printf("\n The Member's  Name : %s",m.mname);
printf("\n The Member's Contact Number  : %d",m.mnum);
printf("\n The Books Issued from Library : %s",m.reDate_issued);
printf("\n The Books Returned Date : %s",m.reDate_return);

printf("\n\n\n");
}
printf("\n\n\t\t  Total number of records present are : %d\n\n", nofrec);
fclose(fp);
}

//*********************FUNCTION TO DELETE MEMBER'S RECORD FROM FILE **************************

void Delete_members_record()
{
int recno;
char ch;
struct members m;
FILE *fp, *ft;
fp=fopen("member.txt", "rb");
ft=fopen("Temp.txt", "wb");
printf("Enter the member ID Number to delete : ");
scanf("%d", &recno);
while((fread((char *)&m, sizeof(m), 1, fp))==1)
{
if(m.ID_no==recno)
{
printf("\n The Member ID Number : %d", m.ID_no);
printf("\n The Member First Name : %s",m.mname);
printf("\n The Member's Contact Number  : %d",m.mnum);
printf("\n The Books Issued from Library : %s",m.reDate_issued);
printf("\n The Books Returned Date : %s",m.reDate_return);

printf("\n\n\n");
printf("Do you want to delete this record : ? (Y/N)");
fflush(stdin);
scanf("%c", &ch);
}
}
if(ch=='y'||ch=='Y')
{
rewind(fp);
printf("\n\n\t     Record is deleted       \n\n");
while((fread((char *)&m, sizeof(m), 1, fp))==1)
{
if(recno!=m.ID_no)
{
fwrite((char *)&m, sizeof(m), 1, ft);
}
}
}
else
printf("\n\n\t\t\tNo Record was deleted");
fclose(fp);
fclose(ft);
remove("member.txt");
rename("Temp.txt", "member.txt");
}
