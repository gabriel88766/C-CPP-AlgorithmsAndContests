#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    int n;
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        build(v, 0, n-1, 1);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(4*n);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){st[p] = v[l]; return;}
        build(v, l, (l+r)/2, 2*p);
        build(v, (l+r)/2+1, r, 2*p+1);
        st[p] = op(st[2*p], st[2*p+1]);
    }
    T query(int i, int j, int l, int r, int p){
        if(j < l || i > r) return nullel(); 
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, T value, int l, int r, int p){
        if(i < l || i > r) return;
        if(l == r) {st[p] = value; return;}
        update(i, value, l, (l + r)/2, 2 * p);
        update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); //some operation
    }
    void update(int i, T value){
        update(i, value, 0, n-1, 1);
    }
    int find(int l, int r, int p, int ord){ //segtree op must be sum.
        if(l == r) return l;
        int m = (l + r)/2;
        if(st[2*p] >= ord) return find(l, m, 2*p, ord);
        else return find(m+1, r, 2*p+1, ord-st[2*p]);
    }
    int find(int ord){
        return find(0, n-1, 1, ord);
    }
};

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}

const int N = 3e6+5;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> primes;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            if(i >= 31622) primes.push_back(i);
        }
    }
}
bool vis[N];
bool rmv[N];
//between 1 and 3e6 we have 213415 primes greater than 31622
//at most 1 of each will be removed in each query
//then there will be at least 100000 unremoved primes.
//among these integer, find the Kth

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<int> aux(N, 1);
    SegmentTree<int, op, el> st(aux);
    sieve();
    int q;
    cin >> q;
    st.update(0, 0);
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        if(a < N && vis[a] == false){
            vis[a] = true;
            //remove all multiples of a
            for(int i=a;i<N;i+=a){
                if(!rmv[i]){
                    rmv[i] = true;
                    st.update(i, 0);
                }
            }
        }
        //find the bth number;
        cout << st.find(b) << "\n";
    }
}
