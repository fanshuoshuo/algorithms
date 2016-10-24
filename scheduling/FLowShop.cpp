/* 
Flow shop
date:     20161024  
author �� ShuoshuoFan   
source��  ������㷨�������� ���İ� ��������  3.9  
*/ 
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <vector> 
#include <map>
using namespace std;
class JobShop{

	private:
		int JobTime[100][2];
		int N ;//Number of Job
		map<int ,int> N1,N2;
	public :
		void init();
		void input();
		void computing();
		void output();
};
	void JobShop::init(){
		memset(JobTime,9,sizeof(JobTime));
		N=0;
		N1.clear();
		N2.clear();
	}
	void JobShop::input(){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>JobTime[i][0]>>JobTime[i][1];	
		}
		
	}
	void JobShop::computing(){
		//Johnson rule
		
		for(int i=0;i<N;i++){
		//cout<<JobTime[i][0]<<JobTime[i][1]<<endl;
		   if(JobTime[i][0]<JobTime[i][1])
		   		N1[JobTime[i][0]]=(i+1);
			else {
					N2[JobTime[i][1]]=(i+1);
					cout<<N2[JobTime[i][1]]<<endl;
			}
			//	N2[JobTime[i][1]]=(i+1);	
		}
	}
	void JobShop::output(){

		map<int ,int>::iterator it;
		for(it=N1.begin();it!=N1.end();it++)
			cout<<it->second<<" ";
		//������Ҫע��map �ĵ���������÷� 
	    map<int, int>::reverse_iterator iter;
		for(iter=N2.rbegin();iter!=N2.rend();iter++)
			cout<<iter->second<<" ";
	}	
int main(){
	
	JobShop Js;
	Js.init();
	Js.input();
	Js.computing();
	Js.output(); 
	return 0;
} 

/********************************************************

n����ҵ1-nҪ����2̨����M1��M2��ɵ���ˮ������ɼӹ���ÿ����ҵ�ӹ���˳��
��������M1 �ϼӹ���Ȼ����M2�ϼӹ� ����M1��M2�ϼӹ���ҵi����Ҫ��ʱ��ֱ�
Ϊai��bi����ˮ��ҵ��������Ҫ��ȷ����n����ҵ�����żӹ�˳��ʹ�üӹ������
��Ҫ��ʱ�����١�  

���룺 
5
2 4
1 4
7 3
3 4
4 1
����������ţ���������Щ���������

 2  1 4  3 5
**************************************************************/   
