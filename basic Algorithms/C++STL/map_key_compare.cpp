/*
http://blog.csdn.net/iicy266/article/details/11906189
http://blog.csdn.net/idmer/article/details/54022889

*/
#include <vector> 
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
struct CompareBykeyLen {  
  bool operator()(const string& k1, const string& k2) {  
    return k1.length() < k2.length();  
  }  
};  
typedef pair<string,int> PAIT;
struct CmpByValue{
	bool operator()(const PAIT p1,const PAIT p2){
	  return p1.second<p2.second;
	}
};
int main(){
	//less ,greater
	//sort by key des
	map<int,int,greater<int>> map_num;
	map_num[2]=3;
	map_num[4]=5;
	map_num[4]=6;
	map<int,int>::iterator it;
	for(it=map_num.begin();it!=map_num.end();it++){
		cout<<it->first<<" "<<it->second<<" "<<endl;
	}
	//sort by key length asc
	map<string ,int,CompareBykeyLen> map_str;
	map_str["fan"]=100;
	map_str["shuoshuo"]=102;
	map_str["aaaa"]=33;
	map<string,int>::iterator it_str;

	for(it_str=map_str.begin();it_str!=map_str.end();it_str++){
		cout<<it_str->first<<" "<<it_str->second<<" "<<endl;
	}
	cout<<"sort by value"<<endl;
	vector<PAIT> vec(map_str.begin(),map_str.end());
	sort(vec.begin(),vec.end(),CmpByValue());
	for(int i=0;i<vec.size();i++){
		cout<<vec[i].first<<"  "<<vec[i].second<<endl;
	}
	return 0;
}
