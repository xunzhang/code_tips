#! /usr/bin/python
# Filename: Increment.py
# Notice: leftest index is LSB and rightest index is the MSB

def Increment(lst):
	i = 0
	while i < len(lst) and lst[i] == 1:
		lst[i] = 0
		i = i + 1
	if i < len(lst):
		lst[i] = 1	
	if i == len(lst):
		print 'overflow'
		exit()
	return lst

if __name__ == '__main__':
	length = raw_input("Please input length of the counter\n")
	lst = [0 for i in range(int(length))]
	print '0'
	print lst
	for i in range(2**int(length)-1):
		lst = Increment(lst)
		# for print 
		val = 0
		for i in range(int(length)):
			val += lst[i] * 2 ** i
		print val
		print lst
