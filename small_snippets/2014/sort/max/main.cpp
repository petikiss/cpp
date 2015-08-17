#include <iostream>


int main()
{
    int A[]={11,5,3,2,9,1,10,4,6};

    int r = sizeof(A)/sizeof(A[0]);
    while(r > 0)
    {
        std::cout << "r:" << r << std::endl;
        int i=0;
        int max=A[0];
        int pos=0;

        while(i<r)
        {
            std::cout << A[i] << std::endl;
            if(A[i]>max)
            {
                max=A[i];
                pos=i;
                std::cout << "Max:" << pos << " " << max << std::endl;
            }
            i++;
        }

        A[pos]=A[r-1];
        A[r-1]=max;
        r--;
        std::cout << "---------------------\n";
    }

    for(int i = 0; i < sizeof(A)/sizeof(A[0]);i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
