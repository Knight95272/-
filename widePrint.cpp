#include<iostream>
#include<queue>
#include<stack>

using namespace std;


typedef struct node
{
	int nValue;
	struct node * pLeft;
	struct node * pRight;
}Tree;


Tree * CreateTree()
{
	//根
	Tree * root = (Tree *)malloc(sizeof(Tree));
	root->nValue = 1;

	//根的左
	root->pLeft = (Tree *)malloc(sizeof(Tree));
	root->pLeft->nValue = 2;

	//左的左
	root->pLeft->pLeft = (Tree *)malloc(sizeof(Tree));
	root->pLeft->pLeft->nValue = 4;
	root->pLeft->pLeft->pLeft = NULL; //边界注意赋值为null
	root->pLeft->pLeft->pRight = NULL;

	//左的右
	root->pLeft->pRight = (Tree *)malloc(sizeof(Tree));
	root->pLeft->pRight->nValue = 5;
	root->pLeft->pRight->pLeft = NULL;
	root->pLeft->pRight->pRight = NULL;

	//根的右
	root->pRight = (Tree *)malloc(sizeof(Tree));
	root->pRight->nValue = 3;
	root->pRight->pLeft = NULL;
	root->pRight->pRight = NULL;

	return root;
}

void widePrint(Tree * pTree) //层序遍历
{
	if(pTree == NULL) return;

	//创建队列
	queue<Tree*> que;

	//根节点入队
	que.push(pTree);

	//遍历
	while(!que.empty())
	{
		pTree = que.front();
		que.pop();

		cout<<pTree->nValue<<" ";
		
		//左右节点入队
		if(pTree->pLeft)
		{
			que.push(pTree->pLeft);
		}
		if(pTree->pRight)
		{
			que.push(pTree->pRight);
		}
	}
	cout<<endl;
}
void lengthPrint(Tree * pTree)
{
	if(pTree == NULL) return;

	//创建栈
	stack<Tree *> st;

	//根节点入队
	st.push(pTree);

	while(!st.empty())
	{
		while(pTree)
		{
			cout << pTree->nValue<< " "; //打印
			st.push(pTree);//保存
			pTree = pTree->pLeft;//找下一个左侧
		}

		//弹出
		pTree = st.top();
		st.pop(); 

		//右侧
		pTree = pTree->pRight; 
	}
	cout<<endl;
}
void midPrint(Tree * pTree)
{
	if(pTree == NULL) return;

	//创建栈
	stack<Tree *> st;

	//根节点入栈
	st.push(pTree);

	while(!st.empty())
	{
		while(pTree)
		{
			st.push(pTree);
			pTree = pTree->pLeft;
		}

		//弹出
		pTree = st.top();
		st.pop();

		cout<< pTree->nValue<<" ";

		//右侧
		pTree = pTree->pRight;
	}

	cout<<endl;
}

void laPrint(Tree * pTree)
{
	if(pTree == NULL) return;

	//创建栈
	stack<Tree *> st;
	
	Tree * pMark = NULL;//记录上一次打印的节点

	//根节点入栈
	st.push(pTree);

	while(!st.empty()) 
	{
		//保存 处理左侧
		while(pTree)
		{
			st.push(pTree);
			pTree = pTree->pLeft;
		}
		//处理右侧 判断是否处理过，记录上一次打印的节点
		if( pMark == st.top()->pRight || st.top()->pRight == NULL)
		{
			//处理过 或者 右子节点为空-->弹出 打印 标记
			pMark = st.top(); //先标记

			st.pop();

			cout<<pMark->nValue<<" ";

		}
		else  //未处理-->处理
		{
			pTree = st.top()->pRight;
		}
	}
	cout<<endl;
}
void CreateBST(Tree ** pPTree) //需要通过形参修改实参的值 ，需要放入树节点，而并不是只添加节点里面元素。
{
	Tree * pTemp = NULL; //用于临时存储节点

	Tree * pTree = NULL; //用于给根节点添加左右节点
	while(1)
	{
		int node;
		cout<<"请输入要添加的节点 退出输入-1 "<< " ";
		cin>>node;

		if(node == -1) break;//退出
		
		if(*pPTree == NULL) //根节点
		{
			pTemp = (Tree *)malloc(sizeof(Tree));
			pTemp->nValue = node;
			pTemp->pLeft = NULL;
			pTemp->pRight = NULL;

			*pPTree = pTemp;
			pTree = pTemp;
		}
		else
		{
			if(pTree->nValue > node ) //与当前父节点比较
			{
			 	if(pTree->pLeft == NULL) //左边为空，放入
				{
					pTemp = (Tree *)malloc(sizeof(Tree));
					pTemp->nValue = node;
					pTemp->pLeft = NULL;
					pTemp->pRight = NULL;

					pTree->pLeft = pTemp;	
				}
				
				
					//放入之后左边也不为空，也得向左传 ，继续比较，所以不能用else
					pTree = pTree->pLeft;
				
			}
			else
			{
			 	if(pTree->pRight == NULL) //右边为空，放入
				{
					pTemp = (Tree *)malloc(sizeof(Tree));
					pTemp->nValue = node;
					pTemp->pLeft = NULL;
					pTemp->pRight = NULL;

					pTree->pRight = pTemp;	
				}
					//右边不为空，继续比较
					pTree = pTree->pRight;

			}
		}
	}

}

