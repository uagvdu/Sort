//��̴�ҵĳɳ���Դ������
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


void BubbleSort1(int *a, int sz)//ÿһ��i����i+1֮�������Ԫ�ؽ��бȽϣ�Ȼ��a[i]�����Ӷ��������,�����Ǳ�׼��ð��������Ϊ�䲢�����㡰�����Ƚ����ڼ�¼��
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


void BubbleSort2 (int *a, int sz)//������ֵ���󴫣�ֱ��β����<�����ʽ����ð��>
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
}                       //�ڶ����ǿ��ƴ��������
                        //�������ǿ���С����ǰ��
        
void BubbleSort(int *a, int sz) //�Ż��棺�����ݽӽ��������ʱ�򣬿��Լ��ٲ���Ҫ�Ľ���
{
	bool status = true;//�Ƿ�Ҫ����ð������:˵��δ����
	int i = 0;
	while ((i < sz) &&status)
	{
		status = false;  //˵�������򲻽���ð������ 

		for (int j = sz-1; j >i; j--)   /*ֱ�Ӽ����������� ��������ģ���ô statusֱ��Ϊfalse�� �����ĺô�����һ��ѭ��֮���Բ�ִ�У���
			                              ����Ϊ���鵱i = 0��ʱ�������򣬶������ڿ���i++֮����£�������㷨��Ч�� ��ʹ����������������ô��swap֮��Ҳ���Ϊ����i ������һ��ѭ��Ҳ������ִ�У������˲���Ҫ��ѭ��*/
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



/*ֱ��ѡ������(Straight Select Sorting) Ҳ��һ�ּ򵥵����򷽷������Ļ���˼���ǣ���һ�δ�R[0]~R[n-1]��ѡȡ��
Сֵ����R[0]�������ڶ��δ�R[1]~R[n-1]��ѡȡ��Сֵ����R[1]������....����i�δ�R[i-1]~R[n-1]��ѡ
ȡ��Сֵ����R[i-1]������.....����n-1�δ�R[n-2]~R[n-1]��ѡȡ��Сֵ����R[n-2]�������ܹ�ͨ��n-1�Σ��õ�һ�����������С�������е��������С�*/

void SelectSort1(int *a, int sz)//��ѡ�����򣺲��ϵ�����С��ֵ��a[min]���н��������õ��� a[min] Ϊ��Сֵ
{
	assert(a);
	for (int i = 0; i < sz;i++)
	{
		int  min = i;
		for (int j = i + 1; j < sz; j++) 
		{
			if (a[min] > a[j])
				min = j;          //�ҵ�����Сֵ��j
		}
		swap(a[i],a[min]);
	}
}

void SelectSort2(int *a, int sz)  //������һ�룬������һ��
{
	int left = 0;
	int right = sz - 1;
	
	while (left < right)
	{
		int min = left, max = right;        //�� С���� ��
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

		/*swap(a[left],a[min]);    //��leftΪ����ʱ�򣬽���swap�󣬻�ʹ��maxԭ��ָ���λ�õ�ֵ�������,���bug�����Ƿǳ����׺���
		left++;
		swap(a[right], a[max]);
		right--;*/


	}
}

void SelectSort3(int *a, int sz)//�����Ż���
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

		if (max == left)//�����������������ֵ����left��������Сֵ�����ҵ�ʱ��
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

void HeapSort(int *a, int sz)//�����鿴�����������޷���������
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

int PartSort1(int *a,  int left, int right)//���� 
{
	int begin = left;
	int end = right - 1;
	int key = a[right];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)  //���Ҵ�����С��������ѭ����������С,
		{
			begin++;
		}
		while (begin < end && a[end] >= key)//begin����Ƕ��ѭ���������ǣ�Ҫô����end��Ҫô���ǳ��ִ���key��ֵ
		{
			end--;
		}
		if (begin < end)
			swap(a[begin], a[end]);//������end����λ��һ��Ϊ��begin����λ��һ��ΪС
	}     

	if (a[begin] > a[right])
	{
		swap(a[begin], a[right]);
		return begin;
	}
	else         //a[begin]<= a[right]  ��
		return right; /*��begin == endʱ�� <begin --> end��end-->begin> ��  ��ֵ��key�Ĺ�ϵ����� ��<begin --> end��  ��begin�Ҳ��� > key�Ļ��ͻ��ǵ�begin == end = right - 1 ��ʱ�򡣷�֮ ����������ʱ : �����begin --> end ����begin ��end ���ʱa[begin]һ�������key��
	��ֻҪbegin==end�ͻ��˳��� 	 ���end-->begin���� ��������begin�����ƶ�����begin�ҵ��˴���key��ֵ��( ��begin�Ҳ��� > key�Ļ��ͻ��ǵ�begin == end = right - 1 ��ʱ��)    a[begin]��Ȼ����key������ֻҪkey������д���key����� �ͷ���begin
		 ����a[begin]С��key �������    right ����߶�С��key      */
}

