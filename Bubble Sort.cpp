void BubbleSortA(int A[],int N)
{
  while (N > 1)
  {
    int temp;
    for (int j = 0 ; j < N ; ++ j)
    {
      if(A[j] > A[j+1])
      {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }//while
}//void
