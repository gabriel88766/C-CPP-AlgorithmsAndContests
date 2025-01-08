#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll gr[505][505];
bool vis[505][505];
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll h, w;
    ll X;
    ll p, q;
    cin >> h >> w >> X >> p >> q;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    ll sz = 0;
    queue<pair<ll,ll>> qx; //process queue
    qx.push({p, q});
    vis[p][q] = true;
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
    while(!qx.empty()){
        auto [x, y] = qx.front();
        qx.pop();
        sz += gr[x][y];
        for(int i=0;i<4;i++){
            ll xd = x + dx[i];
            ll yd = y + dy[i];
            if(xd > 0 && xd <= h && yd > 0 && yd <= w){
                if(!vis[xd][yd]){
                    pq.push({gr[xd][yd], xd, yd});
                    vis[xd][yd] = true;
                }
            }
        }
        while(pq.size() && (sz-1)/X >= get<0>(pq.top())){
            auto [a, b, c] = pq.top();
            pq.pop();
            qx.push({b, c});
        }
    }
    cout << sz << "\n";
}
