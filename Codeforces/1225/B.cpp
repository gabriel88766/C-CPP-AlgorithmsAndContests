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
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        set<pair<int,int>> window;

        for(int i=0;i<d;i++){
            auto it = window.lower_bound({v[i], 0});
            if(it == window.end() || it->first != v[i]){
                window.insert({v[i], 1});
            }else{
                auto p = *it;
                window.erase(p);
                p.second++;
                window.insert(p);
            }
        }
        int ans = window.size();
        for(int i=d;i<n;i++){
            auto p = *window.lower_bound({v[i-d], 0});
            window.erase(p);
            p.second--;
            if(p.second != 0) window.insert(p);
            //insert
            auto it = window.lower_bound({v[i], 0});
            if(it == window.end() || it->first != v[i]){
                window.insert({v[i], 1});
            }else{
                auto p = *it;
                window.erase(p);
                p.second++;
                window.insert(p);
            }
            ans = min(ans, (int)window.size());
        }
        cout << ans << "\n";
    }
}
