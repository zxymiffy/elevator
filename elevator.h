//(1) elevator.h
#ifndef ELEVATOR_H_
#define ELEVATOR_H_

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define IBFEASIBLE -1
//#define OVERFLOW -2
//
#define C_LEN sizeof(Client)
#define C_S_LEN sizeof(ClientStack)
#define C_Q_LEN sizeof(ClientQueue)
#define E_LEN sizeof(Elevator)

#define Empty 0
#define Size 5 //电梯层数

#endif 

////////////////
//定义数据类型//
////////////////

typedef int Boolean;
typedef int Status;//函数类型？？？
//电梯运行状态
typedef enum{
	Opening,
	Opened,
	Closing,
	Closed,
	Waiting,
	Moving
		//accelerate,
		//Decelerate
}NowElevatorStatus;
//电梯的状态
typedef enum{
	Goingup,
	Goingdown,
	Idle
}ElevatorStatus
//乘客的存在状态
typedef enum{
	New, //初始化一个人
	GiveUp,
	In,
	Out,
	Finish
}ClientStatus;

///////////////
//数据类型声明/
///////////////

//乘客类型
typedef struct ClientSet{
	int id;
	// int e_id; 用于区分要乘坐的电梯
	int Infloor;
	int Outfloor;
	long GiveupTime;
	long InterTime;//进入电梯的时刻
	ClientStatus statu; //乘客状态
}Client;

typedef Client *QElemType;

typedef struct QNode {
	QElemType data;//???
	struct QNode *next;
}QNode, *QueuePtr;//????

//等待队列类型
typedef struct{
	struct QueuePtr front; //队头指针?????
	struct QueuePtr rear; //队尾指针?????
}ClientQueue,LinkQueue;????????

//电梯类型
typedef struct {
	//int id;
	//ClientStack *client[Size];//乘客栈
	ClientQueue *queue[2];//等待队列，下为0，上为1
	int length; //电梯里乘客人数
	int maxSize; //电梯限载人数
	int floor; //所在楼层
	int toFloor;// 目标楼层
	ElevatorStatus statu; //电梯的当前状态
	NowElevatorStatus nowStatu;//电梯现在所处的运行
	//Action action; //电梯运动方向
	//Boolean CallUp[Size]; //要向上的楼层按钮？？？
	//Boolean CallDown[Size];//要向下的楼层按钮？？？
	Boolean CallCar[Size]; //目标层按钮对应的变量？？？
	int CountTime; //电梯内部用于计算时间
}Elevator;
/*乘客栈没有实现
//乘客栈类型
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct Stack{
Client *base;//在构造之前和销毁后，base为NULL
CLient *top;//栈顶指针
int stacksize; //当前已分配的储存空间，以元素为单位？？？
}ClientStack；
*/

