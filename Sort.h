//编程大家的成长：源于用心
#include<iostream>
#include<stack>
#include<cassert>
using namespace std;

void InsertSort(int* a,int sz)
{
	for (int i = 1; i < sz;i++)
	{
		int tmp = a[i];
		int index = i - 1;
		int j = i;
		while (index >= 0)
		{
			if (a[j] < a[index])
			{
				a[j] = a[index];
				a[index] = tmp;		
				index--;
				j--;
			}
			else
			{
				break;
			}
			
		}
	}
}

void ShellSort(int *a,int sz)
{
	int gap =  sz;
	while (gap >= 1)
	{
		for (int i = gap; i < sz;i++)
		{
			int index = i - gap;
			int j = i;
			int tmp = a[i];
			while (index >= 0)
			{
				if (a[i] < a[index])
				{
					a[i] = a[index];
					a[index] = tmp;
					index -= gap;
					j -= gap;
				}
				else
					break;
			}
		}
		gap--;
	}
}


void BubbleSort1(int *a, int sz)//每一个i都和i+1之后的所有元素进行比较，然后a[i]递增从而完成排序,并不是标准的冒泡排序，因为其并不满足“两两比较相邻记录”
{
	for (int i = 0; i < sz;i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}


void BubbleSort2 (int *a, int sz)//将最大的值往后传，直到尾部，<这个方式更像冒泡>
{
	int i = 1;
	while (sz > 0)              
	{
		i = 1;
		while (i<sz)
		{
			if (a[i] < a[i - 1])
				swap(a[i], a[i - 1]);
			i++;
		}
		sz--;
	}
}                       //第二个是控制大的往后走
                        //第三个是控制小的往前走
        
void BubbleSort(int *a, int sz) //优化版：当数据接近于有序的时候，可以减少不必要的交换
{
	bool status = true;//是否要进行冒泡排序:说明未有序
	int i = 0;
	while ((i < sz) &&status)
	{
		status = false;  //说明有序，则不进行冒泡排序 

		for (int j = sz-1; j >i; j--)   /*直接假设整个数组 都是有序的，那么 status直接为false， 这样的好处是下一次循环之所以不执行，就
			                              是因为数组当i = 0的时候已有序，而不用在考虑i++之后的事，提高了算法的效率 即使假设两个数无序，那么当swap之后也会变为有序，i 的下下一次循环也不会在执行，减少了不必要的循环*/
		{
			if (a[j - 1] > a[j]) 
			{
				swap(a[j - 1], a[j]);
				status = true;
			}
		}
		i++;
	}

}



/*直接选择排序(Straight Select Sorting) 也是一种简单的排序方法，它的基本思想是：第一次从R[0]~R[n-1]中选取最
小值，与R[0]交换，第二次从R[1]~R[n-1]中选取最小值，与R[1]交换，....，第i次从R[i-1]~R[n-1]中选
取最小值，与R[i-1]交换，.....，第n-1次从R[n-2]~R[n-1]中选取最小值，与R[n-2]交换，总共通过n-1次，得到一个按排序码从小到大排列的有序序列·*/

void SelectSort1(int *a, int sz)//：选择排序：不断的找最小的值和a[min]进行交换，最后得到的 a[min] 为最小值
{
	assert(a);
	for (int i = 0; i < sz;i++)
	{
		int  min = i;
		for (int j = i + 1; j < sz; j++) 
		{
			if (a[min] > a[j])
				min = j;          //找的是最小值的j
		}
		swap(a[i],a[min]);
	}
}

void SelectSort2(int *a, int sz)  //正着走一半，反着走一半
{
	int left = 0;
	int right = sz - 1;
	
	while (left < right)
	{
		int min = left, max = right;        //左 小，右 大
		for (int i = left; i < sz; i++)
		{
			if (a[min] > a[i])
				min = i;
	
		}

		swap(a[left], a[min]);
		left++;

		for (int i = right; i >= 0; i--)
		{
			if (a[max] < a[i])
				max = i;
		}

		swap(a[right], a[max]);
		right--;

		/*swap(a[left],a[min]);    //当left为最大的时候，进行swap后，会使得max原来指向的位置的值不是最大,这个bug还真是非常容易忽略
		left++;
		swap(a[right], a[max]);
		right--;*/


	}
}

void SelectSort3(int *a, int sz)//最终优化版
{
	int left = 0;
	int right = sz - 1;
	while (left<right)
	{
		int max = left;
		int min = left;
		for (int i = left; i <= right;i++)
		{
			if (a[min]> a[i])
				min = i;
			if (a[max] < a[i])
				max = i;

		}
		swap(a[min],a[left]);

		if (max == left)//这种情况是针对于最大值在最left，并且最小值在最右的时候。
			max = min;

		swap(a[max], a[right]);
		left++;
		right--;

	}

}

void _AdjustDown(int i, int *a, int sz)
{
	int parent = i;
	int child = parent * 2 + 1;
	while (child < sz)
	{
		if (child + 1 < sz &&a[child] < a[child + 1])
			child++;
		if (a[parent] < a[child])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int *a, int sz)//将数组看作二叉树，无法排序链表。
{
	for (int i = (sz - 2) / 2; i >= 0; i--)
	{
		_AdjustDown(i, a, sz);
	}
	int index = sz - 1;
	while (index)
	{
		swap(a[0],a[index]);
		index--;
		_AdjustDown(0,a,index);
	}
}

int PartSort1(int *a,  int left, int right)//初级 
{
	int begin = left;
	int end = right - 1;
	int key = a[right];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)  //左找大，右找小，跳出内循环，交换大小,
		{
			begin++;
		}
		while (begin < end && a[end] >= key)//begin跳出嵌套循环的条件是：要么等于end，要么就是出现大于key的值
		{
			end--;
		}
		if (begin < end)
			swap(a[begin], a[end]);//交换后end所在位置一定为大，begin所在位置一定为小
	}     

	if (a[begin] > a[right])
	{
		swap(a[begin], a[right]);
		return begin;
	}
	else         //a[begin]<= a[right]  ：
		return right; /*当begin == end时： <begin --> end，end-->begin> ：  其值与key的关系不清楚 。<begin --> end：  若begin找不到 > key的话就会是当begin == end = right - 1 的时候。反之 当发生交换时 : 如果：begin --> end ，则begin 和end 相等时a[begin]一定会大于key，
	（只要begin==end就会退出） 	 如果end-->begin，它 的条件是begin不再移动，即begin找到了大于key的值。( 若begin找不到 > key的话就会是当begin == end = right - 1 的时候。)    a[begin]仍然大于key。所以只要key的左边有大于key的情况 就返回begin
		 所以a[begin]小于key 的情况是    right 的左边都小于key      */
}

