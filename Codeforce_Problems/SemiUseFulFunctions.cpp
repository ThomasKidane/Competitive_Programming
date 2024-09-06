
/*Shifts the array a l places to the left
a - array to be edited ->
t -  total length of array a(1=>0)
n - upto what index do you want the array to be shifted, if the whole array needs to be shifted put t-1
l - number to be shifted towards the left

Note:- This function could used on a string, might need some conversion
*/
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<'\n';
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a
typedef long long ll;
using namespace std;

int isprime(int N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}

std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

int maxSubArrSum(){
    ll x=0;
    ll Sum=0;
    for(int i=0;i<n;i++){
        Sum=max(Sum+a[i],0ll);
        x=max(x,Sum);
    }
    return x;
}

void shiftL(int a[],int t,int n,int l){
    int Ret[t];
    for(int i=l;i<=n;i++){
        Ret[i-l]=a[i];
    }
    for(int i=0;i<l;i++){
        Ret[n-l+i+1]=a[i];
    }
    for(int i=n+1;i<t;i++){
        Ret[i]=a[i];
    }
    for(int i=0;i<t;i++){
        a[i]=Ret[i];
    }
}

bool isPalindrome(string s){
    reverse(s.begin(),s.end());
    string t=s;
    reverse(s.begin(),s.end());
    if(s==t)return true;
    else return false;
}