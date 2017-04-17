#1
b=c(46,33,39,37,46,30,48,32,49,35,30,48)
max(b)
min(b)
sum(b)
length(b)
length(b[b>40])
sum(b>40)
round(length(b[b<35])/length(b)*100,2)

#2
log_natural=function(x)
{
  x=c(1,2,3,4,5)
  v=log(x)
  return(v)
}
log_natural(x)

min_max=function(x)
{
  x=(1:5)
  v=(x-max(x))/min(x)
  return (v)
}
min_max(x)

#3
log_natural=function(x)
{
  
  v=log(x)
  return(v)
}
x=scan("vector.txt")
log_natural(x)

#4
densitate=function(n,p)
{
  barplot(dbinom(0:n,n,p),main='grafic',col='red',xlab='axa X',ylab='axa Y')
}
densitate(25,0.3)
densitate(50,0.7)

#5
pmax=function(n,p)
{
  return(max(dbinom(0:n,n,p)))
}
pmax(25,0.3)

#6
paisson=function(lambda,n)
{return(dpois(0:n,lambda))}
paisson(3,20)

#7
ex7=function(file)
{
  file=read.table("test.txt",header=TRUE)
  x=file[['AA']]
  y=file[['BB']]
  plot(x,y,type='h',main='grafic',col='blue',lwd=10)
}
ex7()