int PartSort2(int *a, int left, int right) //  挖坑法
{                                          //可以通过三位数取中法进行优化

	int begin = left;
	int end = right;
	int key = a[right];
	while (begin < end)
	{
		while (begin<end&&a[begin] <= key)
		{
			begin++;
		}
		if (begin < end)
		{
			a[end] = a[begin];
		}
		while (begin < end&&a[end] >= key)
		{
			end--;
		}
		if (begin < end)
		{
			a[begin] = a[end];
		}

	} 
		a[begin] = key;
		return begin;
 
}

int GetMid(int *a, int left, int right)
{
	//int mid = (left + right) / 2; 有可能发生超过了int的范围，
	int mid = left + ((right - left) >> 1);//右移的效率比取模更高
	//分别比较mid ，left ，right作为下标对应的数的大小，取其中间数
	if (a[mid] < a[left])
	{
		if (a[mid]> a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid] < a[right])
			return right;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
}
//三位数取中法:取得中间值，使得每一次递归接近二分，
int PartSort3(int *a, int left, int right)  // 初级单趟排序之三位数取中法
{                                            
	int mid = GetMid(a,left,right);
	swap(a[mid],a[right]);
	int begin = left;
	int end = right  ;            
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <=  key)
		{
			begin++;
		}
		while (begin < end && a[end] >=  key)
		{
			end--;
		}
		if (end > begin)
			swap(a[begin], a[end]);
	}

	if (a[begin] > a[right])
	{
		swap(a[begin], a[right]);
		return begin;
	}
	else
		return right;

}

int PartSort4(int *a, int left, int right)//前后指针法 ：将小于key的值放到左边
{
	int mid = GetMid (a, left, right); //避免了a[right]为最大值或者最小值的产生的特殊情况
	swap(a[mid], a[right]);
	int cur = left;
	int  key = a[right];
	int prev = left - 1;
	while (cur < right)
	{

		/*if (a[cur] < key && ++prev != cur)
			swap(a[cur], a[prev]);

		++cur;*/
		if (a[cur] > key)  //碰到大于key的prev停止移动，cur一直往后走，直到找< key的值或者是 == right
			cur++;
		else
		{
			prev++;
			if (prev != cur)
			 swap(a[cur],a[prev] );
			cur++;
		}
	}
	swap(a[++prev], a[right]);   //不论a[right] 是最大值还是最小值，都可以直接进行交换

	return prev;

}

