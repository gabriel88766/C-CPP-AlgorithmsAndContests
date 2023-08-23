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
    int q;
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<pair<int,int>> ans;
        int p = 0;
        bool ok = true;
        while(p < t.size()){
            int maxv = 0, indv = 0, indp = 0;
            for(int i=0;i<n;i++){
                for(int j=maxv+1;j<=v[i].size();j++){
                    int pos = p+j-((int)v[i].size());
                    if(pos>=0 && t.substr(pos, v[i].size()) == v[i].substr(0, v[i].size())){
                        maxv = j;
                        indv = i+1;
                        indp = pos+1;
                    }
                }
            }
            if(maxv == 0){
                ok = false;
                break;
            }else{
                p += maxv;
                ans.push_back({indv, indp});
            }
        }
        if(ok){
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x.first << " " << x.second << "\n";
        }else cout << "-1\n";
    }
}