int PartSort2(int *a, int left, int right) //  �ڿӷ�
{                                          //����ͨ����λ��ȡ�з������Ż�

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
	//int mid = (left + right) / 2; �п��ܷ���������int�ķ�Χ��
	int mid = left + ((right - left) >> 1);//���Ƶ�Ч�ʱ�ȡģ����
	//�ֱ�Ƚ�mid ��left ��right��Ϊ�±��Ӧ�����Ĵ�С��ȡ���м���
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
//��λ��ȡ�з�:ȡ���м�ֵ��ʹ��ÿһ�εݹ�ӽ����֣�
int PartSort3(int *a, int left, int right)  // ������������֮��λ��ȡ�з�
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

int PartSort4(int *a, int left, int right)//ǰ��ָ�뷨 ����С��key��ֵ�ŵ����
{
	int mid = GetMid (a, left, right); //������a[right]Ϊ���ֵ������Сֵ�Ĳ������������
	swap(a[mid], a[right]);
	int cur = left;
	int  key = a[right];
	int prev = left - 1;
	while (cur < right)
	{

		/*if (a[cur] < key && ++prev != cur)
			swap(a[cur], a[prev]);

		++cur;*/
		if (a[cur] > key)  //��������key��prevֹͣ�ƶ���curһֱ�����ߣ�ֱ����< key��ֵ������ == right
			cur++;
		else
		{
			prev++;
			if (prev != cur)
			 swap(a[cur],a[prev] );
			cur++;
		}
	}
	swap(a[++prev], a[right]);   //����a[right] �����ֵ������Сֵ��������ֱ�ӽ��н���

	return prev;

}

void QuickSort(int *a,int left,int right) 
{
	assert(a);
	if (left >= right)          /*����left> right ���������Ϊ ֻ�����������е��������ʱ��key < [begin]����swap��[begin]  [right]�� ��
                                 div����begin �Ӷ����ٴεݹ��ʱ���β�right = div-1���β�left = �ϲ��left��*/
    	 return;
	/*int begin = 0;//
	int end = sz - 1;//ÿһ�εݹ��ʱ��begin ��end���ᷢ���ı�*/
	 int div = PartSort1(a,left,right);
	 //int div = PartSort2(a, left, right);//begin == end --> begin
	 // int div = PartSort3(a,left,right);

	if (right - left < 16)
	{
		InsertSort(a + left, right - left + 1); //�ݹ��ȱ����Ƿǳ��˷ѿռ䣬���Ե����ݷǳ����ʱ����õݹ飬�ݹ鵽һ�����ʱ���������ٿ��Բ��ò�������
	}
	else
	{
		//int div = PartSort4(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	
 
}

void QuickSortNOR(int *a, int left, int right) //ÿһ�εݹ鶼��ѹջ������ÿһ���ǵݹ鶼������ѹջ�ķ�ʽ����ݹ�
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