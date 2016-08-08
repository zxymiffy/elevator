/*
 *elevator.c
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
///////////////////
//定义基本外部变量/
//////////////////
int Start = 1; //本垒层  
int Limit = 15;      //电梯的限载 
int Maxfloor = 4;     //最高处 
int Minfloor = 0;    //最低层   
float t = 0.1;      //单位时间0.1毫秒 
int CloseTime = 40;    //电梯关门测试时间 
int OverTime = 300;    //电梯停候超时时间 
int DoorTime = 20;     //开门关门时间 
int InOutTime = 25;    //进出电梯时间 
int AccelerteTime = 15;   //加速时间 
int UpTime = 50;     //上升时间 
int DownTime = 60;     //下降时间 
int UpDecelerateTime = 14;   //上升减速 
int DownDecelerateTime = 23;  //下降减速   
int InOutCount = 0;    //用于进出计时  
int InterTime = 0;    //下一乘客进入系统的时间
///////////////
//函数实现/
//////////////
Client *InitClient();{
Client *C = (Client*) malloc(C_LEN);
	C->statu = New;
	if (!C) {
		exit(OVERFLOW);
	}
	return C;

}
Status DestroyClient(Client *C){
free(C);
	return OK;

}
void PrintClient(Client *C){
switch (C->statu) {
	case New:
		printf("\t%d号乘客进入第%d号电梯第%d层:目标层为第%d层,进入时间为 %.1f S,忍耐时间为 %.1f S\n",
				C->id, C->e_id, C->InFloor, C->OutFloor, C->InterTime * t,
				C->GiveupTime * t);
		break;
	case GiveUp:
		printf("\t第 %.1f S 时\t%d号乘客放弃等待第%d号电梯\n",
				(C->InterTime * t + C->GiveupTime) * t, C->id, C->e_id);
		break;
	case Out:
		printf("\t%d号乘客走出第%d号电梯\n", C->id, C->e_id);
		break;
	case In:
		printf("\t%d号乘客走进第%d号电梯，要去第%d层\n", C->id, C->e_id, C->OutFloor);
		break;
	default:
		break;
	};
}
LinkQueue *InitQueue(){
LinkQueue *Q = (LinkQueue *) malloc(C_Q_LEN);
	if (!Q) {
		exit(OVERFLOW);
	}
	Q->front = Q->rear = (QNode *) malloc(sizeof(QNode));
	if (!Q->front) {
		exit(OVERFLOW);
	}
	Q->front->next = NULL;
	Q->front->data = NULL;
	return Q;
}	

Status ClearQueue(LinkQueue *Q){
while (Q->front) {
		Q->rear = Q->front->next;
		if (Q->front->data) {
			free(Q->front->data);
			free(Q->front);
		} else {
			break;
		}
		Q->front = Q->rear;
	}
	return OK;
}
Status DestroyQueue(LinkQueue *Q){
hile (Q->front) {
		Q->rear = Q->front->next;
		if (Q->front->data) {
			free(Q->front->data);
			free(Q->front);
		} else {
			break;
		}
		Q->front = Q->rear;
	}
	free(Q);
	return OK;
}
int QueueLength(LinkQueue *Q){
QNode *qn;
	int length = 0;
	for (qn = Q->front; qn != Q->rear; qn = qn->next) {
		length++;
	}
	return length;
}
QueuePtr GetHead(LinkQueue *Q){
if (Q->front == Q->rear) {
		return NULL;
	}
	return Q->front->next;
}
//保证插入队列的人是按时间顺序排序的
Status EnQueue(LinkQueue *Q, QElemType e){
QNode *p;
	p = (QNode *) malloc(sizeof(QNode));
	if (!p) {
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}
Status DeQueue(LinkQueue *Q, QElemType e){
QNode *p;
	p = (QNode *) malloc(sizeof(QNode));
	if (!p) {
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}	
Boolean QueueEmpty(LinkQueue Q){
if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}	
Status QDelNode(LinkQueue *Q, QueuePtr p){
QueuePtr q;
	if (p == NULL || p->next == NULL)
		return ERROR;
	q = GetHead(Q);
	while (q) {
		if (q->data->id == p->data->id) {
			if (q == GetHead(Q)) {
				Q->front->next = q->next;
				break;
			}
			q->next = q->next->next;
			break;
		}
		q = q->next;
	}
	return OK;

}	
Status CGiveUp(LinkQueue *Q, int floor, int nowTime){
QueuePtr q;
	if (p == NULL || p->next == NULL)
		return ERROR;
	q = GetHead(Q);
	while (q) {
		if (q->data->id == p->data->id) {
			if (q == GetHead(Q)) {
				Q->front->next = q->next;
				break;
			}
			q->next = q->next->next;
			break;
		}
		q = q->next;
	}
	return OK;

}	
void PrintQueue(LinkQueue Q){
QueuePtr q;
	q = Q.front->next;
	while (q != NULL) {
		PrintClient(q->data);
		q = q->next;
	}

}
Elevator *InitElevator(){
int i = 0;
	Elevator *E = (Elevator *) malloc(E_LEN);
	if (!E) {
		exit(OVERFLOW);
	}
	for (i = 0; i < 2; i++) {
		E->queue[i] = InitQueue();
	}
	E->floor = Start;
	E->toFloor = Start;
	E->length = 0;
	E->maxSize = Limit;
	E->statu = Idle;
	E->nowStatu = Waiting;
	E->CountTime = 0;				//用于开关门计时
	for (i = 0; i < Size; i++) {
		E->CallCar[i] = FALSE;
	}
	return E;
	}
Status DestoryElevator(Elevator *E){
int i;
	for (i = 0; i < 2; i++) {
		DestroyQueue(E->queue[i]);
	}
	free(E);
	return OK;
}

void PrintElevator(Elevator *E, int NowTime) {
	printf("\t第 %.1lf S 时\t第   %d 号电梯抵达第 %d 层\t", NowTime * t, E->id, E->floor);
	if (E->statu == GoingDown) {
		printf("方向向下\n");
	}
	if (E->statu == GoingUp) {
		printf("方向向上\n");
	}
	if (E->statu == Idle) {
		printf("在此层等候\n");
	}

}
//电梯E 根据当前电梯队列判断现在在哪层在叫电梯，那一层的人放弃乘坐电梯？？？
Boolean Call(Elevator *E, int NowTime){
Boolean flag = FALSE;				//有人呼叫电梯
	QueuePtr p, q;
	p = GetHead(E->queue[0]);
	q = GetHead(E->queue[1]);
	while (p) {
		if (NowTime == p->data->InterTime) {
			E->CallCar[p->data->InFloor - Minfloor] = TRUE;
			printf("\t第%0.1fS\t", NowTime * t);
			{
				QueuePtr q;
				q = E->queue[0]->front->next;
				while (q != NULL) {
					if (NowTime == q->data->InterTime) {
						printf("%d号乘客在第%d号电梯第%d层\t", q->data->id, q->data->e_id,
								q->data->InFloor);
						flag = TRUE;
					}
					q = q->next;
				}
			}
			printf("呼叫电梯\n");
		}
		p = p->next;
	}
	while (q) {
		if (NowTime == q->data->InterTime) {
			E->CallCar[q->data->InFloor - Minfloor] = TRUE;
			printf("\t第%0.1fS\t", NowTime * t);
			{
				QueuePtr q;
				q = E->queue[1]->front->next;
				while (q != NULL) {
					if (NowTime == q->data->InterTime) {
						printf("%d号乘客在第%d号电梯第%d层\t", q->data->id, q->data->e_id,
								q->data->InFloor);
						flag = TRUE;
					}
					q = q->next;
				}
			}
			printf("呼叫电梯\n");
		}
		q = q->next;
	}
	return flag;
}
//判断出最新的目标层
void ToFloor(Elevator *E){

}
//控制电梯人的进出，返回进出总人数
int InOut(Elevator *E, int NowTime){
Boolean flag = FALSE;				//有人呼叫电梯
	QueuePtr p, q;
	p = GetHead(E->queue[0]);
	q = GetHead(E->queue[1]);
	while (p) {
		if (NowTime == p->data->InterTime) {
			E->CallCar[p->data->InFloor - Minfloor] = TRUE;
			printf("\t第%0.1fS\t", NowTime * t);
			{
				QueuePtr q;
				q = E->queue[0]->front->next;
				while (q != NULL) {
					if (NowTime == q->data->InterTime) {
						printf("%d号乘客在第%d号电梯第%d层\t", q->data->id, q->data->e_id,
								q->data->InFloor);
						flag = TRUE;
					}
					q = q->next;
				}
			}
			printf("呼叫电梯\n");
		}
		p = p->next;
	}
	while (q) {
		if (NowTime == q->data->InterTime) {
			E->CallCar[q->data->InFloor - Minfloor] = TRUE;
			printf("\t第%0.1fS\t", NowTime * t);
			{
				QueuePtr q;
				q = E->queue[1]->front->next;
				while (q != NULL) {
					if (NowTime == q->data->InterTime) {
						printf("%d号乘客在第%d号电梯第%d层\t", q->data->id, q->data->e_id,
								q->data->InFloor);
						flag = TRUE;
					}
					q = q->next;
				}
			}
			printf("呼叫电梯\n");
		}
		q = q->next;
	}
	return flag;

}
//操作结果：根据当前电梯队列判断现在哪层在叫电梯 
void Controler(Elevator *E, int NowTime){
E->CountTime--;

	CGiveUp(E->queue[0], E->floor, NowTime);				//放弃乘坐电梯处理
	CGiveUp(E->queue[1], E->floor, NowTime);

	if (E->nowStatu == Waiting && E->statu == Idle) {				//是否继续等候等候
		if (Call(E, NowTime)) {
			E->statu = GoingUp;
			E->nowStatu = Closed;
			E->CountTime = 0;
		}
	}
	if (E->nowStatu == Waiting && E->statu == Idle && E->CountTime == 0) {//是否电梯要返回本垒层等候
		E->floor = 1;
		E->toFloor = 1;
		printf("\t此时间段无乘客呼叫第%d号电梯，电梯返回本垒层\n", E->id);
		PrintElevator(E, NowTime);
	}

	if (E->nowStatu == Closed) {		//判断移动时间
		E->nowStatu = Moving;
		if (E->statu == GoingUp) {
			E->CountTime = UpTime;
		}
		if (E->statu == GoingDown) {
			E->CountTime = DownTime;
		}
		return;
	}
	if (E->nowStatu == Moving && E->CountTime == 0) {		//电梯移动计时
		E->CountTime = DoorTime;
		if (E->statu == GoingUp && E->floor != Maxfloor) {
			E->CountTime = UpTime;
			++E->floor;
		} else if (E->statu == GoingUp && E->floor == Maxfloor) {
			E->statu = GoingDown;
			--E->floor;
		} else if (E->statu == GoingDown && E->floor != Minfloor) {
			E->CountTime = DownTime;
			--E->floor;
		} else if (E->statu == GoingDown && E->floor == Minfloor) {
			E->statu = GoingUp;
			++E->floor;
		}
		if (E->CallCar[E->floor - Minfloor]) {	//如果抵达的楼层要求开门,否则重置移动时间
			E->nowStatu = Opening;
			E->CallCar[E->floor - Minfloor] = FALSE;
			PrintElevator(E, NowTime);
		} else {
			E->CountTime = DoorTime;
		}
		return;
	}
	if (E->nowStatu == Opening && E->CountTime == 0) {
		E->nowStatu = Opened;
		printf("\t第%0.1fS\t第%d号电梯正在开门\n", NowTime * t, E->id);
		return;
	}
	if (E->nowStatu == Opened) {
		printf("\t第%0.1fS\t第%d号电梯开门\n", NowTime * t, E->id);
		printf("\t乘客进出：\n");
		InOutCount = InOutTime * InOut(E, NowTime);	//乘客进出时间
		E->nowStatu = Closing;
		E->CountTime = DoorTime + InOutCount;	//关门时间+乘客进出时间
		printf("\t第%0.1fS\t第%d号电梯正在关门\n", NowTime * t), E->id;
		return;
	}

	if (E->nowStatu == Closing && E->CountTime == 0) {
		if (E->length == 0) {			//此时电梯内没人并且没人呼叫电梯
			int i;
			Boolean flag = FALSE;
			for (i = 0; i < Size; i++) {
				if (E->CallCar[i]) {	//是否有人已经有人呼叫电梯了
					flag = TRUE;
				}
			}
			if (!flag) {	//如果一直没有人呼叫电梯
				E->CountTime = OverTime;	//重置等候时间并且在此层等候
				E->nowStatu = Waiting;	//等候状态
				E->statu = Idle;
				PrintElevator(E, NowTime);
				return;
			}
		}
		printf("\t第%0.1fS\t第%d号电梯关门\n", NowTime * t, E->id);
		E->nowStatu = Closed;
		return;
	}

}

