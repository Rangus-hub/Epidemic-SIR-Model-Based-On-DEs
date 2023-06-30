
# Epidemic Models
For an epidemic, there are many models that are used to study how virus spread. Models such as
SIS - Susceptible Infected Susceptible.
SIR - Susceptible Infected Recovered/Removed
SIER - Susceptible Exposed Infected Recovered/Removed

Other methods such as Agent Based Models and Multi-Group Models are also implemented.
This project aims at implementing a simple SIR model.

# SIR-Model-Based-On-DEs
This is an Epidemic SIR model based on Differential Equations. This code helps understand how
basic integration techniques can be implemented in C++.
The SIR model describes the change in the population of each of these compartments 
in terms of two parameters, β and γ.
β describes the effective contact rate(interactions) of the disease:
An infected individual comes into contact with βN other individuals 
per unit time (of which the fraction that are susceptible to contracting the
disease is S/N). γ is the mean recovery rate: that is, 1/γ is the mean period of
time during which an infected individual can pass it on.

SIR model differential equations:

dS/dt = (- β SI)/N

dI/dt = [(β S I)/ N]  - γI

dR/dt = γI
