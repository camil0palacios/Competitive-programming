#include <bits/stdc++.h>
using namespace std;

int n, ax, ay, bx, by, cx, cy;
bool ok = 0;
bool done[1005][1005];

int dx[8] = {1, 0, -1,  0, 1,-1,-1, 1};
int dy[8] = {0, 1,  0, -1, 1, 1,-1,-1};

bool check(int x, int y){
    return abs(x - ax) != abs(y - ay);
}

bool bounds(int val){
    return val > 0 && val <= n;
}

void dfs(int x, int y){
    done[x][y] = 1;
    ok |= (x == cx && y == cy);
    for(int i = 0; i < 8; i++){
        int mx = x + dx[i], my = y + dy[i];
        if(bounds(mx) && bounds(my) && mx != ax && my != ay && check(mx,my) && !done[mx][my]){
            dfs(mx, my);
        }
    }
}

int main(){
    cin >> n;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    memset(done, 0, sizeof done);
    dfs(bx, by);
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}