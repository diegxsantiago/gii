//CLASE PROGRAMA LPS

#include<iostream>
#include<string.h>

using namespace std;

class Programa_LPS {
private:
   int v[1000];
   string instrucciones[100];
   int datos[3][100];
   int utilizados;
 
public:
  	
   Programa_LPS(){
  	
  	   for (int i = 0; i < 1000; i++)
  		   v[i]=0;
  		  
  	   for (int i = 0; i < 3; i++){
  		   for (int j = 0; j < 100; j++)
  		      datos[i][j]=0;
      }
      
      utilizados = 0;
   }

   void SetVar (int i, int e){
  	   v[i]=e;
   }

   void Instruccion (string inst, int e1, int e2, int e3){
    	instrucciones[utilizados]= inst;
    	datos[1][utilizados]= e1;
    	datos[2][utilizados]= e2;
    	datos[3][utilizados]= e3;
      utilizados++;
   }
   
   int GetVar (int i){
      return v[i];
   }
    	
   int Ejecutar(){
   	    	
      int i = 0;
      int codigo_error = 0;
        	
      while(instrucciones[i]!="FIN" && i <= utilizados){

    	   if (instrucciones[i]=="INI")
    		   v[datos[1][i]] = datos[2][i];
         else if (instrucciones[i]=="ASIG")
    		   v[datos[1][i]] = v[datos[2][i]];
    		else if (instrucciones[i]=="IND")
    		   v[datos[1][i]] = v[v[datos[2][i]]];
         else if (instrucciones[i]=="SUM")
    		   v[datos[1][i]] = v[datos[2][i]] + v[datos[3][i]];
    		else if (instrucciones[i]=="INC")
    		   v[datos[1][i]]++;
         else if (instrucciones[i]=="MULT")
    	     	v[datos[1][i]] = v[datos[2][i]] * v[datos[3][i]];
    	   else if (instrucciones[i]=="IR<"){
    		   if (v[datos[1][i]] < v[datos[2][i]])
    		      i = datos[3][i] - 1;
   		}
         else if (instrucciones[i]=="IR="){
            cout << v[datos[1][i]] << " == " << v[datos[2][i]];
    		   if (v[datos[1][i]]==v[datos[2][i]])
    		      i = datos[3][i] - 1;
      	}
      	else if (instrucciones[i]=="IR")
      	{
      	   i = datos[1][i] - 1;
         }  
    		else
    		   codigo_error = 1;
    		  
    		i++;	
      }
      
      return codigo_error;
   }
};
