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
        int n, ax, ay, bx, by;
        cin >> n >> ax >> ay >> bx >> by;
        ll aux = bx - ax;
        map<int, int> mpmn, mpmx;
        mpmn[ax] = mpmx[ax] = ay;
        mpmn[bx] = mpmx[bx] = by;
        vector<int> cds = {ax, bx};
        vector<int> vx(n+1);
        for(int i=1;i<=n;i++){
            cin >> vx[i];
            cds.push_back(vx[i]);
        }
        sort(cds.begin(), cds.end());
        cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
        for(int i=1;i<=n;i++){
            int y;
            cin >> y;
            if(!mpmn.count(vx[i])) mpmn[vx[i]] = y;
            else mpmn[vx[i]] = min(mpmn[vx[i]], y);
            if(!mpmx.count(vx[i])) mpmx[vx[i]] = y;
            else mpmx[vx[i]] = max(mpmx[vx[i]], y);
        }
        ll ymn = ay, ymx = ay;
        ll dpmn = 0, dpmx = 0;
        for(auto x : cds){
            if(x == ax) continue;
            ll ndpmx = INF_LL, ndpmn = INF_LL;
            ll nymn = mpmn[x], nymx = mpmx[x];
            //from dpmn
            ndpmx = min(ndpmx, dpmn + abs(nymn - ymn) + abs(nymx - nymn));
            ndpmn = min(ndpmn, dpmn + abs(nymx - ymn) + abs(nymn - nymx));
            //from dpmx
            ndpmx = min(ndpmx, dpmx + abs(nymn - ymx) + abs(nymx - nymn));
            ndpmn = min(ndpmn, dpmx + abs(nymx - ymx) + abs(nymn - nymx));


            dpmn = ndpmn;
            dpmx = ndpmx;
            ymn = nymn;
            ymx = nymx;
        }

        cout << aux + dpmn << "\n";
    }
}
