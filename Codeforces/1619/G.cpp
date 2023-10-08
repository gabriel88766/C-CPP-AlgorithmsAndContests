#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N], ti[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    ti[a] = min(ti[a], ti[b]);
}

struct Mine{
    ll x, y, t;
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll k;
        int n;
        cin >> n >> k;
        init(n);
        vector<Mine> v(n+1);
        map<int, vector<int>> mpx, mpy;
        set<int> vx, vy;
        for(int i=1;i<=n;i++){
            cin >> v[i].x >> v[i].y >> v[i].t;
            mpx[v[i].x].push_back(i);
            mpy[v[i].y].push_back(i);
            vx.insert(v[i].x);
            vy.insert(v[i].y);
            ti[i] = v[i].t;
        }
        for(auto x : vx){
            auto vec = mpx[x];
            sort(vec.begin(), vec.end(), [&v](int i, int j) {return v[i].y < v[j].y;});
            for(int i=1;i<vec.size(); i++){
                if(v[vec[i]].y - v[vec[i-1]].y <= k) unite(vec[i], vec[i-1]);
            }
        }
        for(auto x : vy){
            auto vec = mpy[x];
            sort(vec.begin(), vec.end(), [&v](int i, int j) {return v[i].x < v[j].x;});
            for(int i=1;i<vec.size(); i++){
                if(v[vec[i]].x - v[vec[i-1]].x <= k) unite(vec[i], vec[i-1]);
            }
        }
        vector<int> tis;
        set<int> comp;
        for(int i=1;i<=n;i++){
            if(!comp.count(get(i))){
                tis.push_back(ti[get(i)]);
                comp.insert(get(i));
            }
        }
        sort(tis.begin(), tis.end(), greater<int>());
        for(int i=0;i<tis.size();i++){
            if(i+1 == tis.size()){
                cout << i << "\n";
            }else if(tis[i+1] <= i){
                cout << i << "\n";
                break;
            }
        }
        
    
    }
}
