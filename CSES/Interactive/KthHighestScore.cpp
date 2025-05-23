#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int check(char c, int f){
    cout << c << " " << f << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    k--;
    int p1 = 1, p2 = 1;
    while(k > 1){
        // cout << p1 << " " << p2 << "\n";
        int j1 = n - p1;
        int j2 = n - p2;
        if(j1 >= k/2 && j2 >= k/2){
            int f1 = check('F', p1 + k/2);
            int f2 = check('S', p2 + k/2);
            if(f1 >= f2){
                p1 += k/2;
                k -= k/2;
            }else{
                p2 += k/2;
                k -= k/2;
            }
        }else if(j1 >= k/2){
            while(j2 < k/2){
                p1++;
                k--;
            }
        }else if(j2 >= k/2){
            while(j1 < k/2){
                p2++;
                k--;
            }
        }else{
            //HOW??? IMPOSSIBLE!!
            assert(false);
        }
    }
    int f1 = check('F', p1);
    int f2 = check('S', p2);
    if(k == 0) cout << "! " << max(f1, f2) << "\n";
    else {
        if(f1 > f2){
            if(p1 < n){
                p1++;
                int f1 = check('F', p1);
                cout << "! " << max(f1, f2) << "\n";
            }else cout << "! " << f2 << "\n";
        }else{
            if(p2 < n){
                p2++;
                int f2 = check('S', p2);
                cout << "! " << max(f1, f2) << "\n";
            }else cout << "! " << f1 << "\n";
        }
    }
    cout.flush();
}
