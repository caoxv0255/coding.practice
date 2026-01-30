#include<iostream>
#include<deque>
#include<string>
using namespace std;
struct Task{
	//参数
	int id;
	string description;
	bool isUrgent;
	//构造函数
	Task(int taskId,const string& desc,bool urgent=false):id(taskId),description(desc),isUrgent(urgent){}
};

deque<Task> taskQueue;

void addTaskToFront(const Task&task){
	taskQueue.push_front(task);
}

void addTaskToBack(const Task&task){
	taskQueue.push_back(task);
}

void processNextTask(){
	if(taskQueue.empty()){
		cout<<"当前没有待处理任务"<<endl;
		return;
	}
	Task task =taskQueue.front();
	cout<<"处理任务-> ";
	cout<<"["<<(task.isUrgent ? "紧急":"普通")<<"] "<<task.id<<" : "<<task.
description<<endl;
	taskQueue.pop_front();
}

void showPendingTasks(){
	cout<<"当前待处理任务列表："<<endl;
	if(taskQueue.empty()){
                cout<<"（空）"<<endl;
                return;
        }
	for(const auto&task:taskQueue){
		cout<<"["<<(task.isUrgent ? "紧急":"普通")<<"] "<<task.id<<" : "<<task.description<<endl;
	}
}



int main(){
	std::cout << "=== 任务调度系统模拟 ===" << std::endl;

    // 模拟流程：添加3个普通任务
    std::cout << "\n1. 添加3个普通任务:" << std::endl;
    addTaskToBack(Task(1, "写文档"));
    addTaskToBack(Task(2, "测试代码"));
    addTaskToBack(Task(3, "提交PR"));

    showPendingTasks();

    // 添加1个紧急任务
    std::cout << "\n2. 添加1个紧急任务:" << std::endl;
    addTaskToFront(Task(99, "修复生产环境Bug",true));

    showPendingTasks();

    // 处理两个任务
    std::cout << "\n3. 开始处理任务:" << std::endl;
    processNextTask(); // 应该处理紧急任务
    processNextTask(); // 处理第一个普通任务
    cout<<"剩余任务："<<taskQueue.size()<<"个"<<endl;
    showPendingTasks();
    return 0;
}

