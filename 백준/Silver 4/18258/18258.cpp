#include <iostream>
#include <cstring>

using namespace std;

struct Queue
{
  const int qSize = 2000001;
  int *arr = new int[qSize];
  int idx = 0;
  int arrSize = 0;

  // 또는 constructor 이용
  // Queue() : qSize(2000001), idx(0), arrSize(0) {arr = new int[qSize];};

  void push(int n)
  {
    arr[idx + arrSize++] = n;
  }

  void pop()
  {
    if (arrSize == 0)
    {
      cout << -1 << "\n";
      return;
    }

    cout << arr[idx++] << "\n";
    arrSize--;
  }

  void size()
  {
    cout << arrSize << "\n";
  }

  void empty()
  {
    cout << (arrSize == 0) ? 1 : 0;
    cout << "\n";
  }

  void front()
  {
    if (arrSize == 0)
    {
      cout << -1 << "\n";
      return;
    }

    cout << arr[idx] << "\n";
  }

  void back()
  {
    if (arrSize == 0)
    {
      cout << -1 << "\n";
      return;
    }

    cout << arr[idx + arrSize - 1] << "\n";
  }

  ~Queue()
  {
    delete[] arr;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  long long N = 0;
  string input = "";
  Queue q;

  cin >> N;

  while (N--)
  {
    cin >> input;

    if (input == "push")
    {
      int tmp;
      cin >> tmp;
      q.push(tmp);
    }
    else if (input == "pop")
    {
      q.pop();
    }
    else if (input == "empty")
    {
      q.empty();
    }
    else if (input == "size")
    {
      q.size();
    }
    else if (input == "back")
    {
      q.back();
    }
    else if (input == "front")
    {
      q.front();
    }
  }

  return 0;
}