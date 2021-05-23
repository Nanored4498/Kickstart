T = int(input())
for t in range(1, T+1):
	N, K, P = map(int, input().split())
	beauty = [None]
	for _ in range(N):
		b = [0] + list(map(int, input().split()))
		for i in range(1, K):
			b[i+1] += b[i]
		beauty.append(b)
	V = [[0]*(P+1)] + [[0] + [-1]*P for _ in range(N)]
	def f(n, p):
		if V[n][p] == -1:
			V[n][p] = max(beauty[n][k] + f(n-1, p-k) for k in range(min(K+1, p+1)))
		return V[n][p]
	res = f(N, P)
	print("Case #{}: {}".format(t, res))