#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 10000000;
int lp[N+1];
vector<int> pr;
void sieve(){
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
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //(n(n+1)) / 2
    sieve();
    for(ll n=1;;n++){
        if(n >= N) break;
        ll cdiv = 1;
        ll n1 = n, n2 = n+1;
        if(n1 % 2 == 0) n1 /= 2;
        else n2 /= 2;
        while(n1 != 1 || n2 != 1){
            ll cf = lp[n1] && lp[n2] ? min(lp[n1], lp[n2]) : (lp[n1] ? lp[n1] : lp[n2]);
            ll cc = 0;
            while(n1 % cf == 0){
                cc++;
                n1 /= cf;
            }
            while(n2 % cf == 0){
                cc++;
                n2 /= cf;
            }
            cdiv *= (cc + 1);
        }
        if(cdiv > 500){
            cout << (n * (n+1))/2 << "\n";
            break;
        }
    }
}
