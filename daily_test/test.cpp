#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//class Person {
//public:
//	void BuyTicket() {
//		cout << "��ͨ��" << endl;
//	}
//};
//
//class Student{
//public:
//	void BuyTicket() {
//		cout << "ѧ��" << endl;
//	}
//};
//
//class Soilder{
//public:
//	void BuyTicket() {
//		cout << "����" << endl;
//	}
//};
//
//template<class T>
//void func(T* ptr) {
//	ptr->BuyTicket();
// }
//int main() {
//	Person person;
//	Student student;
//	Soilder soilder;
//	func(&person);
//	func(&student);
//	func(&soilder);
//
//	return 0;
//}




//class Person {
//public:
//	void BuyTicket() {
//		cout << "��ͨ��" << endl;
//	}
//	int _a;
//	int _b;
//};
//
//template<class T>
//void func(T* ptr) {
//	ptr->BuyTicket();
//	cout << sizeof(T) << endl;
//}
//int main() {
//	Person person;
//	func(&person);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//    int H;
//    int W;
//    cin >> H >> W;
//   /* vector<vector<int>> v;
//    v.resize(H + 2);
//    for (int i = 0; i < H + 2; i++) {
//        v[i].resize(W + 2, 1);
//    }
//    for (int y = 1; y <= H; y++) {
//        for (int x = 1; x <= W; x++) {
//            if (v[y][x] == 1) {
//                v[y - 1][x - 1] = 0;
//                v[y - 1][x + 1] = 0;
//                v[y + 1][x - 1] = 0;
//                v[y + 1][x + 1] = 0;
//            }
//        }
//    }
//    int count = 0;
//    for (int y = 1; y <= H; y++) {
//        for (int x = 1; x <= W; x++) {
//            if (v[y][x] == 1) {
//                count++;
//            }
//        }
//    }
//    cout << count << endl;*/
//    int max = H > W ? H : W;
//    int min = H <= W ? H : W;
//    cout << (max + 1) / 2 * min;
//
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//    int W;
//    int H;
//    int count = 0;
//    cin >> W >> H;
//    vector<vector<int>> v;
//    v.resize(W);
//    for (int i = 0; i < W; i++) {
//        v[i].resize(H, 1);
//    }
//    for (int y = 0; y < W; y++) {
//        for (int x = 0; x < H; x++) {
//            if (v[y][x] == 1 && x + 2 < H) {
//                v[y][x + 2] = 0;
//            }
//            if (v[y][x] == 1 && y + 2 < W) {
//                v[y + 2][x] = 0;
//            }
//        }
//    }
//    for (int y = 0; y < W; y++) {
//        for (int x = 0; x < H; x++) {
//            if (v[y][x] == 1) {
//                count++;
//            }
//        }
//    }
//    cout << count << endl;
//    return 0;
//}



