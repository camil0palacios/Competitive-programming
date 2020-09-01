#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MAXX = 1e6 + 10;
bool s[MAXX];

void fill(){
    memset(s, -1, sizeof s);
    s[0] = s[1] = 0;
    for(ll i = 2; i*i < MAXX; i++){
        if(s[i])
            for(ll j = i*i; j < MAXX; j += i){
                s[j] = 0;
            } 
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long t;
        cin >> t;
        long long sq = sqrt(t);
        cout << (sq * sq == t && s[sq] ? "YES" : "NO") << endl;
    }
    return 0;
}