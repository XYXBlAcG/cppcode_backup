# -*- coding:utf-8 -*-

from sympy import *

a, b, c, d, e = symbols('a b c d e')
out = dict(solve(
	[a + b + c + d + e - 1,
	16*a + 8*b + 4*c + 2*d + e - 3,
	81*a + 27*b + 9*c + 3*d + e - 5,
	256*a + 64*b + 16*c + 4*d + e - 7,
	625*a + 125*b + 25*c + 5*d + e - 114514
	], [a, b, c, d, e]
))

for k, v in out.items(): print(f'{k} = {v}')