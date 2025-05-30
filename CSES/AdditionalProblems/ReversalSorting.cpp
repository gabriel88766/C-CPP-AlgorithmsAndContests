#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//parent commented, but maybe it is right. need more tests!
struct nodeT{//1-indexed!
    ll val;
    int Hv;
    int sz;
    bool rev;
    nodeT *l, *r;
    nodeT *par;
    nodeT(int value){
        val = value;
        Hv = rng();
        l = nullptr;
        r = nullptr;
        par = nullptr;
        rev = false;
        sz = 1;
    }
};
typedef nodeT* pnode;
int getsz(pnode rt){
    return rt ? rt->sz : 0;
}

void upd_sz(pnode rt){
    if(rt) rt->sz = getsz(rt->l) + getsz(rt->r) + 1;
}

// need to reverse? range update? if not, remove this
void push (pnode it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}


void merge(pnode &rt, pnode l, pnode r){
    push(l), push(r);
    if(!l || !r) rt = r ? r : l;
    else if(l->Hv > r->Hv) merge(l->r, l->r, r), rt = l;
    else merge(r->l, l, r->l), rt = r;
    upd_sz(rt);
    if(rt->l) rt->l->par = rt;
    if(rt->r) rt->r->par = rt;
}

void split(pnode rt, pnode &l, pnode &r, int sz){
    push(rt);
    if(!rt) return void(l = r = nullptr);
    int szl = getsz(rt->l);
    if(szl >= sz){
        split(rt->l, l, rt->l, sz);
        r = rt;
    }else{
        split(rt->r, rt->r, r, sz - szl - 1);
        l = rt;
    }
    if(rt->l) rt->l->par = rt;
    if(rt->r) rt->r->par = rt;
    upd_sz(rt);
}


void reverse (pnode rt, int l, int r) {
    pnode t1, t2, t3;
    split (rt, t1, t2, l-1);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (rt, t1, t2);
    merge (rt, rt, t3);
}


// need par implemented
int get_pos(pnode rt){
    vector<pnode> path = {rt};
    while(rt->par != nullptr){
        assert(rt->par->l == rt || rt->par->r == rt);
        rt = rt->par;
        path.push_back(rt);
    }
    int ans = 0;
    for(int i=path.size()-1;i>=0;i--) push(path[i]);
    while(path.size()){
        pnode u = path.back();
        path.pop_back();
        if(path.size()){
            if(path.back() == u->r) {ans += 1 + getsz(u->l);}
        }else{
            ans += getsz(u->l) + 1;
        }
    }
    return ans;
}

const int N = 2e5+3;
pnode nds[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    pnode rt;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        nds[v[i]] = new nodeT(v[i]);
    }
    rt = nds[v[1]];
    for(int i=2;i<=n;i++){
        merge(rt, rt, nds[v[i]]);
    }
    vector<pair<int, int>> ans;
    for(int i=1;i<=n;i++){
        int pos = get_pos(nds[i]);
        if(pos == i) continue;
        else{
            ans.push_back({i, pos});
            reverse(rt, i, pos);
        }
    }
    cout << ans.size() << "\n";
    for(auto [a, b] : ans) cout << a << " " << b << "\n";

    // for(int i=1;i<=n;i++) delete nds[i]; //v[i] is a permutation of (1...n)
    
}
