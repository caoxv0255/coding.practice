//任务描述
//通过Engine（引擎）和Car（汽车）类演示组合关系，理解"整体-部分"的强拥有关系。
//类设计：
//Engine类：
//私有成员：int horsepower（马力）
//公有接口：
//构造函数：Engine(int hp)，默认100马力
//void start() const - 输出"Engine started ([hp] hp)"
//int getHorsepower() const - 返回马力值
//Car类：
//私有成员：std::string brand（品牌）、Engine engine（引擎对象，组合关系）
//公有接口：
//构造函数：Car(const std::string & b, int hp) - 初始化品牌和引擎
//void startCar() const - 先输出"Starting [brand] car..."，再调用engine.start()
//void upgradeEngine(int newHp) - 更换引擎（替换engine对象）
//要求
//体现组合关系：Car对象拥有Engine对象，生命周期一致
//Car类控制Engine的创建和销毁
//演示汽车启动时引擎的协同工作
//完成建议
//先实现简单的Engine类
//在Car类中以组合方式包含Engine对象
//测试代码：

#include<iostream>
#include<string>
class Engine {
private:
    int horsepower;

public:
    Engine(){ horsepower = 100; }
    Engine(int hp) :horsepower(hp) {}
    void start() const {
        std::cout << "Engine started (" << horsepower << "hp)" << std::endl;
    }
    int getHorsepower() const { return horsepower; }
};

class Car {
private:
    std::string brand;
	Engine engine; // 组合关系
public:
	Car(const std::string& b, int hp) :brand(b), engine(hp) {}
    void startCar() const {
        std::cout << "Starting [" << brand << "] car..." << std::endl;
        engine.start();
    }
    void upgradeEngine(int newHp) {
		Engine newEngine(newHp);
        engine = newEngine;
    }
};

int main() {
    Car myCar("Toyota", 150);
    myCar.startCar();

    // 升级引擎
    myCar.upgradeEngine(200);
    myCar.startCar();

    // 演示组合生命周期
    {
        Car tempCar("Honda", 120);
        tempCar.startCar();
    } // tempCar和其engine同时销毁
}
