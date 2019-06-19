#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int NMAX = 1e6 + 5;
bool sieve[NMAX];
long long primes[NMAX], p = 0;

void fill(){
    memset(sieve, 1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for(long long i = 2; i < NMAX; i++){
        if(sieve[i]){
            primes[p++] = i;
            for(long long j = i*i; j < NMAX; j += i){
                sieve[j] = 0;
            }
        }
    }
}

bool is_prime(long long n){
    for(int i = 0; i < p && primes[i]*primes[i] <= n; i++){
        if(n % primes[i] == 0)return 0;
    }
    return 1;
}

int main(){
    fill();
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    while(cin >> n){
        int res = 0;
        if(n == 2)res = 1;
        else if(n % 2 == 0 && n > 2)res = 2;
        else{
            if(is_prime(n))res = 1;
            else if(is_prime(n-2))res = 2;
            else res = 3;
        }
        cout << res << endl;
    }
    return 0;
}