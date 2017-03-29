#include <iostream>  
#include <algorithm>  
#include <iomanip>  
#include <cstring>  
#include <cmath>  
using namespace std;  
#define MAXPOLY 110  
#define MAXN 25  
struct point{  
    int x;  
    int y;  
};  
struct polygon {  
    int n;  
    point p[MAXPOLY];  
}; 
bool leftLower(point first, point second)  
{   
    if (first.x == second.x)  
        return first.y < second.y;  
    else  
        return first.x < second.x;  
}  
point sites[MAXPOLY];  
polygon kingdom[MAXN];  
bool powerOff[MAXN];  
class  SCUDBusters{
  private:
     int kingdomNumber; 
     point missile;  
     double totalArea;
     int sitesNumber; 
  public:
     void initial(); 
     void readcase();
     void computering();
     int crossProduct(point first, point second, point third);
     void convexHull(point vertex[], int vertexNumber, polygon &container) ;   
     bool pointInPolygon(point pt, polygon &polygons);
     double area(point vertex[], int vertexNumber) ;       
}; 
void SCUDBusters::initial(){
      kingdomNumber = 0; 
      memset(powerOff, false, sizeof(powerOff)); 
      totalArea = 0.0;
}
void SCUDBusters::readcase(){
    while (cin >> sitesNumber&&sitesNumber > 0)  {  
        for (int i = 0; i < sitesNumber; i++)  
            cin >> sites[i].x >> sites[i].y;  
        convexHull(sites, sitesNumber, kingdom[kingdomNumber]);  //¼ÆËãÍ¹°ü 
        kingdomNumber++;  
    }     
    while (cin >> missile.x >> missile.y)  {  
        for (int i = 0; i < kingdomNumber; i++)  
            if (pointInPolygon(missile, kingdom[i]))  
                powerOff[i] = true;  
    }
 }
 void SCUDBusters::computering(){
   for (int i = 0; i < kingdomNumber; i++)  
        if (powerOff[i])  
            totalArea += area(kingdom[i].p, kingdom[i].n);  
    cout.precision(2);  
    cout.setf(ios::fixed | ios::showpoint);  
    cout << totalArea << endl;  
 } 
int SCUDBusters::crossProduct(point first, point second, point third)  
{  
    return (second.x - first.x) * (third.y - first.y) -  
        (second.y - first.y) * (third.x - first.x);  
}  
void SCUDBusters::convexHull(point vertex[], int vertexNumber, polygon &container)   {   
    if (vertexNumber <= 3) {  
        for (int i = 0; i < vertexNumber; i++)  
        container.p[i] = vertex[i];  
        container.n = vertexNumber;  
        return;  
    }   
    sort(vertex, vertex + vertexNumber, leftLower);  
    point upper[MAXPOLY], lower[MAXPOLY];  
    int top;    
    upper[0] = vertex[0];  
    upper[1] = vertex[1];  
    top = 2;  
    for (int i = 2; i < vertexNumber; i++)  {  
        upper[top] = vertex[i];  
        while (top >= 2 && crossProduct(upper[top - 2], upper[top - 1], upper[top]) >= 0)  {  
            upper[top - 1] = upper[top];  
            top--;  
        }  
        top++;  
    }  
    container.n = 0;  
    for (int i = 0; i < top; i++)  
        container.p[container.n++] = upper[i];   
    lower[0] = vertex[vertexNumber - 1];  
    lower[1] = vertex[vertexNumber - 2];  
    top = 2;  
    for (int i = vertexNumber - 3; i >= 0; i--) {  
        lower[top] = vertex[i];  
        while (top >= 2 && crossProduct(lower[top - 2], lower[top - 1], lower[top]) >= 0) {  
            lower[top - 1] = lower[top];  
            top--;  
        }  
        top++;  
    }   
    for (int i = 1; i < top - 1; i++)  
        container.p[container.n++] = lower[i];  
}  
bool SCUDBusters::pointInPolygon(point pt, polygon &polygons)  
{  
    int nCross = 0;  
    int crossProduct;  
    for (int i = 0, j = polygons.n - 1; i < polygons.n; j = i++) {    
        if (pt.y >= polygons.p[j].y && pt.y <= polygons.p[i].y ||   pt.y >= polygons.p[i].y && pt.y <= polygons.p[j].y) {  
            crossProduct = (polygons.p[i].x - polygons.p[j].x) *  
                (pt.y - polygons.p[j].y) - (pt.x - polygons.p[j].x) *  
                (polygons.p[i].y - polygons.p[j].y);    
            if (crossProduct == 0 && (pt.x >= polygons.p[j].x &&  
                          pt.x <= polygons.p[i].x  
                          || pt.x >= polygons.p[i].x  
                          && pt.x <= polygons.p[j].x))  
                return true;   
            if (crossProduct > 0  
                && polygons.p[i].y > polygons.p[j].y  
                && pt.y != polygons.p[i].y || crossProduct < 0  
                && polygons.p[i].y < polygons.p[j].y  
                && pt.y != polygons.p[j].y)  
                nCross++;  
        }  
    }  
    return (nCross & 1);  
}  
double SCUDBusters::area(point vertex[], int vertexNumber) {  
    double total = 0.0;  
    for (int i = 0; i < vertexNumber; i++) {  
        int j = (i + 1) % vertexNumber;  
        total += (vertex[i].x * vertex[j].y - vertex[j].x * vertex[i].y);  
    }  
    return fabs(total / 2.0);  
}  
int main() {  
    SCUDBusters  s;
    s.initial();
    s.readcase(); 
    s.computering();
    system("pause");
    return 0;  
}  
