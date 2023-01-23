#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void printc(string &s, char c, int qnt){
    s += string(c, qnt);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); 
    string s;
    vector<string> vs;
    int maxsz = 0, parity = 0;
    while(getline(cin, s)){
        vs.push_back(s);
        maxsz = max(maxsz, (int)s.size());
    }
    for(int i=0;i<maxsz+2;i++) cout << "*";
    cout << "\n";
    for(int i=0;i<vs.size();i++){
        int aux = maxsz - vs[i].size();
        cout << "*";
        if(aux%2){
            for(int j=0;j<aux/2+parity;j++) cout << " ";
            cout << vs[i];
            for(int j=0;j<aux/2+(parity^1);j++) cout << " ";
            parity ^= 1;
        }else{
            for(int j=0;j<aux/2;j++) cout << " ";
            cout << vs[i];
            for(int j=0;j<aux/2;j++) cout << " ";   
        }
        cout << "*\n";
    }
    for(int i=0;i<maxsz+2;i++) cout << '*';
}
