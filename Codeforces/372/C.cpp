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
    int n, m, d;
    cin >> n >> m >> d;
    int lt;
    vector<ll> ans(n), nv;
    

    for(int i=1;i<=m;i++){
        int a, b, ct;
        cin >> a >> b >> ct;
        a--;
        if(i == 1){
            lt = ct;
        }
        if(ct != lt){
            //adjust
            ll md = d;
            md *= ct - lt;
            lt = ct;
            nv = ans;
            deque<pair<ll, ll>> dq;
            for(int i=0;i<n;i++){
                while(dq.size() && dq.back().first <= ans[i]) dq.pop_back();
                while(dq.size() && dq.front().second + md < i) dq.pop_front();
                dq.push_back({ans[i], i});
                nv[i] = max(nv[i], dq.front().first);
            }
            dq.clear();
            for(int i=n-1;i>=0;i--){
                while(dq.size() && dq.back().first <= ans[i]) dq.pop_back();
                while(dq.size() && dq.front().second > i + md) dq.pop_front();
                dq.push_back({ans[i], i});
                nv[i] = max(nv[i], dq.front().first);
            }
            ans = nv;
        }
        for(int j=0;j<n;j++){
            ans[j] += b - abs(j - a);
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << "\n";
}
