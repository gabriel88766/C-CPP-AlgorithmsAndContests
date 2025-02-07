#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> vx;
vector<int> cv;
void genall(int n, int m){
    if(cv.size() == n){
        vx.push_back(cv);
        return;
    }
    int lw = cv.size() ? cv.back() : 1;
    for(int i=lw;i<=m;i++){
        cv.push_back(i);
        genall(n, m);
        cv.pop_back();
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    genall(n, m);
    vector<tuple<int, int, int, int>> rls;
    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        rls.push_back({a, b, c, d});
    }
    int ans = 0;
    for(auto &cv : vx){
        int cur = 0;
        for(auto &[a, b, c, d] : rls){
            if(cv[b-1] - cv[a-1] == c) cur += d;
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
