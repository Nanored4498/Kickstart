MOD = int(1e9)
T = int(input())
for t in range(1, T+1):
	p = input()
	stack = []
	w, h = 0, 0
	mul = 1
	for c in p:
		if c == 'N': h = (h-mul)%MOD
		elif c == 'S': h = (h+mul)%MOD
		elif c == 'W': w = (w-mul)%MOD
		elif c == 'E': w = (w+mul)%MOD
		elif c == '(': continue
		elif c == ')': mul //= stack.pop(-1)
		else:
			d = ord(c) - ord('0')
			mul *= d
			stack.append(d)
	print("Case #{}: {} {}".format(t, w+1, h+1))