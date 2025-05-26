vi primes;
const int N = 1e5; //change if needed
bool found[N];
void sieve(){
    fill(found, found+N+1, true);
    for(int p = 2; p*p<=N; p++){
        if(found[p]){
            primes.pb(p);
            for(int i = p*p; i<=N; i+=p){
                found[i] = false;
            }
        }
    }
}
