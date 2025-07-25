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
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n+1);
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        vp[i] = {a, b};
    }
    for(int i=1;i<=n;i++){
        int ft = i, d = 0;
        for(int j=1;j<=n;j++){
            int x = abs(vp[j].first - vp[i].first);
            int y = abs(vp[i].second - vp[j].second);
            if(x*x+y*y > d){
                d = x*x+y*y;
                ft = j;
            }
        }
        cout << ft << "\n";
    }
}
