#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    double *x = new double[n];
    double *y = new double [n];
    for (int i = 0; i < n; i++){
        cin >> x[i];
        cin >> y[i];
    }
    double sum = 0;
    double perimeter = 0;
    for (int i = 0; i < n-1; i++){
        sum += (y[i+1] + y[i])*(x[i+1] - x[i])/2;
        perimeter += sqrt(pow(x[i+1] - x[i], 2) + pow(y[i+1] - y[i], 2));
    }
    sum += sqrt((y[0] + y[n-1])*(x[0] - x[n-1]));
    perimeter += sqrt(pow(x[0] - x[n-1], 2) + pow(y[0] - y[n-1], 2));

    cout << "square: " << sum << endl;
    cout << "perimeter: " << perimeter << endl;
}