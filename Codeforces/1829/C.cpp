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
        vector<int> b[4];
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int qt;
            string s;
            cin >> qt >> s;
            if(s == "01") b[1].push_back(qt);
            else if(s == "10") b[2].push_back(qt);
            else if(s == "11") b[3].push_back(qt);
        }
        int min1 = INF_INT, min2 = INF_INT;
        for(int i=1;i<=3;i++) sort(b[i].begin(), b[i].end());
        if(b[3].size()) min1 = b[3][0];
        if(b[1].size() && b[2].size()) min2 = b[1][0] + b[2][0];
        int ans = min(min1,min2);
        if(ans == INF_INT) cout << "-1\n";
        else cout << ans << "\n";
    }
}
