/* 
Flow shop
date:     20161024  
author ： ShuoshuoFan   
source：  计算机算法设计与分析 第四版 王晓东著  3.9  
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
		//这里需要注意map 的倒序遍历的用法 
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

n个作业1-n要在由2台机器M1和M2组成的流水线上完成加工。每个作业加工的顺序
都是现在M1 上加工，然后在M2上加工 ，在M1和M2上加工作业i所需要的时间分别
为ai和bi。流水作业调度问题要求确定这n个作业的最优加工顺序，使得加工完成所
需要的时间最少。  

输入： 
5
2 4
1 4
7 3
3 4
4 1
输出任务的序号，代表处理这些任务的序列

 2  1 4  3 5
**************************************************************/   
