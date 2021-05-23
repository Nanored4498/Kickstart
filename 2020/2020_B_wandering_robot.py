T = int(input())
fs = [1]
for t in range(1, T+1):
	W, H, L, U, R, D = map(int, input().split())
	res = 0
	if U > 1 and R < W:
		mul = 1
		po = R
		for u in range(U-1):
			res += mul * (0.5 ** po)
			mul *= (R+u) / (u+1)
			while mul > 1:
				mul /= 2
				po -= 1
			po += 1
	if L > 1 and D < H:
		mul = 1
		po = D
		for l in range(L-1):
			res += mul * (0.5 ** po)
			mul *= (D+l) / (l+1)
			while mul > 1:
				mul /= 2
				po -= 1
			po += 1
	print("Case #{}: {}".format(t, res))