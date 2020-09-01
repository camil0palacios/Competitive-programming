#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NM = 1e6 + 10; 
long long primes[NM];
bool sieve[NM];
int p = 0;

void fill(){
    primes[p++] = 2;
    int i;
    for(i = 3; i*i < NM; i += 2){
        if(!sieve[i]){
            primes[p++] = i;
            for(int j = i*i; j < NM; j += (2*i)){
                sieve[j] = 1;
            }
        }
    }
    while(i < NM){
        if(!sieve[i])primes[p++] = i;
        i += 2;
    }
}

ll num_div(ll n){
    ll ans = 1; 
    for(int i = 0; i < p && primes[i]*primes[i] <= n; i++){
        ll cnt = 0;
        while(n % primes[i] == 0){
            n /= primes[i];
            cnt++;
        }
        ans *= (cnt+1);
    }
    if(n > 1)ans *= 2;
    return ans;
}

void solve(){
    ll A, b;
    cin >> A >> b;
    if(b*b >= A)cout << '0' << endl;
    else{
        ll div = num_div(A);
        div /= 2;
        for(int i = 1; i < b; i++){
            if(A % i == 0)div--;
        }
        cout << div << endl;
    }
}

int main(){
    fill();
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}