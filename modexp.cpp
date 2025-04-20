int mod = 1e9+7;
ll nCk(ll totz){
    //2^titz
    ll ans = 1;
    ll base = 2; //change this for base only, totz is exp
    while(totz>0){
        if(totz&1){
            ans = (ans*base)%mod;
        }
        base = (base*base)%mod;
        totz>>=1;
    }
    return ans;

}
