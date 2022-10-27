#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e7;
int d[Mxn+1], mn[Mxn+1];

void cal() {
    fore(i,1,Mxn) mn[i] = Mxn+1;
    fore(i,1,Mxn) {
        for(int j = i; j <= Mxn; j += i) d[j] += i;   
    }
    fore(i,1,Mxn) 
        if(d[i] <= Mxn) mn[d[i]] = min(mn[d[i]], i);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int t;
    cin >> t;
    while(t--) {
        int c;
        cin >> c;
        cout << (mn[c] <= Mxn ? mn[c] : -1) << endl;        
    }
    return 0; 
}