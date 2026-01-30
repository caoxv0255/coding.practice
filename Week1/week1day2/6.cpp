//挑战1：实现简单的链表
//定义链表节点结构体 Node，包含 int data 和 Node* next
//实现函数：在链表头部插入节点、遍历打印链表、释放链表内存
//注意使用动态内存分配和正确释放
#include<iostream>
#include<stdexcept>
template<typename T>
struct Node {
	T data;
	Node* next;
	Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
	Node<T>* head;
	int size;
public:
	// 构造函数和析构函数(释放内存)
	LinkedList() : head(nullptr), size(0) {}
	~LinkedList() {
		Node<T>* current = head;
		while(current !=nullptr) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
	}

	// 在链表头部插入节点
	void insertAtHead(T val) {
		Node<T>* newNode = new Node<T>(val);
		newNode->next = head;
		head = newNode;
		size++;
	}

	// 遍历打印链表
	void printList() const {
		Node<T>* current = head;
		while (current != nullptr) {
			std::cout << current->data << " -> ";
			current = current->next;
		}
		std::cout << "nullptr" << std::endl;
		std::cout << "size:" << size << std::endl;
	}

	//尾插法
	void insertAtTail(T val) {
		Node<T>* newNode = new Node<T>(val);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node<T>* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
			size++;
		}
	}
	//在指定位置插入节点
	void insertAtPosition(int position, T val) {
		Node<T>* newNode = new Node<T>(val);
		if(position < 0 || position > size) {
			throw std::out_of_range("Position out of range");
		}
		if(position == 0) {
			newNode->next = head;
			head = newNode;
		} else {
			Node<T>* current = head;
			for(int i = 0; i < position - 1; i++) {
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
		}
	}

	//删除节点
	void deleteAtPosition(int position){
		if (position < 0 || position > size) {
			throw std::out_of_range("Position out of range");
		}
		if (position == 0) {
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node<T>* current = head;
		for (int i = 0; i < position - 1; i++) {
			current = current->next;
		}
		Node<T>* temp = current->next;
		current->next = temp->next;
		delete temp;
		size--;
	}

	//查找节点
	Node<T>* find(T val) {
		Node<T>* current = head;
		while (current != nullptr) {
			if (current->data == val) {
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}
};

int main() {
	LinkedList<int> list;
	list.insertAtHead(10);
	list.insertAtHead(20);
	list.insertAtTail(30);
	list.insertAtPosition(1, 15);
	list.printList();
	Node<int>* foundNode = list.find(15);
	if (foundNode) {
		std::cout << "Found node with value: " << foundNode->data << std::endl;
	} else {
		std::cout << "Node not found" << std::endl;
	}
	list.deleteAtPosition(1);
	list.printList();
	return 0;
}