/*
S(t)
are those susceptible but not yet infected with the disease;
I(t)
is the number of infectious individuals;
R(t)
are those individuals who have recovered from the disease and now have immunity to it.

The SIR model describes the change in the population of each of these compartments 
in terms of two parameters, β and γ. β describes the effective contact rate of 
the disease: an infected individual comes into contact with βN other individuals 
per unit time (of which the fraction that are susceptible to contracting the
disease is S/N). γ is the mean recovery rate: that is, 1/γ is the mean period of
time during which an infected individual can pass it on.

SIR model differential equations:
dS/dt = (- β SI)/N
dI/dt = [(β S I)/ N]  - γI
dR/dt = γI

β=0.2, 1/γ=10days in a population of N=1000 (for example crowd in a mall).
The model can be started with a single infected individual on day 0: I(0)=1. 
*/
#include <iostream>
#include <stdio.h>
using namespace std;
class epi
{
    public :

    float n;            //population
    float s,i,r;        //susceptible , infected , recovered
    float beta, gamma;  //effective contact rate(beta) , mean recovery rate(gamma)
    float time ;  //mean period of time during which an infected individual can pass it on.
    float dt;

    epi()
    {
        s = 0;  r = 0;  i = 0;
    }
    void setdt()
    {
        float t;
        cout<<"\nENTER dt FOR INTEGRATION: ";
        cin>>t;
        dt = t;
    }
    void init();
    void internal_calc();
    

}e;

void calc();

void epi::init()
{
    cout<<"\nENTER THE POPULATION: ";
    cin>>n;     //Typically 1000
    s = n;     //Susceptible Population = population
    cout<<"\nENTER NUMBER OF INFECTED PERSONS: ";
    cin>>i;
    r = 0;   //Recovered = 0
    beta = 0.2;
    gamma = 0.1; 
    time = 1/gamma;
}
void epi::internal_calc()
{
    //OUTPUT IN EVERY STEP
    printf("suseptible: %f , infectious: %f , recovered: %f\n",s,i,r);

    //CALCULATE NEW RATE AS PER SIR MODEL
    float newi,newr, news;

    float s_rate = ( (-beta) * s * i) / n;

    float i_rate = (( (beta*s*i) / n) - gamma * i);

    float r_rate = (gamma*i);

    //INTEGRATION TO GET NEXT S,I,R VALUES
    news = s + (s_rate * dt);
    newi = i + (i_rate * dt);
    newr = r + (r_rate * dt);

    //UPDATING VALUES
    s = news;
    i = newi;
    r = newr; 
}
void calc()
{
    cout<<"\nENTER TOTAL TIME(DAYS): ";
    int d,i;
    cin>>d;

    for(i = 0 ; i<d ; ++i)
        {e.internal_calc();cout<<endl;}
}
int main()
{
    cout<<"\n********************************* S I R MODEL BASED ON D Es *********************************\n";
    e.init();
    e.setdt();
    calc();
}
