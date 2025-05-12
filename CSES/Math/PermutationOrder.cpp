#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 101;
ll fat[N], C[N][N];
void init(){
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
    // for(auto x : ans) cout << x << " ";
    // cout << "\n";
    return ans;
}

bool comp(const vector<int> &a, const vector<int> &b){
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return true;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if(x == 1){
            ll n, k;
            cin >> n >> k;
            auto perm = kth_permutation(n, k);
            for(auto &x : perm) cout << x << " ";
            cout << "\n";
        }else{
            ll n;
            cin >> n;
            vector<int> perm(n);
            for(int i=0;i<n;i++) cin >> perm[i];
            ll k = 0;
            for(ll jmp = fat[n];jmp>=1;jmp>>=1){
                while(k + jmp <= fat[n] && comp(kth_permutation(n, k + jmp), perm)) k += jmp;
            }
            cout << k << "\n";
        }
    }
}
