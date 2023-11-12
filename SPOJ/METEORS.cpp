#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+6;
ll bit[N];
int m;
 
ll query(int b){ // sum in range [1, b]
    ll ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    assert(ans >= 0);
    return ans;
}
 
void add(int b, ll value){ //add value to position b
    for(int i = b; i <= m; i += i & -i){
        bit[i] += value;
    }
}
void update(int l, int r, ll value){
    if(r < m) add(r+1, -value);
    add(l, value);
}

struct Query{
    int l, r, qt;
};

void add(Query q){
    if(q.r >= q.l) update(q.l, q.r, q.qt);
    else update(q.l, m, q.qt), update(1, q.r, q.qt);
}

void remove(Query q){
    q.qt = -q.qt;
    add(q);
}


vector<Query> vq;
vector<int> sec[N];
ll obj[N];
int ans[N];
int cur = 0;

void dc(vector<int> &ch, int l, int r){
    if(l == r){
        for(int i=0;i<ch.size();i++) ans[ch[i]] = l;
        return;
    }
    vector<int> v1, v2;
    int mid = (l + r) / 2;
    while(cur > mid) remove(vq[cur--]);
    while(cur < mid) add(vq[++cur]);
    for(auto x : ch){
        ll curv = 0;
        for(int j = 0; j < sec[x].size(); j++){
            curv += query(sec[x][j]);
            if(curv >= obj[x]) break;
        }
        if(curv >= obj[x]) v1.push_back(x);
        else v2.push_back(x);
    }
    if(v1.size()) dc(v1, l, mid);
    if(v2.size()) dc(v2, mid+1, r);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int st;
        cin >> st;
        sec[st].push_back(i);
    }
    for(int i=1;i<=n;i++) cin >> obj[i];
    int q;
    cin >> q;
    vq.resize(q+1);
    for(int i=1;i<=q;i++){
        cin >> vq[i].l >> vq[i].r >> vq[i].qt;
        add(vq[++cur]);
    }
    vector<int> ch;
    for(int i=1;i<=n;i++){
        ll curv = 0;
        for(int j=0;j<sec[i].size();j++){
            curv += query(sec[i][j]);
            if(curv >= obj[i]) break;
        }
        if(curv >= obj[i]) ch.push_back(i);
        else ans[i] = -1;
    }
    dc(ch, 1, q);
    for(int i=1;i<=n;i++){
        if(ans[i] != -1) cout << ans[i] << "\n";
        else cout << "NIE\n";
    }
}
