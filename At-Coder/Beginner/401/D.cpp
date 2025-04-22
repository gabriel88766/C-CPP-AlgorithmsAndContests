#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int co[N], cp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    string s;
    cin >> n >> k >> s;
    int tt = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'o') tt++;
    }
    for(int i=0;i<n;i++){
        if(s[i] == '?'){
            if(i != 0 && s[i-1] == 'o') s[i] = '.';
            if(i != n-1 && s[i+1] == 'o') s[i] = '.';
        }
    }
    if(tt == k){
        for(int i=0;i<n;i++) if(s[i] == '?') s[i] = '.';
        cout << s << "\n";
    }else{
        int od = 0, sq = 0;
        for(int i=0;i<n;i++){
            cp[i] += od + (sq+1)/2;
            co[i] += od + sq/2;
            if(s[i] == '.'){
                od += (sq+1)/2;
                sq = 0;
            }
            if(s[i] == 'o'){
                sq = 0;
            }
            if(s[i] == '?') sq++;
        }
        od = sq = 0;
        for(int i=n-1;i>=0;i--){
            cp[i] += od + (sq+1)/2;
            co[i] += od + sq/2;
            if(s[i] == '.'){
                od += (sq+1)/2;
                sq = 0;
            }
            if(s[i] == 'o'){
                sq = 0;
            }
            if(s[i] == '?') sq++;
        }
        for(int i=0;i<n;i++){
            if(s[i] == '?'){
                if(tt + co[i] + 1 < k) s[i] = '.';
                else if(tt + cp[i] < k) s[i] = 'o';
            }
        }
        cout << s << "\n";

    }
}
