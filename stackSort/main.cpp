#include "heapManage.h"

using namespace std;

int main()
{
    int arrIN[] = {98, 17, 38, 19, 22, 69, 45, 12, 65, 359};
    heapSort(arrIN, sizeof(arrIN)/sizeof(int));
    cout << "Hello world!" << endl;
    return 0;
}
