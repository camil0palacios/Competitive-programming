#include <bits/stdc++.h>
using namespace std;

int main(){

    long double total = 0.0;
    vector<long double> v;
    for(int i = 1 ; i <= 6; i++){
        long double n;
        cin >> n;
        v.emplace_back(n);
        total += (i*n);
    }
    long double mmin = 100000;
    for(int i = 0; i < 6; i++){
        long double s = (total - (i+1)*v[i]);
        long double _v = (3.5 - s)/v[i];
        mmin = min(mmin, abs((i+1) - _v));
    }
    cout << setprecision(3) << fixed << mmin << endl;

    return 0;
}