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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

string a[8];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        fori(i,0,8) cin >> a[i];
        fori(i,0,8) {
            bool eq = 1;
            fori(j,1,8) eq &= a[i][j] == a[i][j-1];
            if(eq && a[i][0] == 'R') {
                cout << "R" << endl;
                break;
            }
        }
        fori(j,0,8) {
            bool eq = 1;
            fori(i,1,8) eq &= a[i][j] == a[i-1][j];
            if(eq && a[0][j] == 'B') {
                cout << "B" << endl;
                break;
            }
        }
    }    
    return 0; 
}