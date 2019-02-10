def rev(x):
	sum = 0
	while x:
		sum = sum*10 + x%10
		x = x//10
	return sum

T = int(input())
for i in range(T):
	a,b = input().split()
	print( rev( rev(int(a)) + rev(int(b)) ) )
