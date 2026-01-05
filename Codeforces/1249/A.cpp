#include<bits/stdc++.h>

#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))
typedef long long ll;
using namespace std;

const int N = 1e5+3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int q;
cin >> q;
while(q--){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    char ok = true;
    for(int i = 1;i<n;i++){
        if(v[i] == (v[i-1]+1)) ok = false;
    }
    if(ok) cout << "1\n";
    else cout << "2\n";
}

}


 