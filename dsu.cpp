class DSU{
public:
    vector<ll> size;
    vector<ll> parent;
    DSU(int n){
        size.resize(n);
        parent.resize(n);
        for(ll i = 0; i<n; i++){
            size[i] = 1LL;
            parent[i] = i;
        }
    }
    int find(int x){
        return(parent[x] == x? x: parent[x] = find(x));
    }
    void merge(ll x, ll y){
        ll xp = find(x);
        ll yp = find(y);
        if(x>y){
            swap(x,y);
        }
        size[xp] += size[yp];
        parent[yp] = parent[xp];
    }
};
