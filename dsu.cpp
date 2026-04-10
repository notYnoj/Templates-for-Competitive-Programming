class DSU{
public:
    vector<ll> size;
    vector<ll> parent;

    DSU(int n){
        size.resize(n);
        parent.resize(n);
        for(ll i = 0; i < n; i++){
            size[i] = 1LL;
            parent[i] = i;
        }
    }

    ll getSize(int i){
        return size[find(i)];  
    }
    ll find(int x) {
    // You need to call find on the PARENT, not on x again!
        return (parent[x] == x ? x : parent[x] = find(parent[x])); 
    }
    void merge(ll x, ll y){
        ll xp = find(x);
        ll yp = find(y);
        if(xp == yp) return;
        size[xp] += size[yp];
        parent[yp] = xp;  
    }

    int unique(){
        vector<int> found(parent.size(), 0);
        int count = 0;
        for(int i = 0; i < parent.size(); i++){
            int root = find(i);  
            if(!found[root]){
                count++;
                found[root] = true;
            }
        }
        return count;
    }
    void debug_parents(){
        cout<<parent;
    }
    void debug_sizes(){
        cout<<sizes;
    }
    void debug(){
        cout<<parent<<'\n';
        cout<<sizes<<'\n';
    }
};
