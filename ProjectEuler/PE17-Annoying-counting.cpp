#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//one two three four five six seven eight nine
int s1[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
//ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen
int s2[] = {3, 6, 6, 8, 8 ,7, 7, 9, 8, 8}; 
//twenty thirty forty fifty sixty seventy eighty ninety
int s3[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
//xx hundred
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int ans = 0;
    for(int i=1;i<=1000;i++){
        int x = (i % 100) / 10;
        int y = i % 10;
        if(x == 1) ans += s2[y];
        else ans +=  s3[x] + s1[y];
        if(i >= 100 && i < 1000){
            ans += s1[i / 100] + 7;
            if(i % 100) ans += 3; //xxx and xxx
        } 
        else if(i == 1000) ans += 11;
    }
    cout << ans << "\n";
}
