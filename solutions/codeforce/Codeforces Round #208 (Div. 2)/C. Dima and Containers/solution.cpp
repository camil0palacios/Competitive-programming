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
int a[Mxn];
int num[Mxn];
string pop[3] = { "popStack", "popQueue", "popFront" };
string action[4] = { "pushBack", "pushStack", "pushQueue", "pushFront" };
string output[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<ii> q;
    fori(i,0,n) {
        cin >> a[i];
        if(!a[i]) {
            for(int j = 1; j <= 3 && !q.empty(); j++) {
                output[q.top().sd] = action[j];
                num[i] = j;
                q.pop(); 
            }
            while(!q.empty()) q.pop();
        } else {
            q.emplace(a[i], i);
        }
    }
    fori(i,0,n) {
        if(!a[i]) {
            cout << num[i];
            fori(j,0,num[i]) cout << " " << pop[j];
            cout << endl;
        } else {
            if(output[i] != "") cout << output[i];
            else cout << action[0];
            cout << endl;
        }
    }
    return 0; 
}