
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
int n,total,x,y;
cin >> n;
int expected = n-1;
vector <int> misses;
total = (n*(n-1))/2 -1;
map<int,int> loses;
map<int,int> wins;
for(int i=0;i<total;i++){
    cin >> x >> y;
    if(!wins.count(x)) wins[x] = 1;
    else wins[x]++;
    if(!loses.count(y)) loses[y]=1;
    else loses[y]++;
}
for(int i=1;i<=n;i++){
    if((wins[i]+loses[i]!=expected)){
        misses.push_back(i);

    }
}
x = misses[0];
y = misses[1];

if(wins[x]>=wins[y]){
    cout << x << " " << y;
}else{
    cout << y << " " << x;
}
}
