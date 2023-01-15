#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        int fb = s.size(), fa = s.size();
        if(s[0] == 'a'){
            for(int i=1;i<s.size();i++){
                if(s[i] == 'b'){
                    fb = i;
                    break;
                }
            }
            if(fb < (s.size() - 1)) cout << s.substr(0, fb) << " "  << s.substr(fb, s.size() - fb - 1) << " " << s.substr(s.size()-1, 1) << "\n";
            else if(fb == (s.size()-1))cout << s.substr(0, fb - 1) << " " << s.substr(fb - 1, 1) << " " << s.substr(fb, 1) << "\n";
            else cout << s.substr(0, 1) <<  " " << s.substr(1, 1) << " " << s.substr(2, s.size() - 2) << "\n";
        }else{
            for(int i=1;i<s.size();i++){
                if(s[i] == 'a'){
                    fa = i;
                    break;
                }
            }
            if(fa < (s.size() - 1)) cout << s.substr(0, fa) << " "  << s.substr(fa, 1) << " " << s.substr(fa+1, s.size() - fa - 1) << "\n";
            else if(fa == (s.size()-1)) cout << s.substr(0, 1) << " " << s.substr(1, s.size() - 2) << " " << s.substr(s.size() - 1, 1) << "\n";
            else cout << s.substr(0, 1) <<  " " << s.substr(1, 1) << " " << s.substr(2, s.size() - 2) << "\n";
        }
    }
}
