#include <iostream>
int main(){ushort n;std::cin >> n;for(ushort i=0;i<n;++i)for(ushort j=0; j<n; ++j) std::cout<<std::abs(i-j)<<" "<<(j==n-1?"\n":"");}
