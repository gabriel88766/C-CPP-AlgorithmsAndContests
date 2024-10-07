#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, c;
    cin >> n >> c;
    vector<vector<int>> pos(N);
    vector<int> ps(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        pos[x].push_back(i);
        if(x == c) ps[i] = 1;
        ps[i] += ps[i-1];
    }
    int ans = ps[n];
    for(int i=1;i<N;i++){
        if(i == c) continue;
        if(pos[i].size()){
            int cur = 0, l = 0;
            for(int j=0;j<pos[i].size();j++){
                cur -= ps[pos[i][j]] - ps[l];
                l = pos[i][j];
                cur = max(cur, 0);
                cur++;
                ans = max(ans, ps[n] + cur);
            }
        }
    }
    cout << ans << "\n";
}
