#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "GPIO.h"
using namespace std;

#define GPIO_PATH "/sys/class/gpio/gpio"

void writeGPIO(string filename, string value){
   ofstream fs;
   string path(GPIO_PATH);
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();
}

void setDirection(string GPIODirection){
	if (direction == "0"){
		wrtieGPIO("direction","in");
	}
	else if (direction == "1"){
		writeGPIO("direction", "out");
	} 
}

void setValue(string value){
	if(value == "off"){
		writeGPIO("value", "0");
	}
	else if(value == "on"){
		writeGPIO("value", "1");
	}
}

int main(int argc, char* argv[]){
   if(argc!=3){
	cout << "Usage is ./control_GPIO one of: " << endl;
        cout << "GPIO number, and hi or low" << endl;
	cout << " e.g. control_GPIO 60 hi" << endl;
        return 3;
   }
   string gpioNumber(argv[1]);
   cout << "Starting the GPIO program" << endl;
   cout << "The current GPIO Path is: " << GPIO_PATH << endl;
   
   string onoroff(argv[2]);
   
   if(onoroff == "on"){
	setDirection(1);
	sleep(1);
	setValue(onoroff);
  }
  else if(onoroff == "off"){
	setDirection(0);
	sleep(1);
	setValue(onoroff);
}
  return 0;
}
