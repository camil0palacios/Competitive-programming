#include <bits/stdc++.h>
#define endl '\n'
#define ll long long 
using namespace std;

/*
ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}

void solve(){
    ll n, _lcm;
    cin >> n;
    cin >> _lcm;
    for(int i = 1; i < n; i++){
        ll x; cin >> x;
        _lcm = lcm(_lcm, x);
    }
    cout << _lcm << endl;
}
*/

const int sz = 10005;
bool sieve[sz];
vector<int> prime;
ll fact[sz];
ll ans[1000000], res_sz;

void fill(){
    memset(sieve, -1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for(int i = 0; i < sz; i++){
        if(sieve[i]){
            prime.emplace_back(i);
            for(int j = i * i; j < sz; j += i){
                sieve[i] = 0; 
            }
        }
    }
}

void mult(ll num){
    ll carry = 0;
    for(int i = 0; i < res_sz; i++){
        ll res = num * ans[i] + carry;
        ans[i] = res % 10; 
        carry = res / 10;
    }
    while(carry){
        ans[res_sz] = carry % 10;
        carry /= 10;
        res_sz++;
    }
}

void solve(){
    int n;
    cin >> n;
    memset(fact, 0, sizeof fact);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        for(int i = 0; i < prime.size() && prime[i] * prime[i] <= x; i++){
            ll cnt = 1;
            while(x % prime[i] == 0){
                cnt *= prime[i];
                x /= prime[i];
            }
            fact[prime[i]] = max(fact[prime[i]], cnt);
        }
        if(x > 1){
            fact[x] = max(fact[x], x);
        }
    }
    memset(ans, 0, sizeof ans);
    ans[0] = res_sz = 1;
    for(int i = 1; i < sz; i++){
        if(fact[i] != 0){
            mult(fact[i]);
        }
    }
    for(int i = res_sz - 1; i >= 0; i--){
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill();
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cout << "Case " << cs <<  ": ";
        solve();
    }
    return 0;
}