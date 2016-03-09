#!/usr/bin/python


class Test:
	def a(self, var):
		print var
	def b(self, var):
		self.a(var)


test = Test()
test.b(3)
