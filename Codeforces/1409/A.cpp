#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,a,b;
cin >> n;
for(int i=0;i<n;i++){
    cin >> a >> b;
    int k = a-b;
    if(k<0) k=-k;
    int r = k%10;
    k/=10;
    if(r) k++;
    cout << k << endl;
}

}
 