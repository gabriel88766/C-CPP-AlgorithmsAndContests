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
    //freopen("in", "r", stdin); //test input
    int N, K;
    cin >> N >> K;
    ll ans = INF_LL;
    vector<int> sx, sy;
    vector<pair<int,int>> p;
    for(int i=1;i<=N;i++){
        int a,b;
        cin >> a >> b;
        sx.push_back(a);
        sy.push_back(b);
        p.push_back({a,b});
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int u=0;u<N;u++){
                for(int w=u+1;w<N;w++){
                    ll cur = abs(sx[i] - sx[j]);
                    cur *= abs(sy[u] - sy[w]);
                    int maxx = max(sx[i], sx[j]);
                    int minx = min(sx[i], sx[j]);
                    int maxy = max(sy[u], sy[w]);
                    int miny = min(sy[u], sy[w]);
                    int cnt = 0;
                    for(int i=0;i<N;i++){
                        if(p[i].first <= maxx && p[i].first >= minx && p[i].second <= maxy && p[i].second >= miny) cnt++;
                    }
                    if(cnt >= K) ans = min(ans, cur);
                }
            }
        }
    }
    cout << ans;
}
