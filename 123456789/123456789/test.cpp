#include <iostream>
using namespace std;

class DB
{
public:
	DB();
	~DB();
	bool checkUser(char *name, char *pwd);
	bool query(char *name);
	void addUser(char *name, char *pwd);
private:
	struct Node
	{
		Node(char *n, char *p) :_pnext(NULL)
		{
			strcpy_s(_name, 20, n);
			strcpy_s(_pwd, 20, p);
		}
		char _name[20];
		char _pwd[20];
		Node *_pnext;
	};

	Node *_phead;
};

class CMenu
{
public:
	CMenu() :_bsysRunning(true){}
	void run();
	void showMainMenu();

	void _login(){ cout << "登陆界面" << endl; }
	void _register(){ cout << "注册界面" << endl; }
	void _loginOut(){ _bsysRunning = 0; cout << "退出界面" << endl; }
private:
	char _name[20];
	char _pwd[20];
	bool _bsysRunning;
	DB _db;
};

typedef void (CMenu::*PFUNC)();
PFUNC pfunc = NULL;

PFUNC gFuncTable[] =
{
	&CMenu::_login,
	&CMenu::_register,
	&CMenu::_loginOut
};
//int gFuncTableLen = sizeof(gFuncTable) / sizeof(gFuncTable[0]);
/////////////////////////////
void CMenu::run()
{
	int choice = 0;
	while (_bsysRunning)
	{
		showMainMenu();
		cout << "input:";
		cin >> choice;
		pfunc = gFuncTable[choice - 1];
	}
}

void CMenu::showMainMenu()
{
	cout << "请输入：" << endl;
	cout << "1 登陆"
		"2 注册"
		"3 退出" << endl;
}
int main()
{
	CMenu menu;
	menu.run();
	(menu.*pfunc)();
	return 0;
}