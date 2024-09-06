#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        int minX=0;
        int maxX=0;
        int minY=0;
        int maxY=0;
        bool found=false;
        string line;
        for(int x=1;x<=n;x++){
            cin>>line;
            for(int y=1;y<=m;y++){
                if(line[y-1]=='#'){
                    if(!found){
                        minX=x;
                        maxX=x;
                        minY=y;
                        maxY=y;
                        found=true;
                    } else {
                        minX=min(minX,x);
                        minY=min(minY,y);
                        maxX=max(maxX,x);
                        maxY=max(maxY,y);
                    }

                }
            }
        }
        int x=(minX+maxX)/2;
        int y=(minY+maxY)/2;
        cout<<x<<" "<<y<<endl;
}
}

