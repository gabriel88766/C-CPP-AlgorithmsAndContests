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
        vector<pair<int, int>> vp;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            vp.push_back({x, i});
        }
        sort(vp.begin(), vp.end());
        if(m <= n/2 && m != 0){
            //x m m
            int x = n - 2*m;
            vector<pair<int, int>> ans;
            for(int i=0;i<x;i++){
                ans.push_back({vp[i].second, vp[i+1].second});
            }
            for(int i=x+m;i<n;i++){
                ans.push_back({vp[i].second, vp[i-m].second});
            }
            cout << ans.size() << "\n";
            for(auto [a, b] : ans){
                cout << a << " " << b << "\n";
            }
        }else if(m == 0){
            ll sum = 0;
            bool ok = false;
            for(int i=n-2;i>=0;i--){
                sum += vp[i].first;
                if(sum >= vp[n-1].first){
                    ok = true;
                    vector<pair<int, int>> ans;
                    for(int j=0;j<i;j++){
                        ans.push_back({vp[j].second, vp[j+1].second});
                    }
                    for(int j=i;j<n-1;j++){
                        ans.push_back({vp[j].second, vp[n-1].second});
                    }
                    cout << ans.size() << "\n";
                    for(auto [a, b] : ans){
                        cout << a << " " << b << "\n";
                    }
                    break;
                }
            }
            if(!ok) cout << "-1\n";
        }else cout << "-1\n";
    }
}
