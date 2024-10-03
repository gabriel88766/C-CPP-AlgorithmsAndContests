#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll g[55], f[55];
ll fat[25];

vector<int> kth_permutation(int n, ll k){
    vector<int> ans;
    vector<bool> used(n+1, false);
    for(int i=1;i<=n;i++){
        int cf = n-i;
        int pos;
        for(int j=0;;j++){
            if(k > fat[cf]*j && k <= fat[cf]*(j+1)){
                pos = j;
                k -= fat[cf] * j;
                break;
            }
        }
        for(int j=1;j<=n;j++){
            if(used[j]) continue;
            if((!used[j]) && (pos == 0)){
                used[j] = true;
                ans.push_back(j);
                break;
            }else pos--;
        } 
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //init;
    g[2] = g[1] = 1;
    fat[0] = 1;
    for(int i=3;i<=22;i++){
        g[i] = g[i-1] * (i-2);
        fat[i-2] = g[i];
    }
    f[0] = 1;
    for(int i=1;i<=22;i++){
        for(int j=0;j<i;j++){
            f[i] += f[j] * g[i-j];
        }
    }
    for(int j=23;j<=50;j++) f[j] = f[j-1];
    //F[22] = 2*10^18
    int t = 0;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<int> ans(n+1);
        if(f[n] >= k){
            for(int i=1;i<=n;i++){
                if(f[n-i] > k){
                    ans[i] = i;
                }else{
                    //fuck!
                    ll cs = 0;
                    int ms = n - i + 1;
                    for(int ig=1;ig<=ms;ig++){
                        if(cs + g[ig]*f[ms-ig] >= k){
                            ll og = (k - cs + f[ms - ig] - 1) / f[ms - ig];
                            k -= (og - 1) * f[ms - ig] + cs;
                            //need to permute g[ig] in og order
                            //generate kth order permutation
                            if(ig > 2){
                                vector<int> aux = kth_permutation(ig-2, og);
                                vector<int> aux2;
                                vector<bool> used(ig - 1, false);
                                for(int j=0;j<aux.size();j++){
                                    int cur = 0;
                                    for(int u=1;u<=aux[j];u++){
                                        if(!used[u]) cur++;
                                    }
                                    used[aux[j]] = true;
                                    aux2.push_back(cur);
                                }
                                aux2.push_back(0);
                                vector<int> rss;
                                //0 -> ig-1
                                used = vector<bool>(ig, false);
                                vector<int> out(ig, -1), in(ig, -1);
                                out[0] = ig - 1;
                                in[ig-1] = 0;
                                rss.push_back(ig - 1);
                                for(int j=1;j<=ig-1;j++){
                                    vector<int> can;
                                    if(!in[j]){
                                        for(int u=0;u<ig;u++) if(in[u] != -1 && u != j) can.push_back(u);
                                    }else{
                                        int cant = j;
                                        while(in[cant]) cant = in[cant];
                                        for(int u=0;u<ig;u++) if(in[u] != -1 && u != cant) can.push_back(u);
                                    }
                                    int nw = can[aux2[j-1]];
                                    rss.push_back(nw);
                                    out[j] = nw;
                                    in[nw] = j;
                                }
                                for(int j=0;j<rss.size();j++){
                                    ans[ig + j] = ig + rss[j];
                                }
                            }else if(ig == 1){
                                assert(og == 1);
                                ans[ig] = ig;
                            }else{
                                assert(og == 1);
                                ans[ig] = ig + 1;
                                ans[ig+1] = ig;
                            }
                            i += (ig - 1);
                            
                            break;
                        }else cs += g[ig]*f[ms-ig];
                    }
                }
            }
        }else cout << "-1\n";
    }
}
