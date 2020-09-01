#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long k, w, n;
    cin >> k >> n >> w;
    long long sum = (w * (w + 1)) / 2 * k;
    cout << (n >= sum ? 0 : sum - n) << endl;
    return 0;
}