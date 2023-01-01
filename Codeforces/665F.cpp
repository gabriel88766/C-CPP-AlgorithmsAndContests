#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int N = 1e6+1;
int p[N]; // 0 is prime, 1 is not prime
vector<ll> primes;
void sieve(){
    for(ll i=2; i<=N; i++){
        if(!p[i]){
            for(ll j = i*i; j <= N; j += i){
                p[j] = 1;
            }
            primes.push_back(i);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll count=0, pr, n;
    sieve();
    cin >> n;
    for(int i = 0; i < primes.size(); i++){
        pr = primes[i];
        if ((pr*pr*pr) <= n) count++;
        else break;
    }
    for(int i = 0; i < primes.size(); i++){
        for(int j = i + 1; j < primes.size(); j++){
           
            if((primes[i] * primes[j]) <= n){
                count++;
            }else break;
        }
    }
    cout << count;
    
}
