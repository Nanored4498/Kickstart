T = int(input())
for t in range(1, T+1):
	N = int(input())
	H = list(map(int, input().split()))
	res = 0
	for i in range(1, N-1):
		if H[i-1] < H[i] and H[i+1] < H[i]:
			res += 1
	print("Case #{}: {}".format(t, res))