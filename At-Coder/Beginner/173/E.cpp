#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> pos, neg;
    bool has0 = false;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        if(num > 0) pos.push_back(num);
        else if(num < 0) neg.push_back(num);
        else has0 = true;
    }
    Mint ans = 1;
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());


    if((pos.size()+neg.size()) < k) ans = 0;
    else if(pos.size()+neg.size() == k){
        if(neg.size() % 2 && has0) ans = 0;
        else{
            for(auto x : pos) ans *= x;
            for(auto x : neg) ans *= x;
        }
    }else if(pos.size() == 0){
        if(k % 2){
            if(has0) ans = 0;
            else for(int i=neg.size()-1;i>=neg.size()-k;i--) ans *= neg[i]; 
        }else{
            for(int i=0;i<k;i++) ans *= neg[i];
        }
    }else{
        //even negative
        int qneg;
        if(k <= pos.size()) qneg = 0;
        else{
            qneg = k-pos.size();
            if(qneg % 2) qneg++; 
        }
        int qpos = k-qneg;
        while(qneg + 2 <= neg.size() && qpos >= 2){
            ll prodn = (ll)neg[qneg] * neg[qneg+1];
            ll prodp = (ll)pos[qpos-1] * pos[qpos-2];
            if(prodn > prodp){
                qneg += 2;
                qpos -= 2;
            }else break;
        }
        for(int i=0;i<qpos;i++) ans *= pos[i];
        for(int i=0;i<qneg;i++) ans *= neg[i];
    }
    cout << ans;
    
}
