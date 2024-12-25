const int MXN = 2e5 + 5;
int t[4 * MXN]; 
//min tree, build it
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = INF;
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

// update a pos in the segment tree
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v * 2, tl, tm, pos, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

// query the minimum in [l, r]
int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return min(query(v * 2, tl, tm, l, min(r, tm)),
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
