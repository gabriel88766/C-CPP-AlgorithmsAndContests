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
        priority_queue<pair<int,int>> pq;
        for(int i=1;i<=n;i++){
            int x;
            cin>> x;
            if(x)pq.push({x, i});
        }
        vector<pair<int,int>> ans;
        while(pq.size() >= 2){
            auto [u, i] = pq.top();
            pq.pop();
            auto [v, j] = pq.top();
            pq.pop();
            ans.push_back({i, j});
            u--; v--;
            if(u >= 1) pq.push({u, i});
            if(v >= 1) pq.push({v, j});
        }
        cout << ans.size() << "\n";
        for(auto [u, v] : ans){
            cout << u << " " << v << "\n";
        } 
    }
}
