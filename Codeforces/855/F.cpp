#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ll max_v = 1'000'000'000'001LL;
struct Node {
	ll sum;   // Sum tag
	ll max1;  // Max value
	ll max2;  // Second Max value
	ll maxc;  // Max value count
	ll min1;  // Min value
	ll min2;  // Second Min value
	ll minc;  // Min value count
	ll lazy;  // Lazy tag
};

struct SegmentTree { //1-based
    int n;
    vector<Node> T;
    SegmentTree(int n){
        this->n = n;
        vector<ll> val(n+1, 0);
        T.resize(4*(n+1));
        build(val, 1, n, 1);
    }
    SegmentTree(vector<ll> &val){ //val.size() >= 1
        n = val.size() - 1;
        T.resize(4*(n+1));
        build(val, 1, n, 1);
    }
    void merge(int p){
        T[p].sum = T[2*p].sum + T[2*p+1].sum;
        if(T[2*p].max1 == T[2*p+1].max1){
            T[p].max1 = T[2*p].max1;
            T[p].maxc = T[2*p].maxc + T[2*p+1].maxc;
            T[p].max2 = max(T[2*p].max2, T[2*p+1].max2);
        }else{
            if(T[2*p].max1 > T[2*p+1].max1){
                T[p].max1 = T[2*p].max1;
                T[p].maxc = T[2*p].maxc;
                T[p].max2 = max(T[2*p+1].max1, T[2*p].max2);
            }else{
                T[p].max1 = T[2*p+1].max1;
                T[p].maxc = T[2*p+1].maxc;
                T[p].max2 = max(T[2*p].max1, T[2*p+1].max2);
            }
        }
        if(T[2*p].min1 == T[2*p+1].min1){
            T[p].min1 = T[2*p].min1;
            T[p].minc = T[2*p].minc + T[2*p+1].minc;
            T[p].min2 = min(T[2*p].min2, T[2*p+1].min2);
        }else{
            if(T[2*p].min1 < T[2*p+1].min1){
                T[p].min1 = T[2*p].min1;
                T[p].minc = T[2*p].minc;
                T[p].min2 = min(T[2*p+1].min1, T[2*p].min2);
            }else{
                T[p].min1 = T[2*p+1].min1;
                T[p].minc = T[2*p+1].minc;
                T[p].min2 = min(T[2*p].min1, T[2*p+1].min2);
            }
        }
    }
    void build(vector<ll> &val, int l, int r, int p){
        T[p].lazy = 0;
        if(l == r){
            T[p].maxc = T[p].minc = 1;
            T[p].sum = T[p].max1 = T[p].min1 = val[l];
            T[p].max2 = -max_v; T[p].min2 = max_v;
            return;
        }
        build(val, l, (l+r)/2, 2*p);
        build(val, (l+r)/2+1, r, 2*p+1);
        merge(p);
    }


    

    void push_min(int l, int r, int p, ll b){
        if(b <= T[p].min1) return;
        T[p].sum += (b - T[p].min1)*T[p].minc;
        T[p].min1 =  b;
        if(l == r){
            T[p].max1 = T[p].min1;
        }else{
            if (b >= T[p].max1) {
			    T[p].max1 = b;
            } else if (b > T[p].max2) {
                T[p].max2 = b;
            }
        }
    }

    void push_max(int l, int r, int p, ll b){
        if(b >= T[p].max1) return;
        T[p].sum += (b - T[p].max1)*T[p].maxc;
        T[p].max1 =  b;
        if(l == r){
            T[p].min1 = T[p].max1;
        }else{
            if (b <= T[p].min1) {
			    T[p].min1 = b;
            } else if (b < T[p].min2) {
                T[p].min2 = b;
            }
        }
    }

    void push_add(int l, int r, int p, ll b){
        T[p].lazy += b;
        T[p].sum += (r - l + 1) * b;
        T[p].max1 += b;
        T[p].min1 += b;
        if(T[p].max2 != -max_v) T[p].max2 += b;
        if(T[p].min2 != max_v) T[p].min2 += b;
    }


