/* 
 * Experimenting future
 *
 * @Author: github.com/ex-passion 
 * Experience Passion
 *
 */

#include<future>
#include<vector>
#include<list>
#include<queue>
#include<iostream>
#include<numeric> //For accumulate

template<typename T>
long example(T&& t) {
	std::this_thread::sleep_for(std::chrono::milliseconds(20));
	return accumulate(t.begin(), t.end(),0l);
}

#define MAX (10000000)  

/* Template function for data structure sum */
template<typename D>
void dsSum (){

	D d1;
	for(int i=1; i<=MAX; ++i) {
		d1.emplace_back(i);
	}
	std::future<long> f1 = std::async(std::launch::async, example<D>, move(d1));
	//std::future<int> f1 = std::thread(example, vm1).get_future();
	//std::future<int> f1 = std::thread(example, vm1);

	D d2;
	for(int i=MAX; i>0; --i) {
		d2.emplace_back(i);
	}
	std::future<long> f2 = std::async(example<D>, move(d2));

	D d3;
	for(int i=MAX; i>0; --i) {
		d3.emplace_back(i);
	}
	std::future<long> f3 = std::async(example<D>, d3);

	D d4;
	for(int i=1; i<=MAX; ++i) {
		d4.emplace_back(i);
	}
	std::future<long> f4 = std::async(std::launch::deferred, example<D>, d4);

	std::cout<<"Result is "<<f1.get()<<std::endl;
	std::cout<<"Result is "<<f2.get()<<std::endl;
	std::cout<<"Result is "<<f3.get()<<std::endl;
	std::cout<<"Result is "<<f4.get()<<std::endl;
}


int main(){

	dsSum<std::vector<int>>();
	std::cout<<std::endl;

	dsSum<std::list<int>>();
	std::cout<<std::endl;

	return 0;
}
