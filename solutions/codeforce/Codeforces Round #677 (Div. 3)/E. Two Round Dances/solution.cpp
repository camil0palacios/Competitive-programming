#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 25;
ll fact[MXN];

int nCr(int a, int b) {
    return fact[a] / (fact[b] * fact[a - b]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fact[0] = 1;
    for(int i = 1; i < MXN; i++) {
        fact[i] = fact[i - 1] * i;
    }
    int n;
    cin >> n;
    int mid = n / 2;
    ll x = fact[mid - 1];
    cout << (nCr(n, n / 2) * x * x) / 2 << endl;
    return 0;
}