void linear_search(A[N] , int N , int value , int &here)
{
  bool found;
  int j;
  found = false;
  j = 0;
  while(!found && (j < N))
  {
    found = A[j] == value;
    ++ j;
  }
  if (found)
  {
    here = -1;
  }
  else
  {
    here = --j;
  }
}
