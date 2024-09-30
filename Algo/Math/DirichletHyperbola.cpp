
//Dirichlet hyperbola method
//sum f*g(i) from 1 to n:
//let F(n) = sum 1 to n f(i);
//let G(n) = sum 1 to n g(i)
//sum from 1 to sqt(n) of f(i)G(n/i) + sum from 1 to sqt of g(i)F(n/i) - F(sqt(n))*G(sqt(n));

//example 1: div^2 (n)
// n^2 conv 1

ll sum_g(ll n){ //O(1)
    return n % MOD;
}

ll sum_f(ll n){ //O(1)
    ll p1 = n;
    ll p2 = n+1;
    ll p3 = 2*n+1;
    if(!(p1 % 3)) p1 /= 3;
    else if(!(p2 % 3)) p2 /= 3;
    else p3 /= 3;
    if(n % 2) p2 /= 2;
    else p1 /= 2;
    p1 %= MOD;
    p2 %= MOD;
    p3 %= MOD;
    p1 = (p1 * p2) % MOD;
    p1 = (p1 * p3) % MOD;
    return p1;
}

//just apply the formula
ll hyperbola_dirichlet(ll n){
    ll ans = 0;
    ll sqt = sqrt(n);
    while((sqt+1)*(sqt+1) <= n) sqt++;
    for(ll i=1;i<=sqt;i++){
        ll fv = (i*i) % MOD;
        ans += fv * sum_g(n/i);
        ans += sum_f(n/i);
        ans %= MOD;    
    }
    ans -= (sum_g(sqt) * sum_f(sqt)) % MOD;
    ans %= MOD;
    if(ans < 0) ans += MOD;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    cout << hyperbola_dirichlet(1'000'000'000'000'000LL) << "\n";
}
