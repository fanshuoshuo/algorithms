/***********************
Sort 

author :ShuoshuoFan
date   :20170302 
source :Introduction to Algorithms

************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class sort{

	private:

		vector<int> A;
		int p,r;
		int partition(vector<int> &A,int p,int r);
		void QuickSort(vector<int> &A,int p,int r);
		void exchange(int *a,int *b);
	public :
		void initialize(int length);
		void Sort(){QuickSort(A,p,r);};
		void output();


};
void sort:: QuickSort(vector<int> &A,int p,int r){

	if(p<r){
		int q=partition(A,p,r);
		QuickSort(A,p,q-1);
		QuickSort(A,q+1,r);

	}
}
int sort::partition(vector<int> &A,int p,int r){
	int x=A[r];
	int i=p-1;
	for(int j=p;j<=r-1;j++){
		if(A[j]<=x){
			i++;
			//exchange(&A[j],&A[i]);
			int temp=A[j];
			A[j]=A[i];
			A[i]=temp;
		}
	}
	int tmp=A[r];
	A[r]=A[i+1];
	A[i+1]=tmp;

	return i+1;

}
void sort:: output(){
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<"  ";
	
	}
	cout<<endl;
}
void sort:: initialize(int length){
	A.clear();
	A.resize(length);
	for(int i=0;i<length;i++)
		A[i]=rand()/100000000;
	p=0;r=length-1;
}
void sort::exchange(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(){

	sort S;
	S.initialize(6);
	S.output();
	S.Sort();
	S.output();
	return 0;
}

/******************************************************
QuickSort
Input: a array A,start index p,end index r ;
Function QuickSort(A,p,r){
	
	if(p<r)
		q=partition(A,p,r)
		QuickSort(A,p,q-1)
		QuickSort(A,q+1,p)	
}
Funciton partation(A,p,r) return partation index q 
	x=A[r]
	i=p-1
	for j=p to r-1
		if(A[j]<x)
			i++;
			exchange(A[i][j])
	i++
	exchange (A[i],A[r]);
	return i;


}
Output: Sorted array A
**********************************************************/	
