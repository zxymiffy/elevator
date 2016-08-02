
void Virus_System(N max , clinical_size , p lt , p i , p an , LNR , LIT ) { 
  CP = ∅ {Clinical Picture} 
 int  iterations =0 
  Get_Initial_Clinical_Picture(CP, clinical_size , p lt ) 
  Do{ 
    iterations =iterations+1; 
    For (c =1; c<=clinical_size;c++){
     If (Replicat_Type(CP(c)) ==‘Lytic’) 
	Lytic_Replication (c,LNR); 
     Else 
	Lysogenic_Replication(c);
    }
   while(iterations=NmaxorCheck_Gap(CP) =True); 
 }

void Get_Initial_Clinical_Picture (CP , clinical_size ,p lt ){ 
	For(i =1;i<=clinical_size;i++){ 
	 //Get randomly a feasible solution 
	 CP (i) = Get_Rnd_Feasible_Solution();
	 //Assign randomly a replication type, Lytic or Lysogenic  
	 Replicat_Type(CP(i))=Get_Rnd_Replication_Type (plt);
	}
}
void Procedure Lytic_Replication (c){ 
 //Get the number of replicated nucleus-capsids 
   z = Get_Rnd_Binomial_Probability(LNR , pr );
   z=Get_Value_Binomial (Z,LNR,pr); 
   CP(c).NR =CP(c).NR+z; 
   If (CP (c ).NR >CP (c ).LNR) 
    Interaction_Virus(c );
    }
void Interaction_Virus(c){
   Get_ Neighbourhood (c ,V c ); 
   //Get the probability of generating antibodies 
   A = Get_Rnd_Binomial_Probability(|V c |, p an ); 
   a = Get_Value_Binomial(A , |V c |, p an );
   //Get the probability of infection in the neighbourhood 
   Y = Get_Rnd_Binomial_Probability(|V c |, p i ); 
   y = Get_Value_Binomial(Y ,|V c |, p i );
   Get_Best_Neighbourhood_Solution(V c , y , a ,c NEW ); 
   c =cNEW ;
   Replicat_Type (CP(c)) =Get_Rnd_Replication_Type (plt); 
}
void  Get_Best_Neighbourhood_Solution(Vc,y,a){
       j = Get_Rnd_Starting_Evaluation(|V c |);
       int i =0 
       Do{ 
	  i =i+1; 
          Solution = Get_Solution(V c , j );
	  if (health(c NEW ) < health(Solution))
	  cNEW =Solution ;
	  j=j+1; 
       } while(i =y-a); 
}
void Lysogenic(c){
	 CP(c).IT =CP(c).IT+1;
	  If (CP (c ).IT > CP (c ).LIT) {
	   Mutation(c , c NEW );
	  c =cNEW ;
         Replicat_Type(CP(c)) =Get_Rnd_Replication_Type(PLytic);
	 }
}
int main() {

}

