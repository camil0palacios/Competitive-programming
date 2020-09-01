#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int sum = n - m;
    int mx = (sum * (sum + 1)) / 2;
    int sum2 = (n + m - 1) / m;
    int mn = m * (n / m - 1) + (n % m) / 2;
    cout << mn << ' ' << mx << endl; 
    return 0;
}