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
        ll n, m, x1, x2, y1, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;
        ll movl = min(x1-1, x2-1);
        ll movr = min(n-x1, n-x2);
        ll movd = min(m-y1, m-y2);
        ll movu = min(y1-1, y2-1);
        vector<ll> px(4), py(4);
        px[0] = x1 - movl, py[0] = y1 - movu;
        px[1] = x1 + movr, py[1] = y1 + movd;
        px[2] = x2 - movl, py[2] = y2 - movu;
        px[3] = x2 + movr, py[3] = y2 + movd;
 
        ll ans = n*m;
        ans -= (px[1]-px[0]+1)*(py[1]-py[0]+1);
        ans -= (px[3]-px[2]+1)*(py[3]-py[2]+1);
        if(x1 != x2 && y1 != y2){
            vector<pair<ll,ll>> psq1(4), psq2(4);
            int ind1 = -1, ind2 = -1;
            for(int i=0;i<4;i++){
                psq1[i] = {px[i%2], py[i/2]};
                psq2[i] = {px[2+i%2], py[2+i/2]};
                if(psq1[i].first >= px[2] && psq1[i].first <= px[3] && psq1[i].second >= py[2] && psq1[i].second <= py[3]) ind1 = i;
                if(psq2[i].first >= px[0] && psq2[i].first <= px[1] && psq2[i].second >= py[0] && psq2[i].second <= py[1]) ind2 = i;
            }
            if(ind1 != -1){
                ans += (abs(psq1[ind1].first - psq2[ind2].first)+1) * (abs(psq1[ind1].second - psq2[ind2].second)+1);
            }
        }else{
            if(x1 == x2) if(2*abs(y1-y2) < m) ans += (m-2*abs(y2-y1))*n;
            if(y1 == y2) if(2*abs(x1-x2) < n) ans += (n-2*abs(x2-x1))*m;
        }
        
        
        cout << ans << "\n";
    }
}