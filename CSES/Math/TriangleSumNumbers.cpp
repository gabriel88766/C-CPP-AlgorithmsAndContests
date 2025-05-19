#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> trn;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    for(ll i = 2; ;i++){
        ll tn = ((i-1)*i)/2;
        trn.push_back(tn);
        if(tn > 1'000'000'000'000LL) break; //1 triangle number more to avoid lower bound going to end.
    }
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        auto ind = lower_bound(trn.begin(), trn.end(), n) - trn.begin();
        if(trn[ind] == n) cout << "1\n";
        else{
            ind--;
            int p = 0;
            bool ok = false;
            while(ind >= 0){
                if(trn[ind] + trn[p] > n) ind--;
                else if(trn[ind] + trn[p] < n) p++;
                else{
                    ok = true;
                    cout << "2\n";
                    break;
                }
            }
            if(!ok) cout << "3\n";
        }
        
    }
}
