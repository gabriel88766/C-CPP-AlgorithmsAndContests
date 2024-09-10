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

struct SegmentTreeBeats { //1-based
    int n;
    vector<Node> T;
    SegmentTreeBeats(int n){
        this->n = n;
        vector<ll> val(n+1, 0);
        T.resize(4*(n+1));
        build(val, 1, n, 1);
    }
    SegmentTreeBeats(vector<ll> &val){ //val.size() >= 1
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

    void update_add(int i, int j, ll b, int l, int r, int p){ //ai -> ai + b
        
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

    void update_chmin(int i, int j, ll b, int l, int r, int p){ //ai -> min(ai, b)
        
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
        if(i > j) return;
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
        if(i > j) return;
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

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    int n;
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(2*n);
        build(v);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(2*n);
    }
    void build(vector<T> &v){
        for(int i=n;i<2*n;i++) st[i] = v[i-n];
        for(int i=n-1;i>=1;i--) st[i] = op(st[2*i], st[2*i+1]); //merge op
    }
    T query(int l, int r){
        T ans = nullel();
        l += n, r += n;
        while(l <= r){
            int no = l, c = 1;
            while(!(no & 1) && (r-l+1) >= (c << 1)){
                c <<= 1;
                no >>= 1;
            }
            ans = op(ans, st[no]); //merge op
            l += c;
        }
        return ans;
    }
    void update(int l, T val){
        l += n;
        st[l] = val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

int opmn(int a, int b){
    return min(a, b);
}

int elmn(){
    return INF_INT;
}


const int N = 2e5+3; 
int n, c;
// n log n
vector<int> suffix_array(string &s){
    s += "$";
    n = s.size(), c=-1;
    vector<int> mp(n), cnt(max(n+1, 256)), mp2(256), aux(n); 
    vector<pair<int,int>> cs(n); // class,class <int,int>

    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<256;i++){
        if(cnt[i]) mp2[i] = ++c;
        if(i) cnt[i] += cnt[i-1];
    } 
    for(int i=0;i<n;i++) mp[--cnt[s[i]]] = i; 
    for(int i=0;i<n;i++) cs[i].first = mp2[s[i]];

    for(int i=0;(1 << i) < n;i++){
        fill(cnt.begin(), cnt.begin() + c + 2, 0);
        int offset = 1 << i;
        for(int j=0;j<n;j++){
            int mindex = (j + offset) >= n ? j + offset - n : j + offset;
            cs[j].second = cs[mindex].first;
            cnt[cs[j].second + 1]++;
        }
        //begin raddix_sort of pair O(n)
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n; j++) aux[cnt[cs[j].second]++] = j;
        fill(cnt.begin(), cnt.begin() + c + 2, 0);
        for(int j=0; j<n; j++) cnt[cs[j].first+1]++; 
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n;j++) mp[cnt[cs[aux[j]].first]++] = aux[j]; 
        //end raddix_sort
        aux[mp[0]] = c = 0;
        for(int j=1;j<n;j++){
            if(cs[mp[j]] == cs[mp[j-1]]) aux[mp[j]] = c;
            else aux[mp[j]] = ++c;
        }
        for(int j=0;j<n;j++) cs[j].first = aux[j];
    }
    return mp;
}
//longest common prefix in O(n), between 2 consecutive indexes of suffix array
vector<int> lcp(string &s, vector<int> &sa){
    vector<int> ans(n - 1, 0);
    vector<int> invmp(n, 0);
    for(int i=0;i<n; i++) {invmp[sa[i]] = i;}
    int cnt = 0;
    for(int i=0;i < (n-1); i++){
        if(invmp[i] == (n-1)){
            cnt = 0;
            continue;
        }
        int j = sa[invmp[i] + 1];
        while (s[i+cnt] == s[j+cnt]) cnt++;
        ans[invmp[i]] = cnt;
        if (cnt) cnt--;
    }
    return ans;
}

int cnt[N];
int inv[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    auto sa = suffix_array(s);
    auto lc = lcp(s, sa);
    for(int i=1;i<sa.size();i++){
        sa[i] += 1;
        inv[sa[i]] = i;
    }
    lc.push_back(0);//append 0;
    SegmentTree<int, opmn, elmn> stm(lc);
    SegmentTreeBeats stb(n+1);
    for(int i=0;i<q;i++){
        ll ans = 0;
        int a, b;
        cin >> a >> b;
        vector<int> v1(a), v2(b);
        for(int i=0;i<a;i++){
            cin >> v1[i];
            cnt[v1[i]]++;
        }
        for(int i=0;i<b;i++){
             cin >> v2[i];
             cnt[v2[i]]++;
        }
        sort(v1.begin(), v1.end(), [&](int u, int v){
            return inv[u] < inv[v];
        });
        sort(v2.begin(), v2.end(), [&](int u, int v){
            return inv[u] < inv[v];
        });
        
        for(int i=0;i<a;i++){
            if(cnt[v1[i]] == 2) ans -= n - v1[i] + 1;
            cnt[v1[i]]--;
        }
        for(int i=0;i<b;i++){
            cnt[v2[i]]--;
        }  
        //first for each v1[i], chk sum v2[j], v2[j] > v1[i]
        stb.update_chmin(1, n, 0); //zero'd
        int p1 = b-1;
        int cn = n;
        for(int i=a-1;i>=0;i--){
            while(p1 >= 0 && inv[v2[p1]] >= inv[v1[i]]){
                stb.update_chmin(cn, n, stm.query(inv[v2[p1]], cn-1)); 
                cn = inv[v2[p1]];
                stb.update_chmax(cn, cn, n - v2[p1] + 1);
                p1--;
            }
            if(cn > inv[v1[i]]){
                stb.update_chmin(inv[v1[i]], n, stm.query(inv[v1[i]], cn-1));
                cn = inv[v1[i]];
            }
            ans += stb.query_sum(1, n);
        } 
        p1 = 0;
        cn = 0;
        stb.update_chmin(1, n, 0); //zero'd
        for(int i=0;i<a;i++){
            while(p1 < b && inv[v2[p1]] <= inv[v1[i]]){
                stb.update_chmin(1, cn, stm.query(cn, inv[v2[p1]] - 1)); 
                cn = inv[v2[p1]];
                stb.update_chmax(cn, cn, n - v2[p1] + 1);
                p1++;
            }
            if(cn < inv[v1[i]]){
                stb.update_chmin(1, cn, stm.query(cn, inv[v1[i]] - 1));
                cn = inv[v1[i]];
            }
            ans += stb.query_sum(1, n);
        } 




        cout << ans << "\n";

    }
}