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
        ll n, m, L;
        cin >> n >> m >> L;
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            int x, y;
            cin >> x >> y;
            vp[i] = {x, y};
        }
        vector<pair<int,int>> pw(m);
        for(int i=0;i<m;i++){
            int x, y;
            cin >> x >> y;
            pw[i] = {x, y};
        }
        int p = 0;
        int ans = 0;
        priority_queue<int> pq;
        int jv = 1;
        for(int i=0;i<n;i++){
            while(p < m && pw[p].first < vp[i].first){
                pq.push(pw[p].second);
                p++;
            }
            while(pq.size() && jv <= vp[i].second - vp[i].first + 1){
                jv += pq.top();
                pq.pop();
                ans++;
            }
            if(jv <= vp[i].second - vp[i].first + 1){
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
}
