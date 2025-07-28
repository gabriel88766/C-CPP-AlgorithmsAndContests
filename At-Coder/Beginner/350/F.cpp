#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//parent commented, but maybe it is right. need more tests! tested on Reversal Sorting
struct nodeT{//1-indexed!
    char val;
    int Hv;
    int sz;
    bool rev;
    nodeT *l, *r;
    // nodeT *par;
    nodeT(char value = '0'){
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


vector<char> ans;
void dfsbst(pnode rt){
    push(rt);
    if(rt->l) dfsbst(rt->l);
    ans.push_back(rt->val);
    if(rt->r) dfsbst(rt->r);
}

int cnt = 0;
pnode nds = new nodeT[500005];

void invert(char &c){
    if(c >= 'a' && c <= 'z') c += 'A' - 'a';
    else c += 'a' - 'A';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int cp = 0;
    stack<int> st;
    pnode rt = nullptr;
    for(auto &c : s){
        if(c != '(' && c != ')'){
            if(cp % 2){
                invert(c);
            }
            nds[++cnt].val = c; 
            if(rt == nullptr) rt = &nds[cnt];
            else{
                merge(rt, rt, &nds[cnt]);
            }
        }else if(c == '('){
            st.push(cnt+1);
            cp++;
        }else{
            if(cnt >= st.top()){
                assert(rt != nullptr);
                reverse(rt, st.top(), cnt);
            }
            st.pop();
            cp--;
        }
    }
    if(rt != nullptr){
        dfsbst(rt);
        for(auto x : ans) cout << x;
        cout << "\n";
    }
}