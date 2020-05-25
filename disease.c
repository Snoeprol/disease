/*
acute -> "Fast infections"
SIR-model deterministic
S -> I -> R
  ^--!
parameters:
\lambda force of infection = per capita rate to contract infection
\lambda * X = New infections, X in class S
*/
#include <stdio.h>
#include <string.h>

void main(int argc, char * argv[])
{	
	int steps = 100;
	double mu = 0;
	double rho = 0;
	double gamma = 0.01;
	double beta = 0.02;
	double I[steps], S[steps], R[steps];

	I[0] = 0.04;
	S[0] = 1-I[0];
	R[0] = 0;
	if(* argv[1] == 'b')
	{		
		mu = 0.1;
	}
	if(* argv[1] == 'p')
	{	
		mu = 0.1;
		rho = 0.003;
	}

	double dS, dI, dR;
	for(int i = 0; i < steps; i++)
	{
		printf("%i \t%.2f\t %.2f \t %.2f\t %.2f\n", i, S[i], I[i], R[i], S[i] + I[i] + R[i]);
		dS = -beta * S[i] * I[i] + mu * S[i] + mu - rho / (1 - rho) * I[i];
		dI = beta * S[i] * I[i] - gamma * I[i] - mu * I[i];
		dR = gamma * I[i] - mu * R[i];
	
		S[i+1] = S[i] + dS;
		I[i+1] = I[i] + dI;
		R[i+1] = R[i] + dR;
	}
}
