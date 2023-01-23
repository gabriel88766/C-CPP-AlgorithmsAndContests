#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    string s;
    cin >> n >> s;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        if(s[i] != '0'){
            int toint = s[i] - '0';
            vp.push_back({(toint-1)/3, (toint-1)%3});
        }else{
            vp.push_back({3,1});
        }
    }
    vector<pair<int,int>> moves = {{0,1}, {0, -1}, {1,0}, {-1, 0}};
    bool canmove = false;
    for(int i=0;i<moves.size();i++){
        bool isOk = true;
        for(int j=0;j<n;j++){
            pair<int,int> p = {vp[j].first + moves[i].first, vp[j].second + moves[i].second};

            if(p.first < 0 || p.second < 0) isOk = false;
            if(p.second > 2) isOk = false;
            if(p.first > 2 && p.second != 1) isOk = false;
            if(p.first > 3) isOk = false;
        }
        if(isOk){
            canmove = true;
        }
    }
    if(canmove) cout << "NO";
    else cout << "YES";
}
 