#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 5;
int n, m, s, f;
int a[MAXN], t[MAXN], l[MAXN], r[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> s >> f;
    for(int i = 0; i < m; i++){
        cin >> t[i] >> l[i] >> r[i];
    }
    int add; char c;
    if(s < f){
        add = 1; 
        c = 'R';
    }else{
        add = -1;
        c = 'L';
    }
    int cur_t = 1, j = 0;
    string ans;
    while(s != f){
        int d = s + add;
        while(t[j] < cur_t)j++;
        if(t[j] == cur_t && ((l[j] <= s && s <= r[j]) || (l[j] <= d && d <= r[j]))){
            ans += 'X';
        }else{
            ans += c;
            s = d;
        }
        cur_t++;
    }
    cout << ans << endl; 
    return 0;
}