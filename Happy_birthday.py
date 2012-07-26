#! /usr/bin/python
# Filename : Happy_birthday.py
# from :www.douban.com/note/156130243 of NullPointer
 
c = [1]*14
c[6] = c[0]+c[1]
c[0] = c[10] = c[6]**(c[0]+c[6])
c[2] = c[3] = c[0]*c[6]
c[4] = c[-1] = c[0]+c[1]+c[2]
c[5] = -c[0]**c[6]
c[7] = c[0]+c[1]
c[8] = c[6]*c[7]
c[9] = c[6]+c[8]
c[11] = c[10]/c[6]
print "".join(chr(x+sum(c)+2**3-1) for x in c) 
