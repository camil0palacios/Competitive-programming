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

const int Mxn = 1e5 + 5;
ll a[Mxn], p[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    fori(i,0,n) cin >> a[i];
    sort(a, a+n);
    fori(i,0,n) p[i+1] = p[i] + a[i];
    ll fq = 1, num = a[0];
    fore(i,1,n) {
        int l = 1, r = i-1, idx = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int len = i-mid+1;
            if(a[i-1]*len - (p[i] - p[mid-1]) <= k) idx = mid, r = mid-1;
            else l = mid+1;
        }
        if(idx != -1 && fq < i-idx+1) {
            fq = i-idx+1;
            num = a[i-1];
        }
    }
    cout << fq << ' ' << num << endl;
    return 0; 
}