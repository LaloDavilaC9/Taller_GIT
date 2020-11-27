#include <iostream>
#include <Windows.h>

using namespace std;

class Time{
	private:
		int dia;
		int mes;
		int anio;
	public:
		Time(int =7, int =2, int =2001);//constructores
		Time(char *datos);
		Time(const Time &);
		//////////////////////////
		int dayy();
		int dayw();
		int weeky();
		////////////////
		bool valy(int bus);
		bool vald(int bus);
		int day();
		void day(int n);
		///////////////
		int month();
		void month(int n);
		//////////////////
		int year();
		void year(int n);
		bool valmes(int nmes);
		
		////////////////////////////////////////////////////////
		 friend ostream & operator <<(ostream &, Time &);
		
	/////////////////////////////////////////////////////////////////////////
		void operator =(char *datos){
        char vec[2],vec2[4];
        vec[0]=datos[0];
        vec[1]=datos[1];
        this->dia=(atoi(vec));
        vec[0]=datos[3];
        vec[1]=datos[4];
        this->mes=(atoi(vec));
        vec2[0]=datos[6];
        vec2[1]=datos[7];
        vec2[2]=datos[8];
        vec2[3]=datos[9];
        
        this->anio=(atoi(vec2));
    }
	//////////////////////////////////////////////////////////////////////////////
	void operator =(Time & a){
        bool aux;
        if(a.mes >=1 && a.mes<=12)
            this->mes=a.mes;
        else
            cout<<endl<<"Mes invalido";
        
        if(a.anio>=1500 && a.anio<=2500)
            this->anio=a.anio;
        else
            cout<<endl<<"Año invalido";
        
        aux=this->vald(a.dia);
        if(aux==true)
             this->dia=a.dia;
        else{
		
            this->dia=1;
            cout<<endl<<"Dia invalido, se asigno el dia 1 por defecto";
        }
    }
    ////////////////////////////////////////////////////////////////////
    bool operator==(Time & a){
        int i=0;
        bool aux=false;
        if(this->dia==a.dia)
            i++;
        
        if(this->mes==a.mes)
            i++;
        
        if(this->anio==a.anio)
            i++;
        
        if(i==3)
            aux=true;
        
        return aux;
    }
    ////////////////////////////////////////////////////////////////////
    bool operator !=(Time & a){
        int i=0;
        bool aux=true;
        if(this->dia==a.dia)
            i++;
        
        if(this->mes==a.mes)
            i++;
        
        if(this->anio==a.anio)
            i++;
        
        if(i==3)
            aux=false;
        
        return aux;
    }
		///////////////////////////////////////////////////////////////
	void operator ++(){
			bool aux;
			aux=this->vald((this->dia)+1);
			if(aux==true)
				this->dia=this->dia+1;
					else
						cerr<<endl<<"No es posible aumentar ese dia...";
		}
		///////////////////////////////////////////////////////////////
	void operator ++(int){
			bool aux;
			aux=this->vald((this->dia)+1);
			if(aux==true)
				this->dia=this->dia+1;
					else
						cerr<<endl<<"No es posible aumentar ese dia...";
		}
		////////////////////////////////////////////////////////////////
	void operator --(){
			bool aux;
			aux=this->vald((this->dia)-1);
			if(aux==true)
				this->dia=this->dia-1;
					else
						cerr<<endl<<"No es posible disminuir ese dia...";
		}
		////////////////////////////////////////////////////////////////
	void operator--(int){
			bool aux;
			aux=this->vald((this->dia)-1);
			if(aux==true)
				this->dia=this->dia-1;
					else
						cerr<<endl<<"No es posible disminuir ese dia...";
		}
		////////////////////////////////////////////////////////////////
	void operator +(int n){
			bool aux;
			aux=this->vald((this->dia)+n);
			if(aux==true)
				this->dia=(this->dia)+n;
					else
						cerr<<endl<<"No es posible aumentar esa cantidad de dias...";
		}
		
		/////////////////////////////////////////////////////////
	void operator -(int n){
			bool aux;
			aux=this->vald((this->dia)-n);
			if(aux==true)
				this->dia=(this->dia)-n;
					else
						cerr<<endl<<"No es posible disminuir esa cantidad de dias...";
		}
		
