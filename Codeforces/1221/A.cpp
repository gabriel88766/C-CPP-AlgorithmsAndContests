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
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        multiset<ll> ms;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            ms.insert(x);
        }
        bool ok = false;
        while(ms.size()){
            auto el1 = *ms.begin();
            if(el1 == 2048) ok = true;
            ms.erase(ms.begin());
            if(ms.size()){
                auto el2 = *ms.begin();
                if(el1 == el2){
                    ms.erase(ms.begin());
                    ms.insert(2*el1);
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
