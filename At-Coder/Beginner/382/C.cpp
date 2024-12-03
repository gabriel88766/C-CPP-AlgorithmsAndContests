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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> vp;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(!vp.size() || vp.back().first > x){
            vp.push_back({x, i});
        }
    }
    for(int i=1;i<=m;i++){
        int x;
        cin >> x;
        if(x < vp.back().first) cout << "-1\n";
        else{
            int p = vp.size() - 1;
            for(int k=vp.size()/2;k>=1;k>>=1){
                while(p - k >= 0 && vp[p-k].first <= x) p -= k;
            }
            cout << vp[p].second << "\n";
        }
    }
}
