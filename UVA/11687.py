while True:
	s = input()
	if s == "END":
		break
	i = 1
	while True:
		s2 = str(len(s))
		if s2 == s:
			print(i)
			break
		i += 1
		s = s2
