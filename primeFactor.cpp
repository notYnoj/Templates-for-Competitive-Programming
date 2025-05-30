const int N = 1e6+5;
int found[N];
void sieve(){
    fill(found, found+N+1, -1);
    for(int p = 2; p*p<=N; p++){
        if(found[p] == -1){
            found[p] = p;
            for(int i = p*p; i<=N; i+=p){
                if(found[i] == -1)found[i] = p;
            }
        }
    }
}
vi factor(int x){
    vi ret;
    while(x!=1){
        ret.pb(found[x]);
        x/=found[x];
    }
}
