#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
        if(u < 0) return (Mint(1)/v).pow(-u);
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
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 8e5+2; //O(N) preprocessing, O(1) query

//Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for(int i=0;i<n;i++) cin >> vp[i].first >> vp[i].second;
    int mx = 0;
    for(int i=0;i<n;i++){
        mx = max(vp[i].first, mx);
        mx = max(vp[i].second, mx);
    }   
    bool chk = false;
    for(int i=0;i<n;i++){
        if(mx == vp[i].first && mx == vp[i].second) chk = true;
    }
    if(chk){
        //winner will have mx + 1 points (asserted)
        int c1 = 0, c2 = 0;
        for(int i=0;i<n;i++){
            if(vp[i].first == mx && vp[i].second == mx) c1++;
            else if(vp[i].first == mx || vp[i].second == mx) c2++;
        }
        Mint inv2 = Mint(1) / Mint(2);
        Mint inv2x = Mint(1) / Mint(2).pow(c2);
        Mint inv2y = c2 >= 1 ? Mint(1) / Mint(2).pow(c2-1) : 0;

        Mint p1, p2;
        //case c1-1, c2
        for(int i=0;i<=c2;i++){
            Mint cp = nCr(c2, i) * inv2x;
            //i out of c2 are chose
            p1 += cp * inv2 * (Mint(1) / (c1 + i));
        }
        //case c1, c2-1
        for(int i=0;i<=c2-1;i++){
            Mint cp = nCr(c2-1, i) * inv2y;
            //i out of c2-1 are chose
            p2 += cp * inv2 * (Mint(1) / (1 + c1 + i));
        }
            
        for(int i=0;i<n;i++){
            //odds = 1/2 * 1 / (1 + c3 + x(c4)) where c4 = c2 or c2-1 and c3 = c1 or c1 - 1 depending on i
            if(vp[i].first == mx && vp[i].second == mx) cout << p1 << " " << p1 << " ";
            else if(vp[i].first == mx) cout << p2 << " " << 0 << " ";
            else if(vp[i].second == mx) cout << 0 << " " << p2 << " ";
            else cout << "0 0 ";
        }
    }else{
        //winner will either have mx or mx+1 points. 
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for(int i=0;i<n;i++){
            if(vp[i].first == mx-1 && vp[i].second == mx-1) c1++;
            else if(vp[i].first == mx-1 || vp[i].second == mx-1){
                if(vp[i].first == mx || vp[i].second == mx) c2++;
                else c3++;
            }else if(vp[i].first == mx || vp[i].second == mx) c4++;
        }
        //c1 {mx-1, mx-1} will be +1 for mx.
        //c2 {mx, mx-1} => could be double mx or mx+1
        //c3 {mx-1, X} => maybe +1 for mx
        //c4 {mx, X} => could be +1 for mx+1 or mx 
        //options, mx-1 go to mx, class c1, c2 or c3; mx go to mx+1, class c2 or c4 (equivalent here)
        Mint p1, p2, p3, p4;
        // if mx => 1/2 * (1/2)^(c2+c4) * (1 / (1 + c1 + 2*c2 + c3(x) + c4));
        Mint inv2x = Mint(1)/Mint(2).pow(c2+c4+1);
        Mint inv2y = Mint(1)/Mint(2).pow(c2+c4);
        Mint ic3x = Mint(1) / Mint(2).pow(c3);
        Mint ic3y = c3 ? Mint(1) / Mint(2).pow(c3-1) : 0;
        for(int i=0;i<=c3;i++){
            if(c1) p1 += inv2x * nCr(c3, i) * ic3x * (Mint(1) / (c1 + 2*c2 + i + c4));
            if(c2) p2 += inv2y * nCr(c3, i) * ic3x * (Mint(1) / (c1 + 2*c2 + i + c4));
        }
        for(int i=0;i<=c3-1;i++){
            p3 += inv2x * nCr(c3-1, i) * ic3y * (Mint(1) / (1 + c1 + 2*c2 + i + c4));
        }
        //p4 c1 c3 doesn't matter. c2 will vary
        //if mx+1 => 1/2 * (1 / 1 + c2c4(x));
        for(int i=0;i<=c2+c4-1;i++){
            p4 += inv2y * nCr(c2+c4-1, i) * (Mint(1)/(1 + i));
        }
        //but it can keep mx too... in that case all mx must keep mx (1/2)^(c4+c2), c3 vary, c1 doesn't matter
        //(1/2)^(c2+c4) * 1 /(c1 + 2*c2 + c3(x) + c4)
        for(int i=0;i<=c3;i++){
            p4 += inv2y * nCr(c3, i) * ic3x * (Mint(1) / (c1 + 2*c2 + i + c4));
        }


        for(int i=0;i<n;i++){
            if(vp[i].first == mx - 1){
                if(vp[i].second == mx-1) cout << p1 << " ";
                else if(vp[i].second == mx) cout << p2 << " ";
                else cout << p3 << " ";
            }else if(vp[i].first == mx){
                cout << p4 << " ";
            }else{
                cout << "0 ";
            }

            if(vp[i].second == mx - 1){
                if(vp[i].first == mx-1) cout << p1 << " ";
                else if(vp[i].first == mx) cout << p2 << " ";
                else cout << p3 << " ";
            }else if(vp[i].second == mx){
                cout << p4 << " ";
            }else{
                cout << "0 ";
            }
        }
    }
    cout << "\n";
}