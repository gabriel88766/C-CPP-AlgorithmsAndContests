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
        int n, m, k;
        cin >> n >> m;
        vector<int> a(n);
        vector<pair<ll,ll>> n1, n2, nr1, nr2;
        for(int i=0;i<n;i++){
             cin >> a[i];
             int qt = 1;
             while(!(a[i] % m)){
                a[i] /= m;
                qt *= m;
             }
             n1.push_back({a[i], qt});
        }
        cin >> k;
        vector<int> b(k);
        for(int i=0;i<k;i++){ 
            cin >> b[i];
            int qt = 1;
            while(!(b[i] % m)){
                b[i] /= m;
                qt *= m;
            }
            n2.push_back({b[i], qt});
        }
        auto func = [&](vector<pair<ll, ll>> vec){
                int n = vec.size();
                vector<pair<ll,ll>> ans;
                int p = 0;
                while(p < n){
                    ll nxt = vec[p].first;
                    ll qt = vec[p].second;
                    p++;
                    while(p < n && vec[p].first == nxt){
                        qt += vec[p].second;
                        p++;
                    }
                    ans.push_back({nxt, qt});
                }
                return ans;
        };
        nr1 = func(n1);
        nr2 = func(n2);
        if(nr1 == nr2) cout << "Yes\n";
        else cout << "No\n";
    }
}
