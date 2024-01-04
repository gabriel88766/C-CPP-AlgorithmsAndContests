#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 32000;
int p[N]; // 0 if prime, 1 if not prime
vector<int> pr;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            pr.push_back(i);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();    
    int t;
    cin >> t;
    while(t--){
        int a, b, k;
        cin >> a >> b >> k;
        if(a > b) swap(a, b); //b >= a is true

         if(k == 1){
            if(b % a || b == a) cout << "NO\n";
            else cout << "YES\n";
        }else{
            int c1 = 0, c2 = 0;
            for(int i=0; i < pr.size(); i++){
                while(!(a % pr[i])){
                    c1++;
                    a /= pr[i];
                }
                while(!(b % pr[i])){
                    c2++;
                    b /= pr[i];
                }
            }
            if(a != 1) c1++;
            if(b != 1) c2++;
            int sz = c1 + c2;
            if(sz >= k) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
