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
    int n, q;
    string s;
    cin >> n >> q >> s;
    //conditions:
    //n odd, all NO.
    //n even, option 1: sum is 0 and there is no ((  nor  )) and it must begin ( end )
    //n even, option 2: sum is any but : first (( before first )) last )) after last (( and it must begin ( end )
    if(n % 2){
        for(int i=0;i<q;i++){
            int x;
            cin >> x;
            cout << "NO\n";
        }
        return 0;
    }
    int sum = 0;
    for(auto &c : s){
        if(c == '(') sum++;
        else sum--;
    }
    set<int> s1, s2;
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            if(s[i] == '(') s1.insert(i);
            else s2.insert(i);
        }
    }
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        x--;
        s1.erase(x);
        s1.erase(x-1);
        s2.erase(x);
        s2.erase(x-1);
        if(s[x] == '('){
            sum -= 2;
            s[x] = ')';
        }else{
            sum += 2;
            s[x] = '(';
        }
        if(x > 0 && s[x] == s[x-1]){
            if(s[x] == '(') s1.insert(x-1);
            else s2.insert(x-1);
        }
        if(x < n-1 && s[x] == s[x+1]){
            if(s[x] == '(') s1.insert(x);
            else s2.insert(x);
        }
        if(s1.size() || s2.size()){
            if(s1.size() && s2.size() && s[0] == '(' && s.back() == ')' && *s1.begin() < *s2.begin() && *prev(s2.end()) > *prev(s1.end())) cout << "YES\n";
            else cout << "NO\n";
        }else{
            if(sum == 0 && s[0] == '(') cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
