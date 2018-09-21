#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    double n,ns;
    cin>> n;
    int percen = 0;
    if( n >= 0 && n <=  400.00){ ns = n + (n*0.15); percen = 15;}
    else if( n >= 400.01 && n <=  800.00){ ns = n + (n*0.12); percen = 12;}
    else if( n >= 800.01 && n <=  1200.00){ ns = n + (n*0.10); percen = 10;}
    else if( n >= 1200.01 && n <=  2000.00){ ns = n + (n*0.07); percen = 7;}
    else if( n > 2000.00){ ns = n + (n*0.04); percen = 4;}
    
    printf("Novo salario: %.2f\n",ns);
    printf("Reajuste ganho: %.2f\n",ns-n);
    cout<<"Em percentual: "<<percen<<" %"<<endl;
    
    return 0;
}
