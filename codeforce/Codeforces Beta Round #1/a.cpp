#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n, m, a;
    cin >> n >> m >> a;
    cout << (long long)ceil(n/(double)a) * (long long)ceil(m/(double)a) << endl;
    return 0;
}