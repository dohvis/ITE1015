#include <iostream>
#define SIZE 5

using namespace std;


int main()
{
    int array[SIZE];
    
    int sum = 0;
    for(int i=0; i<SIZE; i++) {
        cin >> array[i];
        sum += array[i];
    }
   
    sort(array, array + SIZE);
    int min = array[0];
    int max = array[SIZE-1];
   
    cout << "min: " << min << endl << "max: " << max << endl << "sum: " << sum << endl;
    return 0;
}
