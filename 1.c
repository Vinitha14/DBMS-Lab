//
//To install mysql header files -> apt-get install libmysqlclient-dev
//To run embedded sql in c -> gcc test1.c `mysql_config --cflags --libs`

#include <mysql.h>
#include <stdio.h>

void main() {
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;

   char *server = "localhost"; // localhost for accessing local mysql
   char *user = "root";// root for students
   char *password = "vinitha24144525"; /* set me first - pwd : iiitdm123 */ 
   char *database = "COMPANY"; // Here you need to enter the database name if you have already other wise leave it free.

   conn = mysql_init(NULL);

   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
//char name[20];
//int age,n=5,tmp;
//printf("Enter the new name and new age");
//scanf("%s %d",name,&age);

/*// create employee table
if (mysql_query(conn, "create table employee (name varchar(50),ssn int, dob date,salary int, superssn int, dno int)")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
*/
/* Add primary key 
if (mysql_query(conn, "alter table employee add primary key (ssn)")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
//add auto_increment
if (mysql_query(conn, "ALTER TABLE employee modify column ssn int not null auto_increment")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
*/
/*
*/


/*
// Insertion on employee table Example-- start
char name[20];
int yr,mnth,date,sal,sssn,dno,n;
char statement[512], *my_str = "MyString";
printf("Enter the number of records:");
scanf("%d",&n);
for (int i=0;i<n;i++)
{
printf("Enter the name ");
scanf("%s",name);
printf("Enter the dob (yyyy-mm-dd)");
scanf("%d-%d-%d",&yr,&mnth,&date);
printf("Enter the salary ");
scanf("%d",&sal);
printf("Enter the super SSN ");
scanf("%d",&sssn);
printf("Enter the Department No: ");
scanf("%d",&dno);
snprintf(statement, 512, "INSERT INTO employee VALUES ('%s',ssn,'%d-%d-%d',%d,%d,%d)", name,yr,mnth,date,sal,sssn,dno);
mysql_query(conn, statement);
}
*/


/*
// create department table
if (mysql_query(conn, "create table department (dname varchar(50),dnumber int not null auto_increment, mssn int,primary key(dnumber))")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

//Add primary key on Department table 
if (mysql_query(conn, "alter table department add primary key (dnumber)")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
//add auto_increment on Department No
if (mysql_query(conn, "ALTER TABLE department modify column dnumber int not null auto_increment")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }



// set foreign key for super ssn (superssn)
if (mysql_query(conn, "alter table employee add constraint c1 foreign key (superssn) references employee(ssn) ")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }


// Insertion on department table Example-- start
char dname[20];
int mssn,n;
char statement[512], *my_str = "MyString";
printf("Enter the number of records:");
scanf("%d",&n);
for (int i=0;i<n;i++)
{
printf("Enter the department name ");
scanf("%s",dname);
printf("Enter the manager ssn");
scanf("%d",&mssn);
snprintf(statement, 512, "INSERT INTO department VALUES ('%s',dnumber,%d)", dname,mssn);
mysql_query(conn, statement);
}


// set foreign key for department no (dno)
if (mysql_query(conn, "alter table employee add foreign key (dno) references department(dnumber) ")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }


if (mysql_query(conn, "alter table department add foreign key (mssn) references employee(ssn) ")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }


// Update employee table 
char dname[20];
int age,n=5,tmp,salary,ssn;
char statement[1024], *my_str = "MyString";
printf("Enter the ssn number");
scanf("%d",&ssn);
printf("Enter the new employee Name");
scanf("%s",dname);
printf("Enter the new employee salary");
scanf("%d",&salary);
snprintf(statement, 1024, "UPDATE employee SET name='%s',salary=%d  WHERE ssn=%d", dname,salary,ssn);
mysql_query(conn, statement);



// select key word queries
if (mysql_query(conn, "select max(salary) from employee")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   res = mysql_use_result(conn);
while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s \n", row[0]);
mysql_free_result(res);


*/
while(1)
{
 int ch;
 printf("Enter your choice:\n1)Display\n2)Update a record\n3)Insert a record\n4)Delete a record\n5)Search for a record\nEnter your choice:");
 scanf("%d",&ch);
 switch(ch)
  {
   case 1:
    {
     if (mysql_query(conn,"SELECT * from Employee")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
res = mysql_use_result(conn);

unsigned long *lengths;
unsigned int num_fields;
/*
the arguments for "%.*s"  are the string width and the target string.
it's syntax is :
printf("%.*s", string_width, string);
*/
int i;
while ((row = mysql_fetch_row(res)) != NULL)
{
num_fields = mysql_num_fields(res);
    lengths = mysql_fetch_lengths(res);
    for(i = 0; i < num_fields; i++)
    {
//printf("%d",lengths[i]);
printf("%s\t",row[i]);
//printf("%7.*s \t", (int) lengths[i],row[i] ? row[i] : "NULL");
         //printf("Column %u is %lu bytes in length.\n",i, lengths[i]);
//printf("%s \n", row[i]);
    }
printf("\n");
}
      //printf("%s \n", row[0]);

mysql_free_result(res);
    }
    break;
   case 2:
    {
     char name[30],temp[15];
     char statement[1024];
     printf("Enter the Ssn:\n");
     scanf("%s",temp);
     printf("Enter the new name:\n");
     scanf("%s",name);
     snprintf(statement, 1024, "UPDATE Employee SET FName='%s' WHERE Ssn='%s'", name,temp);
     mysql_query(conn, statement);
    }
    break;
   case 3:
    {
     char fname[30],lname[30],bd[30],add[20],gen,sssn[15],minit;
     int sal,dno,sno;
     char ssn[15];
     char statement[512];
     printf("Enter First Name\n");
     scanf("%s",fname);
     printf("Enter middle name\n");
     scanf("\n%c",&minit);
     printf("Enter last Name\n");
     scanf("\n%s",lname);
     printf("Enter Ssn of employee:\n");
     scanf("\n%s",ssn);
     printf("Enter Bdate\n");
     scanf("\n%s",bd);
     printf("Enter Address\n");   
     scanf("\n%s",add);
     printf("Enter gender:\n");
     scanf("\n%c",&gen);
     printf("Enter Salary\n");
     scanf("%d",&sal);
     printf("Enter supervisor Ssn\n");
     scanf("\n%s",sssn);
     printf("Enter department no.\n");
     scanf("%d",&dno);
     printf("Enter serial no.\n");
     scanf("%d",&sno);
    
     snprintf(statement, 512, "INSERT INTO Employee VALUES ('%s','%c','%s','%s','%s','%s','%c','%d','%s','%d','%d')", fname,minit, lname, ssn, bd, add, gen,sal, sssn,dno,sno);
     mysql_query(conn, statement);
    }
    break;

   case 4 :
     {
       char ssn[10];
       puts("Enter ssn");
       scanf("%s",ssn);
       char statement[128];
   
       snprintf(statement, 128, "delete from Employee where Ssn = '%s'",ssn);

       mysql_query(conn, statement);

     }
   break;
  
   case 5:
   {
char ssn[10];
       puts("Enter ssn");
       scanf("%s",ssn);
if (mysql_query(conn, "select * from Employee where Ssn='123456789'")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   res = mysql_use_result(conn);
while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s \n", row[0]);
mysql_free_result(res);
break;
}
   default:
   printf("Invalid Entry\n");
   break;
  }
}




// Update Example-- End




/*
// Update Example-- start
char name[20];
int age,n=5,tmp;
char statement[1024], *my_str = "MyString";

for (int i=0;i<n;i++)
{
printf("Enter the old age");
scanf("%d",&tmp);

printf("Enter the new name and new age");
scanf("%s %d",name,&age);
snprintf(statement, 1024, "UPDATE employee SET name='%s' WHERE rno=%d", name,tmp);
mysql_query(conn, statement);

}
// Update Example-- End
/*
// Insertion Example-- End

   /* send SQL query */
  /* if (mysql_query(conn, "insert into employee values ('ram',2);\
 insert into employee values ('raja',22);\
")) 
{
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
*/
   res = mysql_use_result(conn);

   /* output table name */
/*
printf("MySQL Tables in mysql database:\n");
   while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s \n", row[0]);
*/
   /* close connection */

   mysql_free_result(res);
   mysql_close(conn);
}
