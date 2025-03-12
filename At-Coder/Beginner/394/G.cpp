#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 3e5+3;   
int p[N], sz[N], his[N];
int tim = 0;
bool vis[N];
void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int find(int a, int t){
    if(p[a] == a) return a; //his[a] = 0
    if(his[a] > t) return a;
    else return find(p[a], t);
}


void unite(int a, int b){
    ++tim;
    a = find(a, tim);
    b = find(b, tim);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    his[b] = tim; 
    sz[a] += sz[b];
}

int h, w;
int get(int i, int j){
    return w*(i-1) + j;
}
int cv[2000005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //here [i, j] = w*(i-1) + j
    cin >> h >> w;
    vector<tuple<int, int, int>> vt;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int val;
            cin >> val;
            vt.push_back({val, i, j});
        }
    }
    init();
    sort(vt.begin(), vt.end(), greater<tuple<int,int,int>>());
    for(auto [a, b, c] : vt){
        vis[get(b, c)] = true;
        for(int k=0;k<4;k++){
            int xd = dx[k] + b;
            int yd = dy[k] + c;
            if(xd > 0 && xd <= h && yd > 0 && yd <= w){
                if(vis[get(xd, yd)]){
                    unite(get(b, c), get(xd, yd));
                }
            }
            if(!cv[tim]) cv[tim] = a;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a, b, y, c, d, z;
        cin >> a >> b >> y >> c >> d >> z;
        if(a == c && b == d) cout << abs(z - y) << "\n";
        else{
            int lo = 1, hi = tim;
            while(lo != hi){
                int mid = lo + (hi - lo)/2;
                if(find(get(a, b), mid) == find(get(c, d), mid)) hi = mid;
                else lo = mid + 1;
            }
            int vx = cv[lo];
            int vy = min(z, y);
            if(vy >= vx) cout << abs(z-y) + 2*(vy - vx) << "\n";
            else cout << abs(z-y) << "\n";
        }
    }
}
