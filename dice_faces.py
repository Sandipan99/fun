import random as re
import matplotlib.pyplot as plt

def all_face_up(l):
	flg=0
	for obj in l:
		if obj==0:
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
	ite=0

	count=[]

	while(ite<100000):
		face=[0 for i in xrange(6)]
		tries=0
		#dice=[1,2,3,4,5,6]
		while True:
			tries+=1
			f_c=re.randint(1,6)
			face[f_c-1]+=1
			if all_face_up(face):
				count.append(tries)
				break
		ite+=1

	distribution(count)
