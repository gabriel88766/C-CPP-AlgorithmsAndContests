#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool dp[1 << 18]; //0 is lose 1 is win
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int, int>> nx(n);
    for(int i=0;i<n;i++){
        cin >> nx[i].first >> nx[i].second;
    }
    for(int i=0;i<(1 << n);i++){
        for(int j=0;j<n;j++){
            if(!(i & (1 << j))) continue;
            for(int k=0;k<n;k++){
                if(j == k) continue;
                if(!(i & (1 << k))) continue;
                if(nx[j].first == nx[k].first || nx[j].second == nx[k].second){
                    int gx = (i ^ (1 << j)) ^ (1 << k);
                    if(dp[gx] == false) dp[i] = true;
                }
            }
        }
    }
    if(dp[(1 << n) - 1]) cout << "Takahashi\n";
    else cout << "Aoki\n";
}
