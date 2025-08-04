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
    int n, d;
    cin >> n >> d;
    vector<tuple<int, int, int>> vt(n);
    vector<vector<int>> tog(2021);
    for(int i=0;i<n;i++){
        int x, y, r;
        cin >> x >> y >> r;
        vt[i] = {x, y, r};
        double dst = sqrt(x*x + y*y);
        int fc = (dst) / d;
        int lc = fc;
        fc = max(1, fc - 13);
        lc = lc + 13;
        assert(lc + 1 <= 2020);
        tog[fc].push_back(i);
        tog[lc+1].push_back(i);
    }
    set<int> chk;
    for(int i=1;i<=2020;i++){
        for(auto x : tog[i]){
            if(chk.count(x)) chk.erase(x);
            else chk.insert(x);
        }
        for(auto xx : chk){
            auto [x, y, r] = vt[xx];
            
        }
    }

}
