#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll nCr[51][51];

void init(){
    nCr[0][0] = 1;
    for(int i=1;i<=50;i++){
        for(int j=0;j<=i;j++){
            if(j == 0 || j == i) nCr[i][j] = 1;
            else nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    init();
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    sort(v.begin()+1, v.end(), greater<ll> ());
    pair<bool, int> check = {false, 0};
    for(int i=a;i<=n;i++){
        if(v[i] == v[1]) check = {true, i};
        else break;
    }
    ll ans = 0;
    if(check.first){
        // nCr(i, a) + nCr(i, a+1) + ... nCr(i, b);
        for(int i=a;i<=b;i++) ans += nCr[check.second][i];
    }else{
        //just choose last;
        int cnt1 = 0, cnt2 = 0;
        for(int i=1;i<=a;i++) if(v[i] == v[a]) cnt1++;
        for(int i=(a+1);i<=n;i++) if(v[i] == v[a]) cnt2++;
        //nCr(cnt1+cnt2, cnt1)
        ans = nCr[cnt1+cnt2][cnt1];
    }
    long double avg = 0;
    for(int i=1;i<=a;i++) avg += v[i];
    avg /= a;
    cout << setprecision(6) << fixed << avg << "\n" << ans;
}
 