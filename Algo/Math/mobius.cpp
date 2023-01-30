const int N = 1e7+1;
ll mi[N], p[N];
void mobius(){ //another sieve.
    for(ll i =1; i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                p[j] = 1, mi[j] *= -1;
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
}
//example task, number of pairs coprimes in [a,b] with [c,d]
// mi[i] acts like inclusion exclusion principle to count coprimes.
// mi[6] excludes numbers that 2|a, 2|b and 3|a, 3|b. 
ll a,b,c,d;
ll ans;
cin >> a >> b >> c >> d;
ans = (b-a+1) * (d-c+1);
for(int i=2;i<=min(b-a+1,d-c+1);i++){
    ll f = mi[i] * ((b/i) - (a-1)/i) * ((d/i)-(c-1)/i);
    ans += f;
}