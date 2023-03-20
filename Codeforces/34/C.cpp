#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


vector<int> v;
void splitIt(string s){
    int p = 0, opv = 0;
    while(p < s.size()){
        while((p+1) < s.size() && s[p+1] >= '0' && s[p+1] <= '9') p++;
        string num = s.substr(opv, p-opv+1);
        int val = 0;
        for(int i=0;i<num.size();i++){
            val *= 10;
            val += (num[i]-'0');
        }
        v.push_back(val);
        opv = p = p+2;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    splitIt(s);
    sort(v.begin(), v.end());
    string ans;
    int fi = v[0], li = v[0];
    bool flag = false;
    for(int i=1;i<v.size();i++){
        if(v[i] <= (li + 1)) li = v[i];
        else{
            if(flag) cout << ",";
            flag = true;
            if(fi != li) cout << fi << "-" << li;
            else cout << li;
            fi = li = v[i];
        }
    }
    if(flag) cout << ",";
    if(fi != li) cout << fi << "-" << li;
    else cout << li;
}
