#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


// {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}

// the set must contain 1, 17, 19, 23, 29, 31; (6 numbers)
// the set can contain 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,20,21,22,24,25,26,27,28,30 (25 numbers)
// check for multiplicity 2, 3, 5, 7, 11, 13 (6 numbers) at most in the msk
vector<int> chk = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,20,21,22,24,25,26,27,28,30};
vector<int> pr = {2, 3, 5, 7, 11, 13};
vector<int> mu = {1, 17, 19, 23, 29};
vector<int> pmsk;
void init(){    
    vector<int> bdm; //popcount (m & bdm[j]) must be equal 1
    for(auto x : pr){
        int cur = 0;
        for(int j=0;j<25;j++){
            if(!(chk[j] % x)){
                cur |= (1 << j);
            }
        }
        bdm.push_back(cur);
    }
    for(int m=0; m<(1 << 25); m++){
        if(__builtin_popcount(m) > 6) continue;
        bool ok = true;
        for(auto x : bdm){
            if(__builtin_popcount(x & m) != 1) ok = false;
        }
        if(ok) pmsk.push_back(m);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = INF_INT;
    vector<int> ansv;

    for(auto m : pmsk){
        vector<bool> cu(31, false);
        vector<int> cans;
        int cnt = 5;
        for(auto x : mu) cu[x] = true;
        for(int j=0;j<25;j++){
            if(m & (1 << j)){
                 cu[chk[j]] = true;
                 cnt++;
            }
        }
        vector<int> aln;
        for(int j=1;j<=30;j++) if(cu[j]) aln.push_back(j);
        int cur = 0;
        
        for(int i=0;i<n;i++){
            int curmin = INF_INT, bnum = -1;
            for(int j=1;j<=30;j++){
                if(!cu[j]) continue;
                if(abs(j - v[i]) < curmin){
                    bnum = j;
                    curmin = abs(j - v[i]);
                }
            }
            cur += curmin;
            cans.push_back(bnum);
        }
        if(cur < ans){
            ans = cur;
            ansv = cans;
        }
    }
    for(auto x : ansv) cout << x << " ";
    cout << "\n";
}
