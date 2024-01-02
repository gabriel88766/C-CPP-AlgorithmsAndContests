// check if a number < 10^18 is prime or no O(log^3(n)) <- using binmul and binpow, O(log(n)) using only binpow
// tested in https://www.spoj.com/problems/PON/
//key idea, if n is prime then a^(n-1) == 1 mod n and a^(2^r*d) - 1 == 0 mod n, 
//and (a^[2^(r-1)*d]+1)...(a^(2d)+1)(a^d+1)(a^d-1) == 0 mod n.
//if n is prime, some of these should be a multiple of n, just check it. if fails, is composite.
// we only need to check for a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}
ull mult(ull a, ull  b, ull  m){
    __int128 res = (unsigned __int128)a * b % m;
    return (ull)res;
}

ull binpow(ull a, ull b, ull m){
    a %= m;
    ull ans = 1;
    while(b){
        if(b & 1) ans = mult(ans, a, m);
        a = mult(a, a, m);
        b >>= 1;
    }
    return ans;
}

bool check_composite(ull n, ull a, ull d, int s){
    ull res = binpow(a, d, n);
    if(res == 1 || res == (n-1)) return false;
    for(int r=1;r<s;r++){
        res = mult(res, res, n);
        if(res == (n-1)) return false;
    }
    return true;
}

bool isPrime(ull n){
    if(n < 2) return false;
    int s = 0;
    ull d = n - 1;
    while(!(d & 1)){
        d >>= 1;
        s++;
    }
    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if (n == a) return true;
        if(check_composite(n,a,d,s)) return false;
    }
    return true;
}