#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	int height;
};
class AVL
{
	public:
		node *ROOT;
	public:
	AVL()
	{
		this->ROOT=NULL;
	}
	int CalCulate_Height(node *iter)
	{
		if(iter==NULL)
		{
			return 0;
		}
		else if(iter->left && iter->right)
		{
			if(iter->left->height < iter->right->height)
			{
				return iter->right->height+1;
			}
			else if(iter->left->height > iter->right->height)
			{
				return iter->left->height+1;
			}
		}
		else if(iter->left && iter->right == NULL)
		{
			return iter->left->height+1;
		}
		else if(iter->left == NULL && iter->right)
		{
			return iter->right->height+1;
		}
		return 0;
	}
	int Balance_Factor(node *iter)
	{
		int a;
		if(iter->left && iter->right)
		{
			a=(iter->left->height - iter->right->height);
			return a;
		}
		else if(iter->left && iter->right==NULL)
		{
			a=iter->left->height;
			return a;
		}
		else if(iter->left==NULL && iter->right)
		{
			a=(-(iter->right->height));
			return a;
		}
			return a;
	}
	node *Left_Rotation(node *iter)
	{
		node *a;             //           (30)             (20)
		node *b;             //          /                /    \. 
		a=iter;              //       (20)            (10)      (30)
		b=a->left;           //      /.
		a->left=b->right;    //  (10)
		b->right=a;          
		return b;            
	}
	node *Right_Rotation(node *iter)
	{
		node *a;           //     (30)                         (20)  
		node *b;           //         \                       /    \.
		a=iter;            //          (20)                (30)     (10) 
		b=a->right;        //              \.
		a->right=b->left;  //               (10)
                b->left=a;
		return b;
	}
	node *Right_Left_Rotation(node *iter)
	{
		node *a;             //  (10)    (R)  (10)        (L)       (20)
		node *b;             //      \            \                /    \.
		node *c;             //       (30)         (20)         (10)     (20)
		a=iter;              //      /                 \.
		b=a->right;          //   (20)                  (30)
		c=a->right->left;    
		a->right=c->left;    
		b->left=c->right;    
		c->left=a;
		c->right=b;
		return c;
	}
	node *Left_Right_Rotation(node *iter)
	{
		node *a;            //        (30)          (30)          (20)
		node *b;            //        /            /             /    \.
		node *c;            //     (10)          (20)          (10)    (30)
		a=iter;             //        \          /
		b=a->left;          //        (20)     (10)
		c=a->left->right;   //
		a->left=c->right;   //
		b->right=c->left;   //
		c->right=a;
		c->left=b;
		return c;
	}
	node *insert(node *iter,int DATA)
	{
		if(iter==NULL)
		{
			node *NewNode= new node;
			NewNode->data=DATA;
			iter=NewNode;
			iter->left = iter->right =NULL;
			iter->height=1;
			return iter;
		}
		else
		{
			if(DATA<iter->data)
			{
				iter->left=insert(iter->left,DATA);
			}
			else if(DATA>iter->data)
			{
				iter->right=insert(iter->right,DATA);
			}
		}
		iter->height=CalCulate_Height(iter);
		if(Balance_Factor(iter)==2 && Balance_Factor(iter->left)==1)
		{
			iter=Left_Rotation(iter);
		}
		else if(Balance_Factor(iter)==2 && Balance_Factor(iter->right)==1)
		{
			iter=Right_Rotation(iter);
		}
		else if(Balance_Factor(iter)==-2 && Balance_Factor(iter->right)==1)
		{
			iter= Right_Left_Rotation(iter);
		}
		else if(Balance_Factor(iter)==2 && Balance_Factor(iter->right)==-1)
		{
			iter=Left_Right_Rotation(iter);
		}
		return iter;
	}
	node *deleteNode(node *iter, int data)
	{
		if(iter->left==NULL && iter->right==NULL)
		{
			if(iter==this->ROOT)
			{
				this->ROOT=NULL;
			}
			delete iter;
			return NULL;
		}
	//	node *t;
		node *q;
		if(iter->data > data)
		{
			iter->left=deleteNode(iter->left,data);
		}
		else if(iter->data <data)
		{
			iter->right=deleteNode(iter->right,data);
		}
		else
		{
			if(iter->left != NULL)
			{
				q = inpre(iter->left);
				iter->data = q->data;
                iter->left=deleteNode(iter->left,q->data);
			}
			else
			{
				q = insuc(iter->right);
                iter->data = q->data;
                iter->right = deleteNode(iter->right,q->data);
			}
		}
		if(Balance_Factor(iter)==2 && Balance_Factor(iter->left)==1)
		{
			iter = Left_Rotation(iter); 
		}                  
		else if(Balance_Factor(iter)==2 && Balance_Factor(iter->left)==-1)
		{
			iter = Left_Right_Rotation(iter);
		}
		else if(Balance_Factor(iter)==2 && Balance_Factor(iter->left)==0)
		{ 
			iter = Left_Rotation(iter);
		}
		else if(Balance_Factor(iter)==-2 && Balance_Factor(iter->right)==-1)
		{ 
			iter = Right_Rotation(iter);
		}
		else if(Balance_Factor(iter)==-2 && Balance_Factor(iter->right)==1)
		{ 
			iter = Right_Left_Rotation(iter); 
		}
		else if(Balance_Factor(iter)==-2 && Balance_Factor(iter->right)==0)
		{ 
			iter = Left_Rotation(iter); 
		}
		return iter;
	}
	node* inpre(node* p){
        while(p->right!=NULL)
            p = p->right;
        return p;    
    }
    node* insuc(node* p){
        while(p->left!=NULL)
            p = p->left;

        return p;    
    }
	void Pre_Order_Print(node *iter)
	{
		if(iter!=NULL)
		{
			cout<<iter->data<<",";
			Pre_Order_Print(iter->left);
			Pre_Order_Print(iter->right);
		}
	}
	~AVL(){
    }
};
int main()
{
	AVL a;
	a.ROOT=a.insert(a.ROOT,13);
	a.ROOT=a.insert(a.ROOT,10);
	a.ROOT=a.insert(a.ROOT,24);
	a.ROOT=a.insert(a.ROOT,7);
	a.ROOT=a.insert(a.ROOT,20);
	a.ROOT=a.insert(a.ROOT,30);
	a.ROOT=a.insert(a.ROOT,15);
	a.ROOT=a.insert(a.ROOT,25);
	a.ROOT=a.insert(a.ROOT,36);
	cout<<"Before Deletion !!!"<<endl;
	a.Pre_Order_Print(a.ROOT);
	cout<<endl;
	
	a.ROOT=a.deleteNode(a.ROOT,20);
	a.ROOT=a.deleteNode(a.ROOT,24);
	cout<<"After Deletion !!!"<<endl;
	a.Pre_Order_Print(a.ROOT);
	cout<<endl;


	
	return 0;
}
