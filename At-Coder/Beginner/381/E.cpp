#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = " " + s;
    vector<int> sl;
    vector<int> p1(n+1), p2(n+1);
    for(int i=1;i<=n;i++){
        if(s[i] == '/') sl.push_back(i);
        else{
            if(s[i] == '1') p1[i] = 1;
            if(s[i] == '2') p2[i] = 1;
        }
        p1[i] += p1[i-1];
        p2[i] += p2[i-1];
    }
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        auto i1 = lower_bound(sl.begin(), sl.end(), l);
        auto i2 = lower_bound(sl.begin(), sl.end(), r+1);
        if(i1 != sl.end() && *i1 <= r){
            i2 = prev(i2);
            int ind1 = i1 - sl.begin();
            int ind2 = i2 - sl.begin();
            //[ind1, ind2]
            int fj = sl[ind1];
            if(p1[fj] - p1[l-1] <= p2[r] - p2[fj]){
                int bi = ind1;
                for(int j=(ind2-ind1)/2; j >= 1; j >>= 1){
                    while(bi + j <= ind2){
                        int nj = sl[bi + j];
                        if(p1[nj] - p1[l-1] <= p2[r] - p2[nj]) bi += j;
                        else break;
                    }
                }
                int ans = 0;
                int j1, j2;
                j1 = sl[bi];
                j2 = bi == ind2 ? sl[bi] : sl[bi+1];
                ans = 1 + 2*max(min(p1[j1] - p1[l-1], p2[r] - p2[j1]), min(p1[j2] - p1[l-1], p2[r] - p2[j2]));
                cout << ans << "\n";
            }else{
                cout << 2*(p2[r] - p2[fj]) + 1 << "\n";
            }
        }else cout << "0\n";
    }
    

}
