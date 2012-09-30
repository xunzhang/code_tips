#! /usr/bin/python
# Filename: Xor_Str.py
# A = ['monkey', 'dog', 'pig'], B = ['dog', 'pig'] => result = ['monkey']

def Xor_Str(str1, str2):
  res = '' 
  if len(str1) < len(str2):
    leng = len(str2)
  else:
    leng = len(str1)
  for i in range(leng):
    if i >= len(str1):
      str1 += chr(0)
    if i >= len(str2):
      str2 += chr(0)
    res += chr(ord(str1[i]) ^ ord(str2[i]))
  return res  

if __name__ == '__main__':
  A = ['monkey', 'dog', 'pig']
  B = ['pig', 'dog']
  result = ''
  
  for i in range(len(B)):
    A[i] = Xor_Str(A[i], B[i])
  
  result = A[len(A)-1]
  for i in range(len(A)-1):
    result = Xor_Str(result, A[i]) 
  print result
