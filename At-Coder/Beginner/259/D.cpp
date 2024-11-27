#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool check(tuple<ll, ll, ll> circle, pair<int,int> point){
    auto [x, y, r] = circle;
    auto [a, b] = point;
    return (x-a)*(x-a) + (y-b)*(y-b) == r * r;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    pair<int,int> src, dst;
    cin >> src.first >> src.second >> dst.first >> dst.second;
    vector<tuple<ll,ll,ll>> vc(n+1);
    for(int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vc[i] = {a, b, c};
    }
    vector<bool> vis(n+1, false);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(check(vc[i], src)){
            q.push(i);
            vis[i] = true;
        }
    }
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int v=1;v<=n;v++){
            if(!vis[v]){
                //check intersection between u and v
                //conditions:
                //1-distance between centers less than or equal to sum of radius (square)
                //2-no inner circle
                auto [x1, y1, r1] = vc[u];
                auto [x2, y2, r2] = vc[v];
                if(r1 > r2){
                    swap(x1, x2); swap(y1, y2); swap(r1, r2);
                }
                ll dist = (x1-x2)*(x1-x2) + (y1-y2) * (y1-y2);
                if(dist <= (r1+r2) * (r1+r2)){
                    ll dr = (r2 - r1) * (r2 - r1);
                    if(dist >= dr){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }
    bool ok = false;
    for(int i=1;i<=n;i++){
        if(vis[i] && check(vc[i], dst)) ok = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
