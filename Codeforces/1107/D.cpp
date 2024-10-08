#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 5201;
int p[N]; // 0 if prime, 1 if not prime
vector<int> primes;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(int j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            primes.push_back(i);
        }
    }
}

bool gr[N][N];
bitset<N> rw[N], col[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int cc = 0;
        for(int j=0;j<s.size();j++){
            int cn;
            if(s[j] <= '9' && s[j] >= '0') cn = s[j] - '0';
            else cn = s[j] - 'A' + 10;
            for(int k=0;k<=3;k++){
                gr[i][cc + 3 - k] = (cn & (1 << k)) >> k;
            }
            cc += 4;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rw[i][j] = col[j][i] = gr[i][j];
        }
    }
    vector<int> ppt;
    for(auto x : primes){
        if(!(n % x)) ppt.push_back(x);
    }
    auto check = [&](int cd){
        bool ok = true;
        for(int i=0;i<n;i+=cd){
            for(int j=i+1;j<i+cd;j++){
                if((rw[i]^rw[j]).count()) ok = false;
            }
        }
        for(int i=0;i<n;i+=cd){
            for(int j=i+1;j<i+cd;j++){
                if((col[i]^col[j]).count()) ok = false;
            }
        }
        return ok;
    };
    int ans = 1;
    for(auto x : ppt){
        while(true){
            int cur = ans * x;
            if(n % cur) break; //not a divisor.
            //check if cur is ok
            if(!check(cur)) break;
            else ans = cur;
        }
    }
    cout << ans << "\n";
}
