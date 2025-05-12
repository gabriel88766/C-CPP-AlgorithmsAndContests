#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+3;   
int p[N], sz[N];

void init(){
    for(int i=0;i<N;i++) {p[i] = i; sz[i] = 1;}
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
}

struct Edge{
    int a, b, w;
    bool operator< (Edge v){
        if(w != v.w) return w < v.w;
        else return make_pair(a,b) < make_pair(v.a,v.b);
    }
};

vector<Edge> edges;
ll tw = 0;

void kruskal(){
    sort(edges.begin(), edges.end());
    init();
    for(auto e : edges){
        if(get(e.a) != get(e.b)){
            unite(e.a, e.b);
            tw += e.w;
        }
    }
}

vector<string> split(string s, char c){
    string cs = "";
    vector<string> ans;
    for(auto &x : s){
        if(x == c){
            ans.push_back(cs);
            cs = "";
        }else cs += x;
    }
    ans.push_back(cs);
    return ans;
}
int adj1[40][40];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in", "r", stdin); //test input
    string s;
    int cr = 0;
    memset(adj1, 0xFF, sizeof(adj1));
    while(getline(cin, s)){
        auto v = split(s, ',');
        for(int j=0;j<v.size();j++){
            if(v[j] != "-") adj1[cr][j] = stoi(v[j]);
        }
        cr++;
    }
    ll fw = 0;
    for(int i=0;i<40;i++){
        for(int j=i+1;j<40;j++){
            if(adj1[i][j] != -1){
                fw += adj1[i][j];
                edges.push_back({i, j, adj1[i][j]});
            }
        }
    }
    cout << fw << " " << tw << "\n";
    kruskal();
    cout << fw - tw << "\n";

}
