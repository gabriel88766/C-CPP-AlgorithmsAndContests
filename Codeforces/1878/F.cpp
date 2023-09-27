#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5;
int p[N]; // 0 if prime, j if not prime and
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                if(!p[j]) p[j] = i;
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    sieve();
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;
        set<pair<int,int>> ini;
        auto aux = n;
        while(aux != 1){
            int cnt = 0;
            int x = p[aux];
            while(!(aux % x)){
                cnt++;
                aux /= x;
            }
            ini.insert({x, cnt});
        }
        set<pair<int,int>> cur = ini;
        for(int i=0;i<q;i++){
            int type;
            cin >> type;
            if(type == 1){
                ll num;
                cin >> num;
                aux = num;
                while(aux != 1){
                    int cnt = 0;
                    int x = p[aux];
                    while(!(aux % x)){
                        cnt++;
                        aux /= x;
                    }
                    auto it = cur.lower_bound({x, 0});
                    if(it != cur.end() && it->first == x){
                        auto p = *it;
                        cur.erase(it);
                        p.second += cnt;
                        cur.insert(p);
                    }else cur.insert({x, cnt});
                }
                ll dn = 1;
                for(auto x : cur){
                    dn *= (x.second+1);
                }
                for(auto x : cur){
                    for(int i=0;i<x.second; i++){
                        if(!(dn % x.first)) dn /= x.first;
                    }
                }
                if(dn == 1) cout << "YES\n";
                else cout << "NO\n";
            }else{
                cur = ini;
            }
        }
        cout << "\n";
    }
}
