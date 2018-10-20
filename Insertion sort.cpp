void InsertionSortA(int A[], int N)
{
  int j,i,temp;
  for (j = 1 ; j < N ; ++ j)
  {
    i = j - 1;
    temp = A[j];
    while((i >= 0) && (A[i] < temp))
    {
      A[i+1] = A[i]
      -- i;
    }//while
    A[i + 1] = temp;
  }//for
}//void
