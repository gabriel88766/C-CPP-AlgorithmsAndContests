struct Frac{
    ll a,  b;
    Frac(ll a, ll b){
        assert(b != 0); //please don't use b = 0; :)
        ll g = gcd(abs(a), abs(b));
        if(b < 0){
            a = -a;
            b = -b;
        }
        this->a = a / g;
        this->b = b / g;
    }
    Frac() : a(0), b(1) {}
    bool operator< (const Frac &f) const{
        // return (__int128)a * f.b < (__int128)b * f.a; //if necessary
        return a * f.b < b * f.a;
    }
    bool operator== (const Frac &f) const{
        return a == f.a && b == f.b;
    }
    Frac& operator+= (const Frac &f) { //Use only if you know it won't overflow denominators.
        a = a * f.b + b * f.a;
        b *= f.b;
        ll g = gcd(a, b);
        a /= g, b /= g;
        return *this;
    }
    friend Frac operator+ (Frac a, Frac const &b){ return a += b;}
};