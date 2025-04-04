#include <iostream>
#include <vector>

using namespace std;

/* 打印 vector 容器中的元素 */
void print_vector(vector<int> nums) {
  vector<int>::iterator it = nums.begin();
  while (it != nums.end()) {
    cout << *it << " ";
    it++;
  }

  cout << endl;
}

// 复制和拷贝
void test_01() {
  vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
  cout << "v1: ";
  print_vector(v1);

  // 将 v1 中的元素拷贝给 v2
  vector<int> v2(v1.begin(), v1.begin() + 4);
  cout << "v2: ";
  print_vector(v2);
  // cout << "v2[4] = " << v2[4] << endl;

  vector<vector<int>> mat = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};

  // 将 mat[1] 中的元素拷贝给 v3
  vector<int> v3(mat[1]);
  cout << "v3: ";
  print_vector(v3);
  cout << "v3[3] = " << v3[1] << endl;
}

// 赋值
void test_02() {
  vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
  cout << "v1: ";
  print_vector(v1);

  // 将 v1 的值赋值给 v2
  vector<int> v2;
  v2 = v1;
  cout << "v3: ";
  print_vector(v2);

  vector<int> v3;
  v3.assign(10, 20);
  cout << "v3: ";
  print_vector(v3);
}

// 容器大小和容量
void test_03() {
  vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};

  if (v1.empty()) {
    cout << "v1 容器为空！";
  } else {
    cout << "容器大小（元素个数）：" << v1.size() << endl;
    cout << "容器容量（容器可以放多少个元素）：" << v1.capacity() << endl;
  }

  cout << "重新填充过的容器：";
  v1.resize(10, -1);
  print_vector(v1);
  if (v1.empty()) {
    cout << "v1 容器为空！";
  } else {
    cout << "容器大小（元素个数）：" << v1.size() << endl;
    cout << "容器容量（容器可以放多少个元素）：" << v1.capacity() << endl;
  }
}

// 插入和删除
void test_04() {
  vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};

  // 在索引 0 位置插入元素
  v1.insert(v1.begin(), 10);
  print_vector(v1);

  // 在索引 2 位置插入元素
  v1.insert(v1.begin() + 2, -1);
  print_vector(v1);

  // 在索引 0 位置插入 2 个元素（往后推）
  v1.insert(v1.begin(), 2, -2);
  print_vector(v1);

  // 删除索引 0 位置的元素
  v1.erase(v1.begin());
  print_vector(v1);

  // 清空
  v1.erase(v1.begin(), v1.end());
  if (v1.empty()) {
    cout << "v1 容器为空！" << endl;
  }

  vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8};
  // cout << "v2 删除前 3 个：";
  // v2.erase(v2.begin(), v2.begin() + 3);
  cout << "v2 删除后 3 个：";
  v2.erase(v2.end() - 3, v2.end());
  print_vector(v2);
}

// 数据存取
void test_05() {
  vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};

  cout << "首个元素：" << v1.front() << endl;
  cout << "末尾元素：" << v1.back() << endl;
}

// 互换元素
void test_06() {
  vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> v2 = {2, 4, 3, 6, 8};

  v2.swap(v1);

  cout << "v1: ";
  print_vector(v1);

  cout << "v2: ";
  print_vector(v2);
}

int main() {
  test_01();
  // test_02();
  // test_03();
  test_04();
  // test_05();
  // test_06();

  return 0;
}