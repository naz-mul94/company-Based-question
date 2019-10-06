#include <bits/stdc++.h>

using namespace std;

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {

    int xorLR=l^r;
    int i, flag=0;
    string binary="";
    for ( i = 31; i >= 0; --i)
    {
        int bitMask=1<<i;
        if((xorLR & bitMask) !=0)
        {
            flag=1;continue;
        }
        if(flag)
        {
            xorLR|=bitMask;
        }
    }
    return xorLR;
}

int main()
{
    

    int l;
    cin >> l;

    int r;
    cin >> r;

    int result = maximizingXor(l, r);

    cout << result << "\n";

    return 0;
}
