#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int arr[] = {1, 2, 4, 5, 9, 10, 20, 21, 41, 42, 84, 85, 169, 170, 340, 341, 681, 682, 1364, 1365, 2729, 2730,
5460, 5461, 10921, 10922, 21844, 21845, 43689, 43690, 87380, 87381, 174761, 174762, 349524, 349525, 699049, 699050
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<38;i++) if(n == arr[i]){
        cout << "1\n";
        return 0;
    }
    cout << "0\n";
}