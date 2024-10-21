#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
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
    nodeT *l, *r;
    nodeT(int index, int value){
        Bv = index;
        sum = value;
        val = value;
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


void merge(pnode &rt, pnode l, pnode r){
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



void split2(pnode rt, pnode &l, pnode &r, int sz){
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

ll getsum(pnode rt, int l, int r){
    pnode t1, t2, t3;
    split2 (rt, t1, t2, l-1);
    split2 (t2, t2, t3, r-l+1);
    ll ans = getsum(t2);
    merge(rt, t1, t2);
    merge(rt, rt, t3);
    return ans;
}

void split3(pnode rt, pnode &l, pnode &r, ll sum){
    int rr = 1;
    for(int k=getsz(rt)/2;k>=1;k>>=1){
        while(rr + k <= getsz(rt) && getsum(rt, 1, rr+k) <= sum) rr += k;
    }
    if(getsum(rt, 1, 1) > sum){
        assert(rr == 1);
        rr--;
    }
    split2(rt, l, r, rr);
}

vector<int> ansv;
void dfsbst(pnode rt){
    if(rt->l) dfsbst(rt->l);
    ansv.push_back(rt->val);
    if(rt->r) dfsbst(rt->r);
}

void sub(pnode rt, ll val){
    if(rt->l != nullptr) sub(rt->l, val);
    else rt->val -= val;
    upd_sz(rt);
    updsum(rt);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    freopen("in.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n, g;
        cin >> n >> g;
        // vector<int> v(n);
        ll lv;
        pnode rt = nullptr;
        for(int i=1;i<=n;i++){
            ll cur;
            cin >> cur;
            if(i == 1){
                lv = cur;
            }else{
                if(cur < lv){
                    ll dif = lv - cur - 1;
                    lv = cur;
                    pnode nn = new nodeT(i, dif);
                    pnode l, r;
                    split3(rt, l, r, -1);
                    merge(rt, l, nn);
                    merge(rt, rt, r);
                }else{
                    lv = lv - 1;
                    ll dif = cur - lv;
                    pnode l, r;
                    split3(rt, l, r, dif);
                    ll val = dif - getsum(l);
                    pnode nn = new nodeT(i, val);
                    if(r != nullptr){
                        pnode xr = r;
                        sub(xr, val);
                    }
                    merge(rt, l, nn);
                    merge(rt, rt, r);
                }
            }
        }
        vector<ll> v = {lv};
        dfsbst(rt);
        for(auto x : ansv){
            assert(x >= 0);
            v.push_back(v.back() + x + 1);
        }
        
        
        
        
        
        
        //after finding the vector, I can solve like D1
        sort(v.begin(), v.end(), greater<ll>());
        //for(auto x : v) cout << x << " ";
        //cout << "\n";
        // cout << lv << "\n";
        ll ans = -1, minv = INF_LL;
        for(int i=0;i<n;i++){
            if(abs(v[i] - g) < minv){
                minv = abs(v[i] - g);
                ans = i+1;
            }
        }
        cout << "Case #" << i << ": " << ans << " " << minv << endl;

        ansv.clear();
    }
}
