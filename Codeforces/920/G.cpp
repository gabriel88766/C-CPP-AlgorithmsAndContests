#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
ll mi[N], p[N];
vector<int> pf[N];
vector<int> cm[N];

void mobius(){ //another sieve.
    for(ll i =1; i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                p[j] = 1, mi[j] *= -1;
                pf[j].emplace_back(i);
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
    for(int i=2;i<N;i++){
        int sz = pf[i].size();
        cm[i].emplace_back(1);
        for(int j=0;j< sz;j++){
            int cur = pf[i][j];
            int csz = cm[i].size();
            for(int k = 0;k< csz; k++){
                cm[i].emplace_back(cm[i][k] * cur);
            }
        }
    }
}

void query(int x, int p, int ord){
    int qt = x;
    for(int i=1;i<cm[p].size();i++){
        qt += (x/cm[p][i]) * mi[cm[p][i]];
    }
    int ans = 0;
    for(int i=(3*N); i> 0; i /= 2){
        while(true){
            int nv = ans + i, nqt;
            nqt = nv;
            for(int j=1;j<cm[p].size();j++){
                nqt += (nv/cm[p][j]) * mi[cm[p][j]];
            }
            if(nqt < (ord + qt) ){
                ans += i;
            }
            else break;
        }
    }
    cout << ans + 1 << "\n";
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    mobius();
    int q;
    cin >> q;
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;
        query(a,b,c);
    }
}
