#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll d, k;
        cin >> d >> k;
        ll x = 0, y = 0;
        bool cur = 0, ok = 1;
        while(ok) {
            ok = 0;
            if((x + k)*(x + k) + y*y <= d*d && cur) x += k, ok = 1;
            if(x*x + (y + k)*(y + k) <= d*d && !cur) y += k, ok = 1;
            if(ok) cur ^= 1;
        }
        if(cur) cout << "Ashish" << endl;
        else cout << "Utkarsh" << endl;  
    }
    return 0; 
}