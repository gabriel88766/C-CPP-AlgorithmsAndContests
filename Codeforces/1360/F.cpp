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
        vector<string> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int md = 0;
        pair<int,int> ms;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cnt = 0;
                for(int k=0;k<m;k++){
                    if(v[i][k] != v[j][k]) cnt++;
                }
                if(cnt > md){
                    md = cnt;
                    ms = {i, j};
                }
            }
        }
        if(md <= 1) cout << v[0] << "\n";
        else if(md == 2){
            vector<int> ind;
            string ans = v[ms.first];
            for(int i=0;i<m;i++){
                if(v[ms.first][i] != v[ms.second][i]){
                    ind.push_back(i);
                }
            }
            
            bool ok = false;
            for(int i=0;i<26;i++){
                if(ok) break;
                for(int j=0;j<26;j++){
                    if(ok) break;
                    ans[ind[0]] = 'a'+i;
                    ans[ind[1]] = 'a'+j;
                    bool fail = false;
                    for(int k=0;k<n;k++){
                        int cnt = 0;
                        for(int w=0;w<m;w++){
                            if(v[k][w] != ans[w]) cnt++;
                        }
                        if(cnt > 1){
                            fail = true;
                            break;
                        }
                    }
                    if(!fail) ok = true;
                }
            }
            if(ok) cout << ans << "\n";
            else cout << "-1\n";
        }else cout << "-1\n";
    }
}
 