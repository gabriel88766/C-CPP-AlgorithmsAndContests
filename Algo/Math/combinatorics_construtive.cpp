#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 101;
ll fat[N], C[N][N];
bool inited = false;
void init(){
    if(inited) return;
    inited = true;
    fat[0] = 1;
    for(int i=1;i<N;i++){
        if(INF_LL/i > fat[i-1]) fat[i] = i * fat[i-1];
        else fat[i] = INF_LL;
    }
    C[0][0] = 1;
    for(int i=1;i<N;i++){
        C[i][i] = 1;
        C[i][0] = 1;
        for(int j=1;j<i;j++){
            C[i][j] = min(C[i-1][j-1] + C[i-1][j], INF_LL);
        }
    }
}
//This method is O(n^2), initialize fat[i] = INF for i > 20
vector<int> kth_permutation(int n, ll k){ 
    init();
    vector<int> ans;
    if(k > fat[n]){
        ans.push_back(-1);
        return ans;
    }
    vector<bool> used(n+1, false);
    for(int i=1;i<=n;i++){
        int cf = n-i;
        int pos;
        for(int j=0;;j++){
            if(k <= fat[cf]*(j+1)){
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
    for(auto x : ans) cout << x << " ";
    cout << "\n";
    return ans;
}
//method O(n^3) for general case:
//vp is a vector of frequencies, from 1 to size, freq;
vector<int> kth_permutation(vector<pair<int,int>> &vp, ll k){ 
    init();
    vector<int> ans;
    ll tt = 1;
    int sz = 0;
    for(auto [a, b] : vp) sz += b;
    int asz = sz;
    for(auto [a, b] : vp){
        if(INF_LL/tt > C[asz][b]) tt *= C[asz][b];
        else tt = INF_LL;
        asz -= b;
    }
    if(tt < k){
        ans.push_back(-1);
        return ans;
    }
    for(int i=1;i<=sz;i++){
        for(auto &[c, qc] : vp){
            if(qc == 0) continue; //cant add more c
            ll tta = 1;
            int asz = sz - i;
            for(auto [l, ql] : vp){
                if(l == c){
                    tta *= C[asz][ql-1];
                    asz -= ql - 1;
                }else{
                    tta *= C[asz][ql];
                    asz -= ql;
                }
            }
            if(k <= tta){
                ans.push_back(c);
                qc--;
                break;
            }else k -= tta;
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << "\n";
    return ans;
}

string kth_permutation(string s, ll k){
    vector<pair<int,int>> vp(26);
    for(int i=0;i<26;i++) vp[i] = {i, 0};
    for(auto c : s) vp[c-'a'].second++;
    auto aux = kth_permutation(vp, k);
    if(aux[0] == -1) return "null";
    string ans = "";
    for(auto x : aux) ans += (x + 'a');
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    vector<pair<int,int>> vp;
    for(int i=1;i<=20;i++) vp.push_back({i, 1});
    const ll k = 2'200'000'000'000'000'000;
    kth_permutation(vp, k); //19 2 13 5 11 1 8 10 7 20 15 18 3 12 14 6 16 9 17 4
    kth_permutation(20, k);
    //should be the same for all k
    //for string
    string s = "aabbc";
    cout << kth_permutation(s, k) << "\n"; //null
    cout << kth_permutation(s, 4) << "\n"; //aabbc, aabcb, aacbb, "ababc"
    cout << kth_permutation(s, 30) << "\n"; //last = cbbaa
    cout << kth_permutation(s, 31) << "\n"; //null
}
