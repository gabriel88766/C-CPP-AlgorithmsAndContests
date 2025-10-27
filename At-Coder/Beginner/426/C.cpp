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
    vector<pair<int, int>> qx;
    for(int i=n;i>=1;i--) qx.push_back({i, 1});
    for(int i=1;i<=q;i++){
        int x, y;
        cin >> x >> y;
        int qnt = 0;
        while(qx.back().first <= x){
            qnt += qx.back().second;
            qx.pop_back();
        }
        cout << qnt << "\n";
        if(qnt != 0){
            qx[n-y].second += qnt;
        }
    }
}
