#include<bits/stdc++.h>
using namespace std;

class DBMS
{
	char R[30];
	string f[30][2];
	int n;
	int r;
	string ck[30];
	string str;
	int b;
	string sck;
	string nf[30];
	int m;
public:
	void read();
	void display();
	void fddelete(int i);
	void mincover();
	void checktransitive(string s[2]);
	void delduplicates();
	int checksubstring(string s1,string s2);
	void closure(int a);
	void delck(int x);
	void checksudotrans(string s[2]);
	void candidate();
	DBMS()
	{
		b=0;
		m=1;
	}
};


int DBMS::checksubstring(string s1,string s2)
{
	int flag=0;
	int c=0;
	for(int i=0;i<s1.length();i++)
	{
		if(c!=s2.length()-1)
		{
			if(s1[i]==s2[c])
				c++;

			else
				c=0;
		}

		else
			flag=1;
	}
	return(flag);
}

void DBMS::candidate()
{
	//cout<<"Candidate Key Started"<<endl;
	for(int i=1;i<=r;i++)
	{
		closure(i);
	}
	int min=ck[0].length();
	for(int i=0;i<b;i++)
	{
		if(ck[i].length()<min){
			min=ck[i].length();
		}
	}

	int d=0;
	for(int i=0;i<b;i++)
	{
		if(ck[i].length()==min)
		{
			ck[d]=ck[i];
			d++;
		}
	}
	b=d;
	int del[10];
	int c=0;
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(j!=i)
			{
				if(ck[i]==ck[j])
				{
						delck(j);
				}
			}
		}
	}
	for(int i=0;i<c;i++)
	{
			delck(del[i]);
	}
	cout<<"The Candidate Keys are: "<<endl;
	for(int i=0;i<b;i++)
	{
		cout<<ck[i]<<endl;
	}
	//cout<<"Candidate Key Ended"<<endl;
}

void DBMS::delck(int x)
{
	for(int i=x;i<b-1;i++)
	{
		ck[i]=ck[i+1];
	}
	b--;
}



void DBMS::closure(int a)
{

	string temp;
	temp=f[a][0];
	temp.append(f[a][1]);
	sort(temp.begin(),temp.end());
	for(int i=1;i<=n;i++)
	{
		string res;
		res=temp;
		for(int k=1;k<=r;k++)
		{
			if(k!=a)
			{
				int flag=0;
				int c=0;
				for(int j=0;j<temp.length();j++)
				{
					if(c!=f[k][0].length()-1)
					{
						if(f[k][0][c]==temp[j])
						{
							c++;
						}

						else
							c=0;
					}
					else
						flag=1;
				}

				if(flag==1)
				{
					set_difference(f[k][1].begin(),f[k][1].end(),temp.begin(),temp.end(),back_inserter(res));
					string s;
					set_union(temp.begin(),temp.end(),res.begin(),res.end(),back_inserter(s));
					//cout<<res<<endl;
					res=s;
					sort(res.begin(),res.end());
					//cout<<temp<<" "<<s<<endl;
				}
			}
			}
			if(temp==str)
				break;
			if(temp==res)
			{
				break;
			}

			else
				temp=res;
	}
	//cout<<temp<<endl;
	//cout<<str<<endl;
	if(temp==str)
	{
			//cout<<"Executed"<<endl;
			ck[b]=f[a][0];
			b++;
	}
}


void DBMS::read()
{
	cout<<"Enter the Number of realtions: "<<endl;
	cin>>n;
	cout<<"Enter the Number of FD's: "<<endl;
	cin>>r;
	cout<<"Enter the entities in R: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>R[i];
	}
	for(int i=1;i<=n;i++)
	{
		str.push_back(R[i]);
	}
	sort(str.begin(),str.end());
	cout<<"Enter the FD's: "<<endl;
	for(int i=1;i<=r;i++)
	{
		cin>>f[i][0];
		cin>>f[i][1];
	}
	nf[0]=str;
	//cout<<"Input Ended"<<endl;
}

void DBMS::display()
{
	cout<<"R is: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<R[i]<<",";
	}
	cout<<endl;
	cout<<"The Final FD's are: "<<endl;
	for(int i=1;i<=r;i++)
	{
		cout<<f[i][0]<<"->"<<f[i][1]<<",";
	}

	cout<<endl;
}

