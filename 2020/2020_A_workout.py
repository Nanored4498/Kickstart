import heapq

T = int(input())
for t in range(1, T+1):
	N, K = map(int, input().split())
	M = list(map(int, input().split()))
	for i in range(N-1):
		M[i] = (M[i] - M[i+1], M[i] - M[i+1], 1)
	M.pop()
	heapq.heapify(M)
	for _ in range(K):
		if len(M) == 0: break
		dt, l0, d = heapq.heappop(M)
		d += 1
		if d < -l0:
			dt = l0 // d
			heapq.heappush(M, (dt, l0, d))
		else: break
	res = 1 if len(M) == 0 else -M[0][0]
	print("Case #{}: {}".format(t, res))