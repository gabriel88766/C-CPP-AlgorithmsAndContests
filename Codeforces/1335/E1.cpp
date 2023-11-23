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
        vector<vector<int>> v(27);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            v[x].push_back(i);
        }
        int ans = 1;
        for(int i=1;i<=26;i++){
            if(v[i].size()){
                int p1 = 0;
                int p2 = v[i].size() - 1;
                while(p2 > p1){
                    int qt = 2*(p1+1);
                    for(int j=1;j<=26;j++){
                        //optimize!
                        int cur = lower_bound(v[j].begin(), v[j].end(), v[i][p2]) - lower_bound(v[j].begin(), v[j].end(), v[i][p1]);
                        if(j == i) cur--;
                        if(qt + cur == 3){
                            //cout << i << " " << j << " " << qt << " " << cur << "\n";
                        }
                        ans = max(ans, qt + cur);   
                    }
                    p2--;
                    p1++;
                }
            }
        }
        cout << ans << "\n";
    }
}
