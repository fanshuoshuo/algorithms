/****************************************
function: MergeSort
author	: fanshuoshuo
date	: 20170303
****************************************/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <climits>
using namespace std;
class MergeSort{
	private : 
		vector<int> A;
		int p,r;
		void merge(vector<int>&A,int p,int r,int q);
	public :
		void initialize(int n);
		void mergeSort(vector<int>&A,int p,int r);
		void sort(){mergeSort(A,p,r);};
		void output();
		

};
void MergeSort::initialize(int n){
	p=1;r=n;
	A.push_back(0);
	for(int i=1;i<=n;i++)
		A.push_back(rand()/10000000);
		
}
void MergeSort::mergeSort(vector<int>&A,int p,int r){
	if(p<r){
		int q=(p+r)/2;
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,r,q);
	}
}
void MergeSort::merge(vector<int>&A,int p,int r,int q){
        cout<<p<<q<<r<<endl;
//	output();
	int n1=q-p+1;
	int n2=r-q;
	vector<int> L,R;
	L.push_back(0);R.push_back(0);
	for(int i=1;i<=n1;i++)
		L.push_back(A[i+p-1]);
	for(int j=1;j<=n2;j++)
		R.push_back(A[q+j]);
	L.push_back(INT_MAX);
	R.push_back(INT_MAX);
	int i,j;i=j=1;
	for(int k=p;k<=r;k++){
		if(L[i]<R[j])
			A[k]=L[i++];
		else 	
		  A[k]=R[j++];
	}
	output();
}

void MergeSort::output(){
	for(int i=1;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

}
int main(){

	MergeSort Ms;
	Ms.initialize(8);
	Ms.output();
	Ms.sort();
	//Ms.output();
	return 0;
}

/************************************
intput:an array A,start index p,end index r
MergeSort(A,p,r){

	if(p<r){
		q=(p+r)/2
		MergeSort(A,p,q)
		MergeSort(A,q+1,r)
		Merge(A,p,r,q)
	}
}
Merge(A,p,r,q){
	len1=q-p+1
	len2=r-q
	Let L[0,1...len1] R[0,1,.....lent2]new array
	for i=0 to len1-1
		L[i]=A[p+i]
	for i=0 to len2-1
		R[i]=A[q+i+1]
	L[len1]=Max_Int
	R[len2]=Max_Int
	j=i=0
	for(k= p to r)
		if(L[i]<R[j])
			A[k]=L[i++]
		A[k]=R[j++]

	
}

output:sorted array A


*************************************/
