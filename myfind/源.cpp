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

//����ļ��е�·��������
typedef struct file_data
{
	char path[PATH_LEN];
}file_data;

char root_path[PATH_LEN];            //��Ÿ�Ŀ¼·��
char paths[PATH_NUM][PATH_LEN];      //������в��ҵ�·��
int  file_num = 0;				     //�ļ����� 
char options[4][20] = { "-name", "-prune", "-mtime", "-ctime" };
queue < file_data * > que;
long time_now = time(NULL);
char find_without[PATH_LEN] = " ";         //��������Ŀ¼



void Print_Inf() {
	cout << "*******-----*******" << endl;
	cout << "������201766631228" << endl;
	cout << "*******-----*******" << endl;
	cout << "����help��ȡ����" << endl;
}

void Render_help() {
	cout << endl;
	cout << "ָ���ʽ��find PATH -option ���� -print\n";
	cout << "PATH:     ������·��(�����ո�) \n";
	cout << "-option:  ��ͬ��������ʽ \n";
	cout << "������  ĳЩ������ʽ��Ҫ�����巽ʽ���£�\n";
	cout << "-print:   ���������������粻��������������\n";
	cout << endl;
	cout << "*****************************************************************\n";
	cout << "* -option     *   ����  *                ����                   *\n";
	cout << "**************n**************************************************\n";
	cout << "* -prune      * Ŀ¼��  * ָ������ʱ��������Ŀ¼                *\n";
	cout << "* -name       * �ļ���  * �����ļ��������ļ�                    *\n";
	cout << "* -mtime      * +n��-n  * ��ʾn��֮ǰ/���޸Ĺ����ļ�            *\n";
	cout << "* -ctime      * +n��-n  * ��ʾn��֮ǰ/�󴴽����ļ�              *\n";
	cout << "*****************************************************************\n";
	cout << "\n";

}

void Find_file(char * get_parameter) {
	file_num = 0;
	struct _finddata_t c_file;			// ����ļ�����
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
			cout << "������ָ�" << endl;
			cin >> get_help;
		}

		strcpy_s(get_find, get_help);

		if (strcmp(get_find, "find") != 0) {
			cout << "�������" << endl;
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
			cout << "�������" << endl;
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