T = int(input())
for t in range(1, T+1):
	N = int(input())
	A = list(map(int, input().split()))
	c = [0]*(max(A)+1)
	h, g = 0, 0
	res = []
	for i in range(N):
		c[A[i]] += 1
		if A[i] > h: g += 1
		if g > h:
			h += 1
			g -= c[h]
		res.append(h)
	res = ' '.join(list(map(str, res)))
	print("Case #{}: {}".format(t, res))