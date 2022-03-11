#include<thread>
#include<vector>
#include<iostream>
#include<numeric>
#include<future>


long example(std::vector<int>&& v) {
	std::this_thread::sleep_for(std::chrono::milliseconds(20));
	return accumulate(v.begin(), v.end(),0l);
}

#define MAX (100000000)  //0.4 GB

int main(){

	std::vector<int> vm1;
	for(int i=1; i<=MAX; ++i) {
		vm1.emplace_back(i);
	}
	std::future<long> f1 = std::async(std::launch::async, example, move(vm1));
	//std::future<int> f1 = std::thread(example, vm1).get_future();
	//std::future<int> f1 = std::thread(example, vm1);

	std::vector<int> vm2;
	for(int i=MAX; i>0; --i) {
		vm2.emplace_back(i);
	}
	std::future<long> f2 = std::async(example, move(vm2));

	std::vector<int> vm3;
	for(int i=MAX; i>0; --i) {
		vm3.emplace_back(i);
	}
	std::future<long> f3 = std::async(example, vm3);

	std::vector<int> vm4;
	for(int i=MAX; i>0; --i) {
		vm4.emplace_back(i);
	}

	std::future<long> f4 = std::async(std::launch::deferred,example, vm4);

	std::cout<<"Result is "<<f1.get()<<std::endl;
	std::cout<<"Result is "<<f2.get()<<std::endl;
	std::cout<<"Result is "<<f3.get()<<std::endl;
	std::cout<<"Result is "<<f4.get()<<std::endl;


	return 0;
}
