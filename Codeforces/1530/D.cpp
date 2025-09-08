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
        vector<int> ans(n+1);
        vector<set<int>> vs(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            vs[v[i]].insert(i);
        }
        int p = 1;
        int ansc = n;
        for(int i=1;i<=n;i++){
            if(!vs[i].size()){
                ansc--;
                while(vs[p].size() <= 1) p++;
                if(*vs[p].begin() != i){
                    ans[*vs[p].begin()] = i;
                    vs[p].erase(vs[p].begin());
                }else{
                    ans[*prev(vs[p].end())] = i;
                    vs[p].erase(prev(vs[p].end()));
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(vs[i].size() == 1){
                ans[*vs[i].begin()] = i;
            }
        }
        cout << ansc << "\n";
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
