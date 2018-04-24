#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int attributes[100][100],n,m,k,count=1;
char lhs[100][100],rhs[100][100],ck[100][100];
class twonf
{
public:
   int index(int a)
    {
      int i;
      for(i=0;i<count;i++)
      {
        if(attributes[i][a]==1)
          return i;
      }
      }     
	 int county(char a[])
	 {
	 	int c=0;
	 	for(int i=0;a[i]!='$';i++)
	 	{
	 		c++;

	 	}
	 	
	 	return c;
	 }
	 void check(string t,char l[][100],char r[][100],int h)
	 {
	 	string test,test1;
	 	int c,j,k,d,flag=0;
       for(int i=0;i<m;i++)
       {
          test=l[i];
          c=county(l[i]);
          test=test.substr(0,test.length()-(test.length()-c));
          if(strstr(t.c_str(),test.c_str()))
          {
               flag=1;
          	   test1=r[i];
               d=county(r[i]);
               test1=test1.substr(0,test1.length()-(test1.length()-d));
              
               for(j=0;j<test1.length();j++)
               {
                 k=test1[j]-65;
                 attributes[count][k]=1;
               	 attributes[h][k]=0;
               }
               check(test1,l,r,h);
          }
          else if(strstr(test.c_str(),t.c_str()))
          {
            flag=1;
            
          	for(j=0;j<test.length();j++)
          	{
          		k=test[j]-65;
          		attributes[count][k]=1;
               	attributes[h][k]=0;

          	}
               test1=r[i];
               d=county(r[i]);
               test1=test1.substr(0,test1.length()-(test1.length()-d));
               
               for(j=0;j<test1.length();j++)
               {
                 k=test1[j]-65;
                 attributes[count][k]=1;
               	 attributes[h][k]=0;
               }	
               check(test1,l,r,h);
          }
       }
      if(flag==0)
        return;

	 }
	 void test(char l[][100],char r[][100])
	 {
       string test1,test2,test3;
       int indi,i,j,count1,count2,count3;
       for(i=0;i<m;i++)
       {
       	  test1=l[i];
       	  count1=county(l[i]);
       	  test1=test1.substr(0,test1.length()-(test1.length()-count1)); 
          
        for(j=0;j<k;j++)
       	{ 
       		 test2=ck[j];
       		 count2=county(ck[j]);
       		 test2=test2.substr(0,test2.length()-(test2.length()-count2));
       		 
       		if((strstr(test2.c_str(),test1.c_str())) && (test1!=test2))
       		{   
       		    indi=index(test1[0]-65);	  
       		  	decompose(i,indi);
       		  	test3=r[i];
       		  	count3=county(r[i]);
       		  	test3=test3.substr(0,test3.length()-(test3.length()-count3));
                check(test3,l,r,indi);
                count++;
       		}
          
       	}
       }
	 }
	 void decompose(int a,int k)
	 {
	    
	    int temp1,temp2,i=0,j=0;
	     
	    for(i=0;lhs[a][i]!='$';i++)
	    {
            temp1=lhs[a][i]-65;
            attributes[count][temp1]=1;

	    }
	    for(j=0;rhs[a][j]!='$';j++)
	    {
            temp2=rhs[a][j]-65;
            attributes[k][temp2]=0;
            attributes[count][temp2]=1;
	    }
       
	 }

  
};
class threenf:public twonf
{
 public:
    void test1(char l[][100],char r[][100])
         {
            test(l,r);
            string test1,test2,test3;
            int  i,j,count1,count2,count3,indi,flag=0;
       for(i=0;i<m;i++)
       {
          test1=l[i];
          count1=county(l[i]);
          test1=test1.substr(0,test1.length()-(test1.length()-count1)); 
          flag=0;
        for(j=0;j<k;j++)
        { 
           test2=ck[j];
           count2=county(ck[j]);
           test2=test2.substr(0,test2.length()-(test2.length()-count2));
          if(strstr(test2.c_str(),test1.c_str()))
          {   
              flag=1;
              
          }
         }
         
         if(flag==0)
         {
           indi=index(test1[0]-65);
             decompose(i,indi);
              test3=r[i];
              count3=county(r[i]);
              test3=test3.substr(0,test3.length()-(test3.length()-count3));
               
              check(test3,l,r,indi);
                count++;
         }
         
       }
    }
};
int main()
{
	system("reset");
   int i,j,choice;
   char a,l[100][100],r[100][100];
   cout<<"\tEnter the number of attributes:";
   cin>>n;
   cout<<"\tEnter the number of functional dependencies:";
   cin>>m;
   
   for(i=0;i<n;i++)
   	attributes[0][i]=1;

    
   cout<<"\tEnter the LHS matrix:\n";
   for(i=0;i<m;i++)
   {
   	for(j=0;j<n;j++)
   	{
   		cin>>lhs[i][j];
   	}
   }
   cout<<"\tEnter the RHS matrix:\n";
   for(i=0;i<m;i++)
   {
   	for(j=0;j<n;j++)
   	{
   		cin>>rhs[i][j];
   	}
   }
    
    cout<<"\tEnter the number of candiate keys:";
    cin>>k;
    cout<<"\tEnter the candidate key Matrix:\n";      
    for(i=0;i<k;i++)
    {
      for(j=0;j<n;j++)
      	cin>>ck[i][j];
    	}
      	
   for(i=0;i<m;i++)
   {
   	for(j=0;j<n;j++)
   	{
   		l[i][j]=lhs[i][j];
   		r[i][j]=rhs[i][j];
   	}
   }


    
      cout<<"\t\t\tMENU\n";
      cout<<"\t\t1.Database resolved till 2NF\n\t\t2.Database resolved till 3NF\n";
      cout<<"\t\t3.Test for BCNF in the Database\n";
      cout<<"\t\tEnter your choice:";
      cin>>choice;
      if(choice==1)
      {
        class twonf obj;
        obj.test(l,r);
      }
      else if(choice==2)
      {
        class threenf obj;
        obj.test1(l,r);
      }
    
    cout<<"\tRelation Matrix:\n";
    for(i=0;i<count;i++)
    {cout<<"\n";
     for(j=0;j<n;j++)
      cout<<attributes[i][j]<<"\t";
       }
    
    
     
 cout<<"\n";    
}
