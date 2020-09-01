#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e7 + 5;
long long v[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < q; i++){
        int a, b, k;
        cin >> a >> b >> k;
        a--, b--;
        v[a] += k;
        if(b + 1 < n){
            v[b + 1] -= k;
        }
    }
    long long sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}