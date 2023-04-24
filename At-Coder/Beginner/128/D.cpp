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
    int n, k;
    cin >> n >> k;
    int maxv = 0;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<=min(n, k); i++){
        for(int j=0;j+i<=min(n, k); j++){
            int curs = 0;
            multiset<int> st;
            for(int x=0;x<i;x++) {st.insert(v[x]); curs += v[x];}
            for(int x=n-1;x>=n-j;x--){st.insert(v[x]); curs += v[x];}
            int cnt = i+j;
            while(cnt < k && !st.empty() && *st.begin() < 0){
                curs -= *st.begin();
                st.erase(st.begin());
                cnt++;
            }
            maxv = max(maxv, curs);
        }
    }
    cout << maxv;
}
