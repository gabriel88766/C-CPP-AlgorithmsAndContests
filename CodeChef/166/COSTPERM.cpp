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
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<bool> vis(n+1, false);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vector<int> curv;
                int cur = i;
                do{
                    curv.push_back(cur);
                    cur = v[cur];
                }while(cur != i);
                pq.push(curv.size());
                for(auto x : curv) vis[x] = true;
            }
        }
        ll ans = 0;
        while(pq.size() >= 2){
            ll u = pq.top();
            pq.pop();
            ll v = pq.top();
            pq.pop();
            ans += u + v;
            pq.push(u+v);
        }
        cout << ans << "\n";
    }
}
