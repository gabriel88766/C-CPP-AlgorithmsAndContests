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
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        if(n == 1){
            cout << "NO\n";
        }else{
            vector<ll> aux(n);
            for(int i=0;i<n;i++){
                if(v[i] == 1) aux[i] = 2;
                else aux[i] = 1;
            }
            ll S1 = 0, S2 = 0;
            for(int i=0;i<n;i++){
                S1 += v[i];
                S2 += aux[i];
            }
            if(S2 <= S1) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
