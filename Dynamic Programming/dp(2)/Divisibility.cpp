#include<iostream>
#include<vector>
#include<queue>
#include <map>
#include <cmath>
#include <string>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;
class Divisibility{
private:
    int k;
    vector<int> num;
    bool divisible;
public:
    void initial();
    void readCase();
    void computing();
    void outResult();
};
void Divisibility::initial(){
    num.clear();
    divisible = false;
    k = 0;
}
void Divisibility::readCase(){
    int t;
    int a;
    cin >> t >> k;
    while(t--){
        cin>> a;
        num.push_back(a);
    }
}
void Divisibility::computing(){
    vector<bool> vis;
    // vis ?≥ı ºªØ£ø 
    queue<int> q;
    int cur, r, t;
    int qsize;
    q.push(0);
    for(int i =0; i<num.size(); i++){
        qsize = q.size();
        vis.clear();
        vis.resize(k);
        while(qsize--){
            cur = q.front();
            q.pop();
            t = abs(num[i]) % k;
            r = (cur + t) % k;
            if(!vis[r]){
                vis[r] = true;
                q.push(r);
            }
            t = abs(num[i]) % k;
            r = (cur - t +k) % k;
            if(!vis[r]){
                vis[r] = true;
                q.push(r);
            }
        }
    }
    
    while(!q.empty()){
        if(q.front() == 0){
            divisible = true;
            break;
        }
        else{
            q.pop();
        }
    }
}
void Divisibility::outResult(){
    if(divisible)   cout << "Divisible" << endl;
    else
        cout << "Not divisible" << endl;
}
int main(){
    Divisibility d;
    int t;
    cin>>t;
    while(t--){
        d.initial();
        d.readCase();
        d.computing();
        d.outResult();
    }
    //system("pause");
    return 0;
}
