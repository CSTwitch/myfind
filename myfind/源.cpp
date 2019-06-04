#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <fcntl.h>
#include <io.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

#define PATH_NUM 1024
#define PATH_LEN 1024

//存放文件夹的路径和名字
typedef struct file_data
{
	char path[PATH_LEN];
}file_data;

char root_path[PATH_LEN];            //存放根目录路径
char paths[PATH_NUM][PATH_LEN];      //存放所有查找的路径
int  file_num = 0;				     //文件个数 
char options[4][20] = { "-name", "-prune", "-mtime", "-ctime" };
queue < file_data * > que;
long time_now = time(NULL);
char find_without[PATH_LEN] = " ";         //不搜索该目录



void Print_Inf() {
	cout << "*******-----*******" << endl;
	cout << "刘楚才201766631228" << endl;
	cout << "*******-----*******" << endl;
	cout << "输入help获取帮助" << endl;
}

void Render_help() {
	cout << endl;
	cout << "指令格式：find PATH -option 参数 -print\n";
	cout << "PATH:     搜索的路径(不含空格) \n";
	cout << "-option:  不同的搜索方式 \n";
	cout << "参数：  某些搜索方式需要，具体方式如下：\n";
	cout << "-print:   将搜索结果输出，如不输出，请随便输入\n";
	cout << endl;
	cout << "*****************************************************************\n";
	cout << "* -option     *   参数  *                功能                   *\n";
	cout << "**************n**************************************************\n";
	cout << "* -prune      * 目录名  * 指出搜索时不搜索该目录                *\n";
	cout << "* -name       * 文件名  * 根据文件名搜索文件                    *\n";
	cout << "* -mtime      * +n或-n  * 表示n天之前/后修改过的文件            *\n";
	cout << "* -ctime      * +n或-n  * 表示n天之前/后创建的文件              *\n";
	cout << "*****************************************************************\n";
	cout << "\n";

}

void Find_file(char * get_parameter) {
	file_num = 0;
	struct _finddata_t c_file;			// 存放文件属性
	intptr_t hFile;

	while (que.size() > 0) {
		file_data* floder_temp = que.front();
		char* files = (char*)malloc(sizeof(char) * 1024);

		strcpy(files, floder_temp->path);
		strcat(files, "\\");
		strcat(files, get_parameter);
		if (hFile = _findfirst(files, &c_file) != -1L) {
		
		}

	}
}



int main(int argc,int argv[]) {
	Print_Inf(); 
	char get_help[PATH_LEN];
	char get_find[PATH_LEN];
	char get_option[PATH_LEN];
	char get_parameter[PATH_LEN];
	char get_print[PATH_LEN];
	file_data * folder_first = (file_data *)malloc(sizeof(file_data));
	int  data_time = 0;

	while (1) {
		cin >> get_help;
		while (strcmp(get_help, "help")==0) {
			Render_help();
			cout << "请输入指令：" << endl;
			cin >> get_help;
		}

		strcpy_s(get_find, get_help);

		if (strcmp(get_find, "find") != 0) {
			cout << "输入错误！" << endl;
			continue;
		}
		cin >> root_path;
		cin >> get_option;
		cin >> get_parameter;
		cin >> get_print;
		strcpy_s(folder_first->path, root_path);
		if (strcmp(get_option, options[0]) == 0) {
			que.push(folder_first);

		}
		else if (strcmp(get_option, options[1]) == 0) {
		
		}
		else if (strcmp(get_option, options[2]) == 0)
		{

		}
		else if (strcmp(get_option, options[3]) == 0)
		{

		}
		else {
			cout << "输入错误！" << endl;
			continue;
		}

		if (strcmp(get_print, "-print") == 0) {
			cout << endl << endl;
			for (int i = 0; i < file_num; i++) {
				cout << paths[i] << endl;
			}
			cout << endl << endl;
		}







	}

	

	return 0;

}