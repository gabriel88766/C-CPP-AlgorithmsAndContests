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
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.assign(4*n, 0);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p] = lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] = lz[p]; // += increment = update
                lz[2 * p + 1] = lz[p];
            } 
            lz[p] = 0;
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
        if(i > j) return;
        update(i, j, val, 0, n-1, 1);
    }
    int find(int val, int l, int r, int p){
        push(l, r, p);
        if(l == r) return l;
        push(l, (l+r)/2, 2*p);
        push((l+r)/2+1, r, 2*p+1);
        if(st[2*p] > val){
            return find(val, l, (l + r)/2, 2 * p);
        }else{
            return find(val, (l + r)/2 + 1, r, 2 * p + 1);
        }
    }
    int find(int val){
        return find(val, 0, n-1, 1);
    }
};

int op(int a, int b){
    return max(a, b);
}

int el(){
    return -INF_INT;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int v0 = n;
        SegmentTreeLazy<int, op, el> st(n + m + 2);
        st.update(0, n, -INF_INT);
        st.update(n + m + 1, n + m + 1, INF_INT);
        //dp should always be in a non decreasing order
        vector<int> aux(n + m + 1, -1);
        for(int i=2;i<=n;i++){
            v0--;
            for(int j = i; j <= m; j += i){
                aux[j] = st.query(v0 + j, v0 + j);     
            }

            for(int j = i; j <= m; j += i){
                int aux2 = j;
                int nv = 0;
                while(aux2 % i == 0){
                    aux2 /= i;
                    nv++;
                }
                nv += aux[j];
                if(st.query(v0 + j, v0 + j) < nv){
                    int rg = st.find(nv) - 1; //find largest x such that st[x] <= nv;
                    st.update(v0 + j, rg, nv);
                }
            }
        }
        cout << st.query(v0, v0 + m) << "\n";

    }
}
