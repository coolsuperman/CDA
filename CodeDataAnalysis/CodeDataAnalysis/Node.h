#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//#include<fstream>
#include<string>
#include<io.h>
#include<vector>
using namespace std;


struct Node{//每个文件信息存储；
  string name;//名称；
  string PATH;//路径；
  int lines;//总行数；
  int functions;//函数；-------可弄为vector<string>储存函数原型；
  int classes;//类数；
  int ZS;//注释数；
  int real_lines;//实际行数；
  Node* next;
  void* operator new(size_t n){//重载自定义类型 new
    void*p = NULL;
    p = allocator<Node>().allocate(1);
    cout<<"allocate"<<endl;
    return p;
  }

  void operator delete(void* p){//重载自定义类型 delete
    allocator<Node>().deallocate((Node*)p,1);
    cout<<"deallocate！"<<endl;
  }
};

struct List{//每个类型文件的表头
    List (const List& target) = delete;
	string _name;//名称；
	string _PATH;//路径；
	int _lines=0;//总行数；
	int _functions=0;//函数；
	int _classes=0;//类数；
	int _ZS=0;//注释数；
	int _real_lines=0;//实际行数；
	int _ListSize;
	List* next = NULL;
	Node* _last = NULL;
	Node* _head = NULL;
  List(const string& name,const string&PATH)
    :_name(name)
     ,_PATH(PATH)
	 ,_ListSize(0)
  {}
  ~List(){
    while(_head!=NULL){
      Node*self = _head;
      _head = _head->next;
      delete self;
    }
  }

  int ListSize(){
    return _ListSize;
  }

 void SetNode(Node* fresh){
    if(_ListSize==0){
		_head = fresh;
		_last = fresh;
		
	}
	else {
		fresh->next = NULL;
		_last->next = fresh;
		_last = fresh;
	}
	_lines += fresh->lines;
	_functions += fresh->functions;
	_classes += fresh->classes;
	_ZS += fresh->ZS;
	_real_lines += fresh->real_lines;
	_ListSize++;
  }

 int CheckNode_Byname(const string& target){
	 Node*go = _head;
	 while ( go->next ) {
		 if ( !go->name.compare(target) ) {
			 DisplayNode (go);
			 return 0;
		 }
		 go = go->next;
	 }
    cout<<"Can't find file!"<<go->next<<endl;
	return 1;
  }
 void DisplayNode (Node*node) {
	 if ( _head == NULL ) {
		 cout << "Empty!" << endl;
		 return;
	 }
	 cout << "文件名:" << node->name << endl;
	 cout << "路径:" << node->PATH << endl;
	 cout << "总行数:" << node->lines << endl;
	 cout << "函数数量:" << node->functions << endl;
	 cout << "类型数量:" << node->classes << endl;
	 cout << "注释数量:" << node->ZS << endl;
	 cout << "有效行数:" << node->real_lines << endl;
 }
  void DisplayList(){
    if(_head==NULL){
      cout<<"Empty!"<<endl;
      return;
    }
	cout << "文件类型:" << _name << endl;
	cout << "路径:" << _PATH << endl;
	cout << "文件数量:" << _ListSize << endl;
	cout << "总行数:" << _lines<< endl;
	cout << "函数数量:" << _functions << endl;
	cout << "类型数量:" << _classes << endl;
	cout << "注释数量:" << _ZS << endl;
	cout << "有效行数:" << _real_lines << endl;
  }
};

struct ALL {//存储总共文件信息；
	string _PATH;//路径；
	int lines = 0;//总行数；
	int functions = 0;//函数；-------可弄为vector<string>储存函数原型；
	int classes = 0;//类数；
	int ZS = 0;//注释数；
	int real_lines = 0;//实际行数；
	int AllSize = 0;//文件数；
	List* _first = NULL;
	List* _last = NULL;
	List* map [3] = { 0 };//改成动态的
	int i = 0;
	ALL (string PATH)
		:_PATH (PATH) 			{
}
				void Setbranch (List*fresh) {
					if ( AllSize == 0 ) {
						_first = fresh;
						_last = fresh;

					}
					else {
						fresh->next = NULL;
						_last->next = fresh;
						_last = fresh;
					}
					map [i++] = fresh;
				}
				void CountAll () {
					List*go = _first;
					while ( go->next ) {
						lines += go->_lines;
						functions += go->_functions;
						classes += go->_classes;
						ZS += go->_ZS;
						real_lines += go->_real_lines;
						AllSize += go->_ListSize;
					}
				}

				void CheckNodeByname (const string& target) {
					for ( int j = 0; j < i; j++ ) {
						if ( !(map [j]->_name.compare (target)) ) {//error

						}
					}
				}
			};