    void push(int l, int r, int p){
        if(l == r) return;
    
        int m = (l + r)/2;
        push_add(l, m, 2*p, T[p].lazy);
        push_add(m + 1, r, 2*p+1, T[p].lazy);
        
        push_max(l, m, 2*p, T[p].max1);
        push_max(m+1, r, 2*p+1, T[p].max1);

        push_min(l, m, 2*p, T[p].min1);
        push_min(m+1, r, 2*p+1, T[p].min1);
        T[p].lazy = 0;
        
    }

    void update_add(int i, int j, ll b, int l, int r, int p){ //ai -> max(ai, b)
        
        if(j < l || i > r ) return;
        if(i <= l && r <= j){
            push_add(l, r, p, b);
            return;
        }
        push(l, r, p);
        int m = (l + r)/2;
        update_add(i, j, b, l, m, 2*p);
        update_add(i, j, b, m+1, r, 2*p+1);
        merge(p);
    }
    void update_add(int i, int j, ll b){
        update_add(i, j, b, 1, n, 1);
    }

    void update_chmin(int i, int j, ll b, int l, int r, int p){ //ai -> max(ai, b)
        
        if(j < l || i > r || b >= T[p].max1) return;
        if(i <= l && r <= j && b > T[p].max2){
            push_max(l, r, p, b);
            return;
        }
        push(l, r, p);
        int m = (l + r)/2;
        update_chmin(i, j, b, l, m, 2*p);
        update_chmin(i, j, b, m+1, r, 2*p+1);
        merge(p);
    }
    void update_chmin(int i, int j, ll b){
        update_chmin(i, j, b, 1, n, 1);
    }

    void update_chmax(int i, int j, ll b, int l, int r, int p){ //ai -> max(ai, b)
        
        if(j < l || i > r || b <= T[p].min1) return;
        if(i <= l && r <= j && b < T[p].min2){
            push_min(l, r, p, b);
            return;
        }
        push(l, r, p);
        int m = (l + r)/2;
        update_chmax(i, j, b, l, m, 2*p);
        update_chmax(i, j, b, m+1, r, 2*p+1);
        merge(p);
    }
    void update_chmax(int i, int j, ll b){
        update_chmax(i, j, b, 1, n, 1);
    }
    ll query_sum(int i, int j, int l, int r, int p){
        
        if(j < l || i > r) return 0; //identity element
        if(j >= r && i <= l) return T[p].sum;
        push(l, r, p);
        return query_sum(i, j, l, (l + r)/2, 2 * p) + query_sum(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
    }
    ll query_sum(int i, int j){
        return query_sum(i, j, 1, n, 1);
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n = 1e5+3, q;
    cin >> q;
    vector<ll> a(n+1, 0);
    SegmentTree st1(a), st2(a), st3(a);
    set<int> in1, in2;
    for(int i=1;i<=1e5;i++) in1.insert(i), in2.insert(i);
    for(int i=0;i<q;i++){
        int t, l, r;
        cin >> t >> l >> r;
        r--;
        if(t == 1){
            int k;
            cin >> k;
            if(k > 0){
                //update for l - r if not inited
                vector<int> rml;
                for(auto it = in1.lower_bound(l); it!=in1.end() && *it <= r; ++it){
                    st1.update_chmax(*it, *it, k);
                    if(in2.count(*it)) st3.update_chmax(*it, *it, k);
                    else st3.update_chmin(*it, *it, 0);
                    rml.push_back(*it);
                }
                for(auto x : rml) in1.erase(x);
                st1.update_chmin(l, r, k);
                st3.update_chmin(l, r, k);
            }else{
                k = abs(k);
                vector<int> rml;
                for(auto it = in2.lower_bound(l); it!=in2.end() && *it <= r; ++it){
                    st2.update_chmax(*it, *it, k);
                    if(in1.count(*it)) st3.update_chmax(*it, *it, k);
                    else st3.update_chmin(*it, *it, 0);
                    rml.push_back(*it);
                }
                for(auto x : rml) in2.erase(x);
                st2.update_chmin(l, r, k);
                st3.update_chmin(l, r, k);
            }
        }else{
            cout << st1.query_sum(l, r) + st2.query_sum(l, r) - st3.query_sum(l, r) << "\n";
        }
    }
}