		/////////////////////////////////////////////////////////////////////
	int operator -( Time & a){ //-----------------------------------------<<<<<<<<<
       int a1,a2,aux3,aux4,aux5,res;
       bool aux;
       Time x;
       if(this->anio == a.anio){
           a1=this->dayy();// año mas grande
           a2=a.dayy();
           if(a1<a2){
              res=a2-a1;
              return res;
           }else{
              res=a1-a2;
              return res;
           }
       }
       if(this->anio < a.anio)
            aux=true;
            
        
        if(this->mes< a.mes)
            aux=true;
            
        
        if(this->dia < a.dia)
            aux=true;
            

       if(aux==true){  //11  10
       
            a1=this->dayy();
            a2=a.dayy();                   
                if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                    aux3=365-a1;
                  
                }else{        
                    aux3=366-a1;                 
                }
            
            aux4=this->anio;
            for (int i = aux4+1; i < a.anio; ++i){
                if(aux4 % 4 !=0 || (aux4  % 100 == 0 && aux4  % 400 != 0)){
                  aux3=aux3+365;


                }else{        
                    aux3=aux3+366;                
                }
            }
            aux3=aux3+a2;
            return aux3;
        
       }else{  //else en para menor
            
            a1=a.dayy();
            a2=this->dayy();
            if(a.anio % 4 !=0 || (a.anio % 100 == 0 && a.anio % 400 != 0)){
                    aux3=365-a1;
                }else{        
                    aux3=366-a1;                 
                }
            aux4=a.anio;
            for (int i = aux4+1; i < this->anio; ++i){
                if(aux4 % 4 !=0 || (aux4  % 100 == 0 && aux4  % 400 != 0)){
                  aux3=aux3+365;
                }else{        
                    aux3=aux3+366;                
                }
            }
            aux3=aux3+a2;
            return aux3;    
       }  
    }
    ////////////////////////////////////////////////////////////////////////
    bool operator >(Time &a){
        bool aux=false;
        if(this->anio > a.anio){
            aux=true;
            return aux;
        }
        if(this->mes > a.mes){
            aux=true;
            return aux;
        }
        if(this->dia > a.dia){
            aux=true;
            return aux;
        }
        return aux;
    }
	///////////////////////////////////////////////////////////////////////
    bool operator >=(Time &a){
        int cont=0;
        bool aux=false;
        if(this->anio > a.anio){
            aux=true;
            return aux;
        }
        if(this->mes > a.mes){
            aux=true;
            return aux;
        }
        if(this->dia > a.dia){
            aux=true;
            return aux;
        }
        if(this->dia==a.dia){
            cont++;
        }
        if(this->mes==a.mes){
            cont++;
        }
        if(this->anio==a.anio){
            cont++;
        }
        if(cont==3){
            aux=true;
        }
        return aux;
    }    
    
    ///////////////////////////////////////////////////////////////
	bool operator <(Time &a){
        bool aux=false;
        
        if(this->anio < a.anio){
            aux=true;
            return aux;
        }
        if(this->mes < a.mes){
            aux=true;
            return aux;
        }
        if(this->dia < a.dia){
            aux=true;
            return aux;
        }
        return aux;
    }
    //////////////////////////////////////////////////////////
    bool operator <=(Time &a){
        int cont=0;
        bool aux=false;
        
        if(this->anio < a.anio){
            aux=true;
            return aux;
        }
        if(this->mes < a.mes){
            aux=true;
            return aux;
        }
        if(this->dia < a.dia){
            aux=true;
            return aux;
        }
        if(this->dia==a.dia){
            cont++;
        }
        if(this->mes==a.mes){
            cont++;
        }
        if(this->anio==a.anio){
            cont++;
        }
        if(cont==3){
            aux=true;
        }
        return aux;
    }
    /////////////////////////////////////////////////////////////////////////////////
   
    
    	
};
	///////////////////////////////////////////////////////////////////////////
 Time::Time(const Time &x){
    	this->dia=x.dia;
    	this->mes=x.mes;
    	this->anio=x.anio;
	}
	///////////////////////////////////////////////////////////////////////
	Time::Time (char *data){// 12/05/2001 
    char vecaux[2],veca2[4];
    //int n;
    vecaux[0]=data[0];
    vecaux[1]=data[1];
    this->dia=(atoi(vecaux));
    vecaux[0]=data[3];
    vecaux[1]=data[4];
    this->mes=(atoi(vecaux));
    veca2[0]=data[6];
    veca2[1]=data[7];
    veca2[2]=data[8];
    veca2[3]=data[9];
    this->anio=(atoi(veca2));

}
	///////////////////////////////////////////////////////////////////////////
   Time::Time(int diaa, int mess, int anioo){
  	  bool aux;
    if(mess>=1 && mess <=12)
        this->mes=mess;
    else
        cout<<endl<<"Mes invalido";
    
    if(anioo>=1500 && anioo<=2500)
        this->anio=anioo;
    else
        cout<<endl<<"Año invalido";
    
    aux=this->vald(diaa);
    if(aux==true)
        this->dia=diaa;
    else{
        this->dia=1;
        cout<<endl<<"Dia invalido, se asigno el dia 1 por defecto";
    }
}

