T = int(input())
for t in range(1, T+1):
	N, K = map(int, input().split())
	root = {}
	res = 0
	for _ in range(N):
		w = input()
		node = root
		for c in w:
			if c not in node: node[c] = [{}, 0]
			node[c][1] += 1
			if node[c][1] % K == 0: res += 1
			node = node[c][0]
	print("Case #{}: {}".format(t, res))