// WA on test 6

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//factoring in O(N^1/4 logN) + O(log^3(N)) (of miller rabin)
//begin miller rabin:
void binmul(ull &a, ull  b, ull  m){
    a %= m;
    ull ans = 0;
    while(b){
        if(b & 1){
            ans += a;
            if(ans > m) ans -= m;
        }
        a += a;
        if(a > m) a -= m;
        b >>= 1;
    }
    a = ans;
}

ull binpow(ull a, ull b, ull m){
    a %= m;
    ull ans = 1;
    while(b){
        if(b & 1) binmul(ans, a, m);
        binmul(a, a, m);
        b >>= 1;
    }
    return ans;
}

bool check_composite(ull n, ull a, ull d, int s){
    ull res = binpow(a, d, n);
    if(res == 1 || res == (n-1)) return false;
    for(int r=1;r<s;r++){
        binmul(res, res, n);
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
    binmul(x,x,mod);
    x += c;
    return x > mod ? x - mod : x;
}

ull rho(ull n, ull x0=2, ull c = 1){
    if(!(n&1)) return 2;
    ull x = x0, y = x0;
    ull g = 1;
    while(g == 1){
        x = funct(x,c,n);
        y = funct(y,c,n);
        y = funct(y,c,n);
        g = gcd((x > y ? x-y : y-x), n);
    }
    if(g == n) return rho(g, x0, c+1);
    return isPrime(g) ? g : rho(g, x0, c);
}

vector<pair<ull,ull>> fact(ull n){
    vector<pair<ull,ull>> f;
    if(n == 1) f.push_back({1,1});
    while(n != 1){
        if(isPrime(n)){
            f.push_back({n, 1});
            n = 1;
        }else{
            ull cur = rho(n);
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




//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ull n, m, curm;
    cin >> n >> m;
    vector<ull> phi;
    curm = m;
    while(curm > 2){
        auto facts = fact(curm);
        ull curphi = curm;
        for(auto u:facts){
            curphi *= (u.first - 1);
            curphi /= u.first;
        }
        phi.push_back(curphi);
        curm = curphi;
    }
    vector<ull> wk;
    for(int i=0;i<n;i++){
        ull aux;
        cin >> aux;
        wk.push_back(aux);
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        if(m == 1){
             cout << "0\n";
             continue;
        }else if(m == 2){
            cout << wk[l-1] % 2 << "\n";
            continue;
        }
        if(l == r){
            cout << wk[l-1] % m << "\n";
            continue;
        }
        if(l+1 == r){
            cout << binpow(wk[l-1], wk[l], m) << "\n";
            continue;
        }
        int diff = r-l-1;
        ull ans;
        bool flag = true, ov = false;
        int cnt = 1;

        for(int i = min(diff, (int)phi.size()-1); i >= 0; i--){
            if(wk[l+i] == 1) ov =false;
            if(flag){ if(wk[l+i] > phi[i]) ov = true; ans = wk[l + i] % phi[i]; flag = false; continue;}
            if(ov || ans > (64 - __builtin_ctz(m))) ans += phi[0];
            double p = ans;
            if(p > 32) ov = true;
            p = pow(wk[l+i], ans);
            if(p > (i ? phi[i-1] : m)) ov = true;
            ans = binpow(wk[l+i], ans, phi[i]);
        }
        if(ov || ans > (64 - __builtin_ctz(m))) ans += phi[0];
        ans = binpow(wk[l-1], ans, m);
        cout << ans << "\n";
    }
}
