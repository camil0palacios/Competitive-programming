#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if(n > m)swap(n, m);
    cout << (n / 2) * m + (n % 2 != 0 ? m / 2 : 0) << endl;
    return 0;
}