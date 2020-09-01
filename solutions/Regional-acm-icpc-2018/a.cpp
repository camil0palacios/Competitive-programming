#include <bits/stdc++.h>
using namespace std;

int main(){

    string r;
    cin >> r;
    int j = 0;
    for(int i : r){
        if(i != '.'){
            j *= 10;
            j += i - '0';
        }
    }
    long long i;
    for(i = 1; (i*36000) % j; i++){}
    cout << (i*36000)/j << endl;
    return 0;
}