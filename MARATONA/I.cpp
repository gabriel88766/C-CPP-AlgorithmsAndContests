#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e6+1;
int mi[N], p[N];
int cnt[N], ans[N], lf[N], cnp[N];
const ll MOD = 1e9+7;
    
ll binpow(ll a, ll b, ll m = MOD){
    ll ans = 1, aux = a;
    while(b){
        if(b & 1) ans = (ans * aux) % m;
        aux = (aux * aux) % m;
        b >>= 1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    mi[1] = 1;
    for(int i=1;i<N;i++) mi[i] = i;
    for(int i=2;i<N;i++){
        if(!p[i]){
            for(int j=i;j<N;j +=i){
                if(j != i) p[j] = 1;
                mi[j] *= -1;
                if(!lf[j]) lf[j] = i;
            }
            if(i <= 1000){
                for(int j=i*i;j<N;j+=i*i){
                    mi[j] = 0;
                }
            }
        }
    }
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            cnp[i] += cnt[j];
        }
    }
    cin >> q;
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        int aux = x;
        vector<int> pr;
        while(aux != 1){
            pr.push_back(lf[aux]);
            aux /= lf[aux];
        }
        sort(pr.begin(), pr.end());
        pr.resize(unique(pr.begin(), pr.end()) - pr.begin());
        int sz = pr.size();
        int cur = 0;
        for(int j=0;j<(1 << sz);j++){
            int num = 1;
            for(int k=0;k<sz;k++) if(j & (1 << k)) num *= pr[k];
            if(__builtin_popcount(j) % 2) cur -= cnp[num];
            else cur += cnp[num];
        }
        cout << binpow(2, cur) << "\n";
    }
}