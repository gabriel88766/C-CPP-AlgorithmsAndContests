#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+5;
int p[N]; // 0 if prime, 1 if not prime
vector<vector<ll>> pf(N);
vector<set<int>> conf(N);
bool on[N];

void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = 2*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
                pf[j].push_back(i);
            }
            pf[i].push_back(i);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    sieve();
    for(int i=0;i<m;i++){
        char t;
        int x;
        cin >> t >> x;
        if(t == '-'){
            if(!on[x]){
                cout << "Already off\n";
            }else{
                on[x] = false;
                cout << "Success\n";
                for(auto y : pf[x]){
                    conf[y].erase(x);
                }
            }
        }else{
            if(on[x]){
                cout << "Already on\n";
            }else{
                bool ok = true;
                int num;
                for(auto y : pf[x]){
                    if(conf[y].size()){
                         ok = false;
                         num = y;
                    }
                }
                if(ok){
                    for(auto y : pf[x]) conf[y].insert(x);
                    cout << "Success\n";
                    on[x] = true;
                }else{
                    cout << "Conflict with " << *conf[num].begin() << "\n";
                }
            }
        }
    }
}
