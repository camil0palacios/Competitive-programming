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

void show_exam(map<char,int> & m) {
    bool ok = 0;
    for(auto & p : m) {
        if(ok) cout << ' ';
        cout << p.ft << ":" << p.sd; 
        ok = 1;
    }
    cout << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    map<char,int> tot;
    fori(i,0,6) tot[char(i + 'A')] = 0;
    while(t--) {
        int n;
        cin >> n;
        map<char, int> tmp;
        fori(i,0,6) tmp[char(i + 'A')] = 0;
        fori(i,0,n) {
            char c;
            cin >> c;
            tmp[c]++;
        }
        show_exam(tmp);
        for(auto & p : tmp) tot[p.ft] += p.sd;
    }
    cout << "TOTAL: ";
    show_exam(tot);
    return 0; 
}