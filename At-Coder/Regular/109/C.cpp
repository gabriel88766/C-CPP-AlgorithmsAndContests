#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string find_new(string s){
    string news;
    if(s.size() % 2){
        s += s;
    }
    for(int j=0;j<s.size();j+=2){
        if(s[j] == s[j+1]) news += s[j];
        else{
            char mn = min(s[j], s[j+1]);
            char mx = max(s[j], s[j+1]);
            if(mn == 'P' && mx == 'R') news += 'P';
            else if(mn == 'P' && mx == 'S') news += 'S';
            else if(mn == 'R' && mx == 'S') news += 'R';
            else assert(false);
        }
    }
    return news;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    string s;
    cin >> n >> k >> s;
    for(int i=0;i<k;i++){
        s = find_new(s);
    }
    cout << s[0] << "\n";
}
 