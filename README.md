# weighted-interval-scheduling-algorithm

Implement the Dynamic Programming Weighted Interval Scheduling algorithm, store the requests on csv file: start,finish,value

Problem (Weighted Interval Scheduling)
Given a set of n intervals (si
, fi), each with a value vi
, choose a
subset S of non-overlapping intervals with P
i∈S
vi maximized.

Divide And Conquer Alogirthm Design:
one implicitly explores the space of all possible solutions, by
carefully decomposing things into a series of subproblemss, and then building up correct solutions to larger and larger subproblems.

Interval Scheduling
We have n requests labeled 1, . . . , n, with each request i specifying a
start time si and a finish time fi. Each interval i now also has a value, or weight
vi. Two intervals are compatible if they do not overlap. The goal of our current
problem is to select a subset S ⊆ {1, . . . , n} of mutually compatible intervals,
so as to maximize the sum of the values of the selected intervals, 
i∈S vi.

Recurion Opitmal Solution:
Compute-Opt(j)
If j = 0 then
Return 0
Else
Return max(vj+Compute-Opt(p(j)), Compute-Opt(j − 1))
Endif

This technique of saving values that have already been computed is referred
to as memoization.
. This procedure will make use of an array M[0 . . . n]; M[j] will
start with the value “empty,” but will hold the value of Compute-Opt(j) as
soon as it is first determined. To determine OPT(n), we invoke M-ComputeOpt(n).
a single call to M-Compute-Opt is O(1)

Since M has
only n + 1entries, it follows that there can be at most O(n) calls to M-ComputeOpt, and hence the running time of M-Compute-Opt(n) is O(n), as desired.

M-Compute-Opt so as to keep track of an optimal solution in addition to its
value: we could maintain an additional array S so that S[i]contains an optimal
set of intervals among {1, 2, . . . , i


Memoization of Recursion optimal solution:
M-Compute-Opt(j)
If j = 0 then
Return 0
Else if M[j] is not empty then
Return M[j]
Else
M[j] = max(
v[j] + MemoizedIntSched(p[j]),
MemoizedIntSched(j-1)
)
Return M[j]

ForwardIntSched(j):
M[0] = 0
for j = 1, ..., n:
M[j] = max(v[j] + M[p(j)], M[j-1])

Find-Solution(j)
If j = 0 then
Output nothing
Else
If vj + M[p(j)]≥ M[j − 1] then
Output j together with the result of Find-Solution(p(j))
Else
Output the result of Find-Solution(j − 1)
Endif
Endif
Since Find-Solution calls itself recursively only on strictly smaller values, it makes a total oof O(n) recursive calls; and since it spends constant time
per call, we have
(6.5) Given the array M of the optimal values of the sub-problems, FindSolution returns an optimal solution in O(n) time.


Key to the Efficient algorithm is the array in M
. It encodes the notion
that we are using the value of optimal solutions to the subproblems on intervals
{1, 2, . . . , j} for each j, and it uses (6.1) to define the value of M[j] based on
6.2 Principles of Dynamic Programming 259
values that come earlier in the array
. Once we have the array M, the problem
is solved: M[n] contains the value of the optimal solution on the full instance,
and Find-Solution can be used to trace back through M efficiently and return
an optimal solution itself.

Iterative Alogirthm:
We just
start with M[0]= 0 and keep incrementing j; each time we need to determine
a value M[j], the answer is provided by (6.1). The algorithm looks as follows.

Iterative-Compute-Opt:
M[0]= 0
For j = 1, 2, . . . , n
M[j]= max(vj + M[p(j)], M[j − 1])
Endfor

(i) There are only a polynomial number of subproblems.
(ii) The solution to the original problem can be easily computed from the
solutions to the subproblems. (For example, the original problem may
actually be one of the subproblems.)
(iii) There is a natural ordering on subproblems from “smallest” to “largest,”
together with an easy-to-compute recurrence (as in (6.1) and (6.2)) that
allows one to determine the solution to a subproblem from the solutions
to some number of smaller subproblems.



It should have instructions on how to run your program
You may use Go, Java, C++ and Python for this extra credit assignment
If you have questions about this assignment, please make an appointment.
Whatever points you get here, will be added to the midterm grade, even if they go above 100.
It is very important to make a descriptive README.md
Remember to follow the Academic Integrity guidelines from the syllabus, and that should only submit your own work.
You may include a link to a video on the README.md, the video does not substitute the detailed description, but it may show your program running.
