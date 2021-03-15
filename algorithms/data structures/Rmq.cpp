template<class T>
struct Rmq {
    vector<vector<T>> st; 
    vector<int> lg;
    function f;
    Rmq(){}
    void build(vector<T> & a) {
        int n = (int) a.size();
        lg.resize(n);
        int p = 1, mxlg = 0;
        while(p < n) p *= 2, mxlg++;
        st.assign(n, vector<T>(2));
        lg[1] = 0;
        for(int i = 2; i < n; i++) lg[i] = lg[i/2] + 1;
        for(int i = 0; i < n; i++) st[i][0] = a[i];
        for(int j = 1; j < mxlg; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j-1]);
            }
        }
    }
    T query(int i, int j) {
        i--, j--;
        int k = log[j - i + 1];
        return min(st[i][k], st[j - (1 << k) + 1][k]);
    }
};