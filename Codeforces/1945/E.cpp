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
        int n, x;
        cin >> n >> x;
        vector<int> p(n+1);
        int ix = -1;
        for(int i=1;i<=n;i++){
            cin >> p[i];
            if(p[i] == x) ix = i;
        }
        auto simul = [&](){
            int l = 1, r = n+1;
            while(r-l > 1){
                int m = (l+r)/2;
                if(p[m] <= x) l = m;
                else r = m;
            }
            return l;
        };
        if(x == 1){
            if(ix != 1){
                cout << "1\n" << 1 << " " << ix << "\n";
            }else cout << "0\n";
        }else if(x == n){
            if(ix != n){
                cout << "1\n" << ix << " " << n << "\n";
            }else cout << "0\n";
        }else{
            vector<pair<int,int>> ans;
            for(int i=1;i<=n;i++){
                if(i != ix){
                    swap(p[i], p[ix]);
                    auto ac = simul();
                    int mid = (n+2)/2;
                    if(ac == i){
                        ans.push_back({i, ix});
                        break;
                    }
                    if(ac < mid && i >= mid){
                        if(i != ix) ans.push_back({i, ix});
                        if(ac != i) ans.push_back({i, ac});
                        break;
                    }
                    if(ac >= mid && i < mid){
                        if(i != ix) ans.push_back({i, ix});
                        if(ac != i) ans.push_back({i, ac});
                        break;
                    }
                    swap(p[i], p[ix]);
                }
            }
            cout << ans.size() << "\n";
            for(auto [a,b ] : ans) cout << a << " " << b << "\n";
        }
    }   
}
