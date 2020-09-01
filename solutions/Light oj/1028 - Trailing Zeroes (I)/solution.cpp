#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll MX = 1000000;
bool sv[MX];
int prime[MX], idx = 0;

void fill(){
    memset(sv, -1, sizeof sv);
    sv[0] = sv[1] = 0;
    prime[idx++] = 2;
    ll i;
    for(i = 3; i*i < MX; i += 2){
        if(sv[i]){
            prime[idx++] = i;
            for(ll j = i*i; j < MX; j += 2*i){
                sv[j] = 0;
            }
        }
    }
    for(; i < MX; i += 2){
        if(sv[i])prime[idx++] = i;
    }
}

void solve(){
    ll n;
    cin >> n;
    ll ans = 1;
    for(int i = 0; i < idx && prime[i]*prime[i] <= n; i++){
        if(n % prime[i] == 0){
            ll cnt = 1;
            while(n % prime[i] == 0){
                cnt++;
                n /= prime[i];
            }
            ans *= cnt;
        }
    }
    if(n > 1)ans *= 2;
    ans--;
    cout << ans << endl;
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill();
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}