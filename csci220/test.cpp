#include <iostream>

int findDuplicate(int A[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        while (A[i] != i + 1) 
        {
            if (A[i] == A[A[i] - 1]) // A[i] = i + 1
            {
                return A[i];
            }
            int tmp = A[A[i] - 1];
            A[A[i] - 1] = A[i];
            A[i] = tmp;
        }
    }
    
    return -1;
}

int main()
{
    int A[6] = {1,2,4,3,5,4}; 
    int n{6};
    std::cout << findDuplicate(A, n);
    return 0;
}