void QuickSort(int *a,int left,int right) 
{
	assert(a);
	if (left >= right)          /*出现left> right 的情况是因为 只有两个数进行单躺排序的时候，key < [begin]会有swap（[begin]  [right]） ，
                                 div等于begin 从而当再次递归的时候，形参right = div-1；形参left = 上层的left；*/
    	 return;
	/*int begin = 0;//
	int end = sz - 1;//每一次递归的时候，begin 和end都会发生改变*/
	 int div = PartSort1(a,left,right);
	 //int div = PartSort2(a, left, right);//begin == end --> begin
	 // int div = PartSort3(a,left,right);

	if (right - left < 16)
	{
		InsertSort(a + left, right - left + 1); //递归的缺点就是非常浪费空间，所以当数据非常大的时候采用递归，递归到一定深度时数据量变少可以采用插入排序。
	}
	else
	{
		//int div = PartSort4(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	
 
}

void QuickSortNOR(int *a, int left, int right) //每一次递归都是压栈，所以每一个非递归都可以用压栈的方式解决递归
{
	stack<int> s;
	s.push(left);
	s.push(right);
	 
	while (!s.empty())
	{
		int end = s.top();
		s.pop();
		int begin = s.top();
		s.pop();
		int div = PartSort2(a,begin,end);

		if (begin < div - 1)
		{
			s.push(begin);
			s.push(div - 1);
		}

		if (div + 1 < end)
		{
			s.push(div + 1);
			s.push(end);
		}
	}

}
void Merge(int *a,int *tmp,int begin,int end,int begin2,int end2)
{
	int index = begin;
	while (begin <= end&&begin2 <= end2)
	{
		if (a[begin] <= a[begin2])
		{
			tmp[index++] = a[begin++];
		}
		else
			tmp[index++] = a[begin2++];
	}
	while (begin <= end)
		tmp[index++] = a[begin++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

}

void _MergeSort(int *a,int *tmp,int left,int right)
{
	assert(a);
	if (left == right)
		return;

	int mid = left + ((right - left) >>1);

	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	Merge(a,tmp,left,mid,mid+1,right);

	memcpy(a + left, tmp + left, (right - left + 1)*sizeof(int));
}

void MergeSort(int* a, size_t sz)
{
	int* tmp = new int[sz];
	assert(tmp);

	_MergeSort(a, tmp, 0, sz - 1);


	delete[] tmp;
}

void display(int *a,int sz)	
{
	for (int i = 0; i < sz; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


void TextSort()
{
	int array[] = { 9, 1, 8, 26, 7, 3, 26, 48, 18 };

	int brrby[] = { 9, 1, 8, 5, 7, 3, 26, 48, 18 };
	int crrcy[] = { 49, 9, 8, 5, 7, 3, 26, 18, 1};
	int sz = sizeof(array) / sizeof(array[0]);
	/*InsertSort( array,sz);
	display(array, sz);*/
	cout << "ShellSort : "<<endl;
	 ShellSort(array,sz);
	 display(array, sz);

	cout << "--------------" << endl;
	
	BubbleSort(brrby, sz);
	//BubbleSort2(brrby, sz);
	display(brrby, sz);

	//HeapSort(brrby, sz);

	cout << "--------------" << endl;
	SelectSort2(crrcy, sz); 
	display(crrcy, sz);

}

void TextQSort()
{

	int array[] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 5 };
	int brrby[] = { 6,5,4,3,2,1 };
	int sz = sizeof(array) / sizeof(array[0]);
	int szb = sizeof(brrby) / sizeof(brrby[0]);

	  QuickSort(array, 0,sz-1);
	 display(array, sz);

	  cout << "--------" << endl;
	QuickSort(brrby, 0, szb - 1);

	display(brrby, szb);  

	QuickSortNOR(array, 0, sz - 1);
	display(array, sz);
	QuickSortNOR(brrby, 0, szb - 1);
	display(brrby, szb); 

}

void TextMergeSort()
{
	int array[] = { 9, 8, 1, 5, 26, 7, 8, 26, 48, 8 };
	int sz = sizeof(array) / sizeof(array[0]);
	MergeSort(array,  sz);
	display(array, sz);
}