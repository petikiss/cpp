#include <iostream>


int main()
{
    int A[] = {1,5,7,9};
    int B[] = {2,8,9,10,11};
    int C[8];

    int i=0,j=0,k=0;
    int meretA =  sizeof(A)/sizeof(int);
    int meretB =  sizeof(B)/sizeof(int);

    while ( i < meretA || j < meretB )
    {
//        std::cout << A[i] << " " << B[j] << std::endl;
//        std::cout << "i:" << i << "j:" << j << std::endl;
        if(i >= meretA || A[i] > B[j])
        {
            C[k] = B[j];
            j++;
        }
        else if(j >= meretB || A[i] < B[j])
        {
            C[k] = A[i];
            i++;
        }
        else if (A[i] == B[j])
        {
            C[k] = A[i];
            i++;
            j++;
        }


        k++;
    }

    for (int i = 0; i < sizeof(C)/sizeof(int); i++)
    {
        std::cout << C[i] << " " << "\n";
    }
    return 0;
}
