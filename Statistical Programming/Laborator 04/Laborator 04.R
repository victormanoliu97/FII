#Exemplu 1
disc_area = function(N) { 
  NC = 0; 
  for(i in 1:N) 
  {
    x = runif(1, -1, 1);#genereaza o valoare aleatoare intre -1 si 1
    y = runif(1, -1, 1);
    if(x*x + y*y<= 1) 
      NC = NC + 1; }
  return(4*NC/N);
} 

disc_area(10000)

#Ex I.1
disc_volum = function(N) { 
  NC = 0; 
  for(i in 1:N) 
  {
    x = runif(1, -1, 1);
    y = runif(1, -1, 1);
    z = runif(1, -1, 1);
    if(x*x + y*y +z*z<= 1) 
      NC = NC + 1; } 
  MC=8*NC/N;
  v=vector()
  err_abs=abs(MC-(4*pi/3))
  err_rel=err_abs/(4*pi/3)
  v[1]=err_abs
  v[2]=err_rel
  
} 
disc_volum(10000)

#Ex I-2
#returneaza valoarea
elipsa = function(N) { 
  NC = 0; 
  for(i in 1:N) 
  {
    x = runif(1, -2, 2);
    y = runif(1, -2, 2);
    if(x*x + 4*y*y<= 4) 
      NC = NC + 1; } 
  return(16*NC/N);
} 
elipsa(100000)

#returneaza erorile
elipsa = function(N) { 
  NC = 0; 
  for(i in 1:N) 
  {
    x = runif(1, -2, 2);
    y = runif(1, -2, 2);
    if(x*x + 4*y*y<= 4) 
      NC = NC + 1; } 
  MC=16*NC/N;
  v=vector()
  err_abs=abs(MC-6.28)
  err_rel=err_abs/6.28
  v[1]=err_abs
  v[2]=err_rel
  v
} 
elipsa(10000)

#Ex I-3
Arie3 = function(N) { 
  NC = 0; 
  for(i in 1:N) 
  {
    x = runif(1, -1, 3);
    y = runif(1, 0, 4);
    if(y+x*x<2*x+3) 
      NC = NC + 1; } 
  return(16*NC/N);
}
Arie3(100000)
#Aria corecta=integrala de la -1 la 3 din y=32/3 :10,(6)

#Integrale-Exemplu 1
MC_integration = function(N) { 
  sum = 0; 
  for(i in 1:N) { 
    u = runif(1, 0, 10);
    sum = sum + exp(-u*u/2); } 
  return(10*sum/N); }
MC_integr_average= function(k, N) { 
  estimates=vector();
  for(i in 1:k) 
    estimates[i] = MC_integration(N); 
  print(mean(estimates)); 
  print(sd(estimates)); } 
MC_integr_average(30,20000)

#Integrale-Exemplu 2
#2
MC_improved_integration = function(N) { 
  sum = 0; 
  for(i in 1:N) {
    u = rexp(1, 1);
    sum = sum + exp(-u*u)/exp(-u); }
  return(sum/N); }
MC_imprvd_integr_average= function(k, N) { 
  estimates=vector();
  for(i in 1:k) 
    estimates[i] = MC_improved_integration(N); 
  print(mean(estimates));
  print(sd(estimates)); } 
MC_imprvd_integr_average(30,20000)

#Ex II-1
MC_integration = function(N) { 
  sum = 0; 
  for(i in 1:N) { 
    u = runif(1, 0, pi);
    sum = sum + cos(u)*cos(u); } 
  return(pi*sum/N);}
MC_integr_average= function(k, N) { 
  estimates=vector();
  for(i in 1:k) 
    estimates[i] = MC_integration(N); 
  print(mean(estimates));  } 
MC_integr_average(30,20000)

#b
MC_integration = function(N) { 
  sum = 0; 
  for(i in 1:N) { 
    u = runif(1, 0, 3);
    sum = sum + exp(u); } 
  return(3*sum/N); }
MC_integr_average= function(k, N) { 
  estimates=vector();
  for(i in 1:k) 
    estimates[i] = MC_integration(N); 
  print(mean(estimates)); 
} 
MC_integr_average(30,20000)

#Ex-II2 a)
MC_integration = function(N) { 
  sum = 0; 
  for(i in 1:N) { 
    u = runif(1, 0, 100);
    sum = sum + 1/(u*u+1); } 
  return(100*sum/N); }
MC_integr_average= function(k, N) { 
  estimates=vector();
  for(i in 1:k) 
    estimates[i] = MC_integration(N); 
  print(mean(estimates)); 
} 
erori=function(MC,corect){
  v=vector()
  err_abs=abs(MC,corect)
  err_rel=err_abs/corect
  v[1]=err_abs
  v[2]=err_rel
}
MC_integr_average(30,20000)
erori(MC_integr_average(30,20000),pi/2)

#Ex-II2 b)
MC_integration = function(N) { 
  sum = 0; 
  for(i in 1:N) { 
    u = runif(1, 2, 10);
    sum = sum + 1/(u*u-1); } 
  return(8*sum/N); }
MC_integr_average= function(k, N) { 
  estimates=vector();
  for(i in 1:k) 
    estimates[i] = MC_integration(N); 
  print(mean(estimates)); 
} 
erori=function(MC,corect){
  v=vector()
  err_abs=abs(MC-corect)
  err_rel=err_abs/corect
  v[1]=err_abs
  v[2]=err_rel
  v
}
MC_integr_average(30,50000)
erori(MC_integr_average(30,50000),0.3465)

#Ex-II-3
MC_improved_integration = function(N) { 
  sum = 0;
  for(i in 1:N) { 
    u = rexp(1, 1);
    sum = sum + exp(-u*u/2)/exp(-u); 
  } 
  return(sum/N);}
MC_imprvd_integr_average= function(k, N) { 
  estimates=vector()
  for(i in 1:k) 
    estimates[i] = MC_improved_integration(N); 
  print(mean(estimates));
  print(sd(estimates)); }
MC_imprvd_integr_average(30,40000)

#Ex-III-1
Nr_days = function() { 
  nr_days = 1;
  last_errors = c(11,16,18);
  nr_errors = 11; 
  while(nr_errors > 0) {
    lambda = mean(last_errors);
    nr_errors = rpois(1, lambda);
    last_errors = c(nr_errors, last_errors[1],last_errors[2]) ;
    nr_days = nr_days + 1; } 
  return(nr_days); }
MC_nr_days = function(N) {
  s = 0; 
  for(i in 1:N) 
    s = s + Nr_days(); 
  return(s/N); }
MC_nr_days(1000)

#Ex-III-2
MC_mecanic=function(N)
{
  T=0.0
  for(i in 1:N){
    c=runif(1,0,1)
    if(c<=0.8)
      T=T+rexp(1,20)
    else
      T=T+rexp(1,5)
  }
  return(T/N)
}
MC_mecanic(1000)

# Ex IV-1
MC_prob=function(N)
{prob=0
for(i in 1:N)
{x=rpois(1,lambda=3)
y=rpois(1,lambda=5)
if(x>y)
  prob=prob+1}
return(prob/N)
}
MC_prob(1000)


