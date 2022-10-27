struct Pt {
    int x, y;
    Pt() {}
    Pt(int x, int y): x(x), y(y) {}
    bool operator==(Pt & p) { return x == p.x && y == p.y; }
    const bool operator<(const Pt & p) const {
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
};
    
int dist(Pt & p, Pt & q) {
    int x = p.x - q.x;
    int y = p.y - q.y;
    return x*x + y*y;
}

Pt rest(Pt & p, Pt & q) {
    return Pt(p.x - q.x, p.y - q.y);
}

int cross(Pt p, Pt q) {
    return p.x*q.y - q.x*p.y;
}

vector<Pt> convexHull(vector<Pt> & pts) {
    Pt start = pts[0];
    for(auto & p : pts) {
        if(p.x < start.x) start = p;
    }
    set<Pt> s;
    vector<Pt> coll;
    Pt p = start;
    s.insert(p);
    while(1) {
        Pt nxtp = pts[0];
        for(auto & q : pts) {
            if(p == q) continue;
            int c = cross(rest(nxtp, p), rest(q, p)); 
            if(c == 0) {
                Pt c;
                if(dist(p, q) < dist(p, nxtp)) c = q;
                else c = nxtp, nxtp = q;
                coll.emplace_back(c);
            }
            if(c > 0) {
                coll.clear();
                nxtp = q;
            }
        }
        for(auto & c : coll) s.insert(c);
        if(nxtp == start) break;
        s.insert(nxtp);
        p = nxtp;
    }
    vector<Pt> ans(s.begin(), s.end());
    return ans;
}