#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
//class Solution {
//public:
//    int maxProductDifference(vector<int>& nums) {
//        int max1 = nums[0];
//        int min1 = nums[0];
//        int max_index = 0;
//        int min_index = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] > max1) {
//                max1 = nums[i];
//                max_index = i;
//            }
//            if (nums[i] < min1) {
//                min1 = nums[i];
//                min_index = i;
//            }
//        }
//        nums.erase(nums.begin() + max_index);
//        nums.erase(nums.begin() + min_index);
//        int max2 = nums[0];
//        int min2 = nums[0];
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] > max2) {
//                max2 = nums[i];
//            }
//            if (nums[i] < min2) {
//                min2 = nums[i];
//            }
//        }
//        return max1 * max2 - min1 * min2;
//    }
//};
//
//int main() {
//    vector<int> v;
//    v.push_back(5);
//    v.push_back(9);
//    v.push_back(4);
//    v.push_back(6);
//    Solution solution;
//    solution.maxProductDifference(v);
//    return 0;
//}

//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        sort(nums.begin(), nums.end()); 
//        int left = 0;// �������±�
//        int right = nums.size() - 1; // �������±�
//        int mid = (left + right) / 2; // �м����±�
//        while (left <= right) {
//            if (nums[mid] > target) {
//                right = mid - 1;
//                mid = (left + right) / 2;
//            }
//            else if (nums[mid] < target) {
//                left = mid + 1;
//                mid = (left + right) / 2;
//            }
//            else {
//                return mid;
//            }
//        }
//        return -1;
//    }
//};
//
//int main() {
//    vector<int> v;
//    v.push_back(-1);
//    v.push_back(0);
//    v.push_back(3);
//    v.push_back(5);
//    v.push_back(9);
//    v.push_back(12);
//    cout << Solution().search(v, 2) << endl;
//
//    return 0;
//}

//class A {
//public:
//
//	virtual void func() = 0 {
//
//	}
//	void f() {
//		cout << "12" << endl;
//	}
//};
//int main() {
//	A().f();
//}
//#include<list>
//int main() {
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//	l.push_back(6);
//	for (list<int>::iterator i = l.begin(); i != l.end(); i++) {
//		i++;
//		cout << *i << endl;
//	}
//	
//	return 0;
//}


//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        vector<int>::iterator left = nums.begin(); //left��left��ߵ�ֵ��Ϊ0
//        vector<int>::iterator right = nums.begin();//��rightȥ��left�ұߵ�0
//        // ������ǵ�right�ҵ���left�ұߵ�0����ô���ǽ�[left,right]���������ƶ�һλ
//        // left�����ճ���һ��λ�ã����Ǹ���0
//        // 0 1 0 3 12
//        while (right < nums.end() && left < nums.end()) {
//            // while(left < nums.end()) {
//            //     if(*left == 0) {
//            //         left++;
//            //     }
//            //     else {
//            //         break;
//            //     }
//            // }
//            while (right < nums.end()) {
//                if (*right != 0) {
//                    right++;
//                }
//                else {
//                    break;
//                }
//            }
//            if (right == nums.end()) {
//                break;
//            }
//            for (vector<int>::iterator i = right; i > left; i--) {
//                *i = *(i - 1);
//            }
//            *left = 0;
//            left++;
//            right++;
//        }
//    }
//};
//
//int main() {
//    vector<int> nums;
//    nums.push_back(0);
//    nums.push_back(1);
//    nums.push_back(0);
//    nums.push_back(3);
//    nums.push_back(12);
//    Solution().moveZeroes(nums);
//
//
//    return 0;
//}
//int go = 98;
//
//void func() {
//	cout << go << endl;
//}
//int main() {
//	/*map<string, string> dict;
//	dict.insert(pair<string, string>("sort", "�ֵ�"));
//	dict.insert(make_pair("insert", "����"));*/
//	//vector<int> v(23,3) ;
//	//v.clear();
//	//char ch1 = '(';
//	//char ch2 = ')';
//	//cout << (char)(ch1 ^ 1) << " " << (char)(ch2 ^ 1) << endl;
//	/*string s1 = "ab";
//	string s2 = "eidboaoo";
//	int a = (s2.find(s1, 0) != string::npos);*/
//	func();
//
//	return 0;
//}

//class Solution {
//public:
//    int Sum(vector<int>& arr) {
//        int sum = 0;
//        for (auto& e : arr) {
//            sum += e;
//        }
//        return sum;
//    }
//    vector<int> sortByBits(vector<int>& arr) {
//        vector<int> arr2(arr);
//        vector<int> ret(0);
//        int pos = 0;
//        int count = 0;
//        for (auto& e : arr2) {
//            e &= e - 1;
//        }
//        for (int i = 0; i < arr.size(); i++) {
//            if (arr2[i] == 0) {
//                ret.push_back(arr[i]);
//                count++;
//            }
//        }
//        sort(ret.begin() + pos, ret.end());
//        pos += count;
//        while (Sum(arr2) != 0) {
//            count = 0;
//            vector<int> tmp(arr2);
//                for (auto& e : arr2) {
//                    e &= e - 1;
//                    count++;
//                }
//            for (int i = 0; i < arr.size(); i++) {
//                if (arr2[i] == 0 && tmp[i] != 0) {
//                    ret.push_back(arr[i]);
//                }
//            }
//            sort(ret.begin() + pos, ret.end());
//            pos += count;
//        }
//        return ret;
//    }
//};
//int main() {
//    Solution s;
//    vector<int> arr;
//    arr.push_back(0);
//    arr.push_back(1);
//    arr.push_back(2);
//    arr.push_back(3);
//    arr.push_back(4);
//    arr.push_back(5);
//    arr.push_back(6);
//    arr.push_back(7);
//    arr.push_back(8);
//    s.sortByBits(arr);
//}


//int main() {
//	string s = "abcdefgh";
//	auto left = s.begin();
//	auto right = s.begin() + 3;
//	auto ret = find(left, right, 'x');
//	
//	return 0;
//}


//class Solution {
//public:
//    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//        sort(arr1.begin(), arr1.end());
//        set<int> tmp; //�����洢arr1�е�δ������arr2�е�Ԫ��
//        for (auto i = arr1.begin(); i != arr1.end(); i++) {
//            if (find(arr2.begin(), arr2.end(), *i) == arr2.end()) {
//                tmp.insert(*i);
//                arr1.erase(i);
//            }
//        }
//        for (auto& e : tmp) {
//            arr1.push_back(e);
//        }
//        return arr1;
//    }
//};
//int main() {
//    vector<int> arr1;
//    vector<int> arr2;
//    arr1.push_back(2);
//    arr1.push_back(3);
//    arr1.push_back(1);
//    arr1.push_back(3);
//    arr1.push_back(2);
//    arr1.push_back(4);
//    arr1.push_back(6);
//    arr1.push_back(7);
//    arr1.push_back(9);
//    arr1.push_back(2);
//    arr1.push_back(19);
//    arr2.push_back(2);
//    arr2.push_back(1);
//    arr2.push_back(4);
//    arr2.push_back(3);
//    arr2.push_back(9);
//    arr2.push_back(6);
//    Solution().relativeSortArray(arr1, arr2);
//
//}

//class Solution {
//public:
//    int GetMaxCount(map<int, int>& count, vector<int>& nums) {
//        int num = 0;
//        for (auto e : nums) {
//            if (count[e] > num) {
//                num = count[e];
//            }
//        }
//        return num;
//    }
//    vector<int> frequencySort(vector<int>& nums) {
//        map<int, int> count;
//        for (auto e : nums) {
//            count[e]++;
//        }
//        //cout << count[nums[0]] << endl;
//        vector<int> ret;
//        int maxCount = GetMaxCount(count, nums);
//        for (int i = 1; i <= maxCount; i++) {
//            set<int> tmp;
//            for (int j = 0; j < nums.size(); j++) {
//                if (i == count[nums[i]]) {
//                    tmp.insert(nums[i]);
//                }
//            }
//            for (auto e : tmp) {
//                for (int k = 0; k < i; k++) {
//                    ret.push_back(e);
//                }
//            }
//        }
//        return ret;
//    }
//};
//
//int main() {
//    vector<int> nums = { 1,1,2,2,2,3 };
//    Solution().frequencySort(nums);
//
//    return 0;
//}

//class Solution {
//public:
//    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//        vector<int> ret;
//        for (int i = 0; i < mat[0].size(); i++) {
//            for (int j = 0; j < mat.size(); j++) {
//                if (i == 0) {
//                    if (mat[j][i] == 0) {
//                        ret.push_back(j);
//                        k--;
//                        if (k == 0) {
//                            return ret;
//                        }
//                    }
//                }
//                else if(i > 0 && i < mat[0].size() - 1) {
//                    if (mat[j][i] == 0 && mat[j][i - 1] == 1) {
//                        ret.push_back(j);
//                        k--;
//                        if (k == 0) {
//                            return ret;
//                        }
//                    }
//                }
//                else {
//                    if (mat[j][i - 1] == 1) {
//                        ret.push_back(j);
//                        k--;
//                        if (k == 0) {
//                            return ret;
//                        }
//                    }
//                }
//            }
//        }
//        return ret;
//    }
//};
//
//int main() {
//    vector<vector<int>> mat =
//    {   {1, 1, 0, 0, 0},
//        {1, 1, 1, 1, 0},
//        {1, 0, 0, 0, 0},
//        {1, 1, 0, 0, 0},
//        {1, 1, 1, 1, 1} };
//    vector<int> ret = Solution().kWeakestRows(mat, 3);
//    for (auto e : ret) {
//        cout << e << " ";
//    }
//    cout << endl;
//    return 0;
//}
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	//Add(a1, a2); //�ܹ���ɺ���ģ���ʵ����
//	//Add(d1, d2); //�ܹ���ɺ���ģ���ʵ����
//	cout << Add(a1, (int)d1) << endl; //����䲻��ͨ������
//	
//	return 0;
//}
//template<class T1, class T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	//Add(a1, a2); //�ܹ���ɺ���ģ���ʵ����
//	//Add(d1, d2); //�ܹ���ɺ���ģ���ʵ����
//	cout << Add(a1, d1) << endl; //����䲻��ͨ������
//
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	cout << Add<int>(a1, d1) << endl;;
//	return 0;
//}

//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//}
//int main()
//{
//	Test();
//	return 0;
//}



//template <class T>
//void func(T* x)
//{
//	cout << "T�Ĵ�С��" << sizeof(T) << endl;
//}
//int main()
//{
//	double a = 1;
//	double* pa = &a;
//	func(pa);
//	return 0;
//}

//int main()
//{
//	printf("%d\n", sizeof(2834848));
//	return 0;
//}


