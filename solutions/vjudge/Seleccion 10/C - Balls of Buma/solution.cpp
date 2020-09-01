#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 3e5 + 10;
char c[MAXN];
int a[MAXN], pt = -1;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    char cur = '.';
    for(int i = 0; i < s.size(); i++){
        if(cur != s[i]){
            cur = s[i];
            pt++;
            c[pt] = s[i];
            a[pt] = 1;
        }else{
            a[pt]++;
        }
    } 
    pt++;
    bool ok = (pt & 1 ? 1 : 0); 
    int jump = pt / 2 + 1;
    ok &= a[jump - 1] >= 2;
    for(int i = 0; i < jump; i++){ 
        if(c[jump - 1 - i] != c[jump - 1 + i] || a[jump - 1 - i] + a[jump - 1 + i] < 3){
            ok = 0;
        }
    }
    if(ok){
        cout << a[jump - 1] + 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}