//
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
struct point{
  int x,y;
  point(int a=0,int b=0){x=a;y=b;}
};
class Intersection{
  private:
    point  pa,pb;
    point  p1,p2,p3,p4;
  public:
    void initial();
    void readcase();
    void computering();
    void outResult();
    int  direction(point pi,point pj,point pk);
    bool onSegment(point pi,point pj,point pk);
    bool segmentsIntersect(point p1,point p2,point p3, point p4);
    bool segmentInRectangle(point p1,point p3,point pa,point pb);
};
void Intersection::initial(){
   
}
void Intersection::readcase(){
    int x1,y1,x2,y2,x3,y3,x4,y4;  
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;  
    pa = point(x1,y1);  
    pb = point(x2,y2);  
    p1 = point(x3,y3);  
    p3 = point(x4,y4);  
    p2 = point(x3,y4);  
    p4 = point(x4,y3);  
}
void Intersection::computering(){
      if(segmentInRectangle(p1,p3,pa,pb) == true){//线段在矩形内部  
            cout << "T" << endl;  
        }else if( (segmentsIntersect(p1,p2,pa,pb))||  
                  (segmentsIntersect(p1,p4,pa,pb))||  
                  (segmentsIntersect(p3,p2,pa,pb))||  
                  (segmentsIntersect(p3,p4,pa,pb)) )  
            cout << "T" << endl;//线段在外部，但是和矩形有交点  
        else cout << "F" << endl;   
}
void Intersection::outResult(){
}
int Intersection::direction(point pi,point pj,point pk){  
    return ((pj.x - pi.x)*(pk.y - pi.y)-(pk.x - pi.x)*(pj.y - pi.y));  
}  
 bool Intersection::onSegment(point pi,point pj,point pk){  
    if((min(pi.x,pj.x) <= pk.x && pk.x <= max(pi.x,pj.x)) && (min(pi.y,pj.y) <= pk.y && pk.y <= max(pi.y,pj.y))){  
        return true;  
    }else{  
        return false;  
    }  
 }   
 bool Intersection::segmentsIntersect(point p1,point p2,point p3, point p4){  
    int  d1,d2,d3,d4;  
    d1 = direction(p3,p4,p1);    
    d2 = direction(p3,p4,p2);  
    d3 = direction(p1,p2,p3);  
    d4 = direction(p1,p2,p4);  
    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 >0)) && ((d3 > 0 && d4 < 0)||(d3 < 0 && d4 > 0)))  
        return true;  
    else if((d1 == 0)&&(onSegment(p3,p4,p1)))  
        return true;  
    else if((d2 == 0)&&(onSegment(p3,p4,p2)))  
        return true;  
    else if((d3 == 0)&&(onSegment(p1,p2,p3)))  
        return true;  
    else if((d4 == 0)&&(onSegment(p1,p2,p4)))  
        return true;  
    else return false;    
}  
bool Intersection::segmentInRectangle(point p1,point p3,point pa,point pb){  
    if( (min(p1.x,p3.x) <= pa.x && pa.x <= max(p1.x,p3.x)) &&  
        (min(p1.y,p3.y) <= pa.y && pa.y <= max(p1.y,p3.y)) &&   
        (min(p1.x,p3.x) <= pb.x && pb.x <= max(p1.x,p3.x)) &&   
        (min(p1.y,p3.y) <= pb.y && pb.y <= max(p1.y,p3.y)) )  
       return true;  
    else return false;  
} 
int main(){
   Intersection  d;
   int t;
   cin>>t;
   while(t--){
     d.initial();
     d.readcase();
     d.computering();
     d.outResult();
   }
  // system("pause");
   return 0;
 
}
