Lab 7 custom test suite

Author: Matt Elfbrandt

Design goals:
- Logical feature progression from simple literals to full programs.
- Coverage of all required Lab 7 language features except those explicitly excluded by the assignment.
- Bias toward bug-finding cases such as short-circuit logic, parameter order, recursion, byte-sized storage, shadowing, and indexed array access.

Test order summary:
test01  basic integer literals and unary minus
test02  arithmetic precedence, parentheses, divide, modulo
test03  int and char locals, assignment, byte-sized loads/stores
test04  nested blocks and shadowing
test05  relational/equality operators with if/else
test06  while loops and loop-carried state
test07  logical AND/OR with short-circuit behavior and function side effects
test08  zero-arg functions, multi-arg functions, nested calls, discarded return values
test09  function prototype plus recursive function definition
test10  one-dimensional int arrays with computed indices
test11  one-dimensional char arrays with byte addressing
test12  prints statements mixed with numeric print output

Excluded on purpose per lab directions:
- floating point and long integer operations
- structs
- multi-dimensional arrays
- non-int function returns
- passing arrays to functions
