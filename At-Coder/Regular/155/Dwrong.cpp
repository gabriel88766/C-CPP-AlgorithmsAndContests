#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> dv[N];
int cnt[N];
int vis[N], tt[N], mi[N], p[N];
void sieve(){
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
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            dv[j].push_back(i); 
        }
    }
}

//for conv
ll aux = 0;
ll cntv[N];
void remove(int u){
    for(auto x : dv[u]){
        aux -= mi[x] * --cntv[x];
    }
}
void insert(int u){
    for(auto x : dv[u]){
        aux += mi[x] * cntv[x]++;
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();

    //Approach:  find how many numbers have gcd != 1, if some is odd, then it's win
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        insert(v[i]);
    }
    // for(int i=1;i<=n;i++){
    //     for(auto x : dv[v[i]]){
    //         cnt[x]++;
    //     }
    // }





    for(int i=1;i<=n;i++){
        if(vis[v[i]]){
            if(vis[v[i]] == 1) cout << "Takahashi\n";
            else cout << "Aoki\n";
            continue;
        }


        bool ok = false;
        for(auto x : dv[v[i]]){
            if(x == 1) continue;
            ll oans = aux;
            insert(x);
            ll nans = aux;
            remove(x);
            // cout << x << " " << n-nans + oans  << "\n";
            if((n - nans + oans) % 2 == 0) ok = true;
        }
        //how to solve
        


        if(ok) vis[v[i]] = 2;
        else vis[v[i]] = 1;
        if(ok) cout << "Aoki\n";
        else cout << "Takahashi\n";

        // for(auto x : dv[v[i]]){
        //     cnt[x]++;
        // }
    }
}
