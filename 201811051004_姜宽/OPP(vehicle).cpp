#include <iostream>
using namespace std;

class vehicle // 定义汽车类 
{
  protected: //保护段包含车轮数和重量
  int   wheels; // 车轮数 
  float weight; // 重量 
  
  public: 
  vehicle(int wheels,float weight); 
  int   get_wheels(); 
  float get_weight(); 
  float wheel_load(); 
  void  show(); 
}; 

class car:public vehicle // 定义小车类 
{ 
  int   passenger_load; // 载人数 
  public: 
  car(int wheels,float weight,int passengers=4); 
  int   get_passengers(); 
  void  show(); 
}; 

class truck:public vehicle // 定义卡车类 
{ 
  int   passenger_load; // 载人数 
  float payload; // 载重量 
  public: 
  truck(int wheels,float weight,int passengers=2,
	  float max_load=24000.00); int   get_passengers();  
  void show(); 
}; 

vehicle::vehicle(int wheels,float weight) 
{ 
  vehicle::wheels=wheels; 
  vehicle::weight=weight; 
} 
int vehicle::get_wheels() 
{ 
  return wheels; 
} 
float vehicle::get_weight() 
{ 
  return weight/wheels; 
} 
void vehicle::show() 
{ 
  cout << "车轮:" << wheels << "个" << endl; 
  cout << "重量:" << weight << "公斤" << endl; 
} 

car::car(int wheels, float weight, 
		 int passengers) :vehicle (wheels, weight) 
{ 
  passenger_load=passengers; 
} 
int car::get_passengers () 
{ 
  return passenger_load; 
} 
void car::show() 
{ 
  cout <<"车型:小车" << endl; 
  vehicle::show(); 
  cout << "载人:" << passenger_load << "人" << endl; 
  cout << endl; 
} 

truck:: truck(int wheels, float weight,int passengers, 
			  float max_load):vehicle(wheels,weight) 
{ 
  passenger_load=passengers; 
  payload=max_load; 
} 
int truck::get_passengers() 
{ 
  return passenger_load; 
} 

void truck::show() 
{ 
  cout <<"车型:卡车" << endl; 
  vehicle:: show (); 
  cout << "载人:" << passenger_load << "人" << endl; 
  cout << endl; 
} 

void main () 
{ 
  car car1(4,3000,5); 
  truck tru1(12,10000,3); 
  cout << "输出结果: " << endl; 
  car1. show (); 
  tru1. show (); 
}