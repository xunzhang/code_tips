#! /usr/bin/python
# Filename: Str_cont.py
# Story from paultyma.blogspot.jp/2010/11/google-interviewing-story.html
# Example: String1: ABCDEFGHLMNOPQRS	String1: ABCDEFGHLMNOPQRS
#	   String2: DCGSRQPOM		String2: DCGSRQPOZ
#	   Output: true			Output: false
#
# Best complexity: o(m+n) m:len(String1) & n:len(String2)
#
# Notice: you must input the string in upper case!

dst = {	'A' : 2,
       	'B' : 3,
	'C' : 5,
	'D' : 7,
	'E' : 11,
	'F' : 13,
	'G' : 17,
	'H' : 19,
	'I' : 23,
	'J' : 29,
	'K' : 31,
	'L' : 37,
	'M' : 41,
	'N' : 43,
	'O' : 47,
	'P' : 53,
	'Q' : 59,
	'R' : 61,
	'S' : 67,
	'T' : 71,
	'U' : 73,
	'V' : 79,
	'W' : 83,
	'X' : 89,
	'Y' : 97,
	'Z' : 101}

String1 = 'ABCDEFGHLMNOPQRS'
String2 = 'DCGSRQPOZ'

pro = 1

for i in String1:
	pro *= dst[i]
for i in String2:
	if pro % dst[i] != 0:
		print 'false'
		exit()	
print 'true'

