#include "p3p1.h"
using namespace std;

int FindEmpty(int* slot) {
for (int i=0;i<=34;i++) {
    if (*(slot+i)==0) return i;
}
return 0;
}


int main() {
    int slot[35];
    for (int i=0;i<=34;i++) slot[i]=0;
    /*slot[0]=1;
    slot[1]=1;
    cout<<FindEmpty(slot)<<endl;
    return 0;*/
}