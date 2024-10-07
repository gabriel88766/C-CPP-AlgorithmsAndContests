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
    double ans = 1e19;
    int n, s, t;
    cin >> n >> s >> t;
    vector<vector<pair<int,int>>> v(n);
    for(int i=0;i<n;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i].push_back({a, b});
        v[i].push_back({c, d});
    }
    vector<int> perm;
    for(int i=0;i<n;i++) perm.push_back(i);
    do{
        for(int j=0;j<(1 << n);j++){
            double cur = 0;
            for(int k=0;k<n;k++){
                
                int bi = (j & (1 << k)) >> k;
                int pi = perm[k];
                if(k == 0){
                    double xx = v[pi][bi^1].first;
                    double yy = v[pi][bi^1].second;
                    cur += sqrt(xx*xx+yy*yy) / s;
                }
                int bn = -1;
                
                int pn = -1;
                if(k != n-1){
                    bn = (j & (1 << (k+1))) >> (k+1);
                    bn ^= 1;
                    pn = perm[k+1];
                }
                double xd = abs(v[pi][1].first - v[pi][0].first);
                double yd = abs(v[pi][1].second - v[pi][0].second);
                cur += sqrt(xd*xd + yd*yd) / t;
                if(bn != -1){
                    xd = abs(v[pn][bn].first - v[pi][bi].first);
                    yd = abs(v[pn][bn].second - v[pi][bi].second);
                    cur += sqrt(xd*xd + yd*yd) / s;
                } 
            }
            ans = min(ans, cur);
        }
    }while(next_permutation(perm.begin(), perm.end()));
    cout << fixed << setprecision(15) << ans << "\n";

}
