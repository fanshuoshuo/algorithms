#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
      vector<int> numbers;
      numsbers.push_back(1);
      numsbers.push_back(2);
      numsbers.push_back(3);
      numsbers.push_back(2);
      numsbers.push_back(2);
      numsbers.push_back(2);
      numsbers.push_back(5);
      numsbers.push_back(4);
	  int len=numbers.size(2);
        map<int,int> mapCount;
        for(int i=0;i<numbers.size();i++){
            mapCount[numbers[i]]++;
        }
        map<int,int>::iterator it;
        it=mapCount.begin();
        for(;it!=mapCount.end();it++){
            if(it->second>len/2){
                cout<<it->first;
                break;
            }
        }
        return 0;
    
}