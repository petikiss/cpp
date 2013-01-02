#include <iostream>


int main()
{
    int A[]={11,5,7,3,2,6,9,10,1,4};

    int r = sizeof(A)/sizeof(A[0]);
    bool csere = false;
    while (r > 0 && !csere)
    {
        csere = true;
        for(int i=0; i < r-1; i++)
        {
            if (A[i] > A[i+1])
            {
                int tmp=A[i];
                A[i] = A[i+1];
                A[i+1] = tmp;
                csere = false;
            }
        }
        r--;
    }

    for(int j=0; j < sizeof(A)/sizeof(A[0]); j++)
    {
        std::cout << A[j] << " ";
    }
    std::cout << "\n";
    return 0;
}
