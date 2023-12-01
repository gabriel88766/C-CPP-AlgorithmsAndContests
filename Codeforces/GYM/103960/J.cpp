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
    vector<int> cnt(14, 0);
    int n;
    cin >> n;
    int m = 0, j = 0;
    int a, b;
    cin >> a >> b;
    cnt[a]++;
    cnt[b]++;
    if(a > 10) a = 10;
    if(b > 10) b = 10;
    
    j = a + b;
    cin >> a >> b;
    cnt[a]++;
    cnt[b]++;
    if(a > 10) a = 10;
    if(b > 10) b = 10;
    
    m = a + b;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnt[x]++;
        if(x > 10) x = 10;
        m += x;
        j += x;
    }
    int lss1 = 23 - m;
    int lss2 = 24 - j;
    for(int i=min(lss2,lss1);i<=min(lss1, 10);i++){
        if(4 - cnt[i]){
            cout << i << "\n";
            return 0;
        }
        if(i == 10){
            for(int i=11;i<=13;i++){
                if(4 - cnt[i]){
                    cout << i << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "-1\n";
}
