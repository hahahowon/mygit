#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    for(int i=0;i<q.size();++i)//q.size 변수로 만들어 놓고 넣는게 좋다 호출될때 마다 함수를 불러오기 때문에 시간복잡도가 늘어난다.
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
