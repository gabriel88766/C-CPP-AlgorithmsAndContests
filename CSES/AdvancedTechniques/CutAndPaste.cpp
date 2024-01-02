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
    int Hv;
    int sz;
    nodeT *l, *r;
    nodeT(int val){
        Bv = val;
        Hv = rng();
        l = nullptr;
        r = nullptr;
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
}




void merge(pnode &rt, pnode l, pnode r){
    if(!l || !r) rt = l ? l : r;
    else if(l->Hv > r->Hv) merge(l->r, l->r, r), rt = l;
    else merge(r->l, l, r->l), rt = r;
    upd_sz(rt);
}

void insertT(pnode &rt, pnode t){
    if(!rt) rt = t;
    else if(t->Hv > rt->Hv){
        split(rt, t->l, t->r, t->Bv);
        rt = t;
    }else insertT(t->Bv < rt->Bv ? rt->l : rt->r, t);
    upd_sz(rt);
}

void eraseT(pnode &rt, int val){
    if(!rt) return;
    else if(rt->Bv == val){
        pnode aux = rt;
        merge(rt, rt->l, rt->r);
        assert(aux != rt);
        delete aux; 
    }else eraseT(val < rt->Bv ? rt->l : rt->r, val);
    upd_sz(rt);
}

//Cut and Paste CSES
void split2(pnode rt, pnode &l, pnode &r, int sz){
    if(!rt) l = r = nullptr;
    int szl = getsz(rt->l);
    if(szl >= sz){
        split2(rt->l, l, rt->l, sz);
        r = rt;
    }else if((szl+1) == sz){
        l = rt->l;
        r = rt;
        r->l = nullptr;
    }else{
        split2(rt->r, rt->r, r, sz - szl - 1);
        l = rt;
    }
    upd_sz(rt);
}

void cut(pnode &rt, int lf, int ri){
    pnode l = nullptr, r = nullptr, l2 = nullptr, r2 = nullptr;
    if(lf == 1){
        if(ri != getsz(rt)){
            split2(rt, l, r, ri+1);
            merge(rt, r, l);
        }
    }else if(ri != getsz(rt)){
        split2(rt, l, r, lf);
        split2(r, l2, r2, ri-lf+2);
        merge(rt, l, r2);
        merge(rt, rt, l2);
    }
}

vector<int> ans;
void dfsbst(pnode rt){
    if(rt->l) dfsbst(rt->l);
    ans.push_back(rt->Bv);
    if(rt->r) dfsbst(rt->r);
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //freopen("out", "w", stdout); //test input
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
        cut(rt, a, b);
    }
    dfsbst(rt);
    for(auto x : ans) cout << s[x];
    //cout << cur << "\n";
}