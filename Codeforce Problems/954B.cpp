#include <bits/stdc++.h>
using namespace std;
bool canBeStabilized(long long* a[],int n,int m){
    int ax;
    int b;
    bool found=false;

    for (int y=0;y<n;y++){
            if (found){
                break;
            }
            for (int x=0;x<m;x++){
                if(y<n-1 && y>0){
                    if(x<m-1 && x>0){
                        if(a[y][x]>a[y-1][x] && a[y][x]>a[y][x-1] && a[y][x]>a[y+1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            break;
                        }
                    } else if(x==0){
                        if(a[y][x]>a[y-1][x] && a[y][x]>a[y+1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            break;
                        }
                    } else if(x==m-1){
                        if(a[y][x]>a[y-1][x] && a[y][x]>a[y+1][x] && a[y][x]>a[y][x-1]){
                            found=true;
                            ax=y;
                            b=x;
                            break;
                        }
                    }
                } else if(y==0){
                    if(x<m-1 && x>0){
                        if(a[y][x]>a[y][x-1] && a[y][x]>a[y+1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            break;
                        }
                    } else if(x==0){
                        if(a[y][x]>a[y+1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            break;
                        }
                    } else if(x==m-1){
                        if(a[y][x]>a[y+1][x] && a[y][x]>a[y][x-1]){
                            found=true;
                            ax=y;
                            b=x;
                            break;
                        }
                    }
                } else {
                    if(x<m-1 && x>0){
                        if(a[y][x]>a[y][x-1] && a[y][x]>a[y-1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            break;
                        }
                    } else if(x==0){
                        if(a[y][x]>a[y-1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            break;
                        }
                    } else if(x==m-1){
                        if(a[y][x]>a[y-1][x] && a[y][x]>a[y][x-1]){
                            found=true;
                            ax=y;
                            b=x;
                            break;
                        }
                    }
                }
        }
    }
    if (found){
        return true;
    } else {
    return false;
    }
}

int* getStabilizeCoordinate(long long* a[],int n,int m){
    int ax;
    int b;
    bool found=false;
    for (int y=0;y<n;y++){
            if (found){
                break;
            }
            for (int x=0;x<m;x++){
                if(y<n-1 && y>0){
                    if(x<m-1 && x>0){
                        if(a[y][x]>a[y-1][x] && a[y][x]>a[y][x-1] && a[y][x]>a[y+1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            a[y][x]=max(a[y-1][x],max(a[y][x-1],max(a[y+1][x],a[y][x+1])));
                            break;
                        }
                    } else if(x==0){
                        if(a[y][x]>a[y-1][x] && a[y][x]>a[y+1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            a[y][x]=max(a[y-1][x],max(a[y+1][x],a[y][x+1]));
                            break;
                        }
                    } else if(x==m-1){
                        if(a[y][x]>a[y-1][x] && a[y][x]>a[y+1][x] && a[y][x]>a[y][x-1]){
                            found=true;
                            ax=y;
                            b=x;
                            a[y][x]=max(a[y-1][x],max(a[y+1][x],a[y][x-1]));
                            break;
                        }
                    }
                } else if(y==0){
                    if(x<m-1 && x>0){
                        if(a[y][x]>a[y][x-1] && a[y][x]>a[y+1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            a[y][x]=max(a[y][x-1],max(a[y+1][x],a[y][x+1]));
                            break;
                        }
                    } else if(x==0){
                        if(a[y][x]>a[y+1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            a[y][x]=max(a[y+1][x],a[y][x+1]);
                            break;
                        }
                    } else if(x==m-1){
                        if(a[y][x]>a[y+1][x] && a[y][x]>a[y][x-1]){
                            found=true;
                            ax=y;
                            b=x;
                            a[y][x]=max(a[y+1][x],a[y][x-1]);
                            break;
                        }
                    }
                } else {
                    if(x<m-1 && x>0){
                        if(a[y][x]>a[y][x-1] && a[y][x]>a[y-1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            a[y][x]=max(a[y][x-1],max(a[y-1][x],a[y][x+1]));
                            break;
                        }
                    } else if(x==0){
                        if(a[y][x]>a[y-1][x] && a[y][x]>a[y][x+1]){
                            found=true;
                            ax=y;
                            b=x;
                            a[y][x]=max(a[y-1][x],a[y][x+1]);
                            break;
                        }
                    } else if(x==m-1){
                        if(a[y][x]>a[y-1][x] && a[y][x]>a[y][x-1]){
                            found=true;
                            ax=y;
                            b=x;
                            a[y][x]=max(a[y-1][x],a[y][x-1]);
                            break;
                        }
                    }
                }
        }
    }
    int B[2];
    B[0]=ax;
    B[1]=b;
    return B;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    int n;
    int m;
    int a;
    int B[2];
    for(int i=0;i<t;i++){
        cin>>n>>m;
        long long* a[n];
        for (int y=0;y<n;y++){
            a[y]=new long long[m];
            for (int x=0;x<m;x++){
                cin>>a[y][x];
        }}
        while (canBeStabilized(a,n,m)){
                    getStabilizeCoordinate(a,n,m);
                }
                for (int t=0;t<n;t++){
            for (int y=0;y<m;y++){
                cout<<a[t][y]<<" ";
            }
            cout<<endl;
            }


    }

}


