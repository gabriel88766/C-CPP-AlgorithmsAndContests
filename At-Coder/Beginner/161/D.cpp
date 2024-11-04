#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> nums;
void genall(string cur){
    if(cur == ""){
        for(char c = '1';c<='9';c++) genall(cur + c);
        return;
    }
    nums.push_back(stol(cur));
    if(cur.size() != 10){
        for(char c = '0';c<='9';c++){
            if(abs(cur.back()-c) <= 1) genall(cur + c);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    genall("");
    sort(nums.begin(), nums.end());
    int n;
    cin >> n;
    cout << nums[n-1] << "\n";
}
