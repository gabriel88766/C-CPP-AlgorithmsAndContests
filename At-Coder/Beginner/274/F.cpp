#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
int w[N], x[N], v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, a;
    cin >> n >> a;
    for(int i=1;i<=n;i++){
        cin >> w[i] >> x[i] >> v[i]; 
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        vector<pair<double, int>> vdd;
        for(int j=1;j<=n;j++){
            int vel = v[j] - v[i];
            int s = x[j] - x[i];
            if(s > a && vel >= 0);//impossible situation 1.
            else if(s < 0 && vel <= 0); //impossible situation 2.
            else{
                double in, out;
                if(s < 0){
                    in = abs(s);
                    in /= vel;
                    out = abs(s) + a;
                    out /= vel;
                }else if(s > a){
                    in = s - a;
                    in /= abs(vel);
                    out = s;
                    out /= abs(vel);
                }else{
                    //i'm already in;
                    in = 0;
                    if(vel < 0){
                        out = s;
                        out /= abs(vel);
                    }else if(vel > 0){
                        out = (a-s);
                        out /= vel;
                    }else{
                        out = 1e18;
                    }
                }
                vdd.push_back({in, w[j]});
                vdd.push_back({out + 0.000001, -w[j]});
            }
        }
        sort(vdd.begin(), vdd.end());
        int cw = 0;
        for(auto [a, b] : vdd){
            cw += b;
            ans = max(ans, cw);
        }
    }
    cout << ans << "\n";
}
