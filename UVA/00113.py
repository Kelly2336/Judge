while True:
	try:
		n = int(input())
		p = int(input())
		b = 1000000000
		s = 1
		#binary search
		while True:
			mid = (b+s)//2
			r = mid ** n 
			if r == p :
				print(mid)
				break
			elif r < p :
				s = mid+1
			else :
				b = mid-1
	except:
		break
