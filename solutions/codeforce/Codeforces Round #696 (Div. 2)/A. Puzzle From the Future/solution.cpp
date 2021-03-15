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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string a, b;
        cin >> n >> b;
        int lst = 0;
        fori(i,0,n) {
            if(lst == 2) {
                if(b[i] == '1') a += '0';
                else a += '1';
                lst = 1; 
            }
            else if(lst == 1) {
                if(b[i] == '1') a += '1', lst = 2;
                else a += '0', lst = 0; 
            }
            else if(lst == 0) {
                if(b[i] == '1') lst = 2;
                else lst = 1;
                a += '1';
            }
        }
        cout << a << endl;
    }
    return 0; 
}