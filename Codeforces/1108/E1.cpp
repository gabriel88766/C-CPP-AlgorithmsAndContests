#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<pair<int,int>> seg(m+1);
    for(int i=1;i<=m;i++) cin >> seg[i].first >> seg[i].second;

    int mans = 0;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            vector<int> cur;
            int diff = v[i] - v[j];
            for(int k=1;k<=m;k++){
                bool iin = false, jin = false;
                if(i >= seg[k].first && i <= seg[k].second) iin = true;
                if(j >= seg[k].first && j <= seg[k].second) jin = true;
                if(jin && !iin){
                    diff++;
                    cur.push_back(k);
                }
            }
            if(diff > mans){
                ans = cur;
                mans = diff;
            }
        }
    }
    cout << mans << "\n";
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
}
