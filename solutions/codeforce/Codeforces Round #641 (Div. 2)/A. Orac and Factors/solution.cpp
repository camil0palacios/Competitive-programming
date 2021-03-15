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
        int n, k;
        cin >> n >> k;
        if(n % 2 == 0) {
            cout << n + 2*k << endl;
        } else {
            int d = 0;
            for(int i = 2; i*i <= n; i++) { 
                if(n % i == 0) {
                    d = i;
                    break;
                }
            }
            if(!d) d = n;
            cout << n + d + 2*(k-1) << endl;   
        }
    }
    return 0; 
}