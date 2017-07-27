#tema2-Ex1
QuickSort <- function(S) {
  if ( length(S) > 1 ) 
  {
    pivot <-sample(S,1)                          
    c(QuickSort(S[S < pivot]), S[S == pivot], QuickSort(S[S > pivot])) #pune in vector cazurile pentru pivot date 
  }
  else S
}

S <- runif(10, 1, 20)
print(S)
QuickSort(S)

#tema2-Ex2
Dfs=function(M,n,viz,nod)  #fac dfs pe graful initial
{ vizz=vector()
  for(i in 1:n)
  vizz[i]=viz[i]
  
  for(i in 1:n)
  if(M[nod,i]==1)
   if(vizz[i]==0)
    { vizz[i]=1 
    Dfs(M,n,vizz,i)}
  eval.parent(substitute(viz<-vizz))
}
NrC=function(M,n){      # aflu numarul de componente conexe ale grafului
  viz=vector()
  for(i in 1:n)
    viz[i]=0
  nr=0
  for(i in 1:n)
    if(viz[i]==0)
    {nr=nr+1
      Dfs(M,n,viz,i)}
   nr
}
Karger = function(A) {  
  
   n=nrow(A)       # numarul de linii din matricea de adiacenta
   k=0            
   c1=vector()     #c1 si c2 sunt toate muchiile din graf
   c2=vector()
   for(i in 1:n)
     {for(j in i:n)
       if(A[i,j]==1)
       { k=k+1
         c1[k]=i
         c2[k]=j
       }
   }
   m=k
   M=matrix(0,n,n)
   for(i in 1:n)
     M[i,i]=1
   nr_comp_conexe=10        # am pus un numar mai mare ca 2 pentru a intra in bucla while
   if(NrC(A,n)>=2)
   {return(0)}
   else{
   while(nr_comp_conexe>2&&m>1)      #daca sunt mai mult de 2 componente conexe atunci se termina algoritmul
   {                                 # pentru ca trebuie sa aflu numarul minim de taieturi pentru a imparti graful in 2
   nr=sample(1:m,1)                  # 2 componente conexe e ca si cum as avea din prima 2 grafuri si deci gata
   x=c1[nr] # alegere random a unei muchii
   y=c2[nr]
   M[x,y]=1  # stergerea muchiei de pe pozitia nr
   M[y,x]=1
   
   c1[nr]=c1[m]  #dupa ce sterg muchia duc ultima muchie in locul ei 
   c2[nr]=c2[m]
   m=m-1         #apoi logic ca scad numarul de muchii
   
   #in M conectez nodurile unite prin Contraction
   # asa cum spune si algoritmul o sa ma opresc in momentul in care o sa mai am 2 comp conexe in M
   # M matricea de adiacenta
   
   for(i in 1:m)
     {
     if(M[x,c1[i]]==1&&M[y,c2[i]]==1||M[x,c2[i]]==1&&M[y,c1[i]])
     { c1[i]=c1[m]
       c2[i]=c2[m]
       m=m-1
       i=i-1}
   }
   nr_comp_conexe=NrC(M,n)
   }
   m #asa cum spune algoritmul returnam nr minim de muchii ramase
   }
}
A=matrix(0,4,4)
A[1,2]=1
A[2,1]=1
A[3,4]=1
A[4,3]=1
A[2,3]=1
A[3,2]=1
A[2,4]=1
A[4,2]=1
A
Karger(A)

