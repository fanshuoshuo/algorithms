#include<iostream>
#include<vector>
using namespace std;
////////////////////
struct Stone{
    char s;
    int m;
    Stone(char a = ' ', int b = 0){s = a; m = b;}
};
class DynamicFrog{
private:
    int distance;
    int minMax;
    vector<Stone> stone;
public:
    void initial(){stone.clear();}
    void readCase();
    void computing();
    void outResult(int i){cout << "Case " << i << ": " << minMax << endl;}
};
void DynamicFrog::readCase(){
    int n;
    char s;
    int m;
    char hyphen;
    cin >> n >> distance;
    while(n--){
        cin>> s >> hyphen >> m;
        stone.push_back(Stone(s, m));
    }
    stone.push_back(Stone('B', distance));
}
void DynamicFrog::computing(){
    int lr = 0;
    int rl = 0;
    minMax = 0;
    for(int i = 0; i < stone.size(); i++){
        if(stone[i].s == 'B'){//big
            minMax = max(minMax, stone[i].m - lr);
            minMax = max(minMax, stone[i].m - rl);
            lr = rl = stone[i].m;
        }else if (i%2 == 0){
            minMax = max(minMax, stone[i].m - lr);
            lr = stone[i].m;
        }else{
            minMax = max(minMax, stone[i].m - rl);
            rl = stone[i].m;
        }
    }
}
//2 3 6
////////////////////
int main(){
    int t;
    DynamicFrog df;
    cin >> t;
    for(int i = 1; i <= t; i++){
        df.initial();
        df.readCase();
        df.computing();
        df.outResult(i);
    }
    return 0;
}
