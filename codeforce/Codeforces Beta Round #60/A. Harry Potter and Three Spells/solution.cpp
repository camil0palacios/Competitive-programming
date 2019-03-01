#include <bits/stdc++.h>
using namespace std;

int g(int n){
    n = n ? n : 1;
    return n;
}

int main(){

    int a, b, c, d, e, f;
    while(cin >> a >> b >> c >> d >> e >> f){
        if(a*c*e < b*d*f)cout << "Ron" << endl;
        else{
            if(c == 0 && d > 0)cout << "Ron" << endl;
            else if(a == 0 && d > 0 && b > 0)cout << "Ron" << endl;
            else cout << "Hermione" << endl;
        }
    }
    return 0;
}
/*
0 0 0 493 0 0
0 333 0 0 0 0
*/