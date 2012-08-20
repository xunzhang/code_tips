#! /usr/bin/python
# Filename: M_and_E.py
# Copy from cmu-puzzles:
# The FBI has surrounded the headquarters of the Norne corporation. There are n people in the building. Each person is either an engineer or a manager. All computer files have been deleted, and all documents have been shredded by the managers. The problem confronting the FBI interrogation team is to separate the people into these two classes, so that all the managers can be locked up and all the engineers can be freed. Each of the n people knows the status of all the others. The interrogation consists entirely of asking person i if person j is an engineer or a manager. The engineers always tell the truth. What makes it hard is that the managers may not tell the truth. In fact, the managers are evil geniuses who are conspiring to confuse the interrogators.
# Under the assumption that more than half of the people are engineers, can you find a strategy for the FBI to find one engineer with at most n-1 questions?
# Is this possible in any number of questions if half the people are managers?
# Once an engineer is found, he/she can classify everybody else. Is there a way to classify everybody in fewer questions?

class Stack:
	def __init__(self):
		self.items = []
	
	def push(self, item):
		self.items.append(item)
	
	def pop(self)
		return self.items.pop()
	
	def is_empty(self):
		return (self.items == [])
