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
        vector<pair<int,int>> vp;
        vector<int> st(n+1, false);
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            if(a != 1 && b != 1){
                vp.push_back({a, b});
            }else{
                if(a == 1) st[b] = 1;
                else st[a] = 1;
            }
        }
        vector<tuple<int,int,int>> ans;
        for(auto [a, b] : vp){
            ans.push_back({1, a, b});
            st[a] ^= 1;
            st[b] ^= 1;
        }
        int cx = -1;
        for(int i=2;i<=n;i++) if(st[i]) cx = i;
        if(cx != -1){
            for(int i=2;i<=n;i++){
                if(!st[i]){
                    ans.push_back({1, cx, i});
                    cx = i;
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto [a, b, c] : ans) cout << a << " " << b << " " << c << "\n";
    }
}
