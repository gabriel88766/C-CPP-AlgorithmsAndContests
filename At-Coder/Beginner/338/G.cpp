#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    Mint pow(ll u){
        Mint ans = 1;
        Mint aux = *this;
        while(u){
            if(u & 1) ans *= aux;
            aux *= aux;
            u >>= 1;
        }
        return ans;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
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

Mint op(Mint a, Mint b){
    return a + b;
}

Mint el(){
    return Mint(0);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> ps(n+1, 0);
    vector<int> bord = {0};
    for(int i=1;i<=n;i++){
        if(s[i] >= '1' && s[i] <= '9') ps[i] = 1;
        ps[i] += ps[i-1];
        if(s[i] == '+') bord.push_back(i);
    }
    bord.push_back(n+1);
    Mint ans = 0;
    for(int i=1;i<bord.size();i++){
        int l = bord[i-1], r = bord[i];
        Mint qtb = ps[l];
        Mint qta = ps[n] - ps[r-1];
        Mint cn = 0, res = 1, pot = 1;
        SegmentTree<Mint, op, el> st(r - l);
        for(int j=l+1;j<r;j++){
            if(s[j] >= '1' && s[j] <= '9'){
                cn *= 10;
                cn += (s[j] - '0');
                st.update(j - l, cn * res);
                ans += cn * res * (qtb + 1);
            }else{
                res *= cn;
                cn = 0;
            }
        }
        res *= cn;
        ans += res * (qta * qtb - 1);
        cn = 0, res = 1;
        for(int j=r-1;j>l;j--){
            if(s[j] >= '1' && s[j] <= '9'){
                cn += (s[j] - '0') * pot;
                ans += cn * res * (qta+1);
                pot *= 10;
            }else{
                res *= cn;
                cn = 0;
                pot = 1;
            }
        }
        //internal, both i, j i > bord[i] && j <
        vector<int> b2 = {l};
        for(int j=l+1;j<r;j++){
            if(s[j] < '1' || s[j] > '9') b2.push_back(j);
        }
        b2.push_back(r);
        vector<Mint> nums(b2.size());
        for(int j=1;j<b2.size();j++){
            Mint cn = 0;
            for(int k=b2[j-1]+1;k<b2[j];k++){
                cn *= 10;
                cn += (s[k] -'0');
            }
            nums[j-1] = cn;
        }
        Mint cdiv = 1, cmult = 0;
        for(int j = 0;j<b2.size()-1;j++){
            cdiv *= nums[j];
            pot = 1;
            for(int k=b2[j]+1; k<b2[j+1];k++) pot *= 10;
            pot /= 10;
            cmult = nums[j];
            Mint aux = 0;
            for(int k=b2[j]+1;k<b2[j+1];k++){
                if(k == l+1 || k == r-1);
                else{
                    cout << cmult << " " << cdiv << " " << k-l << " " << r-l-2 << "\n";
                    ans += (cmult / cdiv) * st.query(b2[j+1]-l, r-l-2);
                    ans += st.query(k-l, min(b2[j+1]-l, r-l-2))/(cdiv/nums[j]) - aux * (b2[j+1]-l);
                }
                cmult -= (s[k] - '0') * pot;
                aux += (s[k] - '0') * pot;
                pot /= 10;
            }
        }

        
    }
    cout << ans << "\n";

}
