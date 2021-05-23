T = int(input())
for t in range(1, T+1):
	R, C = map(int, input().split())
	m = []
	w = {}
	for _ in range(R):
		m.append(input())
		for c in m[-1]:
			if c not in w: w[c] = 0
			w[c] += 1
	s = {c:0 for c in w}
	res = ""
	def f(i, j):
		global res
		c = m[i][j]
		while i >= 0 and m[i][j] == c:
			s[c] += 1
			i -= 1
		if s[c] == w[c]:
			res += c
			for a in range(1, R):
				for b in range(C):
					if m[a][b] == c and s[m[a-1][b]] < w[m[a-1][b]]:
						f(a-1, b)
	for i in range(C):
		f(R-1, i)
	if len(res) == len(w):
		print("Case #{}: {}".format(t, res))
	else:
		print("Case #{}: {}".format(t, -1))