void BinarySearchA (int A[] , int N)
{
  int low,high,middle;
  low = 0;
  high = N - 1;
  while(low <= high)
  {
    middle = (low + high) / 2;
    if(value == A[middle])
    {
      here = middle;
      return;
    }
    else if(value > A[middle])
    {
      low = middle + 1;
    }
    else
    {
      high = middle - 1;
    }
  }//while
  here = -1;
}//void
