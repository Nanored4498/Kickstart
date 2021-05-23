T = int(input())
for t in range(1, T+1):
	N, B = map(int, input().split())
	A = sorted(list(map(int, input().split())))
	res, p = 0, 0
	while res < N and p+A[res] <= B:
		p += A[res]
		res += 1
	print("Case #{}: {}".format(t, res))