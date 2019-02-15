#include<iostream>
using namespace std;

class CTestData
{
	int m_nData = 0;
public:
	explicit CTestData(int nParam) : m_nData(nParam) // ������ ��ȯ �����ڰ� ȣ��� ���ɼ� ����
	{
		cout << "CTestData(int)" << endl;
	} // ��ȯ ������
	CTestData(const CTestData& rhs)
	{
		this->m_nData = rhs.m_nData;
		cout << "CTestData(const CTestData&)" << endl;
	}
	int getData() const { return m_nData; }
	void setData(int nParam) { m_nData = nParam; }
};

void TestFunc(CTestData& param) // Ŭ���� ������ �Ű������� ��� �� ���� ���� ���
{
	cout << "TestFunc() : " << param.getData() << endl;
}

int main()
{
	//TestFunc(5); // �����Ϸ��� TestFunc(CTestData(5));�� ��ȯ�� �ڵ���
	CTestData a(5);
	TestFunc(a);
	return 0;
}