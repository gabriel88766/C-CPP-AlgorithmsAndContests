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
        string s;
        int w, m;
        cin >> s >> w >> m;
        int n = s.size();
        vector<vector<int>> vlrem(10);
        vector<int> ps(n+1, 0);
        for(int i=0;i<n;i++){
            ps[i+1] = ps[i] + (s[i]-'0');
        }
        for(int i=w;i<=n;i++){
            vlrem[(ps[i]-ps[i-w])%9].push_back(i-w+1);
        }
        
        for(int i=0;i<m;i++){
            int l, r, k;
            cin >> l >> r >> k;
            int r1 = (ps[r] - ps[l-1])%9;
            pair<int,int> ans = {INF_INT, INF_INT};
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    int x = (r1*i + j) % 9;
                    if(x == k){
                        if(i == j){
                            if(vlrem[i].size() >= 2){
                                ans = min(ans, make_pair(vlrem[i][0], vlrem[i][1]));
                            }
                        }else{
                            if(vlrem[i].size() && vlrem[j].size()){
                                ans = min(ans, make_pair(vlrem[i][0], vlrem[j][0]));
                            }
                        }
                    }
                }
            }
            if(ans != make_pair(INF_INT, INF_INT)) cout << ans.first << " " << ans.second << "\n";
            else cout << "-1 -1\n";
        }
    }
}
