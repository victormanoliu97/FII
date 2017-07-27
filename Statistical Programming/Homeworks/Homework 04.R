#N - marime esantion
#sample_mean - media
#alfa =  1 - 90/100
#s = dispersia

#D2
populatie_interval=function(n,sample_mean,alfa,s)
  {
    se = sqrt(s/n)
    critical_t = qt(1 - alfa/2, n - 1)
    a = sample_mean - critical_t*se
    b = sample_mean + critical_t*se
    interval = c(a, b)
    interval
  }

populatie_interval(144,20,0.1,18)

#D4

#p0 e cazul de referinta si se traduce ca a doua medie a cazurilor de succes e mai mare decat media la care ne raportam
#adica 10% din 128 e mai mare decat 0.025 si daca este inseamna cazul 2 asimetrica la dreapta

f5=function(alfa,n,succese,p0,caz)
{
  p_prim = succese/n
  z_score = (p_prim - p0)/sqrt(p0*(1 - p0)/n)
  if(caz==1)#ip asimetrica la stanga
  {
    critical_z = qnorm(alfa, 0, 1)
  if(z_score>critical_z)
    
    print(" se accepta ipoteza nula")
  else
    print("nu se accepta")
  }
  else
    if(caz==2)#ip asimetrica la dreapta
    {
      critical_z=qnorm(1 - alfa, 0, 1)
      
     if(z_score < critical_z)
       
      print("se accepta ipoteza nula")
    else
      print("nu se accepta")
    }
  else#ip simetrica
  {
    critical_z=qnorm(1 - alfa/2, 0, 1)
  if(abs(z_score)!=abs(critical_z))
    print("se accepta ipoteza nula")
  else
    print("nu se accepta")
    }
  print("z este:")
  print(z_score)
  print("z stelat este:")
  print(critical_z)
}

f5(0.05,128,10,0.025,2)   #nnu se da interval interval de incredere deci fac cu cele mai frecvente 0.05 0.01
f5(0.01,128,10,0.025,2)
