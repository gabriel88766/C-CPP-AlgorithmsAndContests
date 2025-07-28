#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int gct[5001][5001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //precalc gcd Crazy...

    for(int d=1;d<=5000;d++){
        for(int i=d;i<=5000;i+=d){
            for(int j=d;j<=5000;j+=d){
                gct[i][j] = d;
            }
        }
    }
    
    int t;
    cin >> t;
    while(t--){
        int n, g = 0;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            g = gcd(g, v[i]);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(g == v[i]) cnt++;
        }
        if(cnt){
            cout << n - cnt << "\n";
        }else{
            int ans = n - 1;
            vector<int> av(n);
            for(int i=0;i<n;i++) av[i] = v[i] / g;
            vector<int> d(5001, INF_INT);
            queue<int> q;
            for(int i=0;i<n;i++){
                if(d[av[i]] == INF_INT){
                    d[av[i]] = 0;
                    q.push(av[i]);
                }
            }
            while(q.size()){
                int u = q.front();
                q.pop();
                for(auto x : av){
                    if(d[gct[x][u]] > d[u] + 1){
                        d[gct[x][u]] = d[u] + 1;
                        q.push(gct[x][u]);
                    }
                }
            }

            cout << n-1 + d[1] << "\n";
        }
    }
}
