#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        bool ok = true;
        vector<ll> vm;
        for(int i=1;i<=n;i++){
            ll msk = 0;
            ll aux = 1;
            int b = 0;
            ll x;
            cin >> x;
            while(x){
                ll cg = (x % (aux * k))/aux;
                assert(!(x % aux));
                if(cg > 1){
                    ok = false;
                    break;
                }
                if(cg == 1){
                    msk |= 1LL << b;
                }
                b++;
                x -= cg * aux;
                aux *= k;
                
            }
            vm.push_back(msk);
        }
        for(int i=0;i<vm.size();i++){
            for(int j=i+1;j<vm.size();j++){
                if(vm[i] & vm[j]) ok = false;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
