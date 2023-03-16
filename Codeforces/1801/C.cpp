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
        vector<vector<int>> v(n, vector<int>());
        for(int i=0;i<n;i++){
            int tt;
            cin >> tt;
            for(int j=0;j<tt;j++){
                int aux;
                cin >> aux;
                if(j == 0) v[i].emplace_back(aux);
                else if(aux > v[i].back()) v[i].emplace_back(aux);
            }
        }
        set<pair<int, pair<int,int>>> ch;
        for(int i=0;i<n;i++){
            ch.insert({v[i][0], {i, 0}});
        }
        set<pair<int,int>> ans = {{0,0}}; //weird
        while(!ch.empty()){
            auto nowv = *ch.begin();
            ch.erase(nowv);
            auto it = ans.lower_bound({nowv.first, 0}); --it;
            int vec = nowv.second.first;
            int ind = nowv.second.second;
            int sz = v[vec].size() - ind;
            ans.insert({v[vec].back(), it->second + sz});
            if(sz > 1) ch.insert({v[vec][ind+1], {vec, ind+1}});
        }
        cout << ans.rbegin()->second << "\n";
        
        
    }
}
