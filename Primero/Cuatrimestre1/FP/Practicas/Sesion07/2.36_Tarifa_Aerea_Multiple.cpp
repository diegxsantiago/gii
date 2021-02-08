// Diego Santiago Ortiz

// Tarifa aérea: múltiples billetes

#include <iostream>
using namespace std;

int main(){
   
   const int    LIM_KMS_RECARGO = 300;
   const double RECARGO_KM = 0.1;
   const double MIN_KMS_DSCTO = 700.0;
   const int    MIN_PTOS_DSCTO_BAJO = 100;
   const int    MIN_PTOS_DSCTO_ALTO = 200;
   const int    DSCTO_KMS = 2;
   const int    DSCTO_BAJO_PTOS = 3;
   const int    DSCTO_ALTO_PTOS = 4;
   const double TRF_BASE = 150.0;
   const int    MAX_NUM_PTOS = 400;
   const int    MIN_NUM_PTOS = 0;
   const char   BILLETE_NUEVO = 'N';
   const char   TERMINADOR = '#';
      
   double dscto;
   double trf;
   int dist;
   int ptos_fideliz;
   char nuevo;
   
   cin >> nuevo;
   
   do{    
      if (nuevo == BILLETE_NUEVO){ 
         do{
            cin >> dist;         
         }while (dist < 0);
   
         do{
            cin >> ptos_fideliz;   
         }while (ptos_fideliz < MIN_NUM_PTOS
                ||
                MAX_NUM_PTOS < ptos_fideliz);
   
         trf = TRF_BASE;

         if (dist > LIM_KMS_RECARGO)
            trf = trf + RECARGO_KM*(dist - LIM_KMS_RECARGO) ;
        
         if (dist > MIN_KMS_DSCTO)
            dscto = DSCTO_KMS;   
         else
            dscto = 0;   
         
         if (ptos_fideliz > MIN_PTOS_DSCTO_ALTO)   
            dscto = dscto + DSCTO_ALTO_PTOS;
         else if (ptos_fideliz > MIN_PTOS_DSCTO_BAJO)   
            dscto = dscto + DSCTO_BAJO_PTOS;
         
         trf = trf * (1 - dscto / 100.0);

         cout << trf << " ";
      }
      
      cin >> nuevo;
         
   }while(nuevo != TERMINADOR);
   
}
