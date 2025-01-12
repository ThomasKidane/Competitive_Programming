
#include <bits/stdc++.h> 
using namespace std; 
  
long long numberOfDivisors(long long num) {
    long long total = 1;
    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);
            total *= e + 1;
        }
    }
    if (num > 1) {
        total *= 2;
    }
    return total;
}
  
// Driver Program 
int main() 
{ 
    long long n;
    cin>>n;
    cout<<numberOfDivisors(n);
    return 0; 
} 