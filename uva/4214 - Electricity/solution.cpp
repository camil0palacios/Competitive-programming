#include <bits/stdc++.h>
using namespace std;

struct date{
    int d, m, y, c;
    date(){}
};

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n && n){
        int l = 0, r = 0;
        vector<date> v(n);
        for(auto & i : v)cin >> i.d >> i.m >> i.y >> i.c;
        for(int i = 1; i < n; i++){
            int d = v[i-1].d, m = v[i-1].m , a = v[i-1].y;
            if(a % 4 == 0 && a % 100 != 0 && m == 2 && d == 29){
                d = 1;
                m = 3;
            }
            else if(a % 4 != 0 && m == 2 && d == 28){
                d = 1;
                m = 3;
            }
            else if((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d == 31){
                d = 1;
                if(m + 1 > 12)m = 1, a = a + 1;
                else m++;
            }else if((m == 4 || m == 6 || m == 9 || m == 11) && d == 30){
                d = 1;
                m++;
            }else{
                d++;
            }
            if(v[i].y == a && v[i].m == m && v[i].d == d){
                //cout << v[i].y << " " << v[i].m << " " << v[i].d << endl;
                l++;
                r += (v[i].c - v[i-1].c);
            }
        }
        cout << l << " " << r << endl;
    }
    return 0;
}