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
    int t;
    cin >> t;
    while(t--){
        ll n, k, sx, sy, dx, dy;
        cin >> n >> k >> sx >> sy >> dx >> dy;
        ll d = abs(dx-sx) + abs(dy-sy);
        d *= k;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                ll px, py, qx, qy;
                ll rx1 = sx % n, ry1 = sy % n, rx2 = dx % n, ry2 = dy % n;
                px = sx, py = sy, qx = dx, qy = dy;
                if(i == 0) px -= rx1;
                if(i == 1) px += n - rx1;
                if(i == 2) py -= ry1;
                if(i == 3) py += n - ry1;
                if(j == 0) qx -= rx2;
                if(j == 1) qx += n - rx2;
                if(j == 2) qy -= ry2;
                if(j == 3) qy += n - ry2;

                ll cur = abs(dx - qx) + abs(dy - qy) + abs(sx - px) + abs(sy - py);
                cur *= k;
                if((qx % n) && (px % n) && (qx/n) == (px/n)){
                    ll op1 = min(n - (qx % n) + n - (px % n), qx % n + px % n)  + abs(py - qy);
                    ll op2 = abs(px - qx) + abs(py - qy) * k;
                    cur += min(op1, op2);
                }else if((qy % n) && (py % n) && (qy/n) == (py/n)){
                    ll op1 = min(n - (py % n) + n - (qy % n), py % n + qy % n) + abs(px - qx);
                    ll op2 = abs(py - qy) + abs(qx - px) * k;
                    cur += min(op1, op2);
                }else{
                    cur += abs(qx-px) + abs(qy-py);
                }
                d = min(d, cur);
            }
        }
        cout << d << "\n";
    }
}
