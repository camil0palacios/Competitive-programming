#include <bits/stdc++.h>
using namespace std;

struct segment{
    long long l, r;
    int i;
    segment(){}
    segment(long long _l, long long _r, int _i): i(_i), l(_l), r(_r){}
    bool operator<(segment & other)const{
        if(r != other.r)return r > other.r;
        else return l < other.l;
    }
};

int main(){

    int n;
    while(cin >> n){
        vector<segment> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].l >> v[i].r;
            v[i].i = i + 1;
        }
        sort(v.begin(), v.end());
        if(v.size() > 1){
            int f = 1;
            for(int i = 0; i < n; i++){
                if(v[0].l > v[i].l && v[i].r <= v[i].r){
                    f = 0;
                }
            }
            if(f)cout << v[0].i << endl;
            else cout << -1 << endl;
        }
        else cout << v[0].i << endl;
    }
    return 0;
}