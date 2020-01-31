#include <iostream>

using namespace std;

int main()
{
    int ca,cb,N,A,B;
    int temp;
    while(cin>>ca>>cb>>N)
    {
        A = B = 0;
        while(A!=N && B!=N)
        {
            if(A == 0)
            {
                cout<<"fill A"<<endl;
                A = ca;
            }
            if(B == cb)
            {
                cout<<"empty B"<<endl;
                B = 0;
            }
            cout<<"pour A B"<<endl;
            temp = (cb > A+B) ? (A+B) : cb;
            A = (cb >= A+B) ? 0 : (A+B-cb);
            B = temp;
        }
        if(A==N)
        {
            if(B!=0)
            {
                cout<<"empty B"<<endl;
            }
            cout<<"pour A B"<<endl;
        }
        cout<<"success"<<endl;
    }
    return 0;
}
