#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
bitset<N> bs[2001];
vector<int> adj[N];
int cnt = 0;
int ebs[N];
bool vis[N];
const int X = 100;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //Sum of degrees <= 2N = 200000
    //thus, there is at most 2000 nodes with degree >= 100
    //if degree < 100 for both, then brute force.
    // if one >= 100 other < 100, then brute force again, but using bitset
    //if both >= 100, do AND bitset (100000^2 / 32);
    int n, q;
    cin >> n >> q;
    int lx = 0;
    for(int i=1;i<=q;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        ll ra = a * (1 + lx);
        ra %= MOD;
        ra %= 2;
        ra += 1;
        ll rb = b * (1 + lx);
        rb %= MOD;
        rb %= n;
        rb += 1;
        ll rc = c * (1 + lx);
        rc %= MOD;
        rc %= n;
        rc += 1;
        if(ra == 1){
            adj[rb].push_back(rc);
            adj[rc].push_back(rb);
            if(adj[rb].size() == X){
                ebs[rb] = cnt++;
                for(auto x : adj[rb]) bs[ebs[rb]][x] = 1;
            }else if(adj[rb].size() > X){
                bs[ebs[rb]][rc] = 1;
            }
            if(adj[rc].size() == X){
                ebs[rc] = cnt++;
                for(auto x : adj[rc]) bs[ebs[rc]][x] = 1;
            }else if(adj[rc].size() > X){
                bs[ebs[rc]][rb] = 1;
            }
        }else{
            lx = 0;
            if(adj[rb].size() < X && adj[rc].size() < X){
                for(auto x : adj[rb]) vis[x] = true;
                for(auto x : adj[rc]){
                    if(vis[x]){
                        lx = x;
                    }
                }
                for(auto x : adj[rb]) vis[x] = false;
            }else if(adj[rb].size() >= X && adj[rc].size() >= X){
                auto xc = bs[ebs[rc]] & bs[ebs[rb]];
                if(xc.count() == 1) lx = xc._Find_first();
            }else{
                if(adj[rb].size() < adj[rc].size()) swap(rb, rc);
                for(auto x : adj[rc]){
                    if(bs[ebs[rb]][x]) lx = x;
                }
            }
            cout << lx << "\n";
        }
    }
}
