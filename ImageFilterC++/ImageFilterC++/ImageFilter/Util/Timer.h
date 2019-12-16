#pragma once
#include <iostream>
#include <chrono>
#include <string>

using namespace std;

namespace image
{
namespace util 
{

	class chrono_timer {

	public:
		chrono_timer(int count, std::string name) {
			start = std::chrono::system_clock::now();
			this->count = count;
			this->name = name;
		}

		~chrono_timer() {
			std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
			std::cout << "[" << count << "] ";
			std::cout << name;
			std::cout << "elapsed time " << sec.count() << " ms" << std::endl;
		}

	private:
		int count;
		std::string name;
		std::chrono::system_clock::time_point start;
	};

}
}