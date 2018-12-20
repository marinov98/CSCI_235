#include <queue>
#include <iostream>

int main(int argc, char *argv[])
{
        std::priority_queue<int> q;
        q.push(2);
        q.push(5);
        q.push(1);
        q.push(3);

        for(int i = 0; i < 4; i++) {
                std::cout << q.top() << " ";
                q.pop();
        }
        return 0;
}

