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

const int Mxn = 2e5 + 5;
int a[Mxn], in[Mxn], out[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) {
            cin >> a[i];
            in[a[i]] = i;
        }
        int k = 0;
        fore(i,1,n) if(in[i]) k++, out[in[i]] = i;
        cout << k << endl;
        int j = 1;
        fore(i,1,n) {
            if(!out[i]) {
                while(in[j]) j++;
                out[i] = j, in[j] = i;
            }
        } 
        fore(i,1,n) {
            if(out[i] == i) {
                out[i] = a[i];
                out[in[a[i]]] = i;
                in[a[i]] = i;
            }
        }
        fore(i,1,n) cout << out[i] << ' ';
        cout << endl;
        fore(i,1,n) in[i] = out[i] = 0;
    }
    return 0; 
}