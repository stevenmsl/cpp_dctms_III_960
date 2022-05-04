#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace sol960;
using namespace std;

/*takeaways
  - use DP and common longest Increasing Subsequence to solve
    the problem
    - common in a sense that each increasing subsequnce consists
      of the letters from the same set of indexes in each word
  - use Input: ["babca","bbazb"] as an example
    - start with column 0 , dp[0]=1
      A[0] = "b"
      A[1] = "b"
    - look at column 1
      A[0] = "ba" (x)
      A[1] = "bb" (O)
      - we can't extend the length of dp[0] as A[0] is not valid
        as A[0][0] > A[0][1]
      - so we don't update dp[1] and it remains at 1
    - look at column 2
      A[0] = "bab" (0)
      A[1] = "bba" (x)
      - A[1] is not valid do extend dp[0] or dp[1]
        so dp[2] remains 1
    - contiune the process to column 3
      A[0] = "babc"
      A[1] = "bbaz"
      - the only thing we can extend is dp[2] (both A[0] and A[1] agree)
        so dp[3] = dp[2] + 1 = 2
      - A[0] ="bc" A[1]="az"


*/
int Solution::minDeletions(vector<string> &A)
{
  int cols = A[0].size();

  /* the longest increasing subsequence we can get
     up to letter i
  */
  auto dp = vector<int>(cols, 1);

  for (auto c = 0; c < cols; c++)
    /* check all previous columns */
    for (auto j = 0; j < c; j++)
    {
      /* see if everyone agrees to extend
         its own increasing subsequence
         that end at the jth letter
      */
      bool agree = true;
      for (auto &w : A)
        if (w[c] < w[j])
        {
          agree = false;
          break;
        }
      if (agree)
        /* extend the length  */
        dp[c] = max(dp[c], dp[j] + 1);
    }

  /* see how many need to be removed */
  return cols - *max_element(begin(dp), end(dp));
}