//modulo
long long binpow(long long int a, long long int b, long long int m){
    a %= m;
    long long int res = 1;
    while(b > 0){
        if(b & 1) 
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
