A, B = map(int, input().split())

if B > 0:
	p = A//B
else:
	B *= -1

	if A % B == 0:
		p = -A//B
	else:
		p = -A//B + 1
	
	B *= -1

print(p)
print(A-p*B)