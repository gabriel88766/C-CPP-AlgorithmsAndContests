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
    set<pair<int, int>> its;
    int n, m, h, k;
    string s;
    cin >> n >> m >> h >> k >> s;
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        its.insert({x, y});
    }
    bool ok = true;
    int x = 0, y = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'L') x--;
        else if(s[i] == 'R') x++;
        else if(s[i] == 'U') y++;
        else y--;
        h--;
        if(h < 0) ok = false;
        if(its.count({x, y})){
            if(h < k){
                h = k;
                its.erase({x, y});
            }
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";

}
