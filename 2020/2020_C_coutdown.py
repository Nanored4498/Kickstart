T = int(input())
for t in range(1, T+1):
	N, K = map(int, input().split())
	A = list(map(int, input().split()))
	dec = 1
	res = 0
	for i in range(1, N):
		if A[i] == A[i-1]-1: dec += 1
		else: dec = 1
		if dec >= K and A[i] == 1: res += 1
	print("Case #{}: {}".format(t, res))