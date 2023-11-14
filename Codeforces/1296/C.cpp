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
        string s;
        cin >> n >> s;
        int x = 0, y = 0;
        map<pair<int,int>,int> mp;
        mp[{x,y}] = 0;
        int minv = INF_INT;
        int ans1 = -1, ans2 = -1;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'L') x--;
            else if(s[i] == 'R') x++;
            else if(s[i] == 'U') y++;
            else if(s[i] == 'D') y--;
            int cur = i+1;
            if(mp.count({x, y})){
                int cans = cur - mp[{x, y}];
                if(cans < minv){
                    minv = cans;
                    ans1 = mp[{x, y}] + 1;
                    ans2 = cur;
                }
            }
            mp[{x,y}] = cur;
        }
        if(minv != INF_INT) cout << ans1 << " " << ans2 << "\n";
        else cout << "-1\n";
    }
}
