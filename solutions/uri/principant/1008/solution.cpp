#include <iostream>
 
using namespace std;
 
int main() {
 
    int a,b;
    double c;
    cin>>a>>b>>c;
    double salary = b*c;
    cout<<"NUMBER = "<<a<<endl;
    printf("SALARY = U$ %.2f\n",salary);
 
    return 0;
}