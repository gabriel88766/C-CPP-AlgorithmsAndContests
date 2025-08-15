#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 1e6+1;
ll mi[N];
int p[N];
ll cnt[N];
vector<int> dv[N];
void mobius(){ //another sieve.
    for(ll i =1; i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                p[j] = 1, mi[j] *= -1;
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
    //divisors
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            dv[j].push_back(i);
        }
    }
}
 
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    mobius();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        ll ans = 0;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        auto remove = [&](int u){
            for(auto x : dv[u]){
                ans -= mi[x] * --cnt[x];
            }
        };
        auto insert = [&](int u){
            for(auto x : dv[u]){
                ans += mi[x] * cnt[x]++;
            }
        };
        for(int i=1;i<=n;i++){
            insert(v[i]);
        }
        pair<int, int> a1 = {-1, -1}, a2 = {-1, -1};
        for(int i=1;i<=n;i++){
            ll oans = ans;
            remove(v[i]);
            ll nans = ans;
            if(oans != nans){
                for(int j=1;j<=n;j++){
                    if(i == j) continue;
                    if(gcd(v[i], v[j]) == 1){
                        a1 = {i, j};
                        remove(v[j]);
                        break;
                    }
                }
                break;
            }
            insert(v[i]);
        }
        if(a1 != make_pair(-1, -1)){
            for(int i=1;i<=n;i++){
                if(i == a1.first || i == a1.second) continue;
                ll oans = ans;
                remove(v[i]);
                ll nans = ans;
                if(oans != nans){
                    for(int j=1;j<=n;j++){
                        if(i == j) continue;
                        if(j == a1.first || j == a1.second) continue;
                        if(gcd(v[i], v[j]) == 1){
                            a2 = {i, j};
                            remove(v[j]);
                            break;
                        }
                    }
                    break;
                }
                insert(v[i]);
            }
            if(a2 != make_pair(-1, -1)){
                cout << a1.first << " " << a1.second << " " << a2.first << " " << a2.second << "\n";
            }else{
                vector<int> v1, v2;
                for(int i=1;i<=n;i++){
                    if(i == a1.first) continue;
                    if(i == a1.second) continue;
                    if(gcd(v[a1.first], v[i]) == 1) v1.push_back(i);
                    if(gcd(v[a1.second], v[i]) == 1) v2.push_back(i);
                }
                if(v1.size() >= 1 && v2.size() >= 1){
                    if(v1.size() > 1){
                        if(v2[0] != v1[0]) cout << a1.first << " " << v1[0] << " " << a1.second << " " << v2[0] << "\n";
                        else cout << a1.first << " " << v1[1] << " " << a1.second << " " << v2[0] << "\n";
                    }else if(v2.size() > 1){
                        if(v2[0] != v1[0]) cout << a1.first << " " << v1[0] << " " << a1.second << " " << v2[0] << "\n";
                        else cout << a1.first << " " << v1[0] << " " << a1.second << " " << v2[1] << "\n";
 
                    }else if(v1[0] != v2[0]){
                        cout << a1.first << " " << v1[0] << " " << a1.second << " " << v2[0] << "\n";
                    }else cout << "0\n";
                }else cout << "0\n";
            }
        }else cout << "0\n";

        for(int i=1;i<=m;i++) cnt[i] = 0;
    }
    

}
