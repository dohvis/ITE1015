#include "shared_ptr.h"

int main() {
    {
        My_shared_ptr<int> a;
        cout << a.getCount() << endl;
        {
            My_shared_ptr<int> b(new int(5));
            cout << a.getCount() << endl;
            cout << b.getCount() << endl;
            if (a.get_m_obj() == b.get_m_obj())
                cout << "resource shared" << endl;

            a = b;//assignment operation
            cout << a.getCount() << endl;
            cout << b.getCount() << endl;
            if (a.get_m_obj() == b.get_m_obj())
                cout << "resource shared" << endl;
        }
        cout << a.getCount() << endl;
    }
    return 1;
}
