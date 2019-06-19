#include <bits/stdc++.h>
#define llu long long unsigned
#define endl '\n'
using namespace std;

int n, x;
llu dp[26][155];

llu p6[] = { 1LL, 6LL, 36LL, 216LL, 1296LL, 7776LL, 46656LL, 279936LL, 1679616LL, 10077696LL,
                    60466176LL, 362797056LL, 2176782336LL, 13060694016LL, 78364164096LL,
                    470184984576LL, 2821109907456LL, 16926659444736LL, 101559956668416LL,
                    609359740010496LL, 3656158440062976LL, 21936950640377856LL,
                    131621703842267136LL, 789730223053602816LL, 4738381338321616896LL };

llu go(int idx, int acc){
    if(idx == n)return acc >= x;
    if(dp[idx][acc] != -1)return dp[idx][acc];
    llu ans = 0;
    for(int i = 1; i <= 6; i++){
        ans += go(idx + 1, acc + i);
    }
    return dp[idx][acc] = ans;
}

int solve(){
    cin >> n >> x;
    memset(dp, -1, sizeof dp);
    llu q = p6[n];
    llu p = go(0,0);
    llu g = __gcd(p,q);
    if(p % q == 0){
        cout << p / q << endl;
    }
    else{
        cout << (p/g) << '/' << (q/g) << endl;
    }
     
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve(); 
    }
    return 0;   
}