#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,-1,1};

const int N = 2e5+3;
int d[N], p[N];
vector<int> adj[N];

char grid[252][252], vis[252][252];

struct Coords{ //Another name to pair.
    int x, y;
    Coords (int x, int y){ this->x=x; this->y=y; }
};

bool operator< (Coords a, Coords b){
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

bool checkSide(vector<Coords> &v){
    if(v.size() < 4) return false;
    int minx = 250, miny = 250, maxx = 0, maxy = 0;
    for(auto x : v){
        minx = min(minx, x.x);
        miny = min(miny, x.y);
        maxx = max(maxx, x.x);
        maxy = max(maxy, x.y);
    }
    int qtmaxx = 0, qtmaxy = 0, qtminx = 0, qtminy = 0;
    for(auto x : v){
        if(minx == x.x) qtminx++;
        if(miny == x.y) qtminy++;
        if(maxx == x.x) qtmaxx++;
        if(maxy == x.y) qtmaxy++;
    }
    if(qtmaxx != qtmaxy) return false;
    if(qtmaxx != qtminx) return false;
    if(qtmaxy != qtminy) return false;
    if(4*(qtmaxx-1) != v.size()) return false;
    return true;

}

bool checkDiag(vector<Coords> &v){
    if(v.size() < 4) return false;
    int minx = 250, miny = 250, maxx = 0, maxy = 0;
    for(auto x : v){
        minx = min(minx, x.x);
        miny = min(miny, x.y);
        maxx = max(maxx, x.x);
        maxy = max(maxy, x.y);
    }
    if(((maxx - minx) != (maxy - miny)) || ((maxx-minx) % 2)) return false;
    int side = (maxx - minx)/2 + 1;
    if(4*(side-1) != v.size()) return false;
    set<Coords> sc(v.begin(), v.end());

    Coords ini = *sc.begin();
    for(int i=4;i<8;i++){
        for(int j=0;j<side-1;j++){
            Coords nxt = Coords(ini.x + dx[i], ini.y + dy[i]);
            if(!sc.count(nxt)) return false;
            ini = nxt;
        }
    }

    return true;
}

bool check(Coords src){
    queue<Coords> q;
    q.push(src); 
    vector<Coords> ans;
    vis[src.x][src.y] = true;
    while(!q.empty()){
        auto u = q.front();
        ans.push_back(u);
        q.pop();
        for(int i=0;i<8;i++){
            Coords v = Coords(u.x + dx[i], u.y + dy[i]);
            if(!vis[v.x][v.y] && grid[v.x][v.y] == '1'){
                q.push(v);
                vis[v.x][v.y] = true;
            }
        }
    }
    return (checkDiag(ans) || checkSide(ans));
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
        cin >> n >> m; 
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> grid[i][j];
        int ans = 0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(grid[i][j] == '1' && !vis[i][j]) if(check(Coords(i, j))) ans++;
        cout << ans << "\n";
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) grid[i][j] = 0, vis[i][j] = 0;
    }
}
