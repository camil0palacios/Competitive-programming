#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        pair<int,ll> pr = {0, 0}; int mx = 0;
        for(ll i = 2; i*i <= n; i++) {
            if(n % i == 0) {
                ll tmp = n;
                int cnt = 0;
                while(tmp % i == 0) {
                    cnt++;
                    tmp /= i;
                }
                if(tmp > 1) cnt--;
                if(mx < cnt) {
                    mx = cnt;
                    pr = {cnt, i};
                }
            }
        }
        if(pr.second == 0) pr = {1, n};
        vector<ll> ans;
        for(int i = 0; i < pr.first; i++) {
            ans.emplace_back(pr.second);
            n /= pr.second;
        }
        if(n > 1) ans.emplace_back(n);
        cout << ans.size() << endl;
        for(auto & i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0; 
}