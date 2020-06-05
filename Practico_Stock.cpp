#include<iostream>
#include <string.h>
#include<conio.h>

const int TAM_STOCK= 100;
const int TAM_ARTICULO= 40;
using namespace std; 
	bool entro;  
	char stockvacio[40] = "StockVacio"; 
	struct ElemStock{
  		int    codigo;
  		char  articulo[TAM_ARTICULO];
  		int     existencia;
  		int     minrec;
  		int     maxrec;
	};
 	struct Stock{
   		ElemStock articulos_del_stock[TAM_STOCK];  //Elementos del stock. Arreglo
   		int    ultimo_elemento = 0;     //indice del elementos del stock anterior. 
	}minegocio;		
	int op=0,op_consistencia = 1; 
	//Prototipo de funciones------------------------------------------------------------------------
	void menu();
	void reseteo(); 
	void agregarElemento();
	void eliminarElemento(); 
	void modificarElemento(); 
	void listaElementos();
	void reporteStock();
	//Bloque principal -----------------------------------------------------------------------------
	int main(){
		
		do{
				menu();
				switch (op){
					case 1:{
						reseteo();
						break;
					}
					case 2:{
						agregarElemento(); 
						break;
					}
					case 3:{
						
						eliminarElemento(); 
						break;
					}
					case 4:{
						modificarElemento(); 
						break;
					}
					case 5:{
						listaElementos();
						break;
					}
					case 6:{
						reporteStock();
						break;
					}
					case 7:{
						exit(-1);
						break;
					}
				}
		}while(op != 7);
		return 0; 
	}
	//Declaracion de funciones------------------------------------------------------
	void menu(){                // ----------------------------------------------------------------------------
			do{			//Menu Principal 
			system("CLS");   
			cout<<"<< Seleccione la opcion que desee >>"<<endl; 
			cout<<"1. Resetear Stock"<<endl; 
			cout<<"2. Agregar un nuevo elemento de Stock"<<endl; 
			cout<<"3. Eliminar un elemento de Stock"<<endl; 
			cout<<"4. Modificar los campos de un elemento de Stock"<<endl; 
			cout<<"5. Listar todos los elementos que conforman el stock actual"<<endl; 
			cout<<"6. Reporte"<<endl; 
			cout<<"7. Salir"<<endl; 
			cin>>op;
			fflush(stdin);    //Funcion para limpiar el bufer de ingreso de datos
		   				
			if((op > 7)or(op < 1)){
				op_consistencia = 1; 
				system("CLS");
				cout<<"<< Opcion incorrecta >>"<<endl; 
			}else{
				op_consistencia = 2; 
			}
		}while(op_consistencia == 1);
	}
