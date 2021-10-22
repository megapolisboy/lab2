#include <iostream>
#include <cmath>
using namespace std;

double x1, x2, yy1, y2, a, b;

void find_new_point (){
    double k1 = -x2*b*b/(a*a*y2);
    double b1 = a*a*b*b/(x2*y2);
    double k2 = a*a*y2/(x2*b*b);
    double b2 = yy1 - a*a*y2*x1/(x2*b*b);
    double x3 = (b2 - b1)/(k1 - k2);
    double y3 = k1*x3 + b1;
    double x4 = 2*x3 - x1;
    double y4 = 2*y3 - yy1;
    double k = (y2 - y4)/(x2 - x4);
    double t = (x2*y4 - x4*y4 - y2*x4 + x4*y4)/(x2 - x4);
    double aa = b*b + a*a*k*k;
    double bb = 2*a*k*t;
    double cc = a*t*t - a*a*b*b;
    double xnew1 = (-bb + sqrt(bb*bb - 4*aa*cc))/(2*aa);
    double xnew2 = (-bb - sqrt(bb*bb - 4*aa*cc))/(2*aa);
    double xnew;
    if (abs(xnew1 - x2) < 0.01){
        xnew = xnew2;
    } else {
        xnew = xnew1;
    }
    double ynew = k*xnew + t;
    x1 = x2;
    yy1 = y2;
    x2 = xnew;
    y2 = ynew;
    cout << x2 << ' ' << y2 << endl;
}

int main(){
    cin >> a >> b;
    x1 = a/2;
    yy1 = b*sqrt(3)/2;
    y2 = b/2;
    x2 = a*sqrt(3)/2;
    cout << x1 << ' ' << yy1 << endl;
    cout << x2 << ' ' << y2 << endl;
    for (int i = 0; i < 10; i++){
        find_new_point();
    }
    
}