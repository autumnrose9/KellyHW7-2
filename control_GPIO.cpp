#include<sstream>
#include<iostream>
#include<fstream>
#include<string>

#define GPIO_PATH "/sys/class/gpio"

using namespace std;

void writeGPIO(string name, string lvl)
{
	fstream fs;
	string path(GPIO_PATH);
	string val("/value");
	fs.open((path + name + val).c_str(), fstream::out);
	fs << lvl;
	fs.close();
}

int main(int argc, char*argv[])
{
	if(argc != 3)
	{
		cout << "Incorrect Input, Try Again" << endl;
		return 2;
	}
	else
	{
		string GPIO_num(argv[1]);
        	string GPIO_level(argv[2]);
		ostringstream s;
		s << "/gpio" << GPIO_num;
		string Gpio = string(s.str());

		if (GPIO_level == "hi")
		{
			writeGPIO(Gpio, "1");
		}

		else if (GPIO_level == "lo")
		{
			writeGPIO(Gpio, "0");
		}

		else
		{
			cout << "Invalid Commandm Try Again" << endl;
			return 3;
		}

		cout << "Finished GPIO Program" << endl;
	}
}