void DBMS::fddelete(int i)
{
	for(int j=i;j<r;j++)
	{
		f[j][0]=f[j+1][0];
		f[j][1]=f[j+1][1];
	}
	r--;
}

void DBMS::mincover()
{
	//cout<<"Execution Started"<<endl;
	for(int i=1;i<=r;i++)
	{
		if(f[i][1].length()>1)
		{
			for(int j=2;j<=f[i][1].length();j++)
			{
				r++;
				f[r][0]=f[i][0];
				f[r][1]=f[i][1][j-1];
			}
		}
		f[i][1]=f[i][1][0];
	}
	//cout<<"Right Dissasociation Ended"<<endl;
	delduplicates();

	for(int i=1;i<=r;i++)
	{
		if(f[i][0].length()>1)
		{
			{
				for(int k=1;k<=r;k++)
				{
					sort(f[k][0].begin(),f[k][0].end());
					sort(f[k][1].begin(),f[k][1].end());
					sort(f[i][0].begin(),f[i][0].end());
					string temp;
					set_union(f[k][0].begin(),f[k][0].end(),f[k][1].begin(),f[k][1].end(),back_inserter(temp));
					int flag=0;
					int c=0;
					for(int j=0;j<f[i][0].length();j++)
					{
						if(c!=temp.length()-1)
						{
							if(f[i][0][j]==temp[c])
							{
								c++;
							}

							else
							c=0;
						}
						else
							flag=1;
					}
					if(flag==1)
					{
						string res;
						set_difference(f[i][0].begin(),f[i][0].end(),f[k][1].begin(),f[k][1].end(),back_inserter(res));
						f[i][0]=res;
					}
				}
			}
		}
	}
	//cout<<"Left Dissasociation Ended"<<endl;
	delduplicates();



	for(int i=1;i<=r;i++)
	{
		int a[n];
		int c=0;
		for(int j=1;j<=r;j++)
		{
			if(f[i][0]==f[j][0])
			{
				a[c]=j;
				c++;
			}
		}

		for(int j=0;j<c;j++)
		{
			string temp[2];
			set_union(f[i][1].begin(),f[i][1].end(),f[a[j]][1].begin(),f[a[j]][1].end(),back_inserter(temp[1]));
			temp[0]=f[i][0];
			checktransitive(temp);
		}
	}
	//cout<<"Transitive Check Ended"<<endl;
	delduplicates();

	cout<<"Number of FD's in Minimal Cover are: "<<r<<endl;
}

void DBMS::checktransitive(string s[2])
{
	for(int j=1;j<=r;j++)
	{
		if(s[1]==f[j][0] && s[0]!=f[j][0] && s[1]!=f[j][1])
		{
			for(int k=1;k<=r;k++)
			{
				if(k!=j)
				if(s[0]==f[k][0] && f[j][1]==f[k][1])
					{
						//cout<<k<<endl;
						fddelete(k);
					}
			}
			string temp[2];
			temp[0]=s[0];
			temp[1]=f[j][1];
			checktransitive(temp);
		}
	}
}


void DBMS::checksudotrans(string s[2]){
		for(int i=0;i<s[1].length();i++)
		{
			string temp[2];
			temp[0]=s[0];
			temp[1]=s[1];
			temp[1].push_back(temp[0][i]);
			sort(temp[1].begin(),temp[1].end());
			checktransitive(temp);
		}
}



void DBMS::delduplicates()
{
	int a[n];
	int c=0;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=r && j!=i;j++)
		{
			sort(f[i][0].begin(),f[i][0].end());
			sort(f[i][1].begin(),f[i][1].end());
			sort(f[j][0].begin(),f[j][0].end());
			sort(f[j][1].begin(),f[j][1].end());

			if(f[i][0]==f[j][0] && f[i][1]==f[j][1])
			{
				a[c]=j;
				c++;
			}
		}
	}
	for(int i=0;i<c;i++)
	{
		fddelete(a[i]);
	}
}

int main()
{
	DBMS obj;
	obj.read();
	obj.mincover();
	obj.candidate();
	obj.display();
	return(0);
}
