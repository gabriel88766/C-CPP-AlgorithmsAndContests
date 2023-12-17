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
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<pair<int,int>> ans;
    bool ok = true;
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(v[i]) pq.push({v[i], i});
    }
    while(!pq.empty()){
        auto [v, i] = pq.top();
        pq.pop();
        if(v > pq.size()){
            ok = false;
            break;
        }
        vector<pair<int,int>> insl;
        for(int j=0;j<v;j++){
            auto [vv, k] = pq.top();
            pq.pop();
            ans.push_back({i, k});
            --vv;
            if(vv) insl.push_back({vv, k});
        }
        for(auto x : insl) pq.push(x);
    }
    if(ok){
        cout << ans.size() << "\n";
        for(auto [x, y] : ans) cout << x << " " << y << "\n";
    }else cout << "IMPOSSIBLE\n";
}
