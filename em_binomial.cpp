#include<iostream>
#include<stdlib.h>
#include<math.h>

void display(int (*obs)[10]){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<10;j++)
			std::cout << obs[i][j] << " ";
		std::cout<< std::endl;
	}
		
}

void ExpectationMaximization(int (*obs)[10]){
	double theta_1 = 0.6, theta_2 = 0.5,p,p_1,p_2,h_1,t_1,h_2,t_2;
	int iterations = 10;
	int i,j;
	//display(obs);
	int heads[5];
	for(i=0;i<5;i++){
		heads[i] = 0;
		for(j=0;j<10;j++){
			if(obs[i][j]==1)
				heads[i]++;
		}
	} 
	/*
	for(i=0;i<5;i++)
		std::cout << heads[i] << " ";
	std::cout << std::endl;*/
	while(iterations>0){
		h_1=0,t_1=0,h_2=0,t_2=0;
		for(i=0;i<5;i++){
			p_1 = pow(theta_1,heads[i])*pow(1-theta_1,10-heads[i]);
			p_2 = pow(theta_2,heads[i])*pow(1-theta_2,10-heads[i]);
			//std::cout << p_1 << ", " << p_2 << std::endl;
			p = p_1+p_2;
			p_1 = p_1/p;
			p_2 = p_2/p;
			h_1+= p_1*heads[i];
			t_1+= p_1*(10 - heads[i]);
			h_2+= p_2*heads[i];
			t_2+= p_2*(10 - heads[i]);
			//std::cout<< h_1 << "H," << t_1 << "T||" << h_2 << "H," << t_2 << "T" <<std::endl;
		}
		//std::cout << p_1 << "," << p_2 << "," << h_1<<","<<t_1<<","<<h_2<<","<<t_2 << std::endl;
		theta_1 = h_1/(h_1+t_1);
		theta_2 = h_2/(h_2+t_2); 
		//std::cout << theta_1 << " " << theta_2 << std::endl;
		//std::cout << "---------------------" << std::endl;
		iterations--;
	}
	std::cout << theta_1 << " " << theta_2 << std::endl;
}

int main(int argc, char* argv[]){
	float theta_1=0.4,theta_2=0.8,u,theta,v;
	int i,j;
	//int obs[5][10] = {{1,0,0,0,1,1,0,1,0,1},{1,1,1,1,0,1,1,1,1,1},{1,0,1,1,1,1,1,0,1,1},{1,0,1,0,0,0,1,1,0,0},{0,1,1,1,0,1,1,1,0,1}};
	int obs[5][10];
	//perform random experiment
	std::srand(time(0));
	
	for(i=0;i<5;i++){
		u = (float)(rand())/RAND_MAX;
		if(u>0.5)
			theta = theta_1;
		else	theta = theta_2;
		for(j=0;j<10;j++){
			v = (float)(rand())/RAND_MAX;
			if(v<theta)
				obs[i][j] = 1; //1->head, 0->tail
			else	obs[i][j] = 0;
		}
	}

	ExpectationMaximization(obs);
	return 0;
}

