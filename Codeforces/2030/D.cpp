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

int opmx(int a, int b){
    return max(a, b);
}

int elmx(){
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
        int n, q;
        cin >> n >> q;
        vector<int> p(n+1);
        for(int i=1;i<=n;i++) cin >> p[i];
        SegmentTree<int, opmn, elmn> smn(p);
        SegmentTree<int, opmx, elmx> smx(p);
        string s;
        cin >> s;
        s = " " + s;
        set<pair<int,int>> in;
        int fr = 1;
        for(int i=1;i<=n;i++){
            if(s[i] == 'L' && s[i+1] == 'R'){
                in.insert({fr, i});
                fr = i+1;
            }
        }
        in.insert({fr, n});
        int cnt = 0;
        auto check = [&](int l, int r){
            if(smn.query(l, r) == l && smx.query(l, r) == r) return 0;
            else return 1;
        };
        for(auto [a, b] : in){
            cnt += check(a, b);
        }
        for(int i=0;i<q;i++){
            int x;
            cin >> x;
            if(s[x] == 'L') s[x] = 'R';
            else s[x] = 'L';

            auto [l, r] = *prev(in.lower_bound({x+1, 0}));
            in.erase({l, r});
            cnt -= check(l, r);
            if(x == l){
                //then R -> L
                auto [l2, r2] = *prev(in.lower_bound({x, 0}));
                cnt -= check(l2, r2);
                in.erase({l2, r2});
                if(s[x+1] == 'L'){
                    cnt += check(l2, r);
                    in.insert({l2, r});
                }else{
                    cnt += check(l2, x) + check(x+1, r);
                    in.insert({l2, x});
                    in.insert({x+1, r});
                }
            }else if(x == r){
                //then L -> R
                auto [l2, r2] = *in.lower_bound({x, 0});
                cnt -= check(l2, r2);
                in.erase({l2, r2});
                if(s[x-1] == 'R'){
                    cnt += check(l, r2);
                    in.insert({l, r2});
                }else{  
                    cnt += check(l, x-1) + check(x, r2);
                    in.insert({l, x-1});
                    in.insert({x, r2});
                }
            }else{
                if(s[x-1] == 'R' && s[x+1] == 'L'){
                    cnt += check(l, r);
                    in.insert({l, r});
                }else{
                    if(s[x-1] == 'L' && s[x] == 'R'){
                        cnt += check(l, x-1) + check(x, r);
                        in.insert({l, x-1});
                        in.insert({x, r});
                    }else{
                        assert(s[x] == 'L' && s[x+1] == 'R');
                        cnt += check(l, x) + check(x+1, r);
                        in.insert({l, x});
                        in.insert({x+1, r});
                    }
                }
            }
            if(cnt == 0) cout << "YES\n";
            else cout << "NO\n";

        }
    }
}
