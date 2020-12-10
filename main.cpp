#include <iostream>
using namespace std;
#define TAM 20
template <class T>
class Lista{
    private:
        T *Vet;
        int Tamanho, Fim;
    public: 
        Lista(const int &tam)
        {
            Tamanho = tam;
            Vet = new T[Tamanho];
            Fim = -1;
        }
        ~Lista()
        {
            delete [] Vet;
        }
        bool Inserir_No_Fim(const T &valor)
        {
            if(Fim<Tamanho-1)
            {
                ++Fim;
                Vet[Fim]=valor;
                return true;
            }else
                {
                return false;
            }
        }
        bool Inserir_No_Comeco(const T &valor)
        {
            if(Fim<Tamanho-1)
            {
                int Ajuste = Fim;
                while(Ajuste >= 0)
                {
                    Vet[Ajuste+1] = Vet[Ajuste];
                    Ajuste--;
                }
                Vet[0] = valor;
                Fim++;
                return true;
            }else
            {
                return false;
            }
        }
        bool Inserir_No_Meio(const T &valor, const int &posicao)
        {
            if(Fim<Tamanho-1)
            {
                int Ajuste = Fim;
                while(Ajuste >= posicao)
                {
                    Vet[Ajuste+1] = Vet[Ajuste];
                    Ajuste--;
                }
                Vet[posicao] = valor;
                Fim++;
                return true;
            }else
            {
                return false;
            }
        }
        bool Remover_Do_Fim()
        {
            if(Fim == -1)
            {
                return false;
            }else
            {
                Fim--;
                return true;
            }
        }
        bool Remover_Do_Comeco()
        {
           if(Fim<Tamanho-1)
           {
                for(int i = 0; i < Fim; i++)
                {
                    Vet[i] = Vet[i+1];
                }
                Fim--;
                return true;
            }else
            {
                return false;
            }            
        }
        bool Remover_Do_Meio(int const &pos)
        {
            if(Fim>pos)
            {
                for(int i = pos; i < Fim; i++)
                {
                    Vet[i] = Vet[i+1];
                }
                Fim--;
                return true;                
            }else
            {
                return false;
            }
        }        
        void Mostrar_Lista()
        {
            cout<<"[";
            for(int i = 0; i <= Fim; i++)
            {
                cout<<" "<<Vet[i];
            }
            cout<<" ]"<<endl;
        }
        T Mostrar_Do_Meio(int const &pos)
        {
            if(pos<Fim){
                return Vet[pos];
            }else{
                cout<<"Posicao nao existe"<<endl;
            }
           return 0; 
        }
        int Retorna_tamanho(){
            return Fim;
        }
};


int main(){
    Lista<int> L(20);
    for(int i = 0; i<20; i++){
        L.Inserir_No_Fim(i);
    }
    cout<<L.Retorna_tamanho()<<endl;
    L.Mostrar_Lista();
    L.Remover_Do_Meio(3);
    L.Remover_Do_Comeco();
    L.Mostrar_Do_Meio(19);
    cout<<L.Retorna_tamanho()<<endl;
    L.Mostrar_Lista();
    return 0;
}