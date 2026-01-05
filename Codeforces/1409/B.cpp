#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
#define ll long long int
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
ll t,a,b,x,y,n,cura,curb,curn;
ll prod1,prod2;
cin >> t;
for(int i=0;i<t;i++){
    cin >> a >> b >> x >> y >> n;
    cura=a;
    curb=b;
    curn=n;
        if((cura-curn)>x) cura-=curn;
        else{
            curn-=(cura-x);
            cura=x;
            if((curb-curn)>y) curb-=curn;
            else curb=y;
        }
        prod1 = cura*curb;

   cura=a;
    curb=b;
    curn=n;

        if((curb-curn)>y) curb-=curn;
        else{
            curn-=(curb-y);
            curb=y;
            if((cura-curn)>x) cura-=curn;
            else cura=x;
        }
        prod2 = cura*curb;

        if(prod1<prod2) cout << prod1 << endl;
        else cout << prod2 << endl;

}
}
 