template <typename D>
//typename for a thing
class SegTree{
//our segtree class
public:
    ll n;
    vector<D> tree;
    vector<ll> og;
    SegTree(ll size, vector<ll> o){
        n = size;
        tree.resize(4*n);
        og = move(o);
    }
    void build(ll l, ll r, ll u){
        //current node u
        if(l == r){
            D node;
            node.MXc1 = og[l]-l;
            node.MNc1 = og[l]-l;
            node.MXc2 = og[l]+l;
            node.MNc2 = og[l]+l;
            node.ans = 0;
            tree[u] = node;
        }else{
            int mid = (l+r)/2;
            build(l,mid,u*2);
            build(mid+1,r,u*2+1);
            //case 2( max on l)
            D node;
            node.MXc1 = max(tree[u*2].MXc1, tree[u*2+1].MXc1);
            node.MNc1 = min(tree[u*2].MNc1, tree[u*2+1].MNc1);
            node.MXc2 = max(tree[u*2].MXc2, tree[u*2+1].MXc2);
            node.MNc2 = min(tree[u*2].MNc2, tree[u*2+1].MNc2);
            node.ans = max(tree[u*2].ans, tree[u*2+1].ans);
            //Case 1 ( max on r)
            node.ans = max(node.ans, tree[u*2+1].MXc1 - tree[u*2].MNc1);
            //Case 2 (max on l)
            node.ans = max(node.ans, tree[u*2].MXc2 - tree[u*2+1].MNc2);
            tree[u] = node;
        }
    }
    void change(ll l, ll r, ll u, ll new_val, ll pos){
        if(l>pos || r<pos){
            return;
        }
        if(l == r && l == pos){
            //change the val
            D node;
            node.MXc1 = new_val-l;
            node.MNc1 = new_val-l;
            node.MXc2 = new_val+l;
            node.MNc2 = new_val+l;
            node.ans = 0;
            tree[u] = node;
        }else{
            ll tm = (l+r)/2;
            change(l, tm, u*2, new_val, pos);
            change(tm+1, r, u*2+1, new_val, pos);
            //lowk js run it back?
            D node;
            node.MXc1 = max(tree[u*2].MXc1, tree[u*2+1].MXc1);
            node.MNc1 = min(tree[u*2].MNc1, tree[u*2+1].MNc1);
            node.MXc2 = max(tree[u*2].MXc2, tree[u*2+1].MXc2);
            node.MNc2 = min(tree[u*2].MNc2, tree[u*2+1].MNc2);
            node.ans = max(tree[u*2].ans, tree[u*2+1].ans);
            //Case 1 ( max on r)
            node.ans = max(node.ans, tree[u*2+1].MXc1 - tree[u*2].MNc1);
            //Case 2 (max on l)
            node.ans = max(node.ans, tree[u*2].MXc2 - tree[u*2+1].MNc2);
            tree[u] = node;
        }

    }
    ll get(){
        return tree[1].ans;
    }


};
