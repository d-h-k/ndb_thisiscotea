#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char buf[200];

int lsum = 0,rsum = 0;
int main() {
    fgets(buf,200,stdin);
    int slen = strlen(buf);

    for(int i=0 ; i<slen/2 ; i++)  {
        lsum += (int)(buf[i]-'0');
        rsum += (int)(buf[i+(slen/2)]-'0');
    }


    if(lsum == rsum) { 
        cout << "LUCKY" << endl;
    }
    else {
        cout << "READY" << endl;
    }


    return 0;
}