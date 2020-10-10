#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
long long int num;
int n;
cin >> n;
if(n == 2) cout << -1;
else{
    num = 6;
    cout << 6 << endl << 10 << endl << 15 << endl;
    for(int i = 3;i<n;i++){
        num*=2;
        cout << num << endl;
    }
}
}

