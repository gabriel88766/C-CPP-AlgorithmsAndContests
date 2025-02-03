#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> pl[N];
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    set<pair<int,int>> stk;
    for(int i=1;i<=n;i++){
        ans[i] = -1;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        auto it = stk.lower_bound({x, 0});
        if(it == stk.end()){
            if(k == 1){
                ans[x] = i;
            }else{
                pl[i].push_back(x);
                stk.insert({x, i});
            }
        }else{
            auto p = *it;
            stk.erase(p);
            if(pl[p.second].size() + 1 == k){
                for(auto &x : pl[p.second]){
                    ans[x] = i;
                }
                ans[x] = i;
            }else{
                pl[p.second].push_back(x);
                p.first = x;
                stk.insert(p);
            }
        }
    } 
    for(int i=1;i<=n;i++){
        cout << ans[i] << "\n";
    }
}   
 