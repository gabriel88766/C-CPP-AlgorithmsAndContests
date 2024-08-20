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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<pair<int,int>> ans;
        for(int i=1;i<=n;i++){
            auto it = min_element(v.begin() + i, v.end());
            int len = n - i + 1;
            if(it == v.begin() + i) continue;
            else{
                int d = it - v.begin() - i;
                ans.push_back({i, d});
                vector<int> aux = v;
                for(int j=i;j<=n;j++){
                    int p = j + d;
                    if(p > n) p -= len;
                    aux[j] = v[p];
                }
                v = aux;
            }
        }
        cout << ans.size() << "\n";
        for(auto [l, d] : ans){
            cout << l << " " << n << " " << d << "\n";
        }
    }
}
