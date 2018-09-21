#include <iostream>

using namespace std;


int main()
{
    int input[6];
    int array[2][3]; 
    int cnt = 0;
    for(int i=0; i<6; i++) {
        cin >> input[i];   
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<2;j++) {
            array[i][j] = input[cnt];
            cnt += 1;
        }
        cout << array[i][0] << " " << array[i][1] << endl;
    }
    cout << "1번째 열의 숫자의 합: " << array[0][0] + array[1][0] + array[2][0] << endl;
    cout << "2번째 열의 숫자의 합: " << array[0][1] + array[1][1] + array[2][1] << endl;
    return 0;
}
