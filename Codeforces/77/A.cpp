#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<string> mem = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
map<string, int> mp;
bool like[7][7];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<7;i++){
        mp[mem[i]] = i;
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string a, b, c;
        cin >> a >> b >> c;
        like[mp[a]][mp[c]] = true;
    }
    int a, b, c;
    cin >> a >> b >> c;
    vector<tuple<int, int, int>> ttc;
    int mnd = 2'100'000'000;
    for(int i=1;i<=5;i++){
        for(int j=1;i+j<=6;j++){
            int q1 = a / i;
            int q2 = b / j;
            int q3 = c / (7 - i - j);
            int mn = min({q1, q2, q3});
            int mx = max({q1, q2, q3});
            if(mx - mn < mnd){
                ttc.clear();
                ttc.push_back({i, j, 7 - i - j});
                mnd = mx - mn;
            }else if(mx - mn == mnd){
                ttc.push_back({i, j, 7 - i - j});
            }
        }
    }
    cout << mnd << " ";
    int ans = 0;
    for(auto [a, b, c]: ttc){
        for(int i=0;i<(1 << 7); i++){
            if(__builtin_popcount(i) != a) continue;
            for(int j = 0; j < (1 << 7); j++){
                if(__builtin_popcount(j) != b) continue;
                if(i & j) continue;
                for(int k = 0; k < (1 << 7); k++){
                    if(__builtin_popcount(k) != c) continue;
                    if(i & k) continue;
                    if(j & k) continue;
                    int cur = 0;
                    for(int u = 0; u < 7; u++){
                        for(int v = 0; v < 7; v++){
                            if(like[u][v]){
                                if((i & (1 << u)) && (i & (1 << v))) cur++;
                                else if((j & (1 << u)) && (j & (1 << v))) cur++;
                                else if((k & (1 << u)) && (k & (1 << v))) cur++;
                            }
                        }
                    }
                    ans = max(ans, cur);
                }
            }
        }
    }
    cout << ans << "\n";
}
