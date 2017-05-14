
#1.ex1
x=scan("sample1.txt")
stem(x)

#1.ex2
tablou = read.csv("unemploy2012.csv",  sep =";",header = T)
rate= tablou[["rate"]]
max(rate)
hist(rate,breaks=c(0,4,6,8,10,12,14,30),right=T,freq=T,col='blue')

#1.ex3
tablou = read.csv("life_expect.csv",header = T)
male= tablou[["male"]]
female= tablou[["female"]]
intervale=7;
hist(male,breaks = intervale,right=TRUE, freq=TRUE,col='blue')
hist(female,breaks = intervale,right=TRUE, freq=TRUE,col='red')

#2.ex1
esantion1=scan("sample1.txt")
mean(esantion1)
median(esantion1)

#2.ex2
tablou=read.csv("life_expect.csv",header = T)
m = tablou[["male"]]
f = tablou[["female"]]
mean(m)
median(m)
mean(f)
median(f)

#2.ex3
modul=function(x)
{
  maxim=0
  mod=0
  for(i in 1:length(x))
  {
    nr=0
    for(j in 1:length(x))
      if(x[i]==x[j])
        nr=nr+1
      if(nr>maxim)
      { 
        maxim=nr
        mod=x[i]
      }
  }
  
  mod
}
x=c(9,8,8,9 ,8, 41, 9,5,40 ,9)
modul(x)

#3.ex1
outliers_mean=function(esantion)
{
  m = mean(esantion)
  s = sd(esantion)
  new_esantion = vector()
  j = 0
  for(i in 1:length(esantion))
    if(esantion[i] >=m + 2*s || esantion[i] <= m - 2*s) {
      j = j + 1
      new_esantion[j] = esantion[i]
    }
  new_esantion
}
esantion = c(1, 91, 38, 72, 13, 27, 11, 85, 5, 22, 20, 19, 8, 17, 11, 15, 13, 23, 14, 17)
outliers_mean(esantion)  

#3.ex2
outliers_iqr=function(esantion)
{
  Q1=as.vector(quantile(esantion))[2]
  Q3=as.vector(quantile(esantion))[4]
  IQR=Q3-Q1
  new_esantion = vector()
  j = 0
  for(i in 1:length(esantion))
    if(esantion[i] <=Q1 - 1.5 *IQR || esantion[i] >= Q3 + 1.5 * IQR) {
      j = j + 1
      new_esantion[j] = esantion[i]
    }
  new_esantion
}
esantion = c(1, 91, 38, 72, 13, 27, 11, 85, 5, 22, 20, 19, 8, 17, 11, 15, 13, 23, 14, 17)
outliers_iqr(esantion)

#3.3
x=scan("sample2.txt")
summary(x)
outliers_iqr(x)
outliers_mean(x)
