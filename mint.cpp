template <typename T, T mod> class Mint{
private: 
    T val;
    T modinv(T a, T m) {
        T m0=m, t, q;
        T x0=0, x1=1;
        while (a>1) {
            q = a/m;
            t = m;
            m = a%m;
            a = t;
            t=x0;
            x0=x1-q*x0;
            x1=t;
        }
        if (x1<0) x1 += m0;
        return x1;
    }
public:
    Mint(T val) : val((val%mod+mod)%mod){}
    //overload +, -, *, 
    Mint operator+(const Mint& other) const{
        return Mint((other.val + val)%mod);
    }
    Mint operator-(const Mint& other) const{
        return Mint((val - other.val+mod)%mod);
    }
    Mint operator*(const Mint& other) const{
        return Mint((val*other.val)%mod);
    }
    Mint operator/(const Mint& other) const{
        return Mint(((val * modinv(other.val, mod)) + mod ) % mod);
    }
    Mint& operator+=(const Mint& other){
        val = (val+ other.val)%mod;
        return *this;
    }
    Mint& operator-=(const Mint& other){
        val = (val - other.val+mod)%mod;
        return *this;
    }
    Mint& operator*=(const Mint& other){
        val = (val * other.val)%mod;
        return *this;
    }
    Mint& operator/=(const Mint& other){
        val = ((val * modinv(other.val))+mod)%mod;
        return *this;
    }
    bool operator==(const Mint& other) const {return val==other.val;}
    bool operator!=(const Mint& other) const {return val!=other.val;}
    bool operator>(const Mint& other) const {return val>other.val;}
    bool operator<(const Mint&other) const {return val<other.val;}
    bool operator>=(const Mint&other) const {return val>=other.val;}
    bool operator<=(const Mint&other) const {return val<=other.val;} 
};
#define mint Mint<int, mod>
#define mll Mint<ll, (ll)mod>
