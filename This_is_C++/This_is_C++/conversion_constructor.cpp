#include<iostream>
using namespace std;

class CTestData
{
	int m_nData = 0;
public:
	explicit CTestData(int nParam) : m_nData(nParam) // 묵시적 변환 생성자가 호출된 가능성 차단
	{
		cout << "CTestData(int)" << endl;
	} // 변환 생성자
	CTestData(const CTestData& rhs)
	{
		this->m_nData = rhs.m_nData;
		cout << "CTestData(const CTestData&)" << endl;
	}
	int getData() const { return m_nData; }
	void setData(int nParam) { m_nData = nParam; }
};

void TestFunc(CTestData& param) // 클래스 형식을 매개변수로 사용 시 참조 형식 사용
{
	cout << "TestFunc() : " << param.getData() << endl;
}

int main()
{
	//TestFunc(5); // 컴파일러가 TestFunc(CTestData(5));로 변환해 코딩함
	CTestData a(5);
	TestFunc(a);
	return 0;
}