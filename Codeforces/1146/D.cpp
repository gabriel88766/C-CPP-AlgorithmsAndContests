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
    int a, b, m;
    cin >> m >> a >> b;
    ll ans = 0;
    vector<int> vis(a+b + 1, 0); //0 means not visited, 1 means visited but not marked, 2 means visited and marked
    vis[0] = 1;
    ll cur = 0;
    for(int i=0;i<=min(m, a + b); i++){
        queue<int> q;
        if(vis[i] == 1){
            q.push(i);
        }
        while(q.size()){
            auto u = q.front();
            q.pop();
            vis[u] = 2;
            cur++;
            if(u - b >= 0 && vis[u-b] == 0){
                vis[u-b] = 1;
                q.push(u - b); //it will be less than i anyway;
            }
            if(u + a <= a + b && vis[u + a] == 0){
                vis[u + a] = 1;
                if(u + a <= i) q.push(u + a);
            }
        }
        ans += cur;
    }
    int cv;
    for(int i=0;i<a;i++) vis[i] /= 2;
    int x = a + b + 1;
    while(x <= m && (x % a != m % a)){
        cur += vis[x % a];
        ans += cur;
        x++;
    }
    if(x <= m){
        cur += vis[x % a];
        ans += cur;
        x++;
    }
    cv = x % a;
    if(m >= x){
        ll nd = (m + 1 - x) / a;
        ll aux1 = 0, aux2 = 0;
        for(int i=cv;i<a;i++){
            aux2 += vis[i];
            aux1 += aux2;
        }
        for(int i=0;i<cv;i++){
            aux2 += vis[i];
            aux1 += aux2;
        }
        ans += aux1*nd;
        //now Arit prog.
        // a * (cur + cur + aux2 + cur + 2*aux2 + ... + cur + (nd - 1) * aux2);
        ll sum = 2*cur + (nd - 1) * aux2;
        sum *= nd;
        sum /= 2;
        sum *= a;
        ans += sum;
    }
    cout << ans << "\n";
    

}
