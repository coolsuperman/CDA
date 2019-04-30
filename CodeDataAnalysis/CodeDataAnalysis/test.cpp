#define _CRT_SECURE_NO_WARNINGS 1
//项目预期:一个能够爬取项目资源，并进行各类数据分类的自动化分析工具
//Part1：数据分析
//基础预期：统计目录下所有指定文件类型的行数-空行数-注释函数=有效代码行数
//				  统计各文件内函数/类的名称/个数/接口---模糊搜索/精准搜索
//               给定key，返回key所在路径；
//Part2：爬取资源
//基础预期：爬取指定url下相较小数据规模的资源进行分析
//进阶预期:分布式高并发处理大数据规模的需求；
#include"CDA.h"
List s;//如何初始化？
int main () {
	string root_path;
	string search;
	cout << "请输入你要查找的路径(C:\\\\example\\\\example\\\\):" << endl;
	cin >> root_path;
	cout << "请输入你要统计的文件后缀(.c):" << endl;
	cin >> search;
	DA test (root_path , search);
	test.GO ();
	system ("pause");
	return 0;
}