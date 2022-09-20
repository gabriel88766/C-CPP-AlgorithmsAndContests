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

//inv, if m = prime, and division, 4/3 = 4 * inv 3 mod p
long long int x = 600,y = 2,p = 998244353;
long long inv = binpow(y, p-2, p);
long long div = (4 * inv) % p;
//cout << inv << " " << div; 