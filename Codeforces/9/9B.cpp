#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    long double vb,vs,bt=1e18,x,y,mind=1e18;
    vector<long double> xs;
    int n, ans;
    cin >> n >> vb >> vs;
    for(int i=0;i<n;i++){
        cin >> x;
        xs.push_back(x);
    }
    cin >> x >> y;
    for(int i=1;i<n;i++){
        long double d = sqrtl((x-xs[i])*(x-xs[i])+y*y);
        long double curt = (xs[i]-0)/vb + d/vs;
        if(curt +EPS < bt){
            bt = curt;
            mind = d;
            ans = i+1;
        }else if(curt + EPS > bt && curt - EPS < bt){
            if(d + EPS < mind){
                bt = curt;
                mind = d;
                ans = i+1;
            }
        }
    }
    cout << ans;
}
