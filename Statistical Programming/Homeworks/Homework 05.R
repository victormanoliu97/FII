#E1

#daca in enunt spune mai mic => asimetric stanga
#daca in enunt spune mai mare => asimetric dreapta

f6=function(alfa,n, media, niu, disp, caz)
{
  
  z_score = (media- niu)/(disp/sqrt(n))
  if(caz==1)#ip asimetrica la stanga, media<niu
  {
    critical_z = qnorm(alfa, 0, 1)
    if(z_score<critical_z)
      print("se respinge ipoteza nula")
    else
      print("nu se respinge")
  }
  else
    if(caz==2)#ip asimetrica la dreapta, media>niu
    {
      critical_z=qnorm(1 - alfa, 0, 1)
      if(z_score>critical_z)
        print("se respinge ipoteza nula")
      else
        print("nu se respinge")
    }
  else#ip simetrica
  {
    critical_z=qnorm(1 - alfa/2, 0, 1)
    if(abs(z_score)>abs(critical_z))
      print("se respinge ipoteza nula")
    else
      print("nu se respinge")
  }
  print("z este")
  print(z_score)
  print("z stelat este")
  print(critical_z)
}
x=c(1.64,1.54,1.56,1.57,1.44,1.48,1.56)
media=mean(x)
disp=sd(x)

f6(0.01,7,media,1.6,disp,1)

#E3

#pasta se imbunatatste deci cariile scad deci asimetric stanga

z_test=function(alfa,n1,n2, media1, media2,  sigma1, sigma2, m0, caz)
{
  
  z_score = (media1-media2-m0)/sqrt(sigma1^2/n1+sigma2^2/n2)
  if(caz==1)#ip asimetrica la stanga, media<niu
  {
    critical_z = qnorm(alfa, 0, 1)
    if(z_score<critical_z)
      print("se respinge ipoteza nula")
    else
      print("nu se respinge")
  }
  else
    if(caz==2)#ip asimetrica la dreapta, media>niu
    {
      critical_z=qnorm(1 - alfa, 0, 1)
      if(z_score>critical_z)
        print("se respinge ipoteza nula")
      else
        print("nu se respinge")
    }
  else#ip simetrica
  {
    critical_z=qnorm(1 - alfa/2, 0, 1)
    if(abs(z_score)>abs(critical_z))
      print("se respinge ipoteza nula")
    else
      print("nu se respinge")
  }
  print("z este")
  print(z_score)
  print("z stelat este")
  print(critical_z)
}
z_test(0.01,100,100,3,3.5,0.6,0.4,0,1)
z_test(0.05,100,100,3,3.5,0.6,0.4,0,1)

#E6
T_test=function(alfa,n1,n2, media1, media2,  s1, s2, m0, caz, caz2)
{
  s=sqrt(((n1-1)*s1^2+(n2-1)*s2^2)/(n1+n2-2))
  if(caz2==1)
  {
    df=n1+n2-2
    T_score = (media1-media2-m0)/sqrt(s^2/n1+s^2/n2)}
  
  else
  {
    df=min(n1-1, n2-1)
    T_score = (media1-media2-m0)/sqrt(s1^2/n1+s2^2/n2)
  }
  
  if(caz==1)#ip asimetrica la stanga, media<niu
  {
    critical_T = qt(alfa, df)
    if(T_score<critical_T)
      print("se respinge ipoteza nula")
    else
      print("nu se respinge")
  }
  else
    if(caz==2)#ip asimetrica la dreapta, media>niu
    {
      critical_T=qt(1 - alfa, df)
      if(T_score>critical_T)
        print("se respinge ipoteza nula")
      else
        print("nu se respinge")
    }
  else#ip simetrica
  {
    critical_T=qt(1 - alfa/2, df)
    if(abs(T_score)>abs(critical_T))
      print("se respinge ipoteza nula")
    else
      print("nu se respinge")
  }
  print("T este")
  print(T_score)
  print("T stelat este")
  print(critical_T)
}
T_test(0.01,210,190,3.5,4,0.6,0.7,0,1,0)