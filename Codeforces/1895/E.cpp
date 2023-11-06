#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> adj;
struct Interval{
    int l, r, def;
};
void bfs(int src, vector<bool> &rc){
    queue<int> q;
    q.push(src);
    rc[src] = true;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!rc[v]){
                rc[v] = true;
                q.push(v);
            }
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        vector<pair<int,int>> vp1(n);
        for(int i=0;i<n;i++) cin >> vp1[i].first;
        for(int i=0;i<n;i++) cin >> vp1[i].second;
        cin >> m;
        vector<pair<int,int>> vp2(m);
        for(int i=0;i<m;i++) cin >> vp2[i].first;
        for(int i=0;i<m;i++) cin >> vp2[i].second;
        sort(vp1.begin(), vp1.end());
        sort(vp2.begin(), vp2.end());
        vector<pair<int,int>> bd1, bd2;
        for(int i=0;i<n;i++){
            bd1.push_back({vp1[i].second, i});
        }
        for(int i=0;i<m;i++){
            bd2.push_back({vp2[i].second, i});
        }
        sort(bd1.begin(), bd1.end(), greater<pair<int,int>>());
        sort(bd2.begin(), bd2.end(), greater<pair<int,int>>());
        vector<Interval> v1, v2;
        int p = 0, beg = 1;
        while(p < n){
            int fin = vp1[bd1[p].second].first;
            if(fin >= beg){
                v1.push_back({beg, fin, bd1[p].first});
                beg = fin + 1;
            }
            p++;
        }
        v1.push_back({beg, INF_INT, 0});
        p = 0, beg = 1;
        while(p < m){
            int fin = vp2[bd2[p].second].first;
            if(fin >= beg){
                v2.push_back({beg, fin, bd2[p].first});
                beg = fin + 1;
            }
            p++;
        }
        v2.push_back({beg, INF_INT, 0});
        int w = 0, l = 0, d = 0;
        //graph v1.size()  x  v2.size()
        adj.assign(v1.size()+v2.size()+1, vector<int>());
        vector<bool> rc1(v1.size()+v2.size()+1, false);
        vector<bool> rc2(v1.size()+v2.size()+1, false);
        int nn = v1.size(), nm = v2.size();
        for(int i=0;i<v1.size()-1;i++){
            int a = i;
            int b = nm-1;
            for(int j=nm/2;j>=1;j>>=1){
                while(b-j >= 0 && v2[b-j].r > v1[a].def) b -= j;
            }
            adj[nn+b].push_back(a);
        }
        for(int i=0;i<v2.size()-1;i++){
            int a = nn-1;
            int b = i;
            for(int j=nn/2;j>=1;j>>=1){
                while(a-j >= 0 && v1[a-j].r > v2[i].def) a -= j;
            }
            adj[a].push_back(nn+b);
        }
        bfs(nn-1, rc1);
        bfs(nn + nm -1, rc2);
        for(int i=0;i<vp1.size();i++){
            int x = 0;
            //cout << vp1[i].second << " - ";
            for(int j=(nm)/2;j>=1;j>>=1){
                if(x + j < nm && v2[x+j].r <= vp1[i].second) x += j;
            }
            if(v2[x].r <= vp1[i].second) x++;
            //cout << x << " ";
            if(rc1[nn+x]) l++;
            else if(rc2[nn+x]) w++;
            else d++;
        }
        cout << w << " " << d << " " << l << "\n";
    }
}
