//compute phi(n) up to N
const int N = 1e6+5;
int phi[N];
void euler(){
    for(ll i=1;i<N;i++) phi[i] = i;
    for(ll i=2; i < N; i++){
        if(phi[i] == i){
            for(ll j = i; j < N; j += i){
                phi[j] -= phi[j]/i; //marking all multiples of i as not prime
            }
        }
    }
}
// if is needed to compute phi(n) for long integers, use pollard rho (or sieve if < 1e14)
// after this, euler(n) = (p1-1)*(p2-1)*(p3-1) ... / p1*p2*p3...