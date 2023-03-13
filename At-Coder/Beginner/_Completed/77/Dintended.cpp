#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int d[100005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int K;
    cin >> K;
    deque<int> dq;
    dq.push_back(1);
    memset(d, 63, sizeof(d));
    d[1] = 1;
    while(!dq.empty()){
        int u = dq.front(); dq.pop_front();
        int v = (u + 1) % K;
        if(d[v] > d[u] + 1){
            dq.push_back(v);
            d[v] = d[u]+1;
        }
        v = (u*10) % K;
        if(d[v] > d[u]){
            dq.push_front(v);
            d[v] = d[u];
        }
    }
    cout << d[0];
}
