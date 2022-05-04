#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol960;

/*
Input: ["babca","bbazb"]
Output: 3
Explanation: After deleting columns 0, 1, and 4, the final array is A = ["bc", "az"].
Both these rows are individually in lexicographic order (ie. A[0][0] <= A[0][1] and A[1][0] <= A[1][1]).
Note that A[0] > A[1] - the array A isn't necessarily in lexicographic order.
*/
tuple<vector<string>, int>
testFixture1()
{
  auto A = vector<string>{"babca", "bbazb"};
  return make_tuple(A, 3);
}

/*
Input: ["edcba"]
Output: 4
Explanation: If we delete less than 4 columns, the only row won't be lexicographically sorted.
*/
tuple<vector<string>, int>
testFixture2()
{
  auto A = vector<string>{"edcba"};
  return make_tuple(A, 4);
}
/*
Input: ["ghi","def","abc"]
Output: 0
Explanation: All rows are already lexicographically sorted.
*/
tuple<vector<string>, int>
testFixture3()
{
  auto A = vector<string>{"ghi", "def", "abc"};
  return make_tuple(A, 0);
}
void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.minDeletions(get<0>(f)) << endl;
}
void test2()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.minDeletions(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.minDeletions(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}