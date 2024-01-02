//factoring in O(N^1/4 logN) + O(log^2(N)) (of miller rabin)
//begin miller rabin:
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
//end miler rabin

//begin pollard rho finds 
ull gcd(ull a, ull b){
    while(b){ ull c = a % b; a = b; b = c; }
    return a;
}
ull funct(ull x, ull c, ull mod){
    x = mult(x,x,mod);
    x += c;
    return x > mod ? x - mod : x;
}

ull rho(ull n, ull c = 1){
    if(!(n&1)) return 2;
    ull x = 2, y = 2;
    ull g = 1;
    while(g == 1){
        x = funct(x,c,n);
        y = funct(y,c,n);
        y = funct(y,c,n);
        g = gcd((x > y ? x-y : y-x), n);
    }
    if(g == n) return rho(g, rng());
    return isPrime(g) ? g : rho(g, rng());
}

vector<pair<ull,ull>> fact(ull n){
    vector<pair<ull,ull>> f;
    if(n == 1) f.push_back({1,0}); //avoid RTE
    while(n != 1){
        if(isPrime(n)){
            f.push_back({n, 1});
            n = 1;
        }else{
            ull cur = rho(n, rng());
            ull cnt = 0;
            while(!(n % cur)){
                n /= cur;
                cnt++;
            }
            f.push_back({cur, cnt});
        }
    }
    sort(f.begin(),f.end());
    return f;
}

vector<ull> allDivs(ull n){ // O(#divs log #divs) , #divs <= 103680
    auto f = fact(n);
    vector<ull> ans;
    ans.push_back(1);
    for(int i=0;i<f[0].second;i++) ans.push_back(ans.back()*f[0].first);
    for(int i=1;i<f.size();i++){
        auto aux = ans;
        ull aux2 = 1;
        for(int k=0;k<f[i].second;k++){
            aux2 *= f[i].first;
            for(int j=0;j<ans.size();j++){
                aux.push_back(ans[j]*aux2);
            }
        }
        ans = aux;
    }
    sort(ans.begin(),ans.end());
    return ans;
}