///////////////////////////////////////////////////////////////////////////////////

bool Time::vald(int bus){
    bool aux=false;
    switch(this->mes){
        case 1:
            if( bus>0 && bus<=31 )
               aux=true;
            
            break;
        case 2:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                if(bus>0 && bus <= 28)
                    aux=true;
                
            }else{
                if(bus>0 && bus <=29)
                    aux=true;

            }
            break;
        case 3:
            if(bus>0 && bus<=31)
               aux=true;

            break;
        case 4:
        if(bus>0 && bus <=30)
           aux=true;
            break;
        case 5:
            if(bus>0 && bus<=31)
               aux=true;
            
            break;
        case 6:
            if(bus>0 && bus <=30)
               aux=true;
            
            break;
        case 7:
            if(bus>0 && bus<=31)
               aux=true;
            
            break;
        case 8:
            if(bus>0 && bus<=31)
               aux=true;
            
            break;
        case 9:
            if(bus>0 && bus <=30)
               aux=true;
            
            break;
        case 10:
            if(bus>0 && bus <=31)
               aux=true;
            
            break;
        case 11:
            if(bus>0 && bus <=30)
               aux=true;
            
            break;
        case 12:
            if(bus>0 && bus<=31)
               aux=true;
            
            break;
     }
     return aux;
}

/////////////////////////////////////////////////////////////////////////////////////

bool Time::valmes(int nmes){
    bool aux=false;
    switch(nmes){
        case 1:
            if( this->dia<0 && this->dia<=31 ){
               aux=true;
            }
            break;
        case 2:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                if(this->dia<0 && this->dia <= 28)
                    aux=true;
                
            }else{
                if(this->dia>0 && this->dia <=29)
                    aux=true;
                
            }
            break;
        case 3:
            if(this->dia>0 && this->dia<=31)
               aux=true;
            
            break;
        case 4:
        if(this->dia>0 && this->dia <=30)
           aux=true;
        

            break;
        case 5:
            if(this->dia>0 && this->dia<=31)
               aux=true;
            
            break;
        case 6:
            if(this->dia>0 && this->dia <=30)
               aux=true;
            
            break;
        case 7:
            if(this->dia>0 && this->dia<=31)
               aux=true;
            
            break;
        case 8:
            if(this->dia>0 && this->dia<=31)
               aux=true;
            
            break;
        case 9:
            if(this->dia>0 && this->dia <=30)
               aux=true;
            
            break;
        case 10:
            if(this->dia >0 && this->dia <=31)
               aux=true;
            
            break;
        case 11:
            if(this->dia>0 && this->dia<=30)
               aux=true;
            
            break;
        case 12:
            if(this->dia>0 && this->dia<=31)
               aux=true;
            
            break;
     }
     return aux;
}
///////////////////////////////////////////////////////////////////////////////////
bool Time::valy(int bus){
    bool aux=false;
    if(bus >=1500 && bus<=2500){
        if(this->mes ==2){
            if(bus % 4 !=0 || (bus % 100 == 0 && bus % 400 != 0)){

                if(this->dia >0 && this->dia <= 28){
                    aux=true;
                }else{
                    aux=false;
                    return aux;
                }
            }else{                    
                if(this->dia>0 && this->dia <=29){
                    aux=true;
                }else{
                    aux=false;
                    return aux;
                }
            }
        }
        aux=true;
        
    }
    return aux;
}
///////////////////////////////////////////////////////////////////////////////////

void Time::year(int n){
     bool aux;
     aux=this->valy(n);
     if(aux==true){
        this->anio=n;
     }else{
        cout<<endl<<"Año invalido para la fecha";
     }
}
////////////////////////////////////////////////////

int Time::year(){
    return this->anio;
}
///////////////////////////////////////////////
void Time::month(int n){
     bool aux;
     aux=this->valmes(n);
     if(aux==true){
        this->mes=n;
     }else{
        cout<<endl<<"Mes invalido para la fecha";
     }
}
//////////////////////////////////////////////////////

