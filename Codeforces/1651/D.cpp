#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
map<pair<int,int>, int> dst;
map<pair<int,int>, pair<int,int>> par;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int,int>> ap(n);
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        cin >> ap[i].first >> ap[i].second;
        s.insert({ap[i].first, ap[i].second});
    }
    vector<pair<int,int>> pp;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            int cx = ap[i].first + dx[j];
            int cy = ap[i].second + dy[j];
            if(!s.count({cx, cy})) pp.push_back({cx, cy});
        }
    }
    //for each i, find nearest pp[j] for each ap[i]
    queue<pair<int,int>> q;
    for(int i=0;i<pp.size();i++){
        auto [x, y] = pp[i];
        for(int j=0;j<4;j++){
            int cx = x + dx[j];
            int cy = y + dy[j];
            if(s.count({cx, cy}) && (!dst.count({cx, cy}))){
                dst[{cx,cy}] = 1;
                par[{cx, cy}] = {x, y};
                q.push({cx, cy});
            }
        }
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int j=0;j<4;j++){
            int cx = x + dx[j];
            int cy = y + dy[j];
            if(s.count({cx, cy}) && (!dst.count({cx, cy}))){
                dst[{cx,cy}] = 1;
                par[{cx, cy}] = par[{x, y}];
                q.push({cx, cy});
            }
        }
    }
    for(int i=0;i<n;i++){
        auto [x, y] = ap[i];
        cout << par[{x, y}].first << " " << par[{x, y}].second << "\n";
    }
}
