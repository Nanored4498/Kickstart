T = int(input())
op = "+*#"
for t in range(1, T+1):
	N = int(input())
	E = [input() for _ in range(N)]
	m = {}
	M = -1
	def ast(e):
		if e[0] == '(':
			i, p = 1, 0
			while p != 0 or e[i] not in op:
				if e[i] == '(': p += 1
				elif e[i] == ')': p -= 1
				i += 1
			return (e[i], ast(e[1:i]), ast(e[i+1:-1]))
		else:
			return int(e)
	def ev(e):
		global M
		if type(e) == int:
			if e == 0: return tuple()
			return ((tuple(), e),)
		a, b = ev(e[1]), ev(e[2])
		if e[0] == '#':
			if (a, b) not in m:
				m[(a, b)] = M
				M -= 1
			return (((m[(a, b)],), 1),)
		if e[0] == '+':
			i, j = 0, 0
			c = []
			while i < len(a) and j < len(b):
				if a[i][0] == b[j][0]:
					c.append((a[i][0], a[i][1] + b[j][1]))
					i += 1
					j += 1
				elif a[i][0] < b[j][0]:
					c.append(a[i])
					i += 1
				else:
					c.append(b[j])
					j += 1
			c += a[i:] + b[j:]
			return tuple(c)
		c = []
		for x, y in a:
			for x2, y2 in b:
				c.append((tuple(sorted(list(x)+list(x2))), y*y2))
		c.sort()
		c2 = []
		for x, y in c:
			if len(c2) > 0 and x == c2[-1][0]: c2[-1] = (x, c2[-1][1] + y)
			else: c2.append((x, y))
		return tuple(c2)

	Z = 1
	C = {}
	ans = []
	for e in E:
		e = ev(ast(e))
		if e not in C:
			C[e] = Z
			Z += 1
		ans.append(C[e])
	ans = ' '.join(str(z) for z in ans)
	print("Case #{}: {}".format(t, ans))