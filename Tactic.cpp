#include <iostream>
//using namespace std;
void print(int (*matriz)[3]){
	std::cout<<std::endl;
	std::cout<<"-------"<<std::endl;
	for(int i=0;i<3;++i){
		std::cout<<"|";
		for(int j=0;j<3;++j){
			if(matriz[i][j]==0)std::cout<<" |";
			if(matriz[i][j]==1)std::cout<<"X|";
			if(matriz[i][j]==2)std::cout<<"O|";
		}
		std::cout<<std::endl;
		std::cout<<"-------"<<std::endl;
	}
}
void rellenar(int (*matriz)[3]){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			matriz[i][j]=0;
		}
	}
}
bool verificar(int x,int y,int (*matriz)[3]){
	if(matriz[x][y]==1)return false;
	if(matriz[x][y]==2)return false;
	return true;
}
void swap(bool &a, bool &b){
	bool temp=a;
	a=b;
	b=temp;
}

int main(int argc, char *argv[]) {
	int matriz[3][3];
	rellenar(matriz);
	bool estoyjugando=true,ju1=true,ju2=false,jugadavalida=false;
	int x,y;
	while(estoyjugando){
		print(matriz);
		if(ju1){
			std::cout<<"Jugador 1"<<std::endl;
			while(!jugadavalida){
				std::cout<<"numero de fila:";std::cin>>x;
				std::cout<<"numero de columna:";std::cin>>y;
				if(verificar(x,y,matriz))jugadavalida=true;
			}
			matriz[x][y]=1;
		}
		if(ju2){
			std::cout<<"Jugador 2"<<std::endl;
			while(!jugadavalida){
				std::cout<<"numero de fila:";std::cin>>x;
				std::cout<<"numero de columna:";std::cin>>y;
				if(verificar(x,y,matriz))jugadavalida=true;
			}
			matriz[x][y]=2;
		}
		swap(ju1,ju2);
		jugadavalida=false;
	}
	return 0;
}
