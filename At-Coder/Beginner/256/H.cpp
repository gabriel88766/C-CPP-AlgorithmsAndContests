#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st, lz;
    int n;
    SegmentTreeLazy(){}
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
        if(lz[p] != -1){ //0 can be assigned! so lz default = -1
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


struct SetIn{
    int n;
    SegmentTreeLazy<ll, op, el> st;
    set<tuple<int, int, int>> st2;
    SetIn(vector<ll> v){
        this->n = v.size() - 1;
        st = SegmentTreeLazy<ll, op, el>(v);
        for(int i=1;i<=n;i++){
            insert(i, i, v[i]);
        }
    }
    void insert(int l, int r, int v){
        st.update(l, r, v);
        auto it = st2.lower_bound({l, 0, 0});
        if(it != st2.begin() && get<1>(*prev(it)) >= l){
            auto [a, b, c] = *prev(it);
            st2.erase(prev(it));
            st2.insert({a, l-1, c});
            if(b > r) st2.insert({r+1, b, c});
        }
        it = st2.lower_bound({l, 0, 0});
        while(it != st2.end() && get<0>(*it) <= r){
            if(get<1>(*it) <= r){
                st2.erase(it);
                it = st2.lower_bound({l, 0, 0});
            }else{
                auto [a, b, c] = *it;
                st2.erase(it);
                st2.insert({r+1, b, c});
                break;
            }
        }
        it = st2.lower_bound({l, 0, 0});
        while(it != st2.begin() && get<2>(*prev(it)) == v){
            l =  get<0>(*prev(it));
            st2.erase(*prev(it));
            it = st2.lower_bound({l, 0, 0});
        }
        while(it != st2.end() && get<2>(*it) == v){
            r = get<1>(*it);
            st2.erase(it);
            it = st2.lower_bound({l, 0, 0});
        }
        st2.insert({l, r, v});
    }
    void divide(int l, int r, int v){
        vector<tuple<int, int, int>> ins;
        auto it = st2.lower_bound({l, 0, 0});
        if(it != st2.begin() && get<1>(*prev(it)) >= l){
            auto [a, b, c] = *prev(it);
            ins.emplace_back(l, min(b, r), c/v);
        }
        while(it != st2.end() && get<0>(*it) <= r){
            if(get<1>(*it) <= r){
                auto [a, b, c] = *it;
                ins.emplace_back(a, b, c/v);
                ++it;
            }else{
                auto [a, b, c] = *it;
                ins.emplace_back(a, r, c/v);
                break;
            }
        }
        for(auto [a, b, c] : ins) insert(a, b, c);
    }
    ll getsum(int l, int r){
        return st.query(l, r);
    }
    void printstate(){
        for(auto [a, b, c] : st2){
            cout << a << " " << b << " " << c << " - ";
        }
        cout << "\n";
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    SetIn s(v);
    for(int i=1;i<=q;i++){
        int tq, l, r, x;
        cin >> tq >> l >> r;
        if(tq == 1){
            cin >> x;
            s.divide(l, r, x);
        }else if(tq == 2){
            cin >> x;
            s.insert(l, r, x);
        }else{
            cout << s.getsum(l, r) << "\n";
        }
        // s.printstate();
    }
    
    
}
