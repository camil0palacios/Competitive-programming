#include <iostream>
 
using namespace std;
 
int main() {
    
    int p1,u1,p2,u2;
    double c1,c2;
    cin>>p1>>u1>>c1;
    cin>>p2>>u2>>c2;
    printf("VALOR A PAGAR: R$ %.2f\n",(u1*c1)+(u2*c2));
 
    return 0;
}