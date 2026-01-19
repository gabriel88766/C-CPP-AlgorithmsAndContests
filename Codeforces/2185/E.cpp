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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> rb(n), tr(m);
        for(int i=0;i<n;i++) cin >> rb[i];
        for(int i=0;i<m;i++) cin >> tr[i];
        sort(tr.begin(), tr.end());
        map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            auto it = lower_bound(tr.begin(), tr.end(), rb[i]);
            if(it != tr.end()){
                mp[*it - rb[i]].push_back(i);
            }
            if(it != tr.begin()){
                mp[*prev(it) - rb[i]].push_back(i);
            }
        }
        int cur = 0;
        int lw = 0, hg = 0;
        int ans = n;
        vector<bool> dead(n, false);
        string s;
        cin >> s;
        for(auto c : s){
            if(c == 'L') cur--;
            else cur++;
            bool sh = false;
            if(cur > hg){
                hg = cur;
                sh = true;
            }
            if(cur < lw){
                lw = cur;
                sh = true;
            }
            if(sh && mp.count(cur)){
                for(auto x : mp[cur]){
                    if(!dead[x]){
                        dead[x] = true;
                        ans--;
                    }
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
