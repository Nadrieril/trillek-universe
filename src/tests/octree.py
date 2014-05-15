class BSPTree(object):
	def __init__(self, p1, p3):
		self.p1 = p1
		self.p3 = p3
		self.p2 = (p1+p3)/2.
		self.children=None

	def isLeaf(self):
		return type(self.children)!=list

	def makeChild(self, i):
		if i==0:
			self.children[i]=BSPTree(self.p1,self.p2)
		else:
			self.children[i]=BSPTree(self.p2,self.p3)

	def whichSide(self, o):
		return 0 if o<self.p2 else 1

	def add(self, o):
		if not self.p1<=o<self.p3: 1/0
		if self.children==None:
			self.children=o
		else:
			if self.isLeaf():
				o2=self.children
				self.children=[None]*2
				self.addAt(o2, self.whichSide(o2))
			self.addAt(o, self.whichSide(o))

	def addAt(self, o, i):
		if self.children[i]==None:self.makeChild(i)
		self.children[i].add(o)

	def __str__(self):
		if self.isLeaf():return self.children.__str__()
		else:
			return "[%s]"%", ".join([c.__str__() for c in self.children])
				

t=BSPTree(0,1)
t.add(0.5)
t.add(0.2)
t.add(0.1)
# print t.children[0].children
print t