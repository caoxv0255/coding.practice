#include<iostream>
#include<memory>
#include<vector>
class B;
class A {
public:
	std::shared_ptr<B> b_ptr;

	A(){
		std::cout << "A Constructor" << std::endl;
	}
	~A(){
		std::cout << "A Destructor" << std::endl;
	}

	void setB(std::shared_ptr<B> b){
		b_ptr = b;
	}
};
class B {
public:
	std::shared_ptr<A> a_ptr;
	B(){
		std::cout << "B Constructor" << std::endl;
	}
	~B(){
		std::cout << "B Destructor" << std::endl;
	}
	void setA(std::shared_ptr<A> a){
		a_ptr = a;
	}
};

void demonstrateMemoryLeak(){
	std::cout << "Demonstrating memory leak with shared_ptr due to circular reference:" << std::endl;
	std::cout << "constructing A and B objects" << std::endl;
	{
		// Creating shared_ptr instances of A and B
		auto a = std::make_shared<A>();
		auto b = std::make_shared<B>();

		std::cout << "a.use_count(): " << a.use_count() << std::endl;
		std::cout << "b.use_count(): " << b.use_count() << std::endl;
		// Setting up circular references
		std::cout << "setting up circular references" << std::endl;
		a->setB(b);
		b->setA(a);
		std::cout << "a.use_count(): " << a.use_count() << std::endl;
		std::cout << "b.use_count(): " << b.use_count() << std::endl;
		std::cout << "Exiting inner scope..." << std::endl;
	}
	std::cout << "Exited inner scope." << std::endl;
	std::cout << "Note: Destructors for A and B were not called due to circular reference causing memory leak." << std::endl;
}

class B_Weak;
class A_Weak {
	public:
	std::shared_ptr<B_Weak> ptr_to_b;
	A_Weak(){
		std::cout << "A_Weak Constructor" << std::endl;
	}
	~A_Weak(){
		std::cout << "A_Weak Destructor" << std::endl;
	}
	void setB(std::shared_ptr<B_Weak> b){
		ptr_to_b = b;
	}
};
class B_Weak {
	public:
	std::weak_ptr<A_Weak> ptr_to_a;
	B_Weak(){
		std::cout << "B_Weak Constructor" << std::endl;
	}
	~B_Weak(){
		std::cout << "B_Weak Destructor" << std::endl;
	}
	void setA(std::shared_ptr<A_Weak> a){
		ptr_to_a = a;
	}
};

void showAInfo(std::shared_ptr<B_Weak> b_weak_ptr) {
	if (auto a_ptr = b_weak_ptr->ptr_to_a.lock()) {
		std::cout << "A_Weak is still alive." << std::endl;
		std::cout << "a_ptr use_count: " << a_ptr.use_count() << std::endl;
	} else {
		std::cout << "A_Weak has been destroyed." << std::endl;
	}
}
void demonstrateWeakPtrSolution(){
	std::cout << "\nDemonstrating solution to circular reference using weak_ptr:" << std::endl;
	std::cout << "constructing A_Weak and B_Weak objects" << std::endl;
	{
		// Creating shared_ptr instances of A_Weak and B_Weak
		auto a_weak = std::make_shared<A_Weak>();
		auto b_weak = std::make_shared<B_Weak>();
		std::cout << "a_weak.use_count(): " << a_weak.use_count() << std::endl;
		std::cout << "b_weak.use_count(): " << b_weak.use_count() << std::endl;
		// Setting up references with weak_ptr to avoid circular reference
		std::cout << "setting up references with weak_ptr to avoid circular reference" << std::endl;
		a_weak->setB(b_weak);
		b_weak->setA(a_weak);
		std::cout << "a_weak.use_count(): " << a_weak.use_count() << std::endl;
		std::cout << "b_weak.use_count(): " << b_weak.use_count() << std::endl;
		showAInfo(b_weak);
		std::cout << "Exiting inner scope..." << std::endl;
	}
	std::cout << "Exited inner scope." << std::endl;
	std::cout << "Note: Destructors for A_Weak and B_Weak were called successfully, avoiding memory leak." << std::endl;
}

int main() {
	demonstrateMemoryLeak();
	demonstrateWeakPtrSolution();
	return 0;
}