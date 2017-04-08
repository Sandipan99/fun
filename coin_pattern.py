import random as re
import numpy as np
import matplotlib.pyplot as plt

def toss():
	a = re.uniform(0,1)
	if a>0.5:
		return 0
	else:
		return 1

def pattern(out):
	if len(out)<4:
		return 0
	pattern = [1,1,0,0]
	for i in xrange(4):
		if out[i]!=pattern[i]:
			return 0
	return 1

def distribution(l):
	expect=0.0
	d={}
	for obj in l:
		if obj not in d:
			d[obj]=1
		else:
			d[obj]+=1

	x_axis=[]
	y_axis=[]
	for out,freq in sorted(d.items(),key=lambda x:x[0]):
		x_axis.append(out)
		y_axis.append(float(freq)/100000)
		expect+=out*(float(freq)/100000)

	print "Expectation: "+str(expect)
	plt.bar(x_axis,y_axis)
	plt.show()

if __name__=="__main__":
	
	ite =100000
	observ = []
	while(ite>0):
		throws = 0
		stack = []
		while True:
			throws+=1
			a = toss()
			if len(stack)<4:
				stack.append(a)
			else:
				del stack[0]
				stack.append(a)
			if pattern(stack)==1:
				observ.append(throws)
				break
								
 		#print throws
		ite-=1
	distribution(observ)
	#print np.mean(observ)
	
