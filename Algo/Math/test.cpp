#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    euler();
    for(int i=1;i<=100;i++){
        cout << i << " : " << phi[i] << "\n";
    }
}
