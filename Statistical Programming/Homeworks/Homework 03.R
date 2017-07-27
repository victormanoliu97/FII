#1

#vreau sa vad de cate ori in rulari gasesc niste puncte care sa indeplineasca conditia din if pentru ca asa e formula
#data din cerinta

elipsoid = function(N,a,b,c) { 
  NC = 0; 
  for(i in 1:N) 
  {
    x = runif(1, -a, a);     #se alege un numar random intre -a si a si tot asa pt ca sunt intervale date
    y = runif(1, -b, b);
    z = runif(1, -c, c);
    if(((x*x)/(a*a) + (y*y)/(b*b) +(z*z)/(c*c))<= 1) {
      NC = NC + 1; }
    } 
  MC=8*a*b*c*NC/N;       #MC tre sa fie un numar constant * NC / N si ca sa determin numarul normal ar trebui
                         #2*a+2*b+2*c = 8*a*b*c pt ca a--a = a+a etc
  print(MC);
  print(4*pi/3*(a*b*c))  
  v=vector()     #luam un vector cu 2 pozitii : pe o pozitie pun eroare absoluta si pe cealalta eroarea relativa
  err_abs=abs(MC-(4*pi/3*(a*b*c)))   #eroarea absoluta se calculeaza ca modul din MC - valoarea data de prof
  err_rel=err_abs/(4*pi/3*(a*b*c))   #eroarea relativa este eroare_absoluta / valoarea data de prof cu pi
  v[1]=err_abs
  v[2]=err_rel
  v
} 
elipsoid(10000,2,3,4)

elipsoid(20000,2,3,4)

elipsoid(50000,2,3,4)

#3
#a
MC_integration = function(N) 
  { 
  sum = 0; 
  for(i in 1:N) 
    { 
    u = runif(1, 0, 1);
    sum = sum +( (cos(50*u)+sin(20*u))^2);
    } 
  return(sum/N);     # pentru ca avem multe rulari si sum este adunat la fiecare rulare si la sfarsit pentru ca N
                     # reprezintta toate cazurile posibile
  }

MC_integr_average= function(k, N) { 
  estimates=vector();
  for(i in 1:k) 
    estimates[i] = MC_integration(N); 
  print(mean(estimates));  } 
MC_integr_average(30,20000)

#b

MC_integration = function(N) 
{ 
  sum = 0; 
  for(i in 1:N) 
  { 
    u = runif(1, 0, 3);
    sum = sum +((u^3)/(u^4+1));
  } 
  return(3*sum/N);
}

MC_integr_average= function(k, N) {       #curs
  estimates=vector();
  for(i in 1:k) 
    estimates[i] = MC_integration(N); 
  print(mean(estimates));  }          

erori=function(MC,corect){
  v=vector()
  err_abs=abs(MC-corect)
  err_rel=err_abs/corect
  v[1]=err_abs
  v[2]=err_rel
  v
}
m=MC_integr_average(30,2000)
erori(m ,1.01168)

#C5

prob_infectate=function(N) #n este numarul de rulari
{
  sum_days=0     #numarul de zile
  sum_infectate=0  #nr de pc-uri infectate
  
  for(i in 1:N)
  {
    v=vector()     #fac un vector ca sa pun pc-uri infectate in el
    for(j in 1:20)
      v[j]=0       #il marchez la inceput cu 0
    nr_days = 2    #consider ca in prima in zi a fost infectat primul pc si de asta nr_days = 2, adica incep de la zi 2
    a=sample(1:20, 1)   #aleg un pc la intamplare
    v[a]=1              #il infectez si il marchez in vector
    k=1                 #k reprezinta numarul de pc-uri infectate si devine 1
    max_infectate=1     #maximul de calculatoare infectate este 1 pentru ca pe moment este un singur pc infectat
    while(k>0)          
    {
      z=runif(1,0,1)   #aleg un z intre 0 si 1 ce reprezinta probabilitatea ca virus sa ajunga de la pc infectat la pc curat
      if(z<=0.15)      # daca probab e mai mica decat 0.15
      { 
        ok=1           
        while(ok==1&&k<20)   
        {
          y=sample(1:20,1)  #pot alege un pc care este deja infectat pentru ca e ales random
          if(v[y]==0)       #de asta verific daca este infectat sau nu si abia daca nu este il infectez eu
          {
            v[y]=1
            k=k+1
            ok=0
          }
        }
      }
      
      if(k>max_infectate)
        max_infectate=k;
      
      t=runif(1,0,1)     # probab ca administratorul sa repare un calculator infectat
      if(t<=0.2)         
      {
        ok=1
        while(ok==1)
        {
          a=sample(1:20,1)   #alege un calculator la intamplare si il marcheaza curat
          
          if(v[a] == 1)
          {
            v[a]=0
            k=k-1
            ok=0
          }
        }
      }
      
      nr_days=nr_days+1
      
    }
    
    sum_days=sum_days+nr_days                  
    sum_infectate=sum_infectate+max_infectate
    
  }
  print("numar zile")
  print(sum_days/N)
  print("infectate")
  print(sum_infectate/N)
}
prob_infectate(5)

#C6

foc = function()
{
  P=matrix(0,50,20)
  P[1,1]=1
  C=matrix(0,2,1000)
  C[1,1]=1
  C[2,1]=1
  p=1
  u=1
  while(p<=u)
  {
    if(C[2,p]+1<=20){
      # copacu din dreapta
      a=runif(1,0,1)
      if(a<=0.8)
      {
        x=C[1,p]
        y=C[2,p]+1
        if(P[x,y]==0){
          P[x,y]=1
          u=u+1
          C[1,u]=C[1,p]
          C[2,u]=C[2,p]+1
        }
      }
    }
    if(C[2,p]-1>=1)
    {
      # copacu din stanga
      a=runif(1,0,1)
      if(a<=0.3)
      {
        x=C[1,p]
        y=C[2,p]-1
        if(P[x,y]==0){
          P[x,y]=1
          u=u+1
          C[1,u]=C[1,p]
          C[2,u]=C[2,p]-1
        }
      }
    }
    if(C[1,p]-1>=1)
    {
      # copacu de sus
      a=runif(1,0,1)
      if(a<=0.3)
      {
        x=C[1,p]-1
        y=C[2,p]
        if(P[x,y]==0){
          P[x,y]=1
          u=u+1
          C[1,u]=C[1,p]-1
          C[2,u]=C[2,p]
        }
      }
    }
    if(C[1,p]+1<=50)
    {
      # copacu de jos
      a=runif(1,0,1)
      if(a<=0.3)
      {
        x=C[1,p]+1
        y=C[2,p]
        if(P[x,y]==0){
          P[x,y]=1
          u=u+1
          C[1,u]=C[1,p]+1
          C[2,u]=C[2,p]
        }
      }
    }
    p=p+1
  }
  nr=0
  for(j in 1:50)
    for(k in 1:20)
      if(P[j,k]==1)
        nr=nr+1
  if(nr>=300)    #300 pentru ca e 30% din 1000
    return(1)
  else
    return(0)
}

padure=function(N)
{
  ars=0
for(i in 1:N)
{
  x=foc()
  print(x)
  if(x==1)
    ars=ars+1
  
}
  print("au ars 30%")
  print(ars)
  if(ars>0)
    a=1
  else
    a=0
  print("probabilitate")
  print(a)
}

padure(10000)