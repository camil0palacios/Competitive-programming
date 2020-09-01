#include <iostream>
 
using namespace std;
 
int main() {
 
    double a,b,c;
    cin>>a>>b>>c;
    if(b > a && b > c)swap(a,b);
    if(c > a && c > b)swap(a,c);
    if( a >= b + c)cout<<"NAO FORMA TRIANGULO"<<endl;
    else{
        if( a*a == b*b + c*c)cout<<"TRIANGULO RETANGULO"<<endl;
        if( a*a > b*b + c*c)cout<<"TRIANGULO OBTUSANGULO"<<endl;
        if( a*a < b*b + c*c)cout<<"TRIANGULO ACUTANGULO"<<endl;
        if( a == b && b == c)cout<<"TRIANGULO EQUILATERO"<<endl;
        if( (a == b && b != c) || (a == c && c != b) || (b == c && c != a))
        cout<<"TRIANGULO ISOSCELES"<<endl;
    }
    return 0;
}