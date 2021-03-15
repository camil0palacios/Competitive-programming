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

struct Node {
    Node * next;
    int val;
    Node() {}
    Node(int val): val(val), next(nullptr) {}
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    Node * head, * a;
    head = a = nullptr;
    fori(i,0,n) {
        Node * tmp = new Node(i);
        if(!head) head = a = tmp;
        else {
            a->next = tmp;
            a = a->next;
        }
    }
    a->next = head;
    a = head;
    while(a != a->next) {
        cout << a->next->val + 1 << ' ';
        a->next = a->next->next;
        a = a->next;
    }
    cout << a->val + 1 << endl;
    return 0; 
}