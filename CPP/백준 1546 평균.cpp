/*���� ���, 
�������� �ְ����� 70�̰�, 
���������� 50�̾����� ���������� 
50/70*100�� �Ǿ� 71.43���� �ȴ�.
ù° �ٿ� ���� �� ������ ���� N�� �־�����. �� ���� 1000���� �۰ų� ����.
 ��° �ٿ� �������� ���� ������ �־�����. 
�� ���� 100���� �۰ų� ���� ���� �ƴ� �����̰�, ��� �ϳ��� ���� 0���� ũ��.
*/
#include<iostream>
using namespace std;

int main()
{
	int line_num;
	cin>>line_num;
	float arr[line_num];
	float max(0);
	float sum(0);
	
	for(int i=0; i<line_num; i++)
	{
		cin>>arr[i];
		if(arr[i]>max)
		max=arr[i];

	}
	for(int i=0; i<line_num; i++)
	sum+=(arr[i]/max)*100;
	
	cout<<sum/line_num<<endl;
}