Tree * pPre = NULL;//全局，用于标记删除节点的上一个节点
Tree * find(Tree * pRoot,int nNum)//查找删除元素位置
{
	Tree * pTemp = NULL;//用于返回得到的节点
	if(pRoot == NULL ) return;

	if(pRoot->nValue == nNum)
	{
		return pTemp;
	}
	else if(pRoot->nValue > nNum)
	{
		//找左子树
		pPre = pRoot;
		return find(pRoot->pLeft,nNum);
	}
	else
	{
		//找右子树
		return find(pRoot->pRight,nNum);
	}
}
Tree * findRightMin(Tree * pRoot) //找到当前非空右子树的最小节点,注意传右子节点
{
	if(pRoot->pLeft == NULL)
	{
		return pRoot;
	}
	else
	{
		pPre = pRoot; //记录删除的上一个
		return findRightMin(pRoot->pLeft); //左子树非空，继续往左找
	}
}
void deleteTree(Tree * pTree,int nNum)//删除操作，并不太可能删除根节点，除非剩最后一个节点为根，且删除为根，传一级指针即可
{
	Tree * pDel = find(pTree,nNum);//要删除的元素
	Tree * pTemp = NULL;//用于覆盖
	//判断孩子情况 
	if(pDel->pLeft == NULL && pDel->pRight == NULL ) //都为空，直接删除
	{
		free(pDel);
		pDel = NULL;

		return;
	}
	else
	{
		//俩个都不为空，找右子树最小覆盖
		pTemp = findRightMin(pDel->pRight);
		//值覆盖
		pDel->nValue = pTemp->nValue;
		//删除 判断删除节点的子节点的个数
		if(pTemp->pLeft == NULL && pTemp->pRight == NULL) //子结点个数0
		{
			//直接删除
			free(pTemp);
			pTemp = NULL;
		}
		else // 1
		{
			//爷孙相连
			if(pTemp->pLeft == NULL )
			{
				pPre->pRight = pTemp->pRight;
				free(pTemp);
				pTemp = NULL;
			}
			else
			{
				pPre->pLeft = pTemp->pLeft;
				free(pTemp);
				pTemp = NULL;
			}

		}

		return;
	}
	if(pDel->pLeft == NULL) //其中一个为空，直接链接爷孙
	{
		pPre->pRight = pDel->pRight;
		free(pDel);
		pDel = NULL;
		return;
	}
	if(pDel->pRight == NULL)
	{
		pPre->pLeft = pDel->pLeft;
		free(pDel);
		pDel = NULL;
		return;
	}
	
}
void addLeft(Tree * pTree)
{
	Tree * pTemp = (Tree *)malloc(sizeof(Tree));
	pTemp->nValue = 6;
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;

	pTree->pLeft->pLeft->pLeft = pTemp;
}
int main(void)
{
	//Tree * pTree = CreateTree();
	//addLeft(pTree);
	//widePrint(pTree);
	//lengthPrint(pTree);
	//midPrint(pTree);
	//laPrint(pTree);
	Tree * pTree1 = NULL;
	CreateBST(&pTree1);
	lengthPrint(pTree1); //输出俩个数字的原因，此时根节点的位置已经改变

	return 0;
}
