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
    int n, m;
    vector<int> ans;
    init();
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        unite(a,b);
    }
    for(int i=2;i<=n;i++){
        int a,b;
        a = get(i-1);
        b = get(i);
        if(a != b){
            ans.push_back(i-1);
            unite(i, i-1);
        }
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) cout << ans[i] << " " << ans[i]+1 << "\n";
}
