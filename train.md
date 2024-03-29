[number theory 1](https://www.hackerearth.com/fr/practice/math/number-theory/basic-number-theory-1/tutorial/) :
- modular arithmetic & property of modulo
- modular exponential (power)
- gcd with euclidian algo
- modular multiplicative inverse

[number theory 2](https://www.hackerearth.com/fr/practice/math/number-theory/basic-number-theory-2/tutorial/) :
- prime number vs composite number, for i = 1;i*i <= N approch bigO(sqrt(n))
- [Sieve of Erastothenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
- factorization

[Primality Tests](https://www.hackerearth.com/fr/practice/math/number-theory/primality-tests/tutorial/) (check number is prime nb or not)
- `for (int i = 2; i*i <= N; ++i){if(N%i == 0)return false} return true` ... not fast >= 10^15
Probable prime checker:
- fermat theorem: P (=prime), a (0 < a < P) => a^(p-1) = 1%p , check for k nb.
- Miller-Rabin: if X^2=(Y^2)%N and X! = +-Y%N => N(=composite)

[Euler's totient function](https://www.hackerearth.com/fr/practice/math/number-theory/totient-function/tutorial/)
--> X(=nat), all Y (1 <= Y < X) <=> GCD(X,Y) = 1 ==> count(all Y) (get all coprimes of X)
- avoid bruteforce using: N∏p(=prime, 1 <= p < n) (1-1/p)

[Combinatorics](https://www.hackerearth.com/fr/practice/math/combinatorics/basics-of-combinatorics/tutorial/)
- permutation formulation (R out of N): = N! / (N - R)!
- combination formula (R out of N): = N! / (N-R)! * R!
- Rules: A(=set{}), B(=set{}), X(=len(A)), Y(=len(B)), r of product: extractAny(A) + extractAny(B) => X*Y possibility. r of sum: extractAny(A + B) => X+Y possibility.
(NOT FINISH, --pascal triangle)

[Basics of Disjoint Data Structures](https://www.hackerearth.com/fr/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/) :
- union
- find

-------------

[Lagrange multiplier](https://en.wikipedia.org/wiki/Lagrange_multiplier)  (by doing exo tic-tac-toe):
( NOT FINISH --to check)

[contest training, March Easy 2018](https://www.hackerearth.com/en-us/challenge/competitive/march-easy-18/)
- exos: 1/5 perfect, 3/5 exercises tried
- points: 120/500 points
- finish: 264/1545 participants


------------
- sum of integers: sum(1 + 2 + 3 + ... + N) <=> ( N*(N+1) ) /2

----
- number of possibilites

-----------
identite remarquable:
(a + b)^2 = a^2 + 2ab + b^2
(a - b)^2 = a^2 - 2ab + b^2
(a + b)(a - b) = a^2 - b^2

- quadratic equation: equation of degre 2:  ax^2 + bx + c = 0 with (a != 0)
- linear equation: equation of degree 1: ax + b = 0 (with a != 0) || ax + by + c = 0 (with a and b != 0)

law of exponents:

- x^m + x^n = x^(m + n)

- (x^m)^n = x^(mn)

binary theorem


---------

