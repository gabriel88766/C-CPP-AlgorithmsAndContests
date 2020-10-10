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
string v[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
string n;
int cur,k;
cin >> n;
cin >> k;
for(int i=0;i<12;i++){
    if(v[i]==n){
        cur=i;
    }
}
cur+=k;
cur%=12;
cout << v[cur];

}

