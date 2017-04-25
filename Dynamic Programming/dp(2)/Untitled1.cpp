#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(){
	char coin[30];
	int N,M;
	int d[5000];
	int count;
	int ans;
	int min;
	cin>>N;
	while(N--)
	{
		int k=0;
		string str;
		count=0;
		memset(d,0,sizeof(d));
		d[0]=1;
	    getline(cin,str,'#');
	    //cout<<str;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]!=' ')
			{
				coin[k]=str[i];
				count+=(coin[k]-'0');
				k++;
			}
		}
		for(int i=0;i<k;i++)
		{
			for(int j=count;j>=coin[i];j--)
			{
				if(d[j-(coin[i]-'0')]){
					d[j]=1;
				}
			}
		}
		for(int i=count/2;i>=0;i--)
		{
			if(d[i])
			{
				ans=i;
				break;
			}
		}
		min=count-2*ans;
		if(min==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
