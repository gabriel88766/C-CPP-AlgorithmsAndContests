#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st;
    vector<array<int, 3>> lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, {0, 1, 2});
        build(v, 0, n-1, 1);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    array<int, 3> change(array<int, 3> &a, array<int, 3> &b){
        array<int, 3> nv;
        for(int j=0;j<=2;j++){
            nv[j] = b[a[j]];
        }
        return nv;
    }


    void push(int l, int r, int p){
        const array<int, 3> arr = {0, 1, 2};
        if(lz[p] != arr){ //0 can be assigned? change!
            auto nv = lz[p];
            T nde;
            for(int j=0;j<=2;j++){
                nde.c1[nv[j]] += st[p].c1[j];
                for(int k=0;k<=2;k++){
                    nde.c2[nv[j]][nv[k]] += st[p].c2[j][k];
                }
            }
            st[p] = nde;
            if(l != r){
                lz[2 * p] = change(lz[2*p], lz[p]); 
                lz[2 * p + 1] = change(lz[2*p+1], lz[p]);
            } 
            lz[p] = {0, 1, 2};
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
    void update(int i, int j, array<int, 3> val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, array<int, 3> val){
        update(i, j, val, 0, n-1, 1);
    }
};


struct Node{
    ll c1[3], c2[3][3];
    Node(int val){
        for(int j=0;j<=2;j++){
            c1[j] = 0;
            for(int k=0;k<=2;k++){
                c2[j][k] = 0;
            }
        }
        c1[val] = 1;
    }
    Node(){
        //all 0;
        for(int j=0;j<=2;j++){
            c1[j] = 0;
            for(int k=0;k<=2;k++){
                c2[j][k] = 0;
            }
        }
    }
};

Node op(Node a, Node b){
    Node ans;
    for(int i=0;i<=2;i++){
        ans.c1[i] = a.c1[i] + b.c1[i];
        for(int j=0;j<=2;j++){//meaningless i == j
            ans.c2[i][j] = a.c2[i][j] + b.c2[i][j] + a.c1[i] * b.c1[j];
        }
    }
    return ans;
}

Node el(){
    Node null;
    return null;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<Node> aux(n+1);
    for(int i=1;i<=n;i++) aux[i] = Node(v[i]);
    SegmentTreeLazy<Node, op, el> st(aux);
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int l, r;
            cin >> l >> r;
            auto nd = st.query(l, r);
            cout << nd.c2[2][0] + nd.c2[2][1] + nd.c2[1][0] << "\n";
        }else{
            int l, r, s, t, u;
            cin >> l >> r >> s >> t >> u;
            array<int, 3> ch;
            ch[0] = s, ch[1] = t, ch[2] = u;
            st.update(l, r, ch);
        }
    }
}
