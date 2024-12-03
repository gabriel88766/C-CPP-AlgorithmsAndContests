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
        vector<int> v(n+1), g(n+1);
        set<int> v1, v2;
        int c1 = 0, c2 = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(v[i] == 1){
                c1++;
                v1.insert(i);
            }
            if(v[i] == 2){
                c2++;
                v2.insert(i);
            }
        }
        vector<pair<int,int>> ans; 
        for(int i=n;i>=1;i--){
            if(c2 > 0){
                g[i] = 2;
                c2--;
            }else if(c1 > 0){
                g[i] = 1;
                c1--;
            }
            if(v[i] == g[i]) continue;
            else{
                if(v[i] == 0){
                    assert(v1.size());
                    ans.push_back({*v1.begin(), i});
                    swap(v[*v1.begin()], v[i]);
                    v1.erase(v1.begin());
                }
                if(v[i] == 1 && g[i] == 2){
                    assert(v2.size());
                    ans.push_back({*v2.begin(), i});
                    swap(v[*v2.begin()], v[i]);
                    v1.insert(*v2.begin());
                    v2.erase(v2.begin());
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto [a, b] : ans) cout << a << " " << b << "\n";

    }
}
