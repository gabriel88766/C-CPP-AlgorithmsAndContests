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
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        set<int> s;
        for(int i=0;i<n;i++) s.insert(i);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            v[i] = {x, i};
        }
        sort(v.begin(), v.end());
        set<int> s2;
        for(auto [val, i] : v){
            int l = i - val;
            int r = i + val;
            vector<int> rml;
            if(l >= 0){
                auto it = s.begin();
                while(it != s.end() && *it <= l){
                    rml.push_back(*it);
                    ++it;
                }
            }
            if(r < n){
                auto it = s.lower_bound(r);
                while(it != s.end()){
                    rml.push_back(*it);
                    ++it;
                }
            }
            for(auto x : rml) s.erase(x);
            s2.insert(i);
            if(s2.size()){
                if(*s2.begin() <= l){
                    s.clear();
                    break;
                }
                if(*prev(s2.end()) >= r){
                    s.clear();
                    break;
                }
            }
        }
        cout << s.size() << "\n";
    }
}   
 