int Time::month(){
    return this->mes;
}
//////////////////////////////////////////////////////
void Time::day(int n){
    bool aux;
    aux=this->vald(n);
    if(aux==true){
        this->dia=n;
    }else{
        cout<<endl<<"Dia invalido para la fecha";
    }
}
/////////////////////////////////////////////////////////
int Time::day(){
    return this->dia;
}
int Time::dayw(){//1=domingo---7=sabado
     int doomS[4]={3,1,6,4};//martes,domingo,viernes,miercoles
     
     string dias [7]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
     
	 int siglo,bis,rest,docenas,resdoce;
	 int g4,suma,resta7,doom,a1,a2,total;
     
     
     siglo=(this->anio)/100;
     bis=siglo % 4;
     rest=(this->anio)-(siglo*100);
     
     docenas=rest/12;
     resdoce=rest % 12;
     
     g4=resdoce/4;
     suma=docenas +resdoce+g4;
     resta7=suma / 7;
     
     suma=suma -(7*resta7);
     doom=(doomS[bis]+suma)-1;
     if(doom>=7){
        doom=(doom-7);
     }
     switch(this->mes){
        case 1:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
             
                a1=59- this->dia;
                a2=a1/7;
                a2=a2*7;
                a1=a1-a2;
                total=(doom-a1);
                if(total<=7){
                    total=total+7;

                }
                if(total>=7){
                    total=total-7;
                 }
                //no es bisiesto
            }else{
                a1=60- this->dia;
                a2=a1/7;
                a2=a2*7;
                a1=a1-a2;
                total=(doom-a1);
                if(total<=7){
                    total=total+7;

                }
                if(total>=7){
                    total=total-7;
                 }
                //ya es bisiesto
            }
            break;
        case 2:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
             
                a1=28- this->dia;
                a2=a1/7;
                a2=a2*7;
                a1=a1-a2;
                
                total=(doom-a1);
                if(total<=7){
                    total=total+7;

                }
                if(total>=7){
                    total=total-7;
                 }
                //no es bisiesto
            }else{
                a1=29- this->dia;
                a2=a1/7;
                a2=a2*7;
                a1=a1-a2;
                total=(doom-a1);
                if(total<=7){
                    total=total+7;

                }
                if(total>=7){
                    total=total-7;
                 }
                //bisiesto
            }
            break;
        case 3:
            a1=35- this->dia;
            a2=a1/7;
            a2=a2*7;
            a1=a1-a2;
            total=(doom-a1);
            if(total<=7){
                total=total+7;

            }
            if(total>=7){
                total=total-7;
            }   

            break;
        case 4:
            a1=39- this->dia;
            a2=a1/7;
            a2=a2*7;
            a1=a1-a2;
            total=(doom-a1);
            if(total<=7){
                total=total+7;

            }
            if(total>=7){
                total=total-7;
            }
            break;
        case 5:
            a1=37- this->dia;
            a2=a1/7;
            a2=a2*7;
            a1=a1-a2;
            total=(doom-a1);
            if(total<=7){
                total=total+7;

            }
            if(total>=7){
            total=total-7;
            }
            break;
        case 6:
            a1=41- this->dia;
            a2=a1/7;
            a2=a2*7;
            a1=a1-a2;
            total=(doom-a1);
            if(total<=7){
                total=total+7;

            }
            if(total>=7){
                total=total-7;
            }
            break;
        case 7:
            a1=39- this->dia;
            a2=a1/7;
            a2=a2*7;
            a1=a1-a2;
            total=(doom-a1);
            if(total<=7){
                total=total+7;

            }
            if(total>=7){
                total=total-7;
            }
            break;
        case 8:
            a1=36- this->dia;
            a2=a1/7;
            a2=a2*7;
            a1=a1-a2;
            total=(doom-a1);
            if(total<=7){
                total=total+7;

            }
            if(total>=7){
                total=total-7;
            }
            break;
        case 9:
            a1=40- this->dia;
            a2=a1/7;
            a2=a2*7;
            a1=a1-a2;
            total=(doom-a1);
            if(total<=7){
                total=total+7;

            }
            if(total>=7){
                total=total-7;
            }
            break;
        case 10:
            a1=38- this->dia;
            a2=a1/7;
            a2=a2*7;
            a1=a1-a2;
            total=(doom-a1);
            if(total<=7){
                total=total+7;

            }
            if(total>=7){
                total=total-7;
            }
            break;
        case 11:
            a1=42- this->dia;
            a2=a1/7;
            a2=a2*7;
            a1=a1-a2;
            total=(doom-a1);
            if(total<=7){
                total=total+7;

            }
            if(total>=7){
                total=total-7;
            }
            break;
        case 12:
            if(this->dia<=12){
                a1=12- this->dia;
                a2=a1/7;
                a2=a2*7;
                a1=a1-a2;
                total=(doom-a1);
                if(total<=7){
                   total=total+7;

                }
                if(total>=7){
                   total=total-7;
                }
             }else{
                a1=this->dia-12;
                a2=a1/7;
                a2=a2*7;
                a1=a1-a2;
                total=(doom+a1);
                if(total>=7){
                   total=total-7;

                }
             }
            break;
     }
    return total;
}
/////////////////////////////////////////////////////////////////////////////////

