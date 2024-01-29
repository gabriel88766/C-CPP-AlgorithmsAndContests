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
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> h = {{1, 0}};
    int t = 0;
    for(int i=0;i<q;i++){
        int nq;
        cin >> nq;
        if(nq == 1){
            char c;
            cin >> c;
            auto [x, y] = h.back();
            if(c == 'U') y++;
            else if(c == 'D') y--;
            else if(c == 'L') x--;
            else if(c == 'R') x++;
            else assert(false);
            h.push_back({x, y});
            t++;
        }else{
            int p;
            cin >> p;
            if(p - t >= 1) cout << p-t << " " << 0 << "\n";
            else{
                int dif = p-1;
                cout << h[t-dif].first << " " << h[t-dif].second << "\n";
            }
        }
    }
}
