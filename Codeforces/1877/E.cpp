#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
set<int> in[N];
int vis[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        in[v[i]].insert(i);
    }
    set<int> s1, s2;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i].size() == 0){
             q.push(i);
        }
    }
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        s1.insert(u);
        auto x = v[u];
        s2.insert(x);
        auto dst = v[x];
        in[dst].erase(x);
        if(in[dst].size() == 0 && !s1.count(dst)){
            q.push(dst);
        }
    }
    //cycles
    bool ok = true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int cur = i;
            vector<int> path;
            while(!vis[cur]){
                path.push_back(cur);
                vis[cur] = 1;
                cur = v[cur];
            }
            if(vis[cur] == 1){
                vector<int> cycle;
                int curn = cur;
                do{
                    cycle.push_back(curn);
                    curn = v[curn];
                }while(curn != cur);
                //what sho i do with this s#!@#!!!?
                if(!s1.count(cur) && !s2.count(cur)){
                    if(cycle.size() % 2){
                        ok = false;
                        break;
                    }else{
                        for(int i=0;i<cycle.size();i++){
                            if(i% 2) s1.insert(cycle[i]);
                            else s2.insert(cycle[i]);
                        }
                    }
                }
            }
            for(auto x : path) vis[x] = 2;
        }
    }
    if(!ok) cout << "-1\n";
    else{
        cout << s1.size() << "\n";
        for(auto x : s1) cout << v[x] << " ";
        cout << "\n";
    }
}