int Time::dayy(){ 
    int diaopc;
    int nobis[11]={31,59,90,120,151,181,212,243,273,304,334};
    int bisie[11]={31,60,91,121,152,182,213,244,274,305,335};
    switch(this->mes){
        case 1:
            diaopc=this->dia;
            break;
        case 2:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[0];
            }else
                diaopc=this->dia+bisie[0];
            break;
        case 3:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[1];
            }else
                diaopc=this->dia+bisie[1];
            break;
        case 4:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[2];
            }else
                diaopc=this->dia+bisie[2];
            break;
        case 5:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[3];
            }else
                diaopc=this->dia+bisie[3];
            break;
        case 6:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[4];
            }else
                diaopc=this->dia+bisie[4];
            break;
        case 7:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[5];
            }else
                diaopc=this->dia+bisie[5];
            break;
        case 8:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[6];
            }else
                diaopc=this->dia+bisie[6];
            break;
        case 9:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[7];
            }else
                diaopc=this->dia+bisie[7];
            break;
        case 10:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio% 400 != 0)){
                diaopc=this->dia+nobis[8];
                
            }else
                dia=this->dia+bisie[8];
               
            
            break;
        case 11:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[9];
               
            }else
                diaopc=this->dia+bisie[9];
                        
            break;
        case 12:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio% 400 != 0)){
                diaopc=this->dia+nobis[10]; 
            }else
                diaopc=this->dia+bisie[10];
            break;
     }
    return diaopc;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int Time::weeky(){ 
	int diaopc;
    int nobis[11]={31,59,90,120,151,181,212,243,273,304,334};
    int bisie[11]={31,60,91,121,152,182,213,244,274,305,335};
   switch(this->mes){
        case 1:
            diaopc=this->dia;
            break;
        case 2:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[0];
            }else
                diaopc=this->dia+bisie[0];
            break;
        case 3:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[1];
            }else
                diaopc=this->dia+bisie[1];
            break;
        case 4:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[2];
            }else
                diaopc=this->dia+bisie[2];
            break;
        case 5:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[3];
            }else
                diaopc=this->dia+bisie[3];
            break;
        case 6:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[4];
               
            }else
                diaopc=this->dia+bisie[4];

            break;
        case 7:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[5];
               
            }else
                diaopc=this->dia+bisie[5];
            break;
        case 8:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[6];
            }else
                diaopc=this->dia+bisie[6];
            break;
        case 9:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[7];
            }else
                diaopc=this->dia+bisie[7];
            break;
        case 10:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio% 400 != 0)){
                diaopc=this->dia+nobis[8];

            }else
                dia=this->dia+bisie[8];
            break;
        case 11:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio % 400 != 0)){
                diaopc=this->dia+nobis[9];
            }else
                diaopc=this->dia+bisie[9];
            break;
        case 12:
            if(this->anio % 4 !=0 || (this->anio % 100 == 0 && this->anio% 400 != 0)){
                diaopc=this->dia+nobis[10];
            
            }else
                diaopc=this->dia+bisie[10];
            break;
     }
     diaopc=diaopc/7;
     diaopc=diaopc+1;
     return diaopc;
}
////////////////////////////////////
	ostream & operator <<(ostream & out, Time & x){
   out << x.dia<<"/"<<x.mes<<"/"<<x.anio<<endl;
   return out;
}
/////////////////////////////////////////////



int main(){
	string dias[7]={"Domingo","Lunes","Marte","Miercoles","Jueves","Viernes","Sabado"};
	int aux,aux2;
    Time x(3,3,2010),y(3,3,2010),z((char*)"14/02/2020"),a(23,9,2007);
    cout<<endl<<"Fecha de x :"<<x;
    cout<<endl<<"Fecha de z: "<<z;
    cout<<endl<<"La fecha de z mas 1: ";
    z+1;
    cout<<endl<<z;
    cout<<endl<<"La fecha de z mas 16: ";
    z+16;
    cout<<endl<<z;
    aux2=x.dayw();
    cout<<endl<<"El doomsday de x es: ";
    aux=a.weeky();
    cout<<endl<<dias[aux2];
    cout<<endl<<"El numero de semanda de la fecha a es: "<<aux;
    aux=a.dayy();
    cout<<endl<<"El dia del anio de la fecha a es: "<<aux;
    cout<<endl<<"Fecha a menos un dia: ";
    a-1;
    cout<<a;

    return 0;  
	
	
}
