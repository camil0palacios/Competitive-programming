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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t1, v1, t2, v2;
    cin >> t1 >> v1 >> t2 >> v2;
    if(t2 < 0 && v2 >= 10) cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
    else if(t2 < t1) cout << "MCHS warns! Low temperature is expected tomorrow.";
    else if(v2 > v1) cout << "MCHS warns! Strong wind is expected tomorrow.";
    else cout << "No message";
    cout << endl;
    return 0; 
}