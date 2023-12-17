#!/usr/bin/python3
from sys import argv, exit
if len(argv) < 2:
	print('Format: {} args ... dont use commas'.format(argv[0]))
	exit(1)

check = len(argv)
for index in range(1, check):
	if argv[index].isdigit():
		number = int(argv[index])
		while number != 0:
			rem = number % 10
			number = number // 10
			if rem == 3:
				rem2 = number % 10
				if rem2 == 3:
					print('True')
					break
		if number == 0:
			print('False')
	else:
		print("Agument isn't an integer")
