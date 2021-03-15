#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

void mul(int & a, int b) {
    a = (ll)a * b % mod;
}

int be(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) mul(ans, a);
        mul(a, a);
        b >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << be(a, b) << endl; 
    }
    return 0;
}