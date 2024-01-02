#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct nodeT{
    int Bv;
    ll sum;
    ll val;
    int Hv;
    int sz;
    bool rev;
    nodeT *l, *r;
    nodeT(int index, int value){
        Bv = index;
        sum = value;
        val = value;
        Hv = rng();
        l = nullptr;
        r = nullptr;
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

ll getsum(pnode rt){
    return rt ? rt->sum : 0LL;
}

void updsum(pnode rt){
    if(rt) rt->sum = getsum(rt->l) + getsum(rt->r) + rt->val;
}

void split(pnode rt, pnode &l, pnode &r, int val){
    if(!rt) l = r = nullptr;
    else if(val >= rt->Bv){
        split(rt->r, rt->r, r, val);
        l = rt;
    }else{
        split(rt->l, l, rt->l, val);
        r = rt;
    }
    upd_sz(rt);
    updsum(rt);
}

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
    updsum(rt);
}

void insertT(pnode &rt, pnode t){
    if(!rt) rt = t;
    else if(t->Hv > rt->Hv){
        split(rt, t->l, t->r, t->Bv);
        rt = t;
    }else insertT(t->Bv < rt->Bv ? rt->l : rt->r, t);
    upd_sz(rt);
    updsum(rt);
}

void eraseT(pnode &rt, int val){
    if(!rt) return;
    else if(rt->Bv == val){
        pnode aux = rt;
        merge(rt, rt->l, rt->r);
        delete aux; 
    }else eraseT(val < rt->Bv ? rt->l : rt->r, val);
    upd_sz(rt);
    updsum(rt);
}

//Cut and Paste CSES
//implicit treap!
void split2(pnode rt, pnode &l, pnode &r, int sz){
    push(rt);
    if(!rt) return void(l = r = nullptr);
    int szl = getsz(rt->l);
    if(szl >= sz){
        split2(rt->l, l, rt->l, sz);
        r = rt;
    }else{
        split2(rt->r, rt->r, r, sz - szl - 1);
        l = rt;
    }
    upd_sz(rt);
    updsum(rt);
}

//cut l, r and insert in end
void cut(pnode &rt, int l, int r){
    pnode t1, t2, t3;
    split2(rt, t1, t2, l-1);
    split2(t2, t2, t3, r-l+1);
    merge(rt, t1, t3);
    merge(rt, rt, t2);
}

void reverse (pnode rt, int l, int r) {
    pnode t1, t2, t3;
    split2 (rt, t1, t2, l-1);
    split2 (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (rt, t1, t2);
    merge (rt, rt, t3);
}

ll getsum(pnode rt, int l, int r){
    pnode t1, t2, t3;
    split2 (rt, t1, t2, l-1);
    split2 (t2, t2, t3, r-l+1);
    ll ans = getsum(t2);
    merge(rt, t1, t2);
    merge(rt, rt, t3);
    return ans;
}

vector<int> ans;
void dfsbst(pnode rt){
    push(rt);
    if(rt->l) dfsbst(rt->l);
    ans.push_back(rt->Bv);
    if(rt->r) dfsbst(rt->r);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    pnode rt = nullptr;
    for(int i=1;i<=n;i++){
        pnode nn = new nodeT(i);
        insertT(rt, nn);
    }
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        cut(rt, a, b); //or reverse!
    }
    dfsbst(rt);
    for(auto x : ans) cout << s[x];
    //cout << cur << "\n";
}