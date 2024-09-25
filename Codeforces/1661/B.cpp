#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 32768;
vector<int> adj[N];
int d[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<N;i++){
        adj[(i+1)%N].push_back(i);
        adj[(2*i)%N].push_back(i);
    }
    memset(d, 63, sizeof(d));
    queue<int> q;
    q.push(0);
    d[0] = 0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        cout << d[x] << " ";
    }
}
