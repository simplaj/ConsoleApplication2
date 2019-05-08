// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void Max_Min_2_3(int* arr, int p, int q, int* arr_min_max) {
	int n2 = q - p + 1;
	int len = 0;
	if (n2 == 2) {
		len = 2;
	}
	else if (n2 == 3) {
		len = 3;
	}
	for (int i = p; i < p + len; i++) {
		if (arr[i] < arr_min_max[0]) {
			arr_min_max[0] = arr[i];
		}
		if (arr[i] > arr_min_max[1]) {
			arr_min_max[1] = arr[i];
		}
	}
	cout << "分治结果:";
	cout << arr_min_max[0] << " " << arr_min_max[1] << endl;
}

void sqrt_n_sort(int* arr, int p, int q, int* arr_min_max) {
	//cout << " " << endl;
	int n = q - p + 1;
	int n2 = int(sqrt(n));
	if (n2 > 1) {
		int i = 0;
		for (; i < n2 - 1; i++) {
			cout << "从" << p + n2 * i << "到" << p + n2 * (i + 1) - 1 << endl;
			sqrt_n_sort(arr, p + n2 * i, p + n2 * (i + 1) - 1, arr_min_max);
			//Max_Min_2_3(arr, p + n2*i, p + n2*(i+1) - 1);
		}
		cout << "从"<<p + n2 * i << "到" << q << endl;
		sqrt_n_sort(arr, p + n2 * i, q, arr_min_max);
		//Max_Min_2_3(arr, p + n2*i, q);
		//Merge(arr, p, q);
		//Max_MIN()
	}
	else {
		Max_Min_2_3(arr, p, q, arr_min_max);
	}
}

//void Merge(int*arr, int p, int q){}

int main()
{
	int arr[17] = {12,15,46,78,46,49,45,15,64,78,89,45,15,56,32,45,78 };
	int arr_min_max[2] = { INT_MAX,INT_MIN };
	sqrt_n_sort(&arr[0], 0, 16, &arr_min_max[0]);

	cout<<"最终结果:"<<endl;
	cout << "最小值：" << arr_min_max[0] << endl;
	cout << "最大值：" << arr_min_max[1] << endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
