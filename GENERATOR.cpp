#include <iostream>
#include <vector>
#include <string>
//#include "GPMSQ.h"
#include "GPMSQ.cpp"
#include "gnuplot.h"
#include <algorithm>


int Equal_(float * Mass, int len);

int comp2 (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}
using namespace std;

//int Equal_(float * Mass, int len);

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    GPMSQ *Gen = new GPMSQ();
    cout << Gen->Start_Value << "\n";
    int KVADRAT = Gen->Square(Gen->Start_Value);
    cout << KVADRAT << "\n";
    Gen->Int_to_string(KVADRAT);
    
    int joker = 12233445;
    int ost = joker%100;
    joker = joker - ost;
    char stroka[9] = {0};
    sprintf(stroka, "%d", joker);



    int Massiv[10000] = {0};
    int Var = 1;
    for(int i = 0; i < 10000; i++){
        Massiv[i] = Var;
        Var = Var + 1;
    }
    char MASS[8] = {0};
    int SQUAD = 0;

  


  float Ch_ = 0;
  float Square_ = 0;
  float Massive_[10000] = {0};
  char Str_[12] = {0};
  char New_[7] = {0};
  int count = 0;
  int Dlina_ = 1;
  int Length_Massive[10000] = {0};
  float Ch_2 = 0;

FILE* fp = fopen("test.dat","w");

  for(int i = 1; i < 10000; i++){
    //i = 101;
    Ch_ = i / 10000.0;
    Massive_[0] = 0;
    for(int k = 0; k < 10000; k++){
      Massive_[k] = 0;
    }
    count = 1;
    Massive_[count] = Ch_;
    Dlina_ = 1;
    int Flag = 0;
    while( (Ch_ != 0) && (Massive_[count - 1] != Ch_) /*&& Equal_(Massive_,Dlina_)==0*/){
      Massive_[count] = Ch_;
      Square_ = Ch_ * Ch_;
      sprintf(Str_, "%.10f", Square_);
      New_[0] = Str_[0];
      New_[1] = Str_[1];
      New_[2] = Str_[4];
      New_[3] = Str_[5];
      New_[4] = Str_[6];
      New_[5] = Str_[7];
      New_[6] = '\0';
      Dlina_ = Dlina_ + 1;
      Ch_ = atof(New_);
      Ch_2 = Ch_;
      count = count + 1;
      for(int k = Dlina_; k >= 0; k-- ){
        if (Ch_ == Massive_[k])
        {
          Dlina_ = count;
          Flag = 1;
          break;
        }
        
      }
      if(Flag == 1){
        break;
      }

    }
    Length_Massive[i] = Dlina_;
    
    
    fprintf(fp,"%d\t%d\n", i, Length_Massive[i]);

  }


  fclose(fp);

  Gnuplot plot;
  plot("plot 'test.dat' using 1:2 with points");
  
  FILE* fp1 = fopen("test_2.dat","w");



  int Length_Massive_2[10000] = {0};
  int Sq_i = 0;
  int Variable = 0;
  char Srting_var[9] = {0};
  char New_var[5] = {0};
  char Chislo[5] = {0};
  int Length_Chisla = 0;
  int Massive_2[10000] ={0};
  for(int i = 1; i < 10000; i++){
      Variable = i;
      for(int k = 0; k < 10000; k++){
      Massive_2[k] = 0;
      }
      count = 1;
      Dlina_ = 1;
      Massive_2[0] = 0;
      int Flag_2 = 0; 
      while(1){
        Massive_2[count] = Variable;
        Sq_i = Variable*Variable;
        sprintf(Srting_var+1, "%d", Sq_i);
        sprintf(Chislo, "%d", Variable);
        Length_Chisla = strlen(Chislo);
        switch(Length_Chisla){
          case 1:
            New_var[0] = Srting_var[1];

          break;
          case 2:
            New_var[0] = Srting_var[1];
            New_var[1] = Srting_var[2];
            
          break;
          case 3:
            New_var[0] = Srting_var[2];
            New_var[1] = Srting_var[3];
            New_var[2] = Srting_var[4];
          break;
          case 4:
            New_var[0] = Srting_var[2];
            New_var[1] = Srting_var[3];
            New_var[2] = Srting_var[4];
            New_var[3] = Srting_var[5];

          break;
        }
        Variable = atoi(New_var);
        Dlina_ = Dlina_ + 1;
       
        count = count + 1;
        for(int k = Dlina_; k >= 0; k-- ){
        if (Variable == Massive_2[k])
          {
          Dlina_ = count;
          Flag_2 = 1;
          break;
          }
        }
        if(Flag_2 == 1){
        break;
      }



      }
      Length_Massive_2[i] = Dlina_;
      fprintf(fp1,"%d\t%d\n", i, Length_Massive_2[i]);
  }

  fclose(fp1);


Gnuplot plot2;
plot2("plot 'test_2.dat' using 1:2 with boxes");
  
qsort (Length_Massive_2, 10000, sizeof(int), comp2);
qsort (Length_Massive , 10000, sizeof(int), comp2);
for(int i = 0; i < 100; i++){
  printf("%d\t%d\n",Length_Massive_2[i], Length_Massive[i]);
}



/*
/Метод вычетов
*/
    



    
    return 0;
}

int Equal_(float * Mass, int len){
  float Var = 0;
  int count = 0;
  for(int i = 0; i < len; i++){
    Var = Mass[i];

    
    for(int k = len; k >= i; k--){
      if(Var == Mass[k]){
        if(i != k){
          return k;
        }
      }
    }

  }
  return 0;

}