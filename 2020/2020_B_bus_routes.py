T = int(input())
for t in range(1, T+1):
	N, D = map(int, input().split())
	X = list(map(int, input().split()))
	res = D
	for i in range(N-1, -1, -1):
		res -= res % X[i]
	print("Case #{}: {}".format(t, res))