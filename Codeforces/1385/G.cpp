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
        vector<vector<int>> oc(n+1);
        vector<int> a(n+1);
        vector<int> b(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            oc[a[i]].push_back(i);
        }
        for(int i=1;i<=n;i++){
            cin >> b[i];
            oc[b[i]].push_back(i);
        }
        bool ok = true;
        for(int i=1;i<=n;i++) if(oc[i].size() != 2) ok = false;
        if(ok){
            vector<int> vis(n+1, 0);
            vector<int> ans;
            for(int i=1;i<=n;i++){
                if(vis[i] == 0){
                    vector<int> idx;
                    idx.push_back(oc[i][0]);
                    vis[a[idx[0]]]++;
                    vis[b[idx[0]]]++;
                    while(true){
                        int p1 = a[idx.back()], p2 = b[idx.back()];
                        if(vis[p1] == 1){
                            int i1 = oc[p1][0], i2 = oc[p1][1];
                            if(i1 != idx.back()) idx.push_back(i1);
                            else idx.push_back(i2);
                            vis[a[idx.back()]]++;
                            vis[b[idx.back()]]++;
                        }else if(vis[p2] == 1){
                            int i1 = oc[p2][0], i2 = oc[p2][1];
                            if(i1 != idx.back()) idx.push_back(i1);
                            else idx.push_back(i2);
                            vis[a[idx.back()]]++;
                            vis[b[idx.back()]]++;
                        }else break;
                    }
                    vector<int> rev;
                    for(int j=1;j<idx.size();j++){
                        bool lrev;
                        if(rev.size() && rev.back() == j-1) lrev = true;
                        else lrev = false;
                        if(a[idx[j-1]] == a[idx[j]] || b[idx[j-1]] == b[idx[j]]){
                            if(!lrev) rev.push_back(j);
                        }else if(lrev) rev.push_back(j);
                    }
                    int keep = rev.size();
                    int dkeep = idx.size() - rev.size();
                    if(dkeep < keep){
                        int p = 0;
                        for(int j=0;j<idx.size();j++){
                            if(p < rev.size() && rev[p] == j) p++;
                            else ans.push_back(idx[j]);
                        }
                    }else{
                        for(auto j : rev) ans.push_back(idx[j]);
                    }
                }
            }
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else cout << "-1\n";
    }
}
