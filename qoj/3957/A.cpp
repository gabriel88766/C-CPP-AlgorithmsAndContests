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
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> bl(m+1);
    vector<vector<int>> bp(n+1);
    vector<int> cnt(n+1), cnt2(m+1);
    set<pair<int, int>> st;
    for(int i=1;i<=m;i++){
        cin >> cnt2[i];
        bl[i].resize(cnt2[i]);
        for(int j=0;j<cnt2[i];j++){
            cin >> bl[i][j];
            cnt[bl[i][j]]++;
            bp[bl[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++) st.insert({cnt[i], i});
    while(st.size()){
        auto [qt, v] = *st.begin();
        if(qt >= c) break; //we're done.
        //remove the band v from event
        st.erase(st.begin());
        cnt[v] = 0;
        vector<int> ppr;
        for(auto x : bp[v]){
            cnt2[x]--;
            if(cnt2[x] < ((bl[x].size() + 1)/2) && cnt2[x] + 1 >= ((bl[x].size() + 1)/2)) ppr.push_back(x);
        }
        for(auto x : ppr){
            for(auto v : bl[x]){
                if(cnt[v] != 0){
                    st.erase({cnt[v], v});
                    cnt[v]--;
                    st.insert({cnt[v], v});
                }
            }
        }
    }
    if(st.size()){
        cout << "possible\n";
        set<int> ans;
        for(auto [a, b] : st) ans.insert(b);
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }else cout << "impossible\n";
}
