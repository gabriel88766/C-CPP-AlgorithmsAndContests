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
    int n, m;
    cin >> n >> m;
    vector<pair<char, int>> act(m+1);
    vector<bool> is(n+1, false);
    int cnt = 0;
    vector<bool> can(n+1, true);
    vector<int> i0
    for(int i=1;i<=m;i++){
        char c;
        int x;
        cin >> c >> x;
        can[x] = false;
        if(c == '-'){
            if(!is[x]){
                cnt++;
                i0.push_back(x);
            }
            is[x] = false;
        }else{
            is[x] = true;
        }
        act[i] = {c, x};
    }
    for(int i=1;i<=n;i++) is[i] = false;
    for(auto [c, x] : act){
        if(c == '-'){
            cnt--;
            is[x] = false;
            if(cnt != 0) can[x] = false;
        }else{
            if(cnt != 0) can[x] = false;
            cnt++;
            is[x] = true;
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;i++) if(can[i]) ans.push_back(i);
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}   
