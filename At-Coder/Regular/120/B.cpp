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
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for(int i=0;i<h;i++) cin >> v[i];
    int ans = 1;
    for(int s=0;s<=h+w-2;s++){
        bool b = false, r = false;
        for(int i=0;i<h;i++){
            int j = s - i;
            if(j < w && j >= 0){
                if(v[i][j] == 'B') b = true;
                if(v[i][j] == 'R') r = true;
            }
        }
        if(b && r) ans = 0;
        else if((!b) && (!r)) ans = (2*ans) % MOD;
    }
    cout << ans << "\n";
}
