#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
// map은 key와 value로 구성
//int main()
//{
//    map<char, int> m;
//    m['c'] = 1;
//    m['a'] = 10;
//    m['z'] = 99;
//    m['h'] = 77;
//
//    for_each(m.begin(), m.end(), [&](pair<char, int> itr)
//        {
//            printf("%c %d\n", itr.first, itr.second);
//        });
//
//    map<char, int>::reverse_iterator itr = m.rbegin();
//
//    for (; itr != m.rend(); itr++)
//    {
//       printf("%c %d\n", itr->first, itr->second);
//    }
//
//    //printf("%s\n", m.empty());
//    //printf("%d\n", m.size());
//    //printf("%d\n", m.max_size());
//
//    printf("%d\n", m['c']);
//    printf("%d\n", m.at('z'));
//    return 0;
//}

int main()
{
	/****** insert() ******/
	map<char, int> m1;
	m1.insert(pair<char, int>('a', 10));
	m1.insert(pair<char, int>('f', 20));
	m1.insert(pair<char, int>('c', 30));
	

	/****** emplace(), emplace_hint() ******/
	map<char, int> m2;
	m2.emplace('z', 100);
	m2.emplace('d', 200);
	m2.emplace('q', 300);

	map<char, int>::iterator itr1 = m2.find('q');
	m2.emplace_hint(itr1, 'r', 111);
	m2.emplace_hint(itr1, 'x', 222);

	/****** erase() ******/
	map<char, int> m3;
	m3['a'] = 1;
	m3['b'] = 2;
	m3['c'] = 3;
	m3['d'] = 4;
	m3['e'] = 5;
	m3['f'] = 6;
	m3['g'] = 7;

	m3.erase('c');
	m3.erase(m3.find('d'), m3.end());

	/****** swap() ******/
	m1.swap(m3);

	// m1과 m3의 요속소값을 바꿔준다.

	/****** clear() ******/
	m1.clear();    //map<char, int>().swap(m1)을 추천.
	// m1의 데이터 전부 삭제


	map<char, int> m;

	m['a'] = 1;
	m['b'] = 2;
	m['c'] = 3;
	m['d'] = 4;
	m['e'] = 5;
	m['f'] = 6;

	//****** find(), count() ******//

	if (m.find('a') != m.end())
		cout << "find : a" << endl;
	else
		cout << "not find" << endl;
	//output : find : a

	if (m.find('z') != m.end())
		cout << "find : z" << endl;
	else
		cout << "not find" << endl;
	//output : not find

	cout << m.count('a') << endl;    //output : 1
	cout << m.count('c') << endl;    //output : 1
	cout << m.count('z') << endl;    //output : 0


	//******* lower_bound(), upper_bound() ******//

	m.erase(m.lower_bound('c'), m.upper_bound('e'));
	for (auto itr = m.begin(); itr != m.end(); itr++)
		cout << itr->first << " " << itr->second << endl;
	//output : a 1, b 2, f 6

	pair <map<char, int>::iterator, map<char, int>::iterator> itr;
	itr = m.equal_range('a');

	printf("%c %d\n", itr.first->first, itr.first->second);
	printf("%c %d\n", itr.second->first, itr.second-> second);
	
	//output : a 1, b 2
	return 0;
}