#define _CRT_SECURE_NO_WARNINGS 1
//��ĿԤ��:һ���ܹ���ȡ��Ŀ��Դ�������и������ݷ�����Զ�����������
//Part1�����ݷ���
//����Ԥ�ڣ�ͳ��Ŀ¼������ָ���ļ����͵�����-������-ע�ͺ���=��Ч��������
//				  ͳ�Ƹ��ļ��ں���/�������/����/�ӿ�---ģ������/��׼����
//               ����key������key����·����
//Part2����ȡ��Դ
//����Ԥ�ڣ���ȡָ��url�����С���ݹ�ģ����Դ���з���
//����Ԥ��:�ֲ�ʽ�߲�����������ݹ�ģ������
#include"CDA.h"
List s;//��γ�ʼ����
int main () {
	string root_path;
	string search;
	cout << "��������Ҫ���ҵ�·��(C:\\\\example\\\\example\\\\):" << endl;
	cin >> root_path;
	cout << "��������Ҫͳ�Ƶ��ļ���׺(.c):" << endl;
	cin >> search;
	DA test (root_path , search);
	test.GO ();
	system ("pause");
	return 0;
}