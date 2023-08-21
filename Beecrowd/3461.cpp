#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = (1 << 10);
int dist[N];
int p[N];
int ini;

vector<vector<int>> toggle = {{2,5}, {1,3,5,6}, {2,4,6,7}, {3,7}, {1,2,6,8}, {2,3,5,7,8,9}, {4,3,6,9}, {5,6,9,10}, {6,7,8,10}, {8,9}};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<10;i++){
        int aux;
        cin >> aux;
        if(aux) ini |= (1 << i);
    }
    memset(dist, 63, sizeof(dist));
    dist[ini] = 0;
    if(ini == ((1 << 10) -1)){cout << "0\n"; return 0;}
    queue<int> q;
    q.push(ini);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int i=0;i<10;i++){
            int next = u;
            for(auto x: toggle[i]){
                next ^= (1 << (x-1));
            }
            if(dist[next] > dist[u]+1){
                dist[next] = dist[u] + 1;
                p[next] = u;
                q.push(next);
            }
        }
    }
    int end = (1 << 10) - 1;
    if(dist[end] == INF_INT) cout << "-1\n";
    else{
        int cur = end;
        vector<int> ans;
        while(cur != ini){
            for(int i=0;i<10;i++){
                int old = p[cur];
                for(auto x: toggle[i]){
                    old ^= (1 << (x-1));
                }
                if(old == cur){
                    ans.push_back(i+1);
                    break;
                }
            }
            cur = p[cur];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(int i =0; i<ans.size();i++){
            cout << ans[i];
            if(i != (ans.size()-1)) cout << " ";
        }
        cout << "\n";
    }
}
