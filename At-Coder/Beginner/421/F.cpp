#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


struct LinkedList{
    LinkedList *prev, *next;
    int val;
    LinkedList(){}
    LinkedList(int num){
        val = num;
        prev = nullptr;
        next = nullptr;
    }
    void insertRight(LinkedList *r){
        if(this->next != nullptr){
            this->next->prev = r;
            r->next = this->next;
        }
        r->prev = this;
        this->next = r;
    }
    void insertLeft(LinkedList *l){
        if(this->prev != nullptr){
            l->prev = this->prev;
            this->prev->next = l;
        }
        this->prev = l;
        l->next = this;
    }
};

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st, lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, -1);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.assign(4*n, -1);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != -1){ //0 can be assigned? change!
            st[p] = (ll)(r - l + 1) * lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] = lz[p]; // += increment = update
                lz[2 * p + 1] = lz[p];
            } 
            lz[p] = -1;
        }
    }

    T query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, T val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, T val){
        update(i, j, val, 0, n-1, 1);
    }
};

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0LL;
}


const int N = 5e5+3;
LinkedList lk[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    lk[0] = 0;
    //first process only 1
    int q;
    cin >> q;
    vector<vector<int>> aq(q+1);
    vector<int> pos(q+1);
    for(int i=1;i<=q;i++){
        vector<int> cv;
        int x;
        cin >> x;
        cv.push_back(x);
        if(x == 1){
            int v;
            cin >> v;
            cv.push_back(v);
            lk[i] = i;
            lk[v].insertRight(&lk[i]);
        }else{
            int a, b;
            cin >> a >> b;
            cv.push_back(a);
            cv.push_back(b);
        }
        aq[i] = cv;
    }
    LinkedList *rt = &lk[0];
    while(rt->prev != nullptr) rt = rt->prev;
    int cp = 0;
    pos[rt->val] = cp;
    while(rt->next != nullptr){
        rt = rt->next;
        pos[rt->val] = ++cp;
    }
    SegmentTreeLazy<ll, op, el> st(cp+1);
    for(int i=1;i<=q;i++){
        auto &v = aq[i];
        if(v[0] == 1){
            int x = pos[i];
            st.update(x, x, i);
        }else{
            int x = v[1], y = v[2];
            int px = min(pos[x], pos[y]), py = max(pos[x], pos[y]);
            if(py != px + 1){
                cout << st.query(px+1, py-1) << "\n";
                st.update(px+1,py-1, 0);
            }else cout << "0\n";
        }
    }

}
