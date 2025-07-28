#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int d[9][9];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, ans = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> d[i][j];
        }
    }
    vector<int> perm;
    for(int i=2;i<=n;i++) perm.push_back(i);
    do{
        int cur = d[1][perm[0]] + d[perm.back()][1];
        for(int j=1;j<perm.size();j++){
            cur += d[perm[j-1]][perm[j]];
        }
        if(cur == k) ans++;
    }while(next_permutation(perm.begin(), perm.end()));
    cout << ans << "\n";
}
