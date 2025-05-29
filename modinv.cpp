template<typename T>
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
