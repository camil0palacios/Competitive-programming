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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int c1 = (n / 3) + (n % 3);
        int c2 = n / 3;
        int d = abs(c1 - c2);
        int t2 = (n + 2 - 1) / 3;
        int t1 = n - 2*t2;
        int d1 = abs(t1 - t2);
        if(abs(t1 - t2) < d) c1 = t1, c2 = t2;  
        cout << c1 << ' ' << c2 << endl;
    }
    return 0; 
}