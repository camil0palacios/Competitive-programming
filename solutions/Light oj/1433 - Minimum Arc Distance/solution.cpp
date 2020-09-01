#include <bits/stdc++.h>
using namespace std;

struct pt{
    long double x, y;
    pt(){}
    pt(long double _x, long double _y){
        x = _x;
        y = _y;
    }
    pt operator-(pt & o){
        return pt(x-o.x,y-o.y);
    }
};

long double dot(pt a, pt b){
    return a.x*b.x + a.y*b.y;
}

long double angle(pt a, pt b){
    double costheta = dot(a,b)/sqrt(dot(a,a))/sqrt(dot(b,b));
    return acos(max(-1.0,min(1.0,costheta)));
}

int main(){
    pt o, a, b;
    int t;
    cin >> t;
    for(int x = 1; x <= t; x++){
        cin >> o.x >> o.y >> a.x >> a.y >> b.x >> b.y;
        long double r = sqrt(dot(a-o,a-o));
        long double ang = angle(a-o,b-o);
        cout << fixed << setprecision(10) << "Case " << x << ": " << ang*r << endl;
    }
    return 0;
}