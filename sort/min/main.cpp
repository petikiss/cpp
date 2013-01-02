#include <iostream>



int main()
{
    int A[]={10,11,2,1,3,12,5,0,6};


    for(int i=0; i < sizeof(A)/sizeof(A[0]);i++)
    {
        int pos=i;
        int min=A[pos];

        // minimum kereses
        for(int j=i+1;j < sizeof(A)/sizeof(A[0]);j++)
        {
            if(A[j] < min)
            {
                min=A[j];
                pos=j;
            }
        }

        A[pos]=A[i];
        A[i]=min;
    }

    for(int i=0; i < sizeof(A)/sizeof(A[0]);i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
