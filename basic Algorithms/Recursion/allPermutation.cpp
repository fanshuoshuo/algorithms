#include <iostream>
using namespace std;
int b[5]={1,2,3};
 void swap( int a[],int left, int right) {  
        int temp = a[left];  
        a[left] = a[right];  
        a[right] = temp;  
  } 
void solve(int a[], int left, int right) {  
     
        if(left==right){  
            for(int i = 0;i<3;i++){  
                cout<<a[i]<<" ";
            }  
            cout<<endl;
        }else{  
            for(int i = left;i<=right;i++){  
                swap(a,left,i);  
                solve(a,left+1,right);  
                swap(a,left,i);  
            }  
        }  
  }  
  
 

int main(){

	int left=0;
	int right=5;
	solve(b,left,right);
	return 0;
}


  
