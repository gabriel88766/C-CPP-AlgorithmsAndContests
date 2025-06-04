#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int K = 1e6+1;
bool ok[K];
pair<int, int> par[K];

vector<ll> make_xor(vector<ll> a, vector<ll> b){
    vector<ll> ans;
    for(auto &x : a){
        for(auto &y : b){
            ans.push_back((x^y));
        }
    }
    return ans;
}


const int N = 22000000, M = 60; // log aMax * Q = sqrt(2^2 * 3^22) * 60 here
int cnt = 0;
int trie[N][2]; //44 * 4 MB
int sz[N];

bool get(ll num){
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        if(trie[cur][(num & (1LL << i)) >> i]){
            cur = trie[cur][(num & (1LL << i)) >> i];
        }else return false;
    }
    return true;
}
void insert(ll num){
    int cur = 0;
    for(int i=M-1;i >= 0; i--){
        sz[cur]++;
        if(trie[cur][(num & (1LL << i)) >> i]){
            cur = trie[cur][(num & (1LL << i)) >> i];
        }else cur = trie[cur][(num & (1LL << i)) >> i] = ++cnt;
    }
    sz[cur]++;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll k;
    int n, c;
    cin >> n >> c >> k;
    vector<vector<ll>> vc(c+1);
    for(int i=1;i<=n;i++){
        int cl;
        ll val;
        cin >> cl >> val;
        vc[cl].push_back(val);
    }
    //corner case 1 : c = 1 (can't divide in two groups);
    if(c == 1){
        sort(vc[1].begin(), vc[1].end(), greater<ll>());
        cout << vc[1][k-1] << "\n";
        return 0;
    }
    ll ptt = 1;
    for(int x=1;x<=c;x++) ptt *= vc[x].size();

    vector<int> g1, g2;
    //I think I can split in at least 2 groups...
    assert(ptt <= 1e12); //yeah, of course... 3^22 * 2^2
    ll pg = sqrt(ptt); //just knapsack now, instead of meet in the middle.
    ok[1] = true;
    for(int i=1;i<=c;i++){
        if(vc[i].size() == 1) { 
            if(g1.size() == 0) g1.push_back(i); 
            continue;
        }
        for(int j=pg;j>1;j--){
            if(j % vc[i].size()) continue;
            if(ok[j]) continue;
            if(ok[j/vc[i].size()]){
                ok[j] = true;
                par[j] = {j/vc[i].size(), i}; // group 1
            }
        }
    }
    for(int j=pg;j>=1;j--){
        if(ok[j]){
            int cur = j;
            while(cur != 1){
                g1.push_back(par[cur].second);
                cur = par[cur].first;
            }
            break;
        }
    }
    sort(g1.begin(), g1.end());
    int p = 0;
    for(int i=1;i<=c;i++){
        if(p == g1.size() || g1[p] != i){
            g2.push_back(i);
        }else p++;
    }
    assert(g1.size() && g2.size());
    //I strongly hope that product of g2 is at most ~1e6 = (3^11 * 2) * 3, but not proved.
    
    vector<ll> p1 = vc[g1[0]], p2 = vc[g2[0]];
    for(int i=1;i<g1.size();i++){
        p1 = make_xor(p1, vc[g1[i]]);
    }
    for(int i=1;i<g2.size();i++){
        p2 = make_xor(p2, vc[g2[i]]);
    }
    assert(p1.size() <= 360000);
    assert(p2.size() <= 2e6);
    //now the last step of the algo... I didn't told you hehe...
    //count xors betwenn p1 group and p2 group

    for(auto &x : p1) insert(x); //O(N * 60)
    ll ans = 0;
    vector<int> bit(p2.size());
    for(int i=59;i>=0;i--){
        ll cn = (1LL << i) | ans;
        //check how many numbers have xor greater than or equal to ans ^ cb;
        //if greater than k then set this bit;
        //else don't set and subtract them from k
        ll tt = 0;
        for(int j=0;j<p2.size();j++){
            if(p2[j] & (1LL << i)){
                //then 0 is better
                if(bit[j] != -1 && trie[bit[j]][0]) tt += sz[trie[bit[j]][0]];
            }else{
                if(bit[j] != -1 && trie[bit[j]][1]) tt += sz[trie[bit[j]][1]];
            }
        }
        if(tt >= k){
            ans = cn;
            for(int j=0;j<p2.size();j++){
                if(p2[j] & (1LL << i)){
                    if(bit[j] != -1 && trie[bit[j]][0]) bit[j] = trie[bit[j]][0];
                    else bit[j] = -1;
                }else{
                    if(bit[j] != -1 && trie[bit[j]][1]) bit[j] = trie[bit[j]][1];
                    else bit[j] = -1;
                }
            }
        }else{
            k -= tt;
            for(int j=0;j<p2.size();j++){
                if(p2[j] & (1LL << i)){
                    if(bit[j] != -1 && trie[bit[j]][1]) bit[j] = trie[bit[j]][1];
                    else bit[j] = -1;
                }else{
                    if(bit[j] != -1 && trie[bit[j]][0]) bit[j] = trie[bit[j]][0];
                    else bit[j] = -1;
                }
            }
        }
    }
    cout << ans << "\n";


    

}
