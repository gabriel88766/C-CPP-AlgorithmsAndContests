// O(N) memory and O(N loglog N) processing
// typedef long long int ll;
const int N = 1e6+5;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> primes;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            primes.push_back(i);
        }
    }
}
//linear, https://cp-algorithms.com/algebra/prime-sieve-linear.html
const int N = 10000000;
int lp[N+1];
vector<int> pr;

for (int i=2; i <= N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
            break;
        }
    }
}

//seg sieve
const int M = 1e7+2; 
int p2[M]; //primes interval up to 10^7, primes up to N^2
vector<ll> pr;
void segsieve(ll l, ll r){
    for(auto x : primes){
        if(x*x > r) break;
        for(ll i=(l-1)/x+1; i*x <= r; i++){
            p2[i*x-l] = 1;
        }
    }
    for(int i=l;i<=r;i++){
        if(!p2[i-l]) pr.push_back(i);
    }
}