void reseteo(){          //--------------------------------------------------------------------------
	entro = true; 
		//Consigna Eliminar todos los elementos del stock 
	for(minegocio.ultimo_elemento = 0;minegocio.ultimo_elemento < TAM_STOCK;minegocio.ultimo_elemento++){
		strcpy(minegocio.articulos_del_stock[minegocio.ultimo_elemento].articulo,stockvacio); 
		minegocio.articulos_del_stock[minegocio.ultimo_elemento].codigo = minegocio.ultimo_elemento; 
		minegocio.articulos_del_stock[minegocio.ultimo_elemento].existencia = 0;
		minegocio.articulos_del_stock[minegocio.ultimo_elemento].minrec = 0; 
		minegocio.articulos_del_stock[minegocio.ultimo_elemento].maxrec = 0;
	}	 
		//Consigna. cargar desde cero el stock 
	int in = 0;
	minegocio.ultimo_elemento = 0; 
	while((minegocio.ultimo_elemento < TAM_STOCK)&&(in ==0)){
		fflush(stdin);
		system("CLS");
		minegocio.articulos_del_stock[minegocio.ultimo_elemento].codigo = minegocio.ultimo_elemento;       //Asignacion del codigo al articulo de acuerdo al indice del arreglo 
		cout<<"Ingrese articulo: "; cin.getline(minegocio.articulos_del_stock[minegocio.ultimo_elemento].articulo,TAM_STOCK,'\n');
		cout<<"Unidades Existente: "; cin>> minegocio.articulos_del_stock[minegocio.ultimo_elemento].existencia; 
		cout<<"Cantidad Minimas necesarias en stock: "; cin>> minegocio.articulos_del_stock[minegocio.ultimo_elemento].minrec; 
		cout<<"Cantidad Maxima necesarias en stock: "; cin>> minegocio.articulos_del_stock[minegocio.ultimo_elemento].maxrec; 
		cout<<"Codigo: "<<minegocio.ultimo_elemento<<endl; 
		
		system("CLS");    //Limpieza de pantalla
		cout<<"Para ingresar otro articulo precione 0 "; cin>>in;	
	//	system("CLS");      //Limpieza de pantalla
		minegocio.ultimo_elemento++;
	}
	if (minegocio.ultimo_elemento == TAM_STOCK){
		cout<<"<< Listado de Stock lleno >>"<<endl; 
	}	
}
void agregarElemento(){  //------------------------------------------------------------------
	
		//Consigna Agregar elemento al stock 
	system("CLS");      //Limpieza de pantalla
	if (entro == false){
		cout<<"Debe iniciar un Stock en la opcion 1"<<endl; 
		cout<<"Vuelva a al menu principal para realizar la accion correcta"<<endl; 
		system("pause");	
	}else{
		int in=0;
		if (minegocio.ultimo_elemento == TAM_STOCK){
			cout<<"<< Listado de Stock lleno >>"<<endl; 
		}else{
			while((minegocio.ultimo_elemento < TAM_STOCK)&&(in ==0)){
				fflush(stdin);
				minegocio.articulos_del_stock[minegocio.ultimo_elemento].codigo = minegocio.ultimo_elemento;       //Asignacion del codigo al articulo de acuerdo al indice del arreglo 
				cout<<"Ingrese articulo: "; cin.getline(minegocio.articulos_del_stock[minegocio.ultimo_elemento].articulo,TAM_STOCK,'\n');
				cout<<"Unidades Existente: "; cin>> minegocio.articulos_del_stock[minegocio.ultimo_elemento].existencia; 
				cout<<"Cantidad Minimas necesarias en stock: "; cin>> minegocio.articulos_del_stock[minegocio.ultimo_elemento].minrec; 
				cout<<"Cantidad Maxima necesarias en stock: "; cin>> minegocio.articulos_del_stock[minegocio.ultimo_elemento].maxrec; 	
				system("CLS");    //Limpieza de pantalla
				cout<<"Para ingresar otro articulo precione 0 "; cin>>in;	
				system("CLS");      //Limpieza de pantalla
				minegocio.ultimo_elemento++; 
			}						
		}					
						
	}
}
void eliminarElemento(){       //--------------------------------------------------------------------------------
	system("CLS");
		
		if ((entro == false)){
			cout<<"No se encuentran elementos en Stock"<<endl; 
			cout<<"Para crear Stock vuelva al menu principal. Opcion 1"<<endl; 
			system("pause");	
		}else{
			if(minegocio.ultimo_elemento == 0){
				cout<<"No se encontraron elementos en el Stock."<<endl;  
			}else{
			if(minegocio.ultimo_elemento > 0){
								//Consigna Eliminar un elemento del Stock 
				int eliminar_ar = 0; 
				for(int in=0; in < minegocio.ultimo_elemento;in++){
					cout<<"Articulo: "<<minegocio.articulos_del_stock[in].articulo<<" Codigo: "<<minegocio.articulos_del_stock[in].codigo<<endl;
					cout<<"----------------------------------"<<endl; 
				}
				cout<<"Seleccione el codigo del Articulo que desea eliminar: "; cin>>eliminar_ar;
				system("CLS");    //Limpieza de pantalla
			int eliminar_ar_2 = eliminar_ar;
			eliminar_ar_2++; 
				while(eliminar_ar < minegocio.ultimo_elemento ){
					strcpy(minegocio.articulos_del_stock[eliminar_ar].articulo,minegocio.articulos_del_stock[eliminar_ar_2].articulo); 
					minegocio.articulos_del_stock[eliminar_ar].codigo = minegocio.articulos_del_stock[eliminar_ar].codigo;
					minegocio.articulos_del_stock[eliminar_ar].existencia = minegocio.articulos_del_stock[eliminar_ar_2].existencia;
					minegocio.articulos_del_stock[eliminar_ar].minrec = minegocio.articulos_del_stock[eliminar_ar_2].minrec; 
					minegocio.articulos_del_stock[eliminar_ar].maxrec = minegocio.articulos_del_stock[eliminar_ar_2].maxrec; 
					eliminar_ar++; 		
					eliminar_ar_2++;
				}
				minegocio.ultimo_elemento--;
				if(minegocio.ultimo_elemento < 0){
					entro = false; 
				}
			}else{
					cout<<"SIN ELEMENTOS.PUTO"<<endl; 
			}				
			}
			

		}
}	
void modificarElemento(){        //-------------------------------------------------------------------------------------------
	system("CLS");
	if (entro == false){
		cout<<"No se encontraron elementos en Stock"<<endl; 
		cout<<"Vuelva a al menu principal para realizar la accion correcta"<<endl; 
		system("pause");	
	}else{
		if(minegocio.ultimo_elemento == 0){
			cout<<"No se encontraron elementos en el Stock."<<endl; 
		}else{
				// Consigna modificar un elemento del stock 
		int modificar = 0, op_modificar = 0; 
		for(int in=0; in < minegocio.ultimo_elemento;in++){
			cout<<"Articulo: "<<minegocio.articulos_del_stock[in].articulo<<" Codigo: "<<minegocio.articulos_del_stock[in].codigo<<endl;
			cout<<"----------------------------------"<<endl; 
		}
		cout<<"Seleccione el codigo del Articulo que desea modificar: "; cin>>modificar;
		system("CLS");      //Limpieza de pantalla
		cout<<"Seleccione el atributo del Articulo que desea modificar: "<<endl; 
		cout<<"1. Nombre del articulo: "<<minegocio.articulos_del_stock[modificar].articulo<<endl; 
		cout<<"2. Unidades Existentes: "<<minegocio.articulos_del_stock[modificar].existencia<<endl;
		cout<<"3. Articulos Minimos recomendados: "<<minegocio.articulos_del_stock[modificar].minrec<<endl;
		cout<<"4. Articulos Maximos Recomendados: "<<minegocio.articulos_del_stock[modificar].maxrec<<endl;
		cout<<"Codigo (No se puede modificar): "<<minegocio.articulos_del_stock[modificar].codigo<<endl;	
		cin>>op_modificar; 
		system("CLS");    //Limpieza de pantalla
		switch(op_modificar){
			case 1:{
				cout<<"Ingrese Nuevo nombre para el articulo: "; 
				cin.getline(minegocio.articulos_del_stock[modificar].articulo,TAM_STOCK,'\n');
				break;
			}
			case 2:{
				cout<<"Ingrese Nuevas Unidades Existentes "; cin>> minegocio.articulos_del_stock[modificar].existencia;
				break;
			}
			case 3:{
				cout<<"Ingrese Minimo Recomendado "; cin>> minegocio.articulos_del_stock[modificar].minrec;
				break;
			}
			case 4:{
				cout<<"Ingrese Maximo Recomendado "; cin>> minegocio.articulos_del_stock[modificar].maxrec;
				break;
			}
		}			
		}

		system("CLS");    //Limpieza de pantalla
	}
}
void listaElementos(){
	system("CLS"); 
	if (entro == false){
		cout<<"Debe iniciar un Stock en la opcion 1"<<endl; 
		cout<<"Vuelva a al menu principal para realizar la accion correcta"<<endl; 
		system("pause");	
	}else{
		if(minegocio.ultimo_elemento == 0){
			cout<<"No se encontraron elementos en el Stock. "<<endl; 
		}else{
				int aux;
		aux = minegocio.ultimo_elemento;
		aux--;
		char direccion; 	
		int recorrer_arr = 0, getch(),xx=0; 
		do{
			cout<<"<< Visualizacion del Stock >>"<<endl; 
			cout<<" * Para recorrer el stock utilice las flechas 'derecha' e 'Izquierda'"<<endl; 
			cout<<" * Para salir presione 0"<<endl; 
			cout<<"Articulo: "<<minegocio.articulos_del_stock[recorrer_arr].articulo<<endl;
			cout<<"Codido: "<<minegocio.articulos_del_stock[recorrer_arr].codigo<<endl;
			direccion = getch();		
						//cin>>direccion;  
			if (direccion == 77){                  // Derecha 77 
				if(recorrer_arr == aux){
					recorrer_arr = 0; 
				}else{
					recorrer_arr++;	
				}
			}else{
				if(direccion == 75){                  //Izquierda 75
					if(recorrer_arr == 0 ){
						recorrer_arr = aux;  
					}else{
						recorrer_arr--; 	
					}	
				}else{
					if(direccion == 48){                 //cero 48 para salir
						xx = 1; 
					}
				}
			}		
				system("CLS");			
		}while(xx==0);	
		}
	
	}		
}
void reporteStock(){
	system("CLS"); 
	if (entro == false){
		cout<<"Debe iniciar un Stock en la opcion 1"<<endl; 
		cout<<"Vuelva a al menu principal para realizar la accion correcta"<<endl; 	
	}else{
		if(minegocio.ultimo_elemento == 0){
			cout<<"No se encontraron elementos en el Stock. "<<endl; 
		}else{
		for(int in=0; in<minegocio.ultimo_elemento;in++){
			if(minegocio.articulos_del_stock[in].existencia <= minegocio.articulos_del_stock[in].minrec){
					cout<<"Articulo: "<<minegocio.articulos_del_stock[in].articulo<<endl; 
					cout<<"Cantidad de existencias: "<<minegocio.articulos_del_stock[in].existencia<<endl; 
					cout<<"Cantidad insufieciente en Stock. Realizar pedido del mismo"<<endl; 
					cout<<"----------------"<<endl; 
			}else{
				if(minegocio.articulos_del_stock[in].existencia > minegocio.articulos_del_stock[in].maxrec){
					cout<<"Articulo: "<<minegocio.articulos_del_stock[in].articulo<<endl; 
					cout<<"Cantidad de existencias: "<<minegocio.articulos_del_stock[in].existencia<<endl; 
					cout<<"La cantidad de existencias sobrepasa la capacidad del Stock"<<endl; 
					cout<<"----------------"<<endl; 							
				}else{
					if((minegocio.articulos_del_stock[in].existencia < minegocio.articulos_del_stock[in].maxrec)&&(minegocio.articulos_del_stock[in].existencia > minegocio.articulos_del_stock[in].minrec)){
						cout<<"Articulo: "<<minegocio.articulos_del_stock[in].articulo<<endl; 
						cout<<"Cantidad de existencias: "<<minegocio.articulos_del_stock[in].existencia<<endl; 
						cout<<"La cantidad de existencias se encuentra dentro de la capacidad del Stock"<<endl; 
						cout<<"----------------"<<endl; 
					}
				}
			}
		}		
	}
	}	
		system("pause");	
}
