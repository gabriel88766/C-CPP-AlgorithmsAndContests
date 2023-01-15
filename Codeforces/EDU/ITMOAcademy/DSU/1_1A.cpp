#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 1e5+3;
int p[N], sz[N];
void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
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
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        string s;
        int a, b;
        cin >> s >> a >> b;
        if(s == "get"){
            a = get(a);
            b = get(b);
            if(a == b) cout << "YES\n";
            else cout << "NO\n";
        }else unite(a,b);
    }
}
