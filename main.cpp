#include <random>
#include <iostream>
#include <numeric>
#include <vector>
#include <time.h>

template<typename T>
std::vector<T> generatorNorm(const double avarageValue, const double valueRMS, const int samples) {


    std::mt19937 gen(rand());

    std::normal_distribution<> distr(avarageValue, valueRMS);

    // generate the distribution as a histogram
    std::vector<T> histogram;
    for (int i = 0; i < samples; ++i) {
        histogram.push_back(distr(gen));
    }

      return histogram;
}


int main()
{
   double trueAzimut;
   double AzimuthRMS;
   int sampleLength;

   std::cout<<"Введите истинное значение азимута: ";
   std::cin>>trueAzimut;
   std::cout<<"Введите значение СКО: ";
   std::cin>>AzimuthRMS;
   std::cout<<"Введите размер выборки: ";
   std::cin>>sampleLength;

   std::vector<double> azimut=generatorNorm<double>(trueAzimut,AzimuthRMS,sampleLength);


   //Определение истинного значения по выборке
   double averageAzimut= accumulate(azimut.begin(), azimut.end(), 0.f)/azimut.size();
   std::cout<<"Среднее значение aзимута:"<<averageAzimut<<"\n";

   return 0;
}
