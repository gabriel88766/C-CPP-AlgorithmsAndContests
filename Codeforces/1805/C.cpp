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
        int n, m;
        cin >> n >> m;
        set<int> vk;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            vk.insert(x);
        }
        for(int i=0;i<m;i++){
            int a,b,c;
            cin >> a >> b >> c;
            bool ok = false;
            if(c <= 0) cout << "NO\n";
            else{
                ll x = 4*a;
                x *= c;
                auto it = vk.lower_bound(b);
                if(it != vk.end()){ 
                    ll k = b-*it;
                    k *= k;
                    if(k < x){
                        ok = true;
                        cout << "YES\n";
                        cout << *it << "\n";
                    }
                }
                if(ok) continue;
                if(it != vk.begin()){
                    --it;
                    ll k = b-*it;
                    k *= k;
                    if(k < x){
                        ok = true;
                        cout << "YES\n";
                        cout << *it << "\n";
                    }
                }
                if(!ok) cout << "NO\n";
            }
        }
    }
}
