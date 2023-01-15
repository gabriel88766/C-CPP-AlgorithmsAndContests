#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 3e5+3;
int p[N], sz[N];

struct op{
    char type; //0 ask, 1 cut
    int u;
    int v;
};

void init(){
    for(int i=1;i<N;i++) {
        p[i] = i; sz[i] = 1;
    }
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    init();
    int n, m, k, aa, ab;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++) cin >> aa >> ab;
    vector<op> ops;
    for(int i=0;i<k;i++){
        string s;
        int a, b;
        cin >> s >> a >> b;
        if(s == "ask"){
            op newop = {0, a, b};
            ops.push_back(newop);
        }else{ //cut
            op newop = {1, a, b};
            ops.push_back(newop);
        }
    }
    reverse(ops.begin(), ops.end());
    vector<int> ans;
    for(auto opc : ops){
        if(opc.type == 0){
            int a, b;
            a = get(opc.u);
            b = get(opc.v);
            if(a != b) ans.push_back(0);
            else ans.push_back(1);
        }else{
            unite(opc.u, opc.v);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto c : ans){
        if(c) cout << "YES\n";
        else cout << "NO\n";
    }
}
