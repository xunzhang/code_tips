#! /usr/bin/python
# Filename: Max_Adj_interval.py
# Notice: use the pigeonhole principle O(n)
# Shit: the loop iterator of python is soooo terrible!!

# sorted [1.0, 1.2, 1.3, 1.5, 1.9, 2.0]
raw_lst = [1.9, 1.99, 1.3, 1.0, 1.2, 1.5]
#raw_lst = [2, 1, 4, 5]
# find min and max val in lst 'by hand'
# init min and max
if raw_lst[0] > raw_lst[1]:
	min_val = raw_lst[1]
	max_val = raw_lst[0]
else:
	min_val = raw_lst[0]
	max_val = raw_lst[1]
# traverse
for val in raw_lst:
	if val < min_val:
		min_val = val
	if val > max_val: 
		max_val = val


# length of the hole
delta = (float)(max_val - min_val) / (float)(len(raw_lst) - 1)

# init bucket
bucket = {}
for i in range(len(raw_lst) - 1):
	bucket[i] = [0,0]
# hash lst into [min_val, min_val + delta], [min_val + delta, min_val + 2 * delta], ..., [max_val - delta, max_val] and get n-1 buckets 
for val in raw_lst:
	if (val - min_val) / delta == len(raw_lst) - 1:
		bucket[len(raw_lst)-2][1] = val
		if bucket[len(raw_lst)-2][0] == 0:
			bucket[len(raw_lst)-2][0] = val
		continue
	
	if bucket[(int)((val-min_val)/delta)][0] == 0 or bucket[(int)((val-min_val)/delta)][1] == 0:
		bucket[(int)((val-min_val)/delta)][0] = val
		bucket[(int)((val-min_val)/delta)][1] = val

	if val < bucket[(int)((val-min_val)/delta)][0]:
		bucket[(int)((val-min_val)/delta)][0] = val 

	if val > bucket[(int)((val-min_val)/delta)][1]:
		bucket[(int)((val-min_val)/delta)][1] = val 


#print bucket
max_int = 0
for key in bucket.keys():
	nxt = key + 1
	if nxt == len(raw_lst) - 1:
		break
	if bucket[key][1] == 0:
		continue
	while bucket[nxt][0] == 0:
		nxt = nxt + 1
	if max_int < (bucket[nxt][0] - bucket[key][1]):
		max_int = bucket[nxt][0] - bucket[key][1]


print 'the fucking result is', max_int
