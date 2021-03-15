#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 101;
string a[MXN];

void up_left(int x, int y) {
    x++, y++;
    cout << x << ' ' << y << ' ';
    cout << x + 1 << ' ' << y << ' ';
    cout << x << ' ' << y + 1 << endl;
}

void up_right(int x, int y) {
    x++, y++;
    cout << x << ' ' << y << ' ';
    cout << x + 1 << ' ' << y << ' ';
    cout << x << ' ' << y - 1 << endl;
}

void down_left(int x, int y) {
    x++, y++;
    cout << x << ' ' << y << ' ';
    cout << x - 1 << ' ' << y << ' ';
    cout << x << ' ' << y + 1 << endl;
}

void down_right(int x, int y) {
    x++, y++;
    cout << x << ' ' << y << ' ';
    cout << x - 1 << ' ' << y << ' ';
    cout << x << ' ' << y - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int ones = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; j < m; j++) {
                ones += a[i][j] == '1';
            }
        }
        cout << ones*3 << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == '1') {
                    if(i != n-1 && j != m-1) {          
                        up_left(i, j);
                        up_right(i, j + 1);
                        down_left(i + 1, j);
                    }
                    else if(i != n-1 && j == m-1) {
                        up_right(i, j);
                        up_left(i, j - 1);
                        down_right(i + 1, j);
                    }
                    else if(i == n-1 && j != m-1) {
                        down_left(i, j);
                        down_right(i, j + 1);
                        up_left(i - 1, j);
                    }
                    else if(i == n-1 && j == m-1) {
                        down_right(i, j);
                        down_left(i, j - 1);
                        up_right(i - 1, j);
                    }
                }
            }
        }
    }
    return 0;
}