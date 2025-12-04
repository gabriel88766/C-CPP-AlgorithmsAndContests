#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 30;
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

int op(int a, int b){
    return max(a, b);
}

int el(){
    return 0;
}


int ps[200005];
struct Trie{
    vector<pair<int, int>> trie;
    vector<int> nums;
    int cnt;
    Trie(){
        cnt = 0;
        trie.push_back({0, 0});
    }
    void insert(int num){
        int cur = 0;
        int ccn = cnt;
        for(int j=M-1;j>=0;j--){
            int l = (num & (1 << j));
            if(l){
                if(!trie[cur].second) {trie[cur].second = ++cnt; trie.push_back({0, 0});} 
                cur = trie[cur].second;
            }else{
                if(!trie[cur].first) {trie[cur].first = ++cnt; trie.push_back({0, 0});}
                cur = trie[cur].first;
            }
        }
        if(ccn != cnt) nums.push_back(num);
    }
    int maxxor(int num){
        int cur = 0;
        int key = 0;
        for(int i=M-1;i>=0;i--){
            int b = (num & (1 << i));
            if(b){
                if(trie[cur].first){
                    cur = trie[cur].first;
                }else{
                    cur = trie[cur].second;
                    key ^= (1 << i);
                }
            }else{
                if(trie[cur].second){
                    cur = trie[cur].second;
                    key ^= (1 << i);
                }else{
                    cur = trie[cur].first;
                }
            }
        }
        return key ^ num;
    }
    void clear(){
        trie.clear();
        nums.clear();
        trie.push_back({0, 0});
        cnt = 0;
    }
};

int cn = 0;
Trie tr[1000000];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        vector<int> v(n+1);
        map<int, set<int>> mp;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            mp[v[i]].insert(i);
            ps[i] = ps[i-1] ^ v[i];
        }
        SegmentTree<int, op, el> st(v);
        
        function<Trie *(int, int)> solve = [&](int l, int r){
            if(l >= r){ 
                tr[cn].insert(ps[l-1]);
                tr[cn].insert(ps[r]); //maybe r is l-1;
                return &tr[cn++];
            }
            int mx = st.query(l, r);
            int m = *mp[mx].lower_bound(l);
            auto x1 = solve(l, m - 1); // [l-1, m-1]
            auto x2 = solve(m+1, r); // [m, r];
            if(x1->nums.size() < x2->nums.size()){
                swap(x1->cnt, x2->cnt);
                x1->nums.swap(x2->nums);
                x1->trie.swap(x2->trie);
            }
            for(auto x : x2->nums){
                ans = max(ans, x1->maxxor(x ^ mx));
            }
            for(auto x : x2->nums){
                x1->insert(x);
            }

            return x1;
        };
        solve(1, n);
        cout << ans << "\n";

        for(int i=1;i<=n;i++) tr[i].clear();
    }
}
