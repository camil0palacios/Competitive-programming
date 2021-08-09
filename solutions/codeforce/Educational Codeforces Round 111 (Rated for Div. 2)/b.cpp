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

const int oo = 1e9;
int n, a, b;
string s;
int m, t[105];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> a >> b >> s;
        m = 0;     
        fori(i,0,n) {
            int j = i;
            while(j < n && s[i] == s[j]) j++;
            m++; i = j-1;
        }
        cout << n*a + max(n*b, (m/2 + 1)*b) << endl;
    }
    return 0; 
}