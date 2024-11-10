#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s,a,b,ar,br,res;
    int arv = 0, brv =0;
    cin >> s;
    int n = s.length();
    a = s.substr(0, n/2);
    b = s.substr(n/2, n/2);
    for (char c : a)
        arv += (c-65);
    
    for (char c : b)
    {
        brv += (c-65);
        // cout << c << ' ' << c-65 << endl;
    }

    // cout << arv << ' '<< brv << endl;
    for (char c : a)
        ar += ((c - 65 + arv) % 26) + 65;
    
    for (char c : b)
        br += ((c - 65 + brv) % 26) + 65;
    // cout << ar << ' ' << br << endl;
    for (int i = 0; i < n/2 ; i++)
        res += ((ar[i] - 65 + (br[i] - 65)) % 26) + 65;
    
    cout << res << endl;

    return 0;
}