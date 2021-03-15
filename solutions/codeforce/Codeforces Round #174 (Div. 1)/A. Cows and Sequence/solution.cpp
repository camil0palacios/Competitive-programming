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

const int Mxn = 2e5 + 5;

ll stk[Mxn], it, sum;
ll m[Mxn];

void push(int k) { m[it] = 0, stk[it++] = k, sum += k; }
void add(int a, int x) { m[a-1] += x; sum += x*a; }
void pop() { 
    if(it == 0) return;
    it--; 
    sum -= (stk[it] + m[it]);
    if(it - 1 >= 0) m[it-1] += m[it];
    m[it] = 0;
}
double query() {
    if(it == 0) return 0;
    return 1.0*sum / it; 
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    push(0);
    while(n--) {
        int t; cin >> t;
        if(t == 1) {
            int a, x; 
            cin >> a >> x;
            add(a, x);
        }
        if(t == 2) {
            int k; cin >> k;
            push(k);
        }
        if(t == 3) pop();
        cout << query() << endl;
    }
    return 0; 
}