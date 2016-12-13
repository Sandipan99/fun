import math
import random as re
import numpy as np


__author__ = "Sandipan Sikdar"

def size_dist(l1):
	for line in l1:
		temp=line.strip().split("\t")
		print len(temp)
	print "========================="

def NMI(comm_football,comm_louvain,N):  #calculates NMI
	temp=[]
	temp1=[]	
	mid1=[]
	mid2=[]
	mid=[]
	I_omega=0.0
	for line1 in comm_football:
		temp=line1.split("\t")
		for i in xrange(len(temp)-1):
			mid1.append(int(temp[i]))
		count=0
		for line2 in comm_louvain:
			temp1=line2.split("\t")
			count+=1
			for j in xrange(len(temp1)-1):
				mid2.append(int(temp1[j])) 
			mid=list(set(mid1)&set(mid2))
			val1=float(N*(len(mid)))/(len(mid1)*len(mid2))
			val2=len(mid)/float(N)
			
			if(val1>0):
				I_omega+=val2*math.log(val1,2)
			mid2=[]
			mid=[]
		mid1=[]
	H_omega=0.0
	H_clus=0.0
	for line in comm_football:
		temp=line.split("\t")
		val=float(len(temp)-1)/N
		H_omega+=(-1)*val*math.log(val,2)
	for line in comm_louvain:
		temp=line.split("\t")
		val=float(len(temp)-1)/N
		H_clus+=(-1)*val*math.log(val,2)
	nmi=float(2*I_omega)/(H_omega+H_clus)
	return nmi

def permutation(l1,N):            # creates random permutation of partitions with same size distribution
	l2=[]
	size=[]
	to_samp_from=[]
	for i in xrange(N):
		to_samp_from.append(i+1)
	re.shuffle(to_samp_from)

	for i in xrange(len(l1)):
		temp=l1[i].strip().split("\t")
		size.append(len(temp))	
	s=0
	cnt=0
	str1=""
	for obj in to_samp_from:
		str1+=str(obj)+"\t"
		cnt+=1
		if cnt==size[s]:
			l2.append(str1)
			s+=1
			cnt=0
			str1=""	
	
	return l2

def rNMI(l1,l2,N):               # calculates rNMI metric
	nmi_1=NMI(l1,l2,N)
	exp_nmi=[]
	for i in xrange(10):
		l3=permutation(l2,N)
		exp_nmi.append(NMI(l1,l3,N))
	#print "returning: "+str(nmi_1-np.mean(exp_nmi))
	return (nmi_1-np.mean(exp_nmi))

def cNMI(l1,l2,N):               # calculates cNMI metric (mentioned in th paper)
	num=rNMI(l1,l2,N)+rNMI(l2,l1,N)
	den=rNMI(l1,l1,N)+rNMI(l2,l2,N)


	return num/den

if __name__=="__main__":        # main method

	comm_football=[]
	comm_louvain=[]
	
	fs=open("ground_truth_linewise")
	ft=open("cluster_linewise_5")
	for line in fs:
		line=line.replace("\n","")
		comm_football.append(line)
	fs.close()
	for line in ft:
		line=line.replace("\n","")
		comm_louvain.append(line)
	ft.close()

	print cNMI(comm_football,comm_louvain,4174)

