#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
int v[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //if there is a majority, I have ~ 25% of choosing a pair of the majority.
    //try 60 times, if don't print -1 (3/4)^60 of mistake
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    
    for(int i=1;i<=60;i++){
        int i1 = uniform_int_distribution<int>(1, n)(rng);
        int i2 = uniform_int_distribution<int>(1, n)(rng);
        while(i2 == i1) i2 = uniform_int_distribution<int>(1, n)(rng);
        int dif = abs(v[i1] - v[i2]);
        //check all prime factors of dif except 2.
        //if 2 is a factor, 2 times, check 4 instead.
        for(int j=3;j*j<=dif;j++){
            if(dif % j == 0){
                if(j == 4){
                    while(dif % 2 == 0) dif /= 2;
                }else{
                    while(dif % j == 0) dif /= j;
                }
                int cnt = 0;
                for(int k=1;k<=n;k++){
                    if(abs(v[k] - v[i1]) % j == 0) cnt++;
                }
                if(cnt > n-cnt){
                    cout << j << "\n";
                    return 0;
                }
            }
        }
        int cnt = 0;
        if(dif != 1 && dif != 2){
            for(int k=1;k<=n;k++){
                if(abs(v[k] - v[i1]) % dif == 0) cnt++;
            }
            if(cnt > n-cnt){
                cout << dif << "\n";
                return 0;
            }
        }
    }
    cout << "-1\n";
}
