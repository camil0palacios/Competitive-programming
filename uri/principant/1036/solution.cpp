#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    double a,b,c;
    cin>>a>>b>>c;
    if( b*b - 4*a*c < 0 || a == 0)cout<<"Impossivel calcular"<<endl;
    else {
        printf("R1 = %.5f\n",(-b + sqrt( b*b - 4*a*c ))/(2*a) );
        printf("R2 = %.5f\n",(-b - sqrt( b*b - 4*a*c ))/(2*a) );
    }
    return 0;
}