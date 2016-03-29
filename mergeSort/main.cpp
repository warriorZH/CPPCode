#include "recurMerge.h"
#include "iteraMerge.h"

using namespace std;

int main()
{
    int arrIN1[] = {98, 17, 38, 19, 22, 69, 45, 12, 65, 359, 984, 65};
    int arrIN2[] = {98, 17, 38, 19, 22, 69, 45, 12, 65, 359, 984, 65};
    int leftSide = 0;
    int rightSide = sizeof(arrIN1)/sizeof(int) - 1;
    cout << "arr lenght :" << sizeof(arrIN2)/sizeof(int)<<endl;
    recurMergeSort(arrIN1, leftSide, rightSide);
    iteraMergeSort(arrIN2, sizeof(arrIN2)/sizeof(int));

    return